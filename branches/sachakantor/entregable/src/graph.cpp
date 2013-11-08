#include<algorithm>
//#include<numeric>
//#include<functional>
#include<iterator>
//#include <list>
//#include <ctime>
#include<cmath>
#include<iostream>
#include<vector>
#include<deque>
#include<stack>
//#include <union_find_by_rank.hpp> /*define union_find_set*/
#include<graph.hpp> /*define node,edge,graph*/

/*Expresiones Lambda para el ordenamiento de nodos*/
#define MAYOR_A_MENOR_POR_GRADO [this](int v,int w){return this->_nodes[w-1]->_degree < this->_nodes[v-1]->_degree;}
#define MENOR_A_MAYOR_POR_GRADO [this](int v,int w){return this->_nodes[w-1]->_degree > this->_nodes[v-1]->_degree;}
#define MAYOR_A_MENOR_POR_GRADO_PTR [](const node* v,const node* w){return v->_degree < w->_degree;}

using namespace std;

/***************************************************************
node*   *******************************************************
***************************************************************/
/*Constructores y Destructores*/
node::node(const node_id id,const degree d,const uint max_degree) :
    _id(id),
    _degree(d),
    _neighbors()
{
    //this->_neighbors.reserve(max_degree);
}

node::node(uint id,degree d) :
    _id(id),
    _degree(d),
    _neighbors()
{}

node::node(const node& copy) :
    _id(copy._id),
    _degree(copy._degree),
    _neighbors(copy._neighbors)
{}

node::~node(){}

/*Operadores*/
bool node::operator==(const node& v) const{
    return this->_id == v._id &&
            this->_degree == v._degree &&
            this->_neighbors == v._neighbors;
}

bool node::operator!=(const node& v) const{
    return this->_id != v._id ||
            this->_degree != v._degree ||
            this->_neighbors != v._neighbors;
}

bool node::operator<(const node& v) const{
    return this->_id < v._id;
}

/***************************************************************
* Edge  *******************************************************
***************************************************************/
/*Constructor*/
edge::edge() : _node_id_A(0), _node_id_B(0){}

edge::edge(node_id a,node_id b) :
    _node_id_A(a),
    _node_id_B(b)
{}

edge::edge(const edge& e) :
    _node_id_A(e._node_id_A),
    _node_id_B(e._node_id_B)
{}

/*Operadores*/
bool edge::operator==(const edge& e) const{
    return this->_node_id_A == e._node_id_A && this->_node_id_B == e._node_id_B;
}

bool edge::operator!=(const edge& e) const{
    return this->_node_id_A != e._node_id_A || this->_node_id_B != e._node_id_B;
}

/***************************************************************
* Graph *******************************************************
***************************************************************/
/*Constructores y destructor*/
graph::graph() : _quant_nodes(0),_quant_edges(0){}

graph::graph(const graph& copy) :
    _quant_nodes(copy._quant_nodes),
    _quant_edges(copy._quant_edges),
    _adjacency_matrix(copy._adjacency_matrix),
    _nodes(copy._quant_nodes,NULL),
    _edges(copy._quant_edges,NULL)
{
    /* Copiamos los nodos*/
    for(uint i = 0;i<_quant_nodes;++i){
        this->_nodes[i] = new node(*copy._nodes[i]);
    }

    /* Copiamos los ejes */
    for(uint i = 0;i<_quant_edges;++i){
        this->_edges[i] = new edge(*copy._edges[i]);
    }
}

