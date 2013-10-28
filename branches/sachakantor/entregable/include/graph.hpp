#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

using namespace std;

/* Forward declaration */
struct node;

/* Renombres y Structs */
typedef unsigned int uint;
typedef unsigned int node_id;
typedef unsigned int degree;
typedef vector<node_id> adjacent_nodes_id;
typedef vector<vector<bool> > adjacency_matrix;

typedef struct node{
    /*Constructores y Destructores*/
    node(const node_id id,const degree d,const uint max_degree);
    //node(const uint id,const degree d);
    node(const node&);
    ~node();

    /*Operadores*/
    bool operator==(const node& v) const;
    bool operator!=(const node& v) const;
    bool operator<(const node& v) const;

    /*Atributos*/
    const node_id _id;
    degree _degree;
    adjacent_nodes_id _neighbors;

} node;


typedef struct edge{
    /*Constructor*/
    edge();
    edge(node_id a, node_id b);
    edge(const edge&);

    /*Operadores*/
    bool operator==(const edge& e) const;
    bool operator!=(const edge& e) const;

    /*Atributos*/
    const node_id _node_id_A;
    const node_id _node_id_B;
} edge;

/* Clases */
class graph{
    public:
        /*Constructores y destructor*/
        graph();
        graph(const graph& copy);
        graph(uint quant_nodes,uint quant_edges,vector<node_id>::const_iterator& it_edges_nodes);
        ~graph();

        /*Getters*/

        /*Métodos publicos*/
        adjacent_nodes_id cmf_backtracking() const;
        adjacent_nodes_id cmf_golosa() const;
        adjacent_nodes_id cmf_busqueda_local() const;
        adjacent_nodes_id cmf_tabu_search() const;

    private:
        /*Metodos privados*/

        /*Atributos*/
        const uint _quant_nodes;
        const uint _quant_edges;
        adjacency_matrix _adjacency_matrix;
        vector<node*> _nodes;
        vector<edge*> _edges;
};
#endif //GRAPH_HPP_
