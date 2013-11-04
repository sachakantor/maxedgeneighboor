#include<algorithm>
//#include <list>
//#include <ctime>
#include<cmath>
#include<iostream>
#include<vector>
#include<deque>
//#include <union_find_by_rank.hpp> /*define union_find_set*/
#include"../include/graph.hpp" /*define node,edge,graph*/

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
    this->_neighbors.reserve(max_degree);
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
    uint partial_frontier,max_frontier,r;
    double n_pow2;
    uint bound_best_frontier,bound_joinable_nodes;

    /*Comenzamos*/
    if(this->_quant_edges == this->_quant_nodes*(this->_quant_nodes-1)>>1){
        /*El grafo de entrada es un Kn*/
        max_frontier = ((this->_quant_nodes)>>1)*(1+((this->_quant_nodes-1)>>1));
        clique.clear();
        clique.reserve(this->_quant_nodes>>1);
        for(uint i=0;i<this->_quant_nodes>>1;++i)
            clique.push_back(i+1);

    } else {
        /*El grafo no es un Kn, proseguimos
         *
         * Buscamos la cota inferior para max_frontier segun
         * el teorema de Turan
         */
        n_pow2 = pow(this->_quant_nodes,2);
        r = (uint)(ceil(-1 + n_pow2/(n_pow2-(this->_quant_edges<<1))));
        max_frontier = ((r+1)>>1)*(1+(r>>1));
        //cout << "Numero de turam: " << (n_pow2/(n_pow2-(this->_quant_edges<<1))) << endl;
        //cout << "r: " << r << endl;
        //cout << "Frontera Max Inicial: " << max_frontier << endl;

        /* Cargamos los datos iniciales del ciclo de manera que
         * el algoritmo funcione segun el id de los nodos
         */
        for(uint i = 1;i<=this->_quant_nodes;++i)
            candidates[0].push_front(i);
        partial_solution.reserve(this->_quant_nodes);
        partial_frontier = 0;

        while(!candidates[0].empty() || !partial_solution.empty()){
            if(!candidates[partial_solution.size()].empty()){
                /*Tengo opciones validas en candidatos para agrandar la clique*/
                partial_solution.push_back(candidates[partial_solution.size()].back());
                candidates[partial_solution.size()-1].pop_back();
                partial_frontier += -((partial_solution.size()-1)<<1)+this->_nodes[partial_solution.back()-1]->_degree;

                /*Calculo los candidatos de la nueva solucion parcial*/
                bound_joinable_nodes = 0;
                bound_best_frontier = partial_frontier;
                for(deque<node_id>::const_reverse_iterator rit = candidates[partial_solution.size()-1].crbegin();
                    rit != candidates[partial_solution.size()-1].crend();
                    ++rit)
                {
                    if((this->_nodes[*rit-1]->_degree > partial_solution.size()<<1) &&
                        (bool)this->_adjacency_matrix[partial_solution.back()-1][*rit-1])
                    {
                        /* Voy recopilando informacion que se usará para aplicar una
                         * poda una vez terminado el ciclo
                         */
                        if(this->_nodes[*rit-1]->_degree > (partial_solution.size()+bound_joinable_nodes)<<1){
                            bound_best_frontier += this->_nodes[*rit-1]->_degree - ((partial_solution.size()+bound_joinable_nodes)<<1);
                            ++bound_joinable_nodes;
                        }

                        /*Agregamos el candidato*/
                        candidates[partial_solution.size()].push_front(*rit);
                    }
                }

                /* Verifico si sería posible (en el mejor de los casos)
                 * superar la frontera de la mejor solución encontrada
                 * hasta el momento
                 */
                if(max_frontier > bound_best_frontier || candidates[partial_solution.size()].empty()){
                    candidates[partial_solution.size()].clear();

                    /*Verifico si mejoró mi solucion optima al haber terminado la rama*/
                    if(max_frontier < partial_frontier){
                        max_frontier = partial_frontier;
                        clique = partial_solution;
                    }
                }
            } else {
                /*Termine con esta rama, hago Backtracking*/
                partial_frontier += ((partial_solution.size()-1)<<1)-this->_nodes[partial_solution.back()-1]->_degree;
                partial_solution.pop_back();
            }
        }
    }

    return max_frontier;
}

uint graph::cmf_golosa(vector<node_id>& clique) const{
	node * v(NULL);
	v=vertice_mayor_grado(this->_nodes);

	vector<node *> K;
	K.push_back(v);

	vector<node *> cand(this->candidatos(K));
	while(cand.size() != 0){
		v = vertice_mayor_grado(cand);
		K.push_back(v);
		cand = this->candidatos(K);
	}
	// Calculamos la frontera
	uint res(0);
	uint tam(K.size());
	for (int i=0; i< tam; i++){
		res += ((K[i])->_degree - (tam -1)); 
	}
	// Generamos la clique
	for (int i=0; i<tam; i++){
		clique.push_back((K[i])->_id);
	}
	
	return res;
    //return 0;
}

uint graph::cmf_busqueda_local(vector<node_id>& clique) const{
    return 0;
}

uint graph::cmf_tabu_search(vector<node_id>& clique) const{
    return 0;
}

/*Metodos Privados*/

/* JORGE */
bool in(const vector<node *> origen, const vector<node_id> destino) {
    bool res(true);
    for (int i=0; i< origen.size(); i++){
        bool esta(false);
        for (int j=0; j<destino.size(); j++){
            if ((origen[i])->_id == (destino[j])){
                esta=true;
                break;
            }
        }
        if (!esta){
            res=false;
            break;
        }
    }
	return res;
}

node * vertice_mayor_grado(const vector<node *> v){
	int max(v[0]->_degree);
	node * vertice(v[0]);
	for (int i=1; i< v.size(); i++){
		if ((v[i])->_degree > max){
			max = (v[i])->_degree;
			vertice = v[i];
		}
	}
	return vertice;
}

vector<node *> graph::candidatos(const vector<node *> K) const{
	vector<node *> cand;
	
	for (int i=0; i < (this->_nodes).size(); i++){ // Recorriendo todo el grafo
		if ( (this->_nodes)[i]->_degree > 2 * K.size()){
			if (in (K, (this->_nodes)[i]->_neighbors)){ // No hace falta comprobar si i es parte de K, ya que si lo es
														// K no va a estar incluido en _neighbors de i, puesto que
														// puntualmente i no esta en _neighbors de i.
				cand.push_back((this->_nodes)[i]);
			}
		}
	}
	return cand;
}


/* END JORGE */

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
