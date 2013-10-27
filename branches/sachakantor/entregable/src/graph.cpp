#include <algorithm>
#include <list>
#include <ctime>
#include <vector>
#include <union_find_by_rank.hpp> /*define union_find_set*/
#include <graph.hpp> /*define node,edge,graph*/

using namespace std;

/***************************************************************
node*   *******************************************************
***************************************************************/
/*Constructores y Destructores*/
node::node() : _id(){}

node::node(uint id,degree d) : _id(){}

node::node(const node&) : _id(){}

node::~node(){}

/*Operadores*/
bool node::operator==(const node& v) const{
    return true;
}

bool node::operator!=(const node& v) const{
    return true;
}

bool node::operator<(const node& v) const{
    return true;
}

/***************************************************************
* Edge  *******************************************************
***************************************************************/
/*Constructor*/
edge::edge() : _nodeA(NULL), _nodeB(NULL){}

edge::edge(const node& a, const node& b) : _nodeA(&a),_nodeB(&b){}

edge::edge(const edge&) : _nodeA(), _nodeB(){}

/*Operadores*/
bool edge::operator==(const edge& e) const{}

bool edge::operator!=(const edge& e) const{}

bool edge::operator<(const edge& e) const{}

/***************************************************************
* Graph *******************************************************
***************************************************************/
/*Constructores y destructor*/
graph::graph(){}

graph::graph(const graph& copy){}

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
