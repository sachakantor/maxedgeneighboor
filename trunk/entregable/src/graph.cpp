#include <algorithm>
#include <list>
#include <ctime>
#include <vector>
#include <union_find_by_rank.hpp> /*define union_find_set*/
#include <graph.hpp> /*define node,edge,weight*/

using namespace std;

/***************************************************************
 * Edge  *******************************************************
 ***************************************************************/
/*Constructor*/
edge::edge() : _weight(0),_nodeA(0),_nodeB(0){}
edge::edge(node a, node b, weight w) : _weight(w),_nodeA(a),_nodeB(b){}
edge::edge(const edge& e) : _weight(e._weight),_nodeA(e._nodeA),_nodeB(e._nodeB){}

/*Operadores*/
bool edge::operator<(const edge& e) const{
    return this->_weight < e._weight;
}

/***************************************************************
 * Graph *******************************************************
 ***************************************************************/

/*Constructores*/
graph::graph() : _edges(), _adjacency_lists(){}

graph::graph(unsigned int nodes_quant,const vector<edge>& edges,const vector<list<node> >& adjacency_lists)
: _edges(edges),_adjacency_lists(adjacency_lists){}

graph::graph(unsigned int nodes_quant,unsigned int edges_quant,list<unsigned int>::const_iterator& edges)
: _edges(edges_quant),_adjacency_lists(nodes_quant,list<node>()){
    /* edges es un iterador de aristas, tal que la cantidad de elementos es igual a edges_quant*3
    * ya que el formato es el siguiente:
    * *edges = nodo1
    * *(edges+1) = nodo2
    * *(edges+2) = costo de la arista que une nodo 1 con nodo2
    * Y así sucesivamente cada 3 elementos.
    *
    * El iterador edges queda posicionado en la posicion siguiente al ultimo elemento tomado, es decir
    * edges al terminar es edges+edges_quant*3+1
    */

    for(vector<edge>::iterator edges_it = this->_edges.begin();
        edges_it != this->_edges.end();
        ++edges_it){
            /* Creo la arista */
            edges_it->_nodeA = *edges;
            edges_it->_nodeB = *++edges;
            edges_it->_weight = *++edges;

            /* Actualizo las listas de adjacencias */
            this->_adjacency_lists[edges_it->_nodeA-1].push_back(edges_it->_nodeB);
            this->_adjacency_lists[edges_it->_nodeB-1].push_back(edges_it->_nodeA);

            ++edges;
    }
}

graph::graph(const graph& copy)
: _edges(copy._edges),_adjacency_lists(copy._adjacency_lists){}

/*Destructor*/
graph::~graph(){}

/*Getters*/
unsigned int graph::nodes_quant() const{
    return this->_adjacency_lists.size();
}

unsigned int graph::edges_quant() const{
    return this->_edges.size();
}

unsigned int graph::edges_total_weight() const{
    unsigned int total_weight = 0;
    for(vector<edge>::const_iterator edges_it = this->_edges.cbegin();
        edges_it != this->_edges.cend();
        ++edges_it){

        total_weight += edges_it->_weight;
    }

    return total_weight;
}

/*Métodos publicos*/
void graph::kruskal_minimum_spanning_tree(){
    /* Conjunto de aristas del arbol */
    list<edge> tree_edges;
    vector<list<node> > tree_nodes(this->_adjacency_lists.size());

    /* Generamos un vector y una clase de equivalencia para cada nodo
     * usando el constructor default de union_find_sety vector
     */
    vector<union_find_set<node> > nodes_sets(this->_adjacency_lists.size());

    /* Ordenamos las aristas segun su peso, usando
     * el operador de comparacion de edge que ya fue
     * programado
     */
    sort(this->_edges.begin(),this->_edges.end());

    /* Comenzamos a seleccionar aristas */
    for(vector<edge>::iterator edges_it = this->_edges.begin();
        edges_it < this->_edges.cend() && tree_edges.size() < this->_adjacency_lists.size()-1;
        ++edges_it){
        if(nodes_sets[edges_it->_nodeA-1].find_set() != nodes_sets[edges_it->_nodeB-1].find_set()){
            /* Me guardo la arista y sus adjacencias*/
            tree_edges.push_back(*edges_it);
            tree_nodes[edges_it->_nodeA-1].push_back(edges_it->_nodeB);
            tree_nodes[edges_it->_nodeB-1].push_back(edges_it->_nodeA);

            /* Actualizo las clases de equivalencia de los nodos */
            nodes_sets[edges_it->_nodeA-1].union_by_rank(nodes_sets[edges_it->_nodeB-1]);
        }
    }

    /* Cambio las aristas y nodos del grafo quedandome solo con el AGM */
    this->_edges.assign(tree_edges.begin(),tree_edges.end());
    this->_adjacency_lists.assign(tree_nodes.begin(),tree_nodes.end());
}

