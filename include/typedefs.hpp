#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include<vector>
#include<deque>

/* Renombres y Structs */
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned int node_id;
typedef unsigned int degree;
typedef std::deque<node_id> adjacent_nodes_id;
typedef std::vector<std::vector<bool> > adjacency_matrix;

#endif//TYPEDEFS_H_
