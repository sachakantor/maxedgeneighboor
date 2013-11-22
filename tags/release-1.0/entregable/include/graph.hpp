#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<deque>

#include<typedefs.hpp>

using namespace std;

typedef struct node{
    /*Constructores y Destructores*/
    node(const node_id id,const degree d,const uint max_degree);
    node(const uint id,const degree d);
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

        /*Métodos publicos*/
        uint cmf_backtracking(uint frontera_min,vector<node_id>& clique) const;
        uint cmf_backtracking(vector<node_id>& clique) const;
        uint cmf_golosa(vector<node_id>& clique) const;
        uint cmf_busqueda_local(vector<node_id>& clique) const;
        uint cmf_tabu_search(vector<node_id>& clique) const;

    private:
        /*Metodos privados*/
        node_id first_candidate(const deque<node_id>& candidates,const vector<node_id>& clique,const vector<bool>& nodes_ids_in_clique) const;
        void candidates(const vector<node_id>& clique,deque<node_id>& new_candidates) const;
        void candidates(const deque<node_id>& prev_candidates,node_id new_node_id,uint min_degree,deque<node_id>& output) const;

        /*Sobrecarga de operadores*/
        friend ostream& operator<<(ostream &output, const graph& G);

        /*Atributos*/
        const uint _quant_nodes;
        const uint _quant_edges;
        adjacency_matrix _adjacency_matrix;
        vector<node*> _nodes;
        vector<edge*> _edges;
};
#endif //GRAPH_HPP_
