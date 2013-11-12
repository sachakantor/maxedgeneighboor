#ifndef RANDOM_GRAPH_GENERATOR_H_
#define RANDOM_GRAPH_GENERATOR_H_

#include<iostream>
#include<typedefs.hpp>

using namespace std;

/* Generadores de grafos con numeros exactos */
void random_hole_graph(ostream& output,uint quant_nodes);
void random_star_graph(ostream& output,uint quant_nodes);
void random_wheel_graph(ostream& output,uint quant_nodes);
void random_banana_tree_graph(ostream& output,uint quant_star,uint star_size);
void random_complete_graph(ostream& output,uint quant_nodes);
void random_complete_bipartite_graph(ostream& output,uint quant_nodes);
void random_bipartite_graph(ostream& output,uint quant_nodes);
void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,uint quant_edges);
void random_tree_graph(ostream& output,uint quant_nodes);
void random_connected_graph(ostream& output,uint quant_nodes);
void random_connected_graph(ostream& output,uint quant_nodes,uint quant_edges);

/* Generadores de grafos por densidad de nodos */
void random_bipartite_graph(ostream& output,uint quant_nodes,float density);
void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,float density);
void random_connected_graph(ostream& output,uint quant_nodes,float density);

#endif
