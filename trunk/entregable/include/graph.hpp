#ifndef GRAPH_H_
#define GRAPH_H_

#include <iterator>
#include <vector>
#include <list>

using namespace std;

typedef unsigned int node;
typedef unsigned int weight;
typedef struct edge{
    /*Constructor*/
    edge();
    edge(node a, node b, weight w);
    edge(const edge&);

    /*Operadores*/
    bool operator<(const edge& e) const;

    /*Atributos*/
    weight _weight;
    node _nodeA,_nodeB;
} edge;

class graph{
    public:
        /*Constructores y destructor*/
        graph();
        graph(unsigned int nodes_quant,const vector<edge>& edges,const vector<list<node> >& adjacency_lists);
        graph(unsigned int nodes_quant,unsigned int edges_quant,list<unsigned int>::const_iterator& edges);
        graph(const graph& copy);
        ~graph();

        /*Iteradores (solo accedible desde los metodos publicos (constructor escondido)*/
        class const_edges_iterator : public std::iterator<std::random_access_iterator_tag,edge>{
            public:
                /*Operadores*/
                bool operator== (const const_edges_iterator& it) const;
                bool operator!= (const const_edges_iterator& it) const;
                const edge* operator->() const;
                const edge& operator*();
                const_edges_iterator &operator++(); /* ++it*/
                const_edges_iterator operator++(int); /* it++*/
            private:
                /*Constructor*/
                enum itType {BEGIN, END};
                const_edges_iterator(const graph* g,itType);

                /*Atributos*/
                vector<edge>::const_iterator _current_edge;

                /*Declaracion de amistad*/
                friend class graph;
        };

        class edges_iterator : public std::iterator<std::random_access_iterator_tag,edge>{
            public:
                /*Operadores*/
                bool operator== (const edges_iterator& it) const;
                bool operator!= (const edges_iterator& it) const;
                edge* operator->() const;
                edge& operator*();
                edges_iterator &operator++(); /* ++it*/
                edges_iterator operator++(int); /* it++*/
            private:
                /*Constructor*/
                enum itType {BEGIN, END};
                edges_iterator(graph* g,itType);

                /*Atributos*/
                vector<edge>::iterator _current_edge;

                /*Declaracion de amistad*/
                friend class graph;
        };

        class const_nodes_iterator : public std::iterator<std::random_access_iterator_tag,list<node> >{
            public:
                /*Operadores*/
                bool operator== (const const_nodes_iterator& it) const;
                bool operator!= (const const_nodes_iterator& it) const;
                const list<node>* operator->() const;
                const list<node>& operator*();
                const_nodes_iterator &operator++(); /* ++it*/
                const_nodes_iterator operator++(int); /* it++*/
            private:
                /*Constructor*/
                enum itType {BEGIN, END};
                const_nodes_iterator(const graph* g,itType);

                /*Atributos*/
                vector<list<node> >::const_iterator _current_node;

                /*Declaracion de amistad*/
                friend class graph;
        };

        class nodes_iterator : public std::iterator<std::random_access_iterator_tag,list<node> >{
            public:
                /*Operadores*/
                bool operator== (const nodes_iterator& it) const;
                bool operator!= (const nodes_iterator& it) const;
                list<node>* operator->() const;
                list<node>& operator*();
                nodes_iterator &operator++(); /* ++it*/
                nodes_iterator operator++(int); /* it++*/
            private:
                /*Constructor*/
                enum itType {BEGIN, END};
                nodes_iterator(graph* g,itType);

                /*Atributos*/
                vector<list<node> >::iterator _current_node;

                /*Declaracion de amistad*/
                friend class graph;
        };

        /* Constructores publicos de los iteradores */
        graph::const_edges_iterator c_edges_begin();
        graph::const_edges_iterator c_edges_end();
        graph::edges_iterator edges_begin();
        graph::edges_iterator edges_end();
        graph::const_nodes_iterator c_nodes_begin();
        graph::const_nodes_iterator c_nodes_end();
        graph::nodes_iterator nodes_begin();
        graph::nodes_iterator nodes_end();

        /*Getters*/
        unsigned int nodes_quant() const;
        unsigned int edges_quant() const;
        unsigned int edges_total_weight() const;

        /*Métodos publicos*/
        void kruskal_minimum_spanning_tree();
        node farthest_node_bfs(node,vector<node>&) const;
        node find_best_minimum_spanning_tree_root() const;
        node join_nodes_by_ghost_node(list<node>::const_iterator nodes); /* devuelve el numero
                                                                          * del nodo fantasma
                                                                          */
        void remove_ghost_edges(); /*solo sirve para filtrar los ejes fantasma, cuesta O(n)*/

    private:
        /*Atributos*/
        vector<edge> _edges;
        vector<list<node> > _adjacency_lists;
};
#endif //GRAPH_HPP_
