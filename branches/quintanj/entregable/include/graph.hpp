#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

using namespace std;

/* Forward declaration */
//struct node;

/* Renombres y Structs */
typedef unsigned int uint;
typedef unsigned int degree;
typedef vector<node* const> adjacent_nodes_ptr;
typedef vector<vector<bool> > adjacency_matrix;

typedef struct node{
    /*Constructores y Destructores*/
    node();
    node(uint id,degree d);
    node(const node&);
    ~node();

    /*Operadores*/
    bool operator==(const node& v) const;
    bool operator!=(const node& v) const;
    bool operator<(const node& v) const;

    /*Atributos*/
    const uint _id;
    degree _degree;
    adjacent_nodes_ptr _neighbors;

} node;


typedef struct edge{
    /*Constructor*/
    edge();
    edge(const node& a, const node& b);
    edge(const edge&);

    /*Operadores*/
    bool operator==(const edge& e) const;
    bool operator!=(const edge& e) const;
    bool operator<(const edge& e) const;

    /*Atributos*/
    const node* const _nodeA;
    const node* const _nodeB;
} edge;

/* Clases */
class graph{
    public:
        /*Constructores y destructor*/
        graph();
        graph(const graph& copy);
        ~graph();

        /*Getters*/

        /*Métodos publicos*/
        adjacent_nodes_ptr cmf_backtracking() const;
        adjacent_nodes_ptr cmf_golosa() const;
        adjacent_nodes_ptr cmf_busqueda_local() const;
        adjacent_nodes_ptr cmf_tabu_search() const;

    private:
        /*Metodos privados*/

        /*Atributos*/
        adjacency_matrix _adjacency_matrix;
        vector<node> _nodes;
        vector<edge> _edges;
};
#endif //GRAPH_HPP_