graph::graph(uint quant_nodes,uint quant_edges,vector<node_id>::const_iterator& it_edges_nodes) :
    _quant_nodes(quant_nodes),
    _quant_edges(quant_edges),
    _adjacency_matrix(quant_nodes,vector<bool>(quant_nodes,false)),
    _nodes(quant_nodes,NULL),
    _edges(quant_edges,NULL)
{
    /*Variables locales*/
    node_id a,b;

    /*Nodos*/
    for(node_id i = 0; i<quant_nodes; ++i){
        this->_nodes[i] = new node(i+1,0,quant_nodes-1);
    }

    /*Ejes*/
    for(uint edge = 0; edge<quant_edges; ++edge){
        /*Leemos los extremos del eje*/
        a = *it_edges_nodes;
        ++it_edges_nodes;
        b = *it_edges_nodes;
        ++it_edges_nodes;

        /*Creamos el eje y actualizamos la matriz de adyacencia*/
        this->_edges[edge] = new struct edge(a,b);
        this->_adjacency_matrix[a-1][b-1] = true;
        this->_adjacency_matrix[b-1][a-1] = true;

        /*Actualizamos la info de los nodos*/
        ++this->_nodes[a-1]->_degree;
        this->_nodes[a-1]->_neighbors.push_back(b);
        ++this->_nodes[b-1]->_degree;
        this->_nodes[b-1]->_neighbors.push_back(a);
    }

    #ifdef _VECINOS_ORDENADOS
    /*Ordenamos los vecinos segun el grado de mayor a menor*/
    for(vector<node*>::iterator it = this->_nodes.begin();
        it != this->_nodes.end();
        ++it)
    {
        sort((*it)->_neighbors.begin(),
            (*it)->_neighbors.end(),
            MAYOR_A_MENOR_POR_GRADO
        );
    }
    #endif//_VECINOS_ORDENADOS
}

graph::~graph(){
    for(uint i = 0; i < this->_quant_nodes;++i)
        delete this->_nodes[i];

    for(uint i = 0; i < this->_quant_edges;++i)
        delete this->_edges[i];
}

/***************************************************************/
/*Métodos publicos*/
uint graph::cmf_backtracking(vector<node_id>& clique) const{
    /*Variables locales*/
    vector<deque<node_id> > candidates(this->_quant_nodes);
    vector<node_id> partial_solution;
    stack<uint> bound_best_frontier,bound_joinable_nodes;
    uint partial_frontier,max_frontier,r;
    double n_pow2;

    /*Comenzamos*/
    clique.clear();

    if(this->_quant_edges == this->_quant_nodes*(this->_quant_nodes-1)>>1){
        /*El grafo de entrada es un Kn*/
        max_frontier = ((this->_quant_nodes)>>1)*(1+((this->_quant_nodes-1)>>1));
        clique.reserve(this->_quant_nodes>>1);
        r = 0;
        generate_n(back_inserter(clique),this->_quant_nodes>>1,[&r](){return ++r;});

    } else {
        /*El grafo no es un Kn, proseguimos
         *
         * Buscamos la cota inferior para max_frontier segun
         * el teorema de Turan
         */
        n_pow2 = pow(this->_quant_nodes,2);
        r = (uint)(ceil(-1 + n_pow2/(n_pow2-(this->_quant_edges<<1))));
        max_frontier = ((r+1)>>1)*(1+(r>>1));

        /* Cargamos los datos iniciales del ciclo
         */
        this->candidates(clique,candidates[0]);
        partial_solution.reserve(this->_quant_nodes);
        partial_frontier = 0;
        bound_best_frontier.push(0);
        bound_joinable_nodes.push(0);

        /* Calculo la cota de la frontera maxima (algo mejor que "m")
         * para la primera iteracion del ciclo (tengo en cuenta que los
         * candidatos estan ordenados por grado descendientemente)
         */
        for(deque<node_id>::const_iterator it = candidates[0].cbegin();
            it != candidates[0].cend() && this->_nodes[*it-1]->_degree > bound_joinable_nodes.top()<<1;
            ++it)
        {
            bound_best_frontier.top() += this->_nodes[*it-1]->_degree - (bound_joinable_nodes.top()<<1);
            ++bound_joinable_nodes.top();
        }

        while(!candidates[0].empty() || !partial_solution.empty()){
            if(!candidates[partial_solution.size()].empty() && max_frontier < bound_best_frontier.top()){
                /*Tengo opciones validas en candidatos para agrandar la clique*/
                partial_solution.push_back(candidates[partial_solution.size()].front());
                candidates[partial_solution.size()-1].pop_front();
                partial_frontier += -((partial_solution.size()-1)<<1)+this->_nodes[partial_solution.back()-1]->_degree;

                /*Calculo los candidatos de la nueva solucion parcial*/
                this->candidates(candidates[partial_solution.size()-1],
                                    partial_solution.back(),
                                    partial_solution.size()<<1,
                                    candidates[partial_solution.size()]);

                /*Calculo la cota de la frontera optima parcial*/
                bound_joinable_nodes.push(0);
                bound_best_frontier.push(partial_frontier);
                for(deque<node_id>::const_iterator it = candidates[partial_solution.size()].cbegin();
                    it != candidates[partial_solution.size()].cend() &&
                    this->_nodes[*it-1]->_degree > (partial_solution.size()+bound_joinable_nodes.top())<<1;
                    ++it)
                {
                    bound_best_frontier.top() += this->_nodes[*it-1]->_degree - ((partial_solution.size()+bound_joinable_nodes.top())<<1);
                    ++bound_joinable_nodes.top();
                }

                /*Verifico si mejoró mi solucion optima al haber terminado la rama*/
                if(candidates[partial_solution.size()].empty() && max_frontier < partial_frontier){
                    max_frontier = partial_frontier;
                    clique = partial_solution;
                }

            } else {
                /*Termine con esta rama, hago Backtracking*/
                candidates[partial_solution.size()].clear();    /* Por si corte la rama a partir de
                                                                 * la cota de frontera optima parcial
                                                                 */
                if(partial_solution.size() != 0){
                    /*Hago backtracking en la cota de frontera optima parcial*/
                    bound_best_frontier.pop();
                    bound_joinable_nodes.pop();

                    /* Recalculo la cota de la frontera optima parcial de la instancia anterior,
                     * ya que ahora tiene un candidato menos
                     */
                    --bound_joinable_nodes.top();
                    bound_best_frontier.top() +=
                        - this->_nodes[partial_solution.back()-1]->_degree +
                        ((partial_solution.size()-1+bound_joinable_nodes.top())<<1);

                    /* Si quedan nodos en los candidatos para reemplazar el que ya se utilizó,
                     * lo tengo en cuenta
                     */
                    if(candidates[partial_solution.size()-1].size() > bound_joinable_nodes.top() &&
                        this->_nodes[candidates[partial_solution.size()-1][bound_joinable_nodes.top()]-1]->_degree >
                            (partial_solution.size()-1+bound_joinable_nodes.top())<<1)
                    {
                        bound_best_frontier.top() +=
                            this->_nodes[candidates[partial_solution.size()-1][bound_joinable_nodes.top()]-1]->_degree -
                            ((partial_solution.size()-1+bound_joinable_nodes.top())<<1);

                        ++bound_joinable_nodes.top();
                    }

                    /* Hago backtracking en la solucion parcial */
                    partial_frontier += ((partial_solution.size()-1)<<1)-this->_nodes[partial_solution.back()-1]->_degree;
                    partial_solution.pop_back();
                }
            }
        }
    }

    return max_frontier;
}

