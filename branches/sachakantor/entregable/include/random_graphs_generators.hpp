#ifndef RANDOM_GRAPH_GENERATOR_H_
#define RANDOM_GRAPH_GENERATOR_H_

#include<iostream>
#include<typedefs.hpp>

using namespace std;

void random_hole_graph(ostream& output,vector<node_id>::iterator it_begin,const vector<node_id>::iterator it_end);
void random_hole_graph(ostream& output,uint quant_nodes);

void random_star_graph(ostream& output,vector<node_id>::iterator it_begin,const vector<node_id>::iterator it_end);
void random_star_graph(ostream& output,uint quant_nodes);

void random_wheel_graph(ostream& output,vector<node_id>::iterator it_begin,const vector<node_id>::iterator it_end);
void random_wheel_graph(ostream& output,uint quant_nodes);

void random_banana_tree_graph(ostream& output,uint quant_star,uint star_size,vector<node_id>::iterator it_begin,const vector<node_id>::iterator it_end);
void random_banana_tree_graph(ostream& output,uint quant_nodes);
void random_banana_tree_graph(ostream& output,uint quant_star,uint star_size);

void random_complete_graph(ostream& output,vector<node_id>::const_iterator it_begin,const vector<node_id>::const_iterator it_end);
void random_complete_graph(ostream& output,uint quant_nodes);

void random_complete_bipartite_graph(ostream& output,uint quant_nodes);

void random_bipartite_graph(ostream& output,uint quant_nodes);
void random_bipartite_graph(ostream& output,vector<node_id>::iterator it_v1_begin,vector<node_id>::iterator it_v1_end,vector<node_id>::iterator it_v2_begin,vector<node_id>::iterator it_v2_end,uint quant_edges);
void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,uint quant_edges);
void random_bipartite_graph(ostream& output,uint quant_nodes,float density);
void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,float density);

void random_tree_graph(ostream& output,uint quant_nodes);

void random_connected_graph(ostream& output,uint quant_nodes);
void random_connected_graph(ostream& output,uint quant_nodes,uint quant_edges);
void random_connected_graph(ostream& output,uint quant_nodes,float density);

#endif