node graph::farthest_node_bfs(node from,vector<node>& prev) const{
    /* El algoritmo devuelve el nodo mas lejano a partir de
     * from, y en prev coloca en la i-esima posicion al predecesor
     * del nodo i, segun el recorrido DFS desde from, mientras
     * que en la posicion 0 coloca la distancia desde from
     * a el nodo mas lejano
     *
     */

    /* Inicializo el vector prev donde guardare los predecesores
     * de cada nodo, segun la forma de recorrer DFS desde "from"
     * y reservando la primer posicion para la distancia mas
     * larga desde el mismo
     */
    prev = vector<node>(this->_adjacency_lists.size()+1);


    /* Variables locales */
    unsigned int height = 0;
    node highest_node = from;
    stack<node> nodes_to_walk;
    node aux;
    vector<bool> visited(this->_adjacency_lists.size(),false);
    vector<bool> marked(this->_adjacency_lists.size(),false);
    vector<unsigned int> heights(this->_adjacency_lists.size(),0);

    /* Comienzo */
    prev[from] = from; /* el predecesor de from es from */
    marked[from-1] = true;
    nodes_to_walk.push(from);
    while(!nodes_to_walk.empty()){
        aux = nodes_to_walk.top();
        nodes_to_walk.pop();
        visited[aux-1] = true;
        if(heights[aux-1] > height){
            height = heights[aux-1];
            highest_node = aux;
        }
        for(list<node>::const_iterator it = this->_adjacency_lists[aux-1].cbegin();
            it != this->_adjacency_lists[aux-1].cend();
            ++it){
            if(!visited[*it-1] && !marked[*it-1]){
                nodes_to_walk.push(*it);
                prev[*it] = aux;
                heights[*it-1] = heights[aux-1]+1;
                marked[*it-1] = true;
            }
        }
    }
    prev[0] = height; /* Seteo la distancia maxima encontrada en el
                       * parametro de salida
                       */
    return highest_node;
}

node graph::find_best_minimum_spanning_tree_root() const{
    /* Devuelve el mejor nodo raiz (que minimiza la
     * altura del arbol). Se asume que el grafo es un
     * arbol
     */

    /* Variables Locales */
    node leaf_1,leaf_2,root;
    vector<node> bfs_reverse_order;

    /* Comenzamos */
    leaf_1 = this->farthest_node_bfs(1,bfs_reverse_order);
    leaf_2 = this->farthest_node_bfs(leaf_1,bfs_reverse_order);

    /* Itero para atras en el camino que une leaf_2 con leaf_1
     * hasta llegar al medio, ahí me detengo
     */
    bfs_reverse_order[0]>>=1; /* divido por 2 la distancia ya que busco
                               * el nodo del medio
                               */
    for(root = leaf_2;bfs_reverse_order[0]>0;--bfs_reverse_order[0])
        root = bfs_reverse_order[root];

    return root;
}

node graph::join_nodes_by_ghost_node(list<node>::const_iterator nodes){
/* devuelve el numero del nodo fantasma */
    return 1;
}

void graph::remove_ghost_edges(){
/*solo sirve para filtrar los ejes fantasma, cuesta O(n)*/
}

/* Constructores de Iteradores constantes */
graph::const_edges_iterator graph::c_edges_begin(){
/*Funcion que nos permite construir un iterador de ejes*/
    return graph::const_edges_iterator(this,graph::const_edges_iterator::itType::BEGIN);
}

graph::const_edges_iterator graph::c_edges_end(){
    return graph::const_edges_iterator(this,graph::const_edges_iterator::itType::END);
}

graph::const_nodes_iterator graph::c_nodes_begin(){
/*Funcion que nos permite construir un iterador de ejes*/
    return graph::const_nodes_iterator(this,graph::const_nodes_iterator::itType::BEGIN);
}

graph::const_nodes_iterator graph::c_nodes_end(){
    return graph::const_nodes_iterator(this,graph::const_nodes_iterator::itType::END);
}

/* Constructores de Iteradores no constantes*/
graph::edges_iterator graph::edges_begin(){
/*Funcion que nos permite construir un iterador de ejes*/
    return graph::edges_iterator(this,graph::edges_iterator::itType::BEGIN);
}

graph::edges_iterator graph::edges_end(){
    return graph::edges_iterator(this,graph::edges_iterator::itType::END);
}