uint graph::cmf_golosa(vector<node_id>& clique) const{
    /*Comenzamos*/
    clique.clear();
    clique.reserve(this->_quant_nodes);

    /* Agregamos el primer nodo a clique y comenzamos a iterar
     * hasta que se acaben los nodos candidatos
     */
    clique.push_back(
        (*max_element(this->_nodes.cbegin(),
            this->_nodes.cend(),
            MAYOR_A_MENOR_POR_GRADO_PTR)
        )->_id
    );
    deque<node_id> candidates(this->_nodes[clique.back()-1]->_neighbors);
    #ifndef _VECINOS_ORDENADOS
    sort(candidates.begin(),
        candidates.end(),
        MAYOR_A_MENOR_POR_GRADO
    );
    #endif//_VECINOS_ORDENADOS
    uint frontier = this->_nodes[clique.back()-1]->_degree;

    while(!candidates.empty()){
        frontier += this->_nodes[candidates.front()-1]->_degree - (clique.size()<<1);
        clique.push_back(candidates.front());
        candidates.pop_front();
        this->candidates(candidates,clique.back(),clique.size()<<1,candidates);
    }

    return frontier;
}

uint graph::cmf_busqueda_local(vector<node_id>& clique) const{
    /*Variables locales*/
    clique.reserve(this->_quant_nodes);
    vector<bool> nodes_ids_in_clique(this->_quant_nodes,false);
    node_id node_id_add;
    uint frontier,frontier_if_add,frontier_if_remove;
    bool frontier_can_grow = true;

    #ifdef _INTERCAMBIAR
    vector<node_id>::iterator node_exch_out_it;
    node_id node_exch_out_id_aux,node_exch_in_id = 0,node_exch_in_id_aux;
    uint new_node_heap_pos,node_father_heap_pos,left_child_pos,right_child_pos,min_degree_child_pos;
    uint frontier_if_exch,frontier_if_exch_aux;
    #endif//_INTERCAMBIAR

    /*Comenzamos*/
    if(clique.empty()){
        /*Buscamos un primer nodo para comenzar*/
        clique.push_back(
            (*find_if(
                this->_nodes.cbegin(),
                this->_nodes.cend(),
                [this](const node* v){return v->_degree > this->_quant_nodes/this->_quant_edges;})
            )->_id
        );
        frontier = this->_nodes[clique.back()-1]->_degree;
        nodes_ids_in_clique[clique.back()-1] = true;

    } else {
        /* Ya nos dieron un resultado inicial
         *
         *Calculamos la frontera de la clique provista
         */
        frontier = 0;
        for(vector<node_id>::const_iterator node_id_it = clique.cbegin();
            node_id_it != clique.cend();
            ++node_id_it)
        {
            frontier += this->_nodes[*node_id_it-1]->_degree-clique.size()+1;
            nodes_ids_in_clique[*node_id_it-1] = true;
        }
    }

    /* Utilizamos la clique como un "min heap", para asi acceder al
     * nodo de menor grado en O(1)
     */
    make_heap(clique.begin(),clique.end(),MAYOR_A_MENOR_POR_GRADO); /*Popea el de menor grado*/

    /*Comenzamos el ciclo de la busqueda local*/
    do{
        /*Actualizamos las fronteras de agregado y quitado*/
        node_id_add = first_candidate(this->_nodes[clique.front()-1]->_neighbors,clique,nodes_ids_in_clique);
        if((bool)node_id_add) //En caso de que node_id_add = 0 = no hay nodo agregable
            frontier_if_add = frontier+this->_nodes[node_id_add-1]->_degree-(clique.size()<<1);
        else
            frontier_if_add = 0;
        frontier_if_remove = frontier-this->_nodes[clique.front()-1]->_degree+clique.size()-1;

        #ifdef _INTERCAMBIAR
        /* Calculamos los mejores nodos entrante y salientes,
         * manteniendo las estructuras de datos
         */
        node_exch_out_it = clique.end();
        frontier_if_exch = frontier;
        for(vector<node_id>::iterator clk_node_id_it = clique.begin();
            clk_node_id_it != clique.end();
            ++clk_node_id_it)
        {
            frontier_if_exch_aux = frontier;

            /*Saco al elemento de la clique*/
            frontier_if_exch_aux += -this->_nodes[*clk_node_id_it-1]->_degree+clique.size()-1;
            /* No lo quietamos de nodes_ids_in_clique para que first_candidate
             * no lo tenga en cuenta
             *
             * nodes_ids_in_clique[*clk_node_id_it-1] = false;
            */
            iter_swap(clk_node_id_it,clique.end()-1);
            node_exch_out_id_aux = clique.back();
            clique.pop_back();

            /*Buscamos el primer nodo entrante que incremente la frontera*/
            if(clique.empty()){
                node_exch_in_id_aux = (*max_element(this->_nodes.cbegin(),
                        this->_nodes.cend(),
                        MAYOR_A_MENOR_POR_GRADO_PTR)
                    )->_id;

            } else {
                node_exch_in_id_aux = first_candidate(
                        this->_nodes[clique.front()-1]->_neighbors,
                        clique,
                        nodes_ids_in_clique
                    );
            }

            if((bool)node_exch_in_id_aux) //En caso de que node_id_add = 0 = no hay nodo agregable
                frontier_if_exch_aux += this->_nodes[node_exch_in_id_aux-1]->_degree-(clique.size()<<1);

            /* Restauramos la clique y las estructuras
             * de datos
             */
            clique.push_back(node_exch_out_id_aux);
            iter_swap(clk_node_id_it,clique.end()-1);
            /*nodes_ids_in_clique[*clk_node_id_it-1] = true;*/

            /*Vemos si mejoramos el mejor intercambio encontrado*/
            if(frontier_if_exch < frontier_if_exch_aux){
                frontier_if_exch = frontier_if_exch_aux;
                node_exch_in_id = node_exch_in_id_aux;
                node_exch_out_it = clk_node_id_it;
            }
        }
        #endif//_INTERCAMBIAR

        if(frontier < frontier_if_add || frontier < frontier_if_remove
        #ifdef _INTERCAMBIAR
            || frontier < frontier_if_exch
        #endif//_INTERCAMBIAR
        ){
            /*La funcion objeto puede crecer*/
            if(frontier_if_add > frontier_if_remove
            #ifdef _INTERCAMBIAR
                && frontier_if_add > frontier_if_exch
            #endif//_INTERCAMBIAR
            ){
                frontier = frontier_if_add;
                /*Agregamos un nodo*/
                clique.push_back(node_id_add);

                /*Mantenemos la estructura*/
                push_heap(clique.begin(),clique.end(),MAYOR_A_MENOR_POR_GRADO);
                nodes_ids_in_clique[node_id_add-1] = true;

            #ifdef _INTERCAMBIAR
            } else if(frontier_if_exch > frontier_if_remove){
                frontier = frontier_if_exch;
                /*Intercambiamos el nodo*/
                nodes_ids_in_clique[*node_exch_out_it-1] = false;
                nodes_ids_in_clique[node_exch_in_id-1] = true;
                *node_exch_out_it = node_exch_in_id;

                /*Mantenemos la estructura del heap en O(log(n))*/
                new_node_heap_pos = distance(clique.begin(),node_exch_out_it);
                node_father_heap_pos = (new_node_heap_pos - 1)>>1;
                if(new_node_heap_pos > 0 &&
                    this->_nodes[clique[new_node_heap_pos]-1]->_degree <
                    this->_nodes[clique[node_father_heap_pos]-1]->_degree)
                {
                    /*El padre tiene mayor grado, el nuevo nodo debe "subir"*/
                    while(new_node_heap_pos > 0 &&
                        this->_nodes[clique[new_node_heap_pos]-1]->_degree <
                        this->_nodes[clique[node_father_heap_pos]-1]->_degree)
                    {
                        swap(clique[new_node_heap_pos],clique[node_father_heap_pos]);
                        new_node_heap_pos = node_father_heap_pos;
                        node_father_heap_pos = (new_node_heap_pos - 1)>>1;
                    }

                } else {
                    /*El padre tiene menor grado, el nuevo nodo debe "bajar"*/
                    left_child_pos = (new_node_heap_pos<<1)+1;
                    right_child_pos = left_child_pos+1;
                    while(left_child_pos < clique.size()){
                        if(right_child_pos < clique.size() &&
                            this->_nodes[clique[right_child_pos]-1]->_degree <
                            this->_nodes[clique[left_child_pos]-1]->_degree)
                        {
                            min_degree_child_pos = right_child_pos;
                        } else
                            min_degree_child_pos = left_child_pos;

                        /*Intercambiamos si es necesario, sino paramos*/
                        if(this->_nodes[clique[new_node_heap_pos]-1]->_degree <
                            this->_nodes[clique[min_degree_child_pos]-1]->_degree)
                        {
                            swap(clique[new_node_heap_pos],clique[min_degree_child_pos]);
                            new_node_heap_pos = min_degree_child_pos;
                            left_child_pos = (new_node_heap_pos<<1)+1;
                            right_child_pos = left_child_pos+1;
                        } else
                            left_child_pos = clique.size()+1; //para no usar un bool/break
                    }
                }
            #endif//_INTERCAMBIAR

            } else {
                frontier = frontier_if_remove;
                /*Sacamos un nodo manteniendo las estructuras*/
                pop_heap(clique.begin(),clique.end(),MAYOR_A_MENOR_POR_GRADO);
                nodes_ids_in_clique[clique.back()-1] = false;
                clique.pop_back();
            }

        } else
            frontier_can_grow = false;

    }while(frontier_can_grow);

    return frontier;
}

