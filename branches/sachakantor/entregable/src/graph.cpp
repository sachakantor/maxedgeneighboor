//#include<algorithm>
//#include <list>
//#include <ctime>
#include<cmath>
#include<iostream>
#include<vector>
//#include <union_find_by_rank.hpp> /*define union_find_set*/
#include<graph.hpp> /*define node,edge,graph*/

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
    vector<vector<node_id> > ya_procesados(this->_quant_nodes,vector<node_id>(this->_quant_nodes,0));
    uint frontera_max = 0;
    uint r;
    double n2;
    bool stop;

    /*Comenzamos*/
    if(this->_quant_edges == this->_quant_nodes*(this->_quant_nodes-1)>>1){
        /*El grafo de entrada es un Kn*/
        clique = vector<node_id>(this->_quant_nodes>>1,0);
        clique.reserve(this->_quant_nodes>>1);
        for(uint i=0;i<this->_quant_nodes>>1;++i)
            clique[i] = i+1;

    } else {
        /*El grafo no es un Kn, proseguimos*/

        /* Buscamos la cota inferior para frontera_max segun
         * el teorema de Turan
         */
        r = this->_quant_nodes-1;
        stop = false;
        while(r!=0 && !stop){
            n2 = pow(this->_quant_nodes,2);
            if(r<n2/(n2-(this->_quant_edges<<1)))
                stop=true;
            --r;
        }
        frontera_max = ((r+1)/2)*ceil((float)(r+1)/2);

        /*Vaciamos clique y comenzamos el algoritmo*/

    }

    return 0;
}

uint graph::cmf_golosa(vector<node_id>& clique) const{
    return 0;
}

uint graph::cmf_busqueda_local(vector<node_id>& clique) const{
    return 0;
}

uint graph::cmf_tabu_search(vector<node_id>& clique) const{
    return 0;
}

/*Metodos Privados*/

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
