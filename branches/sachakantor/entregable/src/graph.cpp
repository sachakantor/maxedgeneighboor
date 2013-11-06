#include<algorithm>
#include<numeric>
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

#define MAYOR_A_MENOR_POR_GRADO [&](int v,int w){return this->_nodes[w-1]->_degree < this->_nodes[v-1]->_degree;}
#define MAYOR_A_MENOR_POR_GRADO_PTR [&](const node* v,const node* w){return v->_degree < w->_degree;}

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

//node::node(uint id,degree d) :
//    _id(id),
//    _degree(d),
//    _neighbors()
//{
//    this->_neighbors.reserve(d);
//}

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
    _adjacency_matrix(quant_nodes,vector<uchar>(quant_nodes,(uchar)false)),
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
        this->_adjacency_matrix[a-1][b-1] = (uchar)true;
        this->_adjacency_matrix[b-1][a-1] = (uchar)true;

        /*Actualizamos la info de los nodos*/
        ++this->_nodes[a-1]->_degree;
        this->_nodes[a-1]->_neighbors.push_back(b);
        ++this->_nodes[b-1]->_degree;
        this->_nodes[b-1]->_neighbors.push_back(a);
    }

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
}

graph::~graph(){
    for(uint i = 0; i < this->_quant_nodes;++i)
        delete this->_nodes[i];

    for(uint i = 0; i < this->_quant_edges;++i)
        delete this->_edges[i];
}

/*Getters*/

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
    /*
    sort(candidates.begin(),
        candidates.end(),
        MAYOR_A_MENOR_POR_GRADO
    );
    */

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
    deque<node_id> candidates;
    uint frontier;

    /*Comenzamos*/
    if(clique.empty()){
        /*Buscamos un primer nodo para comenzar*/
        clique.reserve(this->_quant_nodes);
        clique.push_back(
            (*find_if(
                this->_nodes.cbegin(),
                this->_nodes.cend(),
                [&](const node* v){return v->_degree > this->_quant_nodes/this->_quant_edges;})
            )->_id
        );
        frontier = this->_nodes[clique.back()-1]->_degree;
        candidates = this->_nodes[clique.back()-1]->_neighbors; /*Ya estan ordenados*/

    } else {
        /* Ya nos dieron un resultado inicial,
         * calculamos sus candidatos y frontera
         * primero
         */
        sort(clique.begin(),
            clique.end(),
            MAYOR_A_MENOR_POR_GRADO
        );
        this->candidates(clique,candidates);
        frontier = accumulate(clique.cbegin(),clique.cend(),0,
            [&](const uint accum,const uint node_id){
                return accum+this->_nodes[node_id-1]->_degree-clique.size();
            }
        );
    }

    return frontier;
}

uint graph::cmf_tabu_search(vector<node_id>& clique) const{
    return 0;
}

/*Metodos Privados*/
void graph::candidates(const vector<node_id>& clique,deque<node_id>& new_candidates) const{
    /*Variables locales*/
    uint r;

    /*Comenzamos*/
    new_candidates.clear();

    if(clique.empty()){
        r = 0;
        generate_n(back_inserter(new_candidates),this->_quant_nodes,[&r](){return ++r;});

        /* Ordeno por grado de mayor a menor para luego
         * poder acotar la frontera maxima de la rama del backtracking
         */
        sort(new_candidates.begin(),
            new_candidates.end(),
            MAYOR_A_MENOR_POR_GRADO
        );

    } else {
        /*Nos dieron una clique inicial, calculamos sus candidatos*/
        new_candidates = this->_nodes[clique.back()-1]->_neighbors;
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
    for(deque<node_id>::const_iterator it = prev_candidates.cbegin();
        it != prev_candidates.cend();
        ++it)
    {
        if(this->_nodes[*it-1]->_degree > min_degree && (bool)this->_adjacency_matrix[new_node_id-1][*it-1])
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
        for(vector<uchar>::const_iterator col = row->cbegin();
            col < row->end();
            ++col)
        {
            output << (bool)*col << " | ";
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