uint graph::cmf_tabu_search(vector<node_id>& clique) const{
    return 0;
}

/***************************************************************/
/*Metodos Privados*/
node_id graph::first_candidate(const deque<node_id>& candidates,const vector<node_id>& clique,const vector<bool>& nodes_ids_in_clique) const{
    /*Variables locales*/
    bool found = false;
    vector<node_id>::const_iterator clk_node_id_it;
    node_id first_candidate = 0;

    /*Comenzamos*/
    for(deque<node_id>::const_iterator candidate_id_it = candidates.cbegin();
        candidate_id_it != candidates.cend() && !found;
        ++candidate_id_it)
    {
        if(!nodes_ids_in_clique[*candidate_id_it-1] && this->_nodes[*candidate_id_it-1]->_degree > clique.size()<<1){
            for(clk_node_id_it = clique.cbegin();
                clk_node_id_it != clique.cend() && this->_adjacency_matrix[*clk_node_id_it-1][*candidate_id_it-1];
                ++clk_node_id_it){}

            if(clk_node_id_it == clique.cend()){
                first_candidate = *candidate_id_it;
                found = true;
            }
        }
    }

    return first_candidate;
}

void graph::candidates(const vector<node_id>& clique,deque<node_id>& new_candidates) const{
    /*Variables locales*/
    uint r;

    /*Comenzamos*/
    new_candidates.clear();

    if(clique.empty()){
        r = 0;
        generate_n(back_inserter(new_candidates),this->_quant_nodes,[&r](){return ++r;});

        /*Ordeno por grado de mayor a meno */
        sort(new_candidates.begin(),
            new_candidates.end(),
            MAYOR_A_MENOR_POR_GRADO
        );

    } else {
        /*Nos dieron una clique inicial, calculamos sus candidatos*/
        new_candidates = this->_nodes[clique.back()-1]->_neighbors;
        #ifndef _VECINOS_ORDENADOS
        /*Ordeno por grado de mayor a meno */
        sort(new_candidates.begin(),
            new_candidates.end(),
            MAYOR_A_MENOR_POR_GRADO
        );
        #endif//_VECINOS_ORDENADOS
        for(vector<node_id>::const_iterator node_id_it = clique.cbegin();
            node_id_it != clique.cend()-1;
            ++node_id_it)
        {
            this->candidates(new_candidates,*node_id_it,clique.size()<<1,new_candidates);
        }
    }
}