graph::nodes_iterator graph::nodes_begin(){
/*Funcion que nos permite construir un iterador de ejes*/
    return graph::nodes_iterator(this,graph::nodes_iterator::itType::BEGIN);
}

graph::nodes_iterator graph::nodes_end(){
    return graph::nodes_iterator(this,graph::nodes_iterator::itType::END);
}
/***************************************************************
 * Iteradores Constantes ***************************************
 ***************************************************************/
/* EDGES */
/* Constructor */
graph::const_edges_iterator::const_edges_iterator(const graph* g,graph::const_edges_iterator::itType type){
    if(type == BEGIN)
        this->_current_edge = g->_edges.cbegin();
    else
        this->_current_edge = g->_edges.cend();
}

/*Operadores*/
bool graph::const_edges_iterator::operator== (const const_edges_iterator& it) const{
    return this->_current_edge == it._current_edge;
}

bool graph::const_edges_iterator::operator!= (const const_edges_iterator& it) const{
    return !(*this == it);
}

const edge* graph::const_edges_iterator::operator->() const{
    return &*this->_current_edge;
}

const edge& graph::const_edges_iterator::operator*(){
    return *this->_current_edge;
}

graph::const_edges_iterator& graph::const_edges_iterator::operator++(){
    /* ++it*/
    ++this->_current_edge;
    return *this;
}

graph::const_edges_iterator graph::const_edges_iterator::operator++(int){
    /* it++*/
    this->_current_edge++;
    return *this;
}

/* NODES */
/* Constructor */
graph::const_nodes_iterator::const_nodes_iterator(const graph* g,graph::const_nodes_iterator::itType type){
    if(type == BEGIN)
        this->_current_node = g->_adjacency_lists.cbegin();
    else
        this->_current_node = g->_adjacency_lists.cend();
}

/*Operadores*/
bool graph::const_nodes_iterator::operator== (const const_nodes_iterator& it) const{
    return this->_current_node == it._current_node;
}

bool graph::const_nodes_iterator::operator!= (const const_nodes_iterator& it) const{
    return !(*this == it);
}

const list<node>* graph::const_nodes_iterator::operator->() const{
    return &*this->_current_node;
}

const list<node>& graph::const_nodes_iterator::operator*(){
    return *this->_current_node;
}

graph::const_nodes_iterator& graph::const_nodes_iterator::operator++(){
    /* ++it*/
    ++this->_current_node;
    return *this;
}

graph::const_nodes_iterator graph::const_nodes_iterator::operator++(int){
    /* it++*/
    this->_current_node++;
    return *this;
}

/***************************************************************
 * Iteradores **************************************************
 ***************************************************************/
/* EDGES */
/* Constructor */
graph::edges_iterator::edges_iterator(graph* g,graph::edges_iterator::itType type){
    if(type == BEGIN)
        this->_current_edge = g->_edges.begin();
    else
        this->_current_edge = g->_edges.end();
}

/*Operadores*/
bool graph::edges_iterator::operator== (const edges_iterator& it) const{
    return this->_current_edge == it._current_edge;
}

bool graph::edges_iterator::operator!= (const edges_iterator& it) const{
    return !(*this == it);
}

edge* graph::edges_iterator::operator->() const{
    return &*this->_current_edge;
}

edge& graph::edges_iterator::operator*(){
    return *this->_current_edge;
}

graph::edges_iterator& graph::edges_iterator::operator++(){
    /* ++it*/
    ++this->_current_edge;
    return *this;
}

graph::edges_iterator graph::edges_iterator::operator++(int){
    /* it++*/
    this->_current_edge++;
    return *this;
}

/* Nodos */
/* Constructor */
graph::nodes_iterator::nodes_iterator(graph* g,graph::nodes_iterator::itType type){
    if(type == BEGIN)
        this->_current_node = g->_adjacency_lists.begin();
    else
        this->_current_node = g->_adjacency_lists.end();
}

/*Operadores*/
bool graph::nodes_iterator::operator== (const nodes_iterator& it) const{
    return this->_current_node == it._current_node;
}

bool graph::nodes_iterator::operator!= (const nodes_iterator& it) const{
    return !(*this == it);
}

list<node>* graph::nodes_iterator::operator->() const{
    return &*this->_current_node;
}

list<node>& graph::nodes_iterator::operator*(){
    return *this->_current_node;
}

graph::nodes_iterator& graph::nodes_iterator::operator++(){
    /* ++it*/
    ++this->_current_node;
    return *this;
}

graph::nodes_iterator graph::nodes_iterator::operator++(int){
    /* it++*/
    this->_current_node++;
    return *this;
}
