#include <algorithm>
//#include <list>
//#include <ctime>
#include <vector>
//#include <union_find_by_rank.hpp> /*define union_find_set*/
#include <graph.hpp> /*define node,edge,graph*/

using namespace std;

/***************************************************************
node*   *******************************************************
***************************************************************/
/*Constructores y Destructores*/
node::node(uint id) :
    _id(id),
    _degree(0),
    _neighbors()
{}

node::node(uint id,degree d) :
    _id(id),
    _degree(d),
    _neighbors(d,NULL)
{}

node::node(const node& copy) :
    _id(copy._id),
    _degree(copy._degree),
    _neighbors(copy._neighbors)
{}

node::~node(){}

/*Operadores*/
bool node::operator==(const node& v) const{
    return this->_id == v._id;
}

bool node::operator!=(const node& v) const{
    return !(*this == v);
}

bool node::operator<(const node& v) const{
    return this->_id < v._id;
}

/***************************************************************
* Edge  *******************************************************
***************************************************************/
/*Constructor*/
edge::edge() : _nodeA(NULL), _nodeB(NULL){}

edge::edge(const node& a, const node& b) :
    _nodeA(&a),
    _nodeB(&b)
{}

edge::edge(const edge& e) :
    _nodeA(e._nodeA),
    _nodeB(e._nodeB)
{}

/*Operadores*/
bool edge::operator==(const edge& e) const{
    return this->_nodeA == e._nodeA && this->_nodeB == e._nodeB;
}

bool edge::operator!=(const edge& e) const{
    return !(*this == e);
}

/***************************************************************
* Graph *******************************************************
***************************************************************/
/*Constructores y destructor*/
graph::graph() : _quant_nodes(),_quant_edges(){}

graph::graph(const graph& copy) :
    _quant_nodes(copy._quant_nodes),
    _quant_edges(copy._quant_edges)
{

}

graph::~graph(){}

/*Getters*/

/*Métodos publicos*/
adjacent_nodes_ptr graph::cmf_backtracking() const{
    return adjacent_nodes_ptr();
}

adjacent_nodes_ptr graph::cmf_golosa() const{
    return adjacent_nodes_ptr();
}

adjacent_nodes_ptr graph::cmf_busqueda_local() const{
    return adjacent_nodes_ptr();
}

adjacent_nodes_ptr graph::cmf_tabu_search() const{
    return adjacent_nodes_ptr();
}