void graph::candidates(
        const deque<node_id>& prev_candidates,
        node_id new_node_id,
        uint min_degree,
        deque<node_id>& new_candidates
) const{
    /*Variables locales*/
    uint index_new_candidates = 0,end_new_candidates = new_candidates.size();

    /*Comenzamos*/
    /*Preservamos el orden de prev_candidates*/
    for(deque<node_id>::const_iterator it = prev_candidates.cbegin();
        it != prev_candidates.cend();
        ++it)
    {
        if(this->_nodes[*it-1]->_degree > min_degree && this->_adjacency_matrix[new_node_id-1][*it-1])
        {
            /*Agregamos el candidato*/
            if(index_new_candidates < end_new_candidates)
                new_candidates[index_new_candidates] = *it;
            else
                new_candidates.push_back(*it);

            ++index_new_candidates;
        }
    }

    /* Destruimos los elementos restantes de new_candidates
     * que no fueron sobreescritos
     */
    new_candidates.resize(index_new_candidates);
}

/***************************************************************/
/*Sobrecarga de operadores*/
ostream& operator<<(ostream& output, const graph& G){
    output << "Matriz de adyacencia:" << endl;

    /*Imprimo la cabecera de la matriz*/
    output << "X";
    output << "|| ";
    for(uint i = 1; i<=G._quant_nodes;++i)
        output << i << " | ";
    output << endl;

    output << "=++=";
    for(uint i = 1; i<G._quant_nodes;++i)
        output << "=" << "===";
    output << "==+" << endl;

    /*Imprimo la matriz propiamente dicha*/
    for(adjacency_matrix::const_iterator row = G._adjacency_matrix.cbegin();
        row < G._adjacency_matrix.cend();
        ++row)
    {
        output << distance(G._adjacency_matrix.cbegin(),row)+1 << "|| ";
        for(vector<bool>::const_iterator col = row->cbegin();
            col < row->end();
            ++col)
        {
            output << *col << " | ";
        }
        output << endl;

        output << "-++-";
        for(uint i = 1; i<G._quant_nodes;++i)
            output << "-" << "-+-";
        output << "--+" << endl;
    }
    cout << endl;

    /*Imprimo los vecinos de todos los nodos*/
    cout << "Datos de los nodos: " << endl;
    for(uint i = 0; i<G._quant_nodes;++i){
        cout << "ID: " << G._nodes[i]->_id << " Grado: " << G._nodes[i]->_degree << " Vecinos: ";
        for(uint j = 0; j<G._nodes[i]->_degree; ++j){
            cout << G._nodes[i]->_neighbors[j] << ", ";
        }
        cout << endl;
    }
    cout << endl;

    /*Imprimo los ejes*/
    cout << "Datos de los ejes: " << endl;
    for(uint i = 0; i<G._quant_edges;++i)
        cout << "e" << i+1 << ": " << G._edges[i]->_node_id_A << "--" << G._edges[i]->_node_id_B << endl;


    return output;
}
