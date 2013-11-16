#include<algorithm>     // std::random_shuffle,generate_n
#include<numeric>       // std::iota
#include<chrono>        // std::chrono::system_clock
#include<cstdlib>       // std::rand, std::srand
#include<ctime>         // std::time
#include<iostream>      // std::cout
#include<random>        // std::default_random_engine
#include<vector>
#include<deque>
#include<map>

#include<random_graphs_generators.hpp>
#include<typedefs.hpp>

#include<ogdf/basic/Graph.h>
#include<ogdf/basic/Graph_d.h>
#include<ogdf/basic/graph_generators.h>
#include<ogdf/basic/List.h>

using namespace std;

/************************* HOLE **************************/
void random_hole_graph(ostream& output,
    vector<node_id>::iterator it_begin,
    const vector<node_id>::iterator it_end)
{
    //Comenzamos
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    random_shuffle(it_begin,it_end);

    //Imprimimos la salida segun el formato pedido
    vector<node_id>::iterator it = it_begin;
    for(;it < it_end-1;++it)
        output << *it << ' ' << *(it+1) << endl;

    output << *it << ' ' << *it_begin << endl;
}

void random_hole_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);

    //Imprimimos la salida segun el formato pedido
    output << quant_nodes << ' ' << quant_nodes << endl;

    random_hole_graph(output,nodes.begin(),nodes.end());
}

/************************* STAR **************************/
void random_star_graph(ostream& output,
    vector<node_id>::iterator it_begin,
    const vector<node_id>::iterator it_end)
{
    //Variables locales
    node_id center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    random_shuffle(it_begin,it_end);

    //Nos guardamos el centro de la estrella
    center = *it_begin;
    ++it_begin;

    //Imprimimos la salida segun el formato pedido
    for(;it_begin < it_end;++it_begin)
        output << center << ' ' << *it_begin << endl;
}

void random_star_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);

    //Imprimimos la salida segun el formato pedido
    output << quant_nodes << ' ' << quant_nodes-1 << endl;
    random_star_graph(output,nodes.begin(),nodes.end());
}

/************************* WHEEL **************************/
void random_wheel_graph(ostream& output,
    vector<node_id>::iterator it_begin,
    const vector<node_id>::iterator it_end)
{
    //Variables locales
    node_id center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    random_shuffle(it_begin,it_end);

    //Nos guardamos el centro de la estrella
    center = *it_begin;
    ++it_begin;

    vector<node_id>::iterator it = it_begin;
    for(;it < it_end-1;++it)
    {
        output << *it << ' ' << *(it+1) << endl;
        output << center << ' ' << *it << endl;
    }
    output << *it << ' ' << *it_begin << endl;
    output << center << ' ' << *it << endl;
}

void random_wheel_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);
    node_id center;
    uint node_id_pos;

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);

    //Imprimimos la salida segun el formato pedido
    if(quant_nodes<=2){
        output << quant_nodes << ' ' << quant_nodes-1 << endl;
        if(quant_nodes == 2)
            output << nodes.front() << ' ' << nodes.back() << endl;

    } else if(quant_nodes == 3){
        output << quant_nodes << ' ' << quant_nodes << endl;
        srand(std::chrono::system_clock::now().time_since_epoch().count());
        node_id_pos = rand()%3;
        center = nodes[node_id_pos];
        nodes.erase(nodes.begin()+node_id_pos);
        output << nodes.back() << ' ' << nodes.front() << endl;
        output << center << ' ' << nodes.front() << endl;
        output << center << ' ' << nodes.back() << endl;

    } else {
        output << quant_nodes << ' ' << 2*(quant_nodes-1) << endl;
        random_wheel_graph(output,nodes.begin(),nodes.end());
    }
}


/************************* BANANA **************************/
void random_banana_tree_graph(ostream& output,
    uint quant_star,
    uint star_size,
    vector<node_id>::iterator it_begin,
    const vector<node_id>::iterator it_end)
{
    //Variables locales
    node_id banana_center;//,star_center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    iter_swap(it_begin,it_begin+rand()%distance(it_begin,it_end));

    //Nos guardamos el centro de la banana
    banana_center = *it_begin;
    ++it_begin;

    //Imprimimos la salida segun el formato pedido
    for(uint star = 0;star<quant_star;++star){
        random_star_graph(output,it_begin+star*star_size,it_begin+star_size*(star+1));
        output << banana_center << ' ' << *(it_begin+star*star_size+1) << endl;
    }
}

void random_banana_tree_graph(ostream& output,uint quant_nodes){
    //Variables locales
    uint quant_star,star_size;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Buscamos un divisor aleatorio para que luego matchee
    //con el tamano de las estrellas
    quant_star = rand()%((quant_nodes-1)/2) + 1;
    while((bool)((quant_nodes-1)%quant_star))
        --quant_star;
    star_size = (quant_nodes-1)/quant_star;

    random_banana_tree_graph(output,quant_star,star_size);
}

void random_banana_tree_graph(ostream& output,uint quant_star,uint star_size){
    //Variables locales
    uint quant_nodes = star_size*quant_star+1;
    vector<node_id> nodes(quant_nodes);

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);

    //Imprimimos la salida segun el formato pedido
    output << quant_nodes << ' ' << quant_star*star_size << endl;
    random_banana_tree_graph(output,quant_star,star_size,nodes.begin(),nodes.end());
}

/************************* COMPLETE **************************/
void random_complete_graph(ostream& output,
    vector<node_id>::const_iterator it_begin,
    const vector<node_id>::const_iterator it_end)
{
    for(;it_begin != it_end ;++it_begin){
        for(vector<node_id>::const_iterator it_left = it_begin+1;
            it_left!=it_end;
            ++it_left)
                output << *it_begin << ' ' << *it_left << endl;
    }
}

void random_complete_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    output << quant_nodes << ' ' << (quant_nodes*(quant_nodes-1))/2 << endl;
    random_complete_graph(output,nodes.cbegin(),nodes.cend());
}

/************************* COMPLETE_BIPARTITE **************************/
void random_complete_bipartite_graph(ostream& output,uint quant_nodes){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    uint v1_size = rand() % (quant_nodes-1)+1; //Me aseguro nodos en ambas particiones

    random_bipartite_graph(output,
                            v1_size,
                            quant_nodes-v1_size,
                            v1_size*(quant_nodes-v1_size),
                            true);
}

/************************* BIPARTIE **************************/
void random_bipartite_graph(ostream& output,
                            uint quant_nodes,
                            float density,
                            bool connected)
{
    random_bipartite_graph(output,
                            quant_nodes,
                            (uint)(density*(quant_nodes*(quant_nodes-1))/2),
                            connected);
}

void random_bipartite_graph(ostream& output,
                            uint quant_nodes_V1,
                            uint quant_nodes_V2,
                            float density,
                            bool connected)
{
    //Variables locales
    uint quant_nodes = quant_nodes_V1+quant_nodes_V2;
    random_bipartite_graph(output,
                            quant_nodes_V1,
                            quant_nodes_V2,
                            (uint)(density*(quant_nodes*(quant_nodes-1))/2),
                            connected);
}

void random_bipartite_graph(ostream& output,
    vector<node_id>::iterator it_v1_begin,
    vector<node_id>::iterator it_v1_end,
    vector<node_id>::iterator it_v2_begin,
    vector<node_id>::iterator it_v2_end,
    uint quant_edges,
    bool connected)
{
    //Variables locales
    map<node_id,vector<node_id> > possible_neighbors;
    vector<node_id>::iterator node_src_it;
    vector<node_id>::iterator it_begin_smallest_node_partition,it_end_smallest_node_partition;
    vector<node_id>::iterator it_begin_largest_node_partition,it_end_largest_node_partition;
    node_id node_dest;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Generamos una lista de posibles vecinos
    if(distance(it_v1_begin,it_v1_end)<distance(it_v2_begin,it_v2_end)){
        it_begin_smallest_node_partition = it_v1_begin;
        it_end_smallest_node_partition = it_v1_end;
        it_begin_largest_node_partition = it_v2_begin;
        it_end_largest_node_partition = it_v2_end;
    } else {
        it_begin_smallest_node_partition = it_v2_begin;
        it_end_smallest_node_partition = it_v2_end;
        it_begin_largest_node_partition = it_v1_begin;
        it_end_largest_node_partition = it_v1_end;
    }
    for(vector<node_id>::const_iterator it = it_begin_smallest_node_partition;
        it != it_end_smallest_node_partition;
        ++it)
    {
        possible_neighbors.insert(
            pair<node_id,vector<node_id> >(
                *it,
                vector<node_id>(it_begin_largest_node_partition,it_end_largest_node_partition)
            )
        );
        std::random_shuffle(possible_neighbors[*it].begin(),possible_neighbors[*it].end());
    }

    //Si nos pidieron un grafo bipartito conexo
    if(connected){
        quant_edges+= -distance(it_v1_begin,it_v1_end)-distance(it_v2_begin,it_v2_end)+1;
        //Nos aseguramos que sea conexo
        bool already_connected = false;
        vector<node_id>::iterator it_smallest = it_begin_smallest_node_partition;
        for(vector<node_id>::const_iterator it_largest = it_begin_largest_node_partition;
            it_largest != it_end_largest_node_partition;
            ++it_largest)
        {
            output << *it_smallest << ' ' << *it_largest << endl;

            /*Borramos esta opcion*/
            iter_swap(
                possible_neighbors[*it_smallest].end()-1,
                find(
                    possible_neighbors[*it_smallest].begin(),
                    possible_neighbors[*it_smallest].end(),
                    *it_largest
                )
            );
            possible_neighbors[*it_smallest].pop_back();

            /*Movemos el iterador de la particion pequena*/
            if(it_smallest < it_end_smallest_node_partition-1 && !already_connected){
                ++it_smallest;
                output << *it_smallest << ' ' << *it_largest << endl;

                /*Borramos esta opcion*/
                iter_swap(
                    possible_neighbors[*it_smallest].end()-1,
                    find(
                        possible_neighbors[*it_smallest].begin(),
                        possible_neighbors[*it_smallest].end(),
                        *it_largest
                    )
                );
                possible_neighbors[*it_smallest].pop_back();

            } else {
                it_smallest = it_begin_smallest_node_partition+
                    rand()%distance(it_begin_smallest_node_partition,it_end_smallest_node_partition);
                already_connected = true;
            }
        }
    }

    //Comenzamos a meter los ejes
    for(uint edge = 0; edge<quant_edges && distance(it_begin_smallest_node_partition,it_end_smallest_node_partition) > 0; ++edge){
        node_src_it = it_begin_smallest_node_partition+
            rand()%distance(
                it_begin_smallest_node_partition,
                it_end_smallest_node_partition
            );

        //Si estabamos en un grafo conexo hay que tener en cuenta
        //que por ahi los vecinos quedaron vacios
        while(connected && possible_neighbors[*node_src_it].empty()){
            iter_swap(node_src_it,it_end_smallest_node_partition-1);
            --it_end_smallest_node_partition;
            node_src_it = it_begin_smallest_node_partition+
                rand()%distance(
                    it_begin_smallest_node_partition,
                    it_end_smallest_node_partition
                );
        }
        node_dest = possible_neighbors[*node_src_it].back();
        output << *node_src_it << ' ' << node_dest << endl;

        /*Borramos esta opcion*/
        possible_neighbors[*node_src_it].pop_back();
        if(possible_neighbors[*node_src_it].empty()){
            iter_swap(node_src_it,it_end_smallest_node_partition-1);
            --it_end_smallest_node_partition;
        }
    }
}

void random_bipartite_graph(ostream& output,
                            uint quant_nodes_V1,
                            uint quant_nodes_V2,
                            uint quant_edges,
                            bool connected)
{
    //Variables locales
    vector<node_id> nodes(quant_nodes_V1+quant_nodes_V2);

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Comenzamos a meter los ejes
    output << quant_nodes_V1 + quant_nodes_V2 << ' ' << quant_edges << endl;
    random_bipartite_graph(
        output,
        nodes.begin(),
        nodes.begin()+quant_nodes_V1,
        nodes.begin()+quant_nodes_V1,
        nodes.end(),
        quant_edges,
        connected
    );
}

void random_bipartite_graph(ostream& output,
                            uint quant_nodes,
                            bool connected)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    uint v1_size = rand() % (quant_nodes-1)+1; //Me aseguro nodos en ambas particiones

    uint quant_edges;
    if(!connected)
        quant_edges = rand()%(v1_size*(quant_nodes-v1_size))+1;
    else if (v1_size*(quant_nodes-v1_size)-quant_nodes+1 != 0){
        quant_edges = rand()%(v1_size*(quant_nodes-v1_size)-quant_nodes+1)+quant_nodes;
        random_bipartite_graph(output,
                                v1_size,
                                quant_nodes-v1_size,
                                quant_edges,
                                connected);
    } else
        random_tree_graph(output,quant_nodes);

}

void random_bipartite_graph(ostream& output,
                            uint quant_nodes,
                            uint quant_edges,
                            bool connected)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    uint v1_size = rand() % (quant_nodes-1)+1; //Me aseguro nodos en ambas particiones

    random_bipartite_graph(output,
                            v1_size,
                            quant_nodes-v1_size,
                            quant_edges,
                            connected);
}

/************************* TREE **************************/
void random_tree_graph(ostream& output,uint quant_nodes){
    random_connected_graph(output,quant_nodes,quant_nodes-1);
}

/************************* CONNECTED **************************/
void random_connected_graph(ostream& output,
    uint quant_nodes,
    float density_lower,
    float density_upper)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    float density = density_lower+
        static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(density_upper-density_lower)));

    random_connected_graph(output,quant_nodes,density);
}

void random_connected_graph(ostream& output,uint quant_nodes,float density){
    density = max(density,(float)2/(float)quant_nodes); //La minima densidad de un conexo
    random_connected_graph(output,quant_nodes,(uint)(density*(quant_nodes*(quant_nodes-1))/2));
}

void random_connected_graph(ostream& output,uint quant_nodes){
    //Variables locales
    uint quant_edges = quant_nodes-1;
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Me aseguro que sea conexo y que no supere el completo
    if(quant_nodes > 2)
        quant_edges = rand()%((quant_nodes*(quant_nodes-3))/2 + 1 ) + quant_nodes-1;

    random_connected_graph(output,quant_nodes,quant_edges);
}

void random_connected_graph(ostream& output,uint quant_nodes,uint quant_edges){
    //Empezamos generando un arbol
    //(copio el codigo porque necesito guardar informacion
    //para luego no generar un multigrafo)
    if(quant_nodes == 1){
        output << quant_nodes << ' ' << '0' << endl;

    } else {
        output << quant_nodes << ' ' << quant_edges << endl;

        //Variables locales
        vector<vector<node_id> > possible_neighbors(quant_nodes,vector<node_id>(quant_nodes));
        vector<node_id> nodes(quant_nodes);
        vector<node_id> tree;
        tree.reserve(quant_nodes);
        uint node_src,node_src_pos,node_dest;//,node_dest_pos;
        int edges_left;

        //Seteamos la semilla para el random
        srand(std::chrono::system_clock::now().time_since_epoch().count());

        //Inicializamos los vecinos
        for(vector<vector<node_id> >::iterator it = possible_neighbors.begin();
            it != possible_neighbors.end();
            ++it)
        {
            std::iota(it->begin(),it->end(),1);
            //Elimino de las opciones de un nodo x a x
            swap(it->back(),it->at(distance(possible_neighbors.begin(),it)));
            it->pop_back();

            //Mezclo
            random_shuffle(it->begin(),it->end());
        }

        //Comenzamos
        std::iota(nodes.begin(),nodes.end(),1);
        random_shuffle(nodes.begin(),nodes.end());

        //Vamos colocando los nodos de a uno, asegurandonos que sea conexo
        //o sea, armamos un arbol primero
        tree.push_back(nodes.back());
        nodes.pop_back();
        while(!nodes.empty()){
            node_src = tree[rand()%tree.size()];
            output << node_src << ' ' << nodes.back() << endl;
            tree.push_back(nodes.back());
            nodes.pop_back();

            //Actualizamos la estructura
            iter_swap(
                possible_neighbors[node_src-1].end()-1,
                find(possible_neighbors[node_src-1].begin(),possible_neighbors[node_src-1].end(),tree.back())
            );
            possible_neighbors[node_src-1].pop_back();

            iter_swap(
                possible_neighbors[tree.back()-1].end()-1,
                find(possible_neighbors[tree.back()-1].begin(),possible_neighbors[tree.back()-1].end(),node_src)
            );
            possible_neighbors[tree.back()-1].pop_back();
        }

        //Colocamos los ejes restantes
        edges_left = quant_edges - quant_nodes +1;
        while(edges_left > 0){
            node_src_pos = rand()%tree.size();
            node_src = tree[node_src_pos];
            if(possible_neighbors[node_src-1].empty()){
                //Si no le quedan vecinos validos, no lo tenemos
                //mas en cuenta
                swap(tree[node_src_pos],tree.back());
                tree.pop_back();

            } else {
                //Agregamos el eje
                node_dest = possible_neighbors[node_src-1].back();
                output << node_src << ' ' << node_dest << endl;

                //Actualizamos las estructuras de datos
                iter_swap(
                    possible_neighbors[node_dest-1].end()-1,
                    find(possible_neighbors[node_dest-1].begin(),
                        possible_neighbors[node_dest-1].end(),
                        node_src)
                );
                possible_neighbors[node_dest-1].pop_back();
                possible_neighbors[node_src-1].pop_back();
                --edges_left;
            }
        }
    }
}

/************** PLANAR (3-Connected) ******************/
void random_planar_graph(ostream& output,uint quant_nodes){
    //Variables locales
    ogdf::List<ogdf::EdgeElement*> edgeList;
    ogdf::Graph g;

    //Comenzamos
    ogdf::planarConnectedGraph(g,quant_nodes,quant_nodes*3-6);
    g.allEdges(edgeList);
    output << quant_nodes << ' ' << quant_nodes*3-6 << endl;
    for(ogdf::ListConstIterator<ogdf::EdgeElement*> edge_it = edgeList.begin();
        edge_it != edgeList.end();
        ++edge_it)
    {
        output << (*edge_it)->source()->index()+1 << ' ' << (*edge_it)->target()->index()+1 << endl;
    }

}

/************** GREEDY ******************/
void join_by_bridge(ostream& output,
                    uint node_src,
                    uint node_dest,
                    vector<node_id>::const_iterator it_bridge_begin,
                    const vector<node_id>::const_iterator it_bridge_end)
{
    output << node_src << ' ' << *it_bridge_begin << endl;
    for(;it_bridge_begin != it_bridge_end-1;++it_bridge_begin)
        output << *it_bridge_begin << ' ' << *(it_bridge_begin+1) << endl;

    output << *it_bridge_begin << ' ' << node_dest << endl;
}

void highest_degree_node_in_CMF(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);
    vector<node_id>::iterator star_begin_it,star_end_it;
    vector<node_id>::iterator clique_begin_it,clique_end_it;
    vector<node_id>::iterator frontier_begin_it,frontier_end_it;
    uint quant_edges,frontier_max;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Nos separamos las secciones que formaran las
    //distintas partes de estos grafos
    clique_begin_it = nodes.begin();
    clique_end_it = nodes.begin()+(nodes.size()+3)/4-1;
    frontier_begin_it = clique_end_it;
    frontier_end_it = frontier_begin_it+(nodes.size()+3)/4-1;
    star_begin_it = frontier_end_it;
    star_end_it = star_begin_it+(nodes.size()-1)/2;

    frontier_max = distance(clique_begin_it,clique_end_it)*distance(frontier_begin_it,frontier_end_it);
    quant_edges =
        distance(star_begin_it,star_end_it)-1+ //Aristas de la estrella
        (distance(clique_begin_it,clique_end_it)*(distance(clique_begin_it,clique_end_it)-1)/2)+ //aristas de la clique
        frontier_max+ //Aristas de la frontera
        distance(star_end_it,nodes.end())+1; //Aristas remaining y la union estrella<->clique

    //Comenzamos a meter los ejes
    output << quant_nodes << ' ' << quant_edges << endl;
    random_complete_graph(output,clique_begin_it,clique_end_it);
    random_bipartite_graph(output,
                            clique_begin_it,
                            clique_end_it,
                            frontier_begin_it,
                            frontier_end_it,
                            frontier_max,
                            true);
    random_star_graph(output,star_begin_it,star_end_it);

    //Uno la estrella
    output << *star_begin_it << ' ' << *clique_begin_it << endl;

    //Agrego los posibles nodos disconexos debido de las divisiones
    //enteras y dejados afuera para luego cumplir con que un nodo
    //de la clique sea el de mayor grado del grafo
    for(vector<node_id>::const_iterator remaining_it = star_end_it;
        remaining_it != nodes.end();
        ++remaining_it)
            output << *clique_begin_it << ' ' << *remaining_it << endl;
}

void highest_degree_node_not_in_CMF(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);
    vector<node_id>::iterator star_begin_it,star_end_it;
    vector<node_id>::iterator clique_begin_it,clique_end_it;
    vector<node_id>::iterator frontier_begin_it,frontier_end_it;
    vector<node_id>::iterator bridge_begin_it,bridge_end_it;
    uint quant_edges,frontier_max;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Nos separamos las secciones que formaran las
    //distintas partes de estos grafos
    star_begin_it = nodes.begin();
    star_end_it = nodes.begin()+nodes.size()/2;
    clique_begin_it = star_end_it;
    clique_end_it = clique_begin_it+nodes.size()/4-1;
    frontier_begin_it = clique_end_it;
    frontier_end_it = frontier_begin_it+nodes.size()/4-1;
    bridge_begin_it = frontier_end_it;
    bridge_end_it = nodes.end();

    frontier_max = distance(clique_begin_it,clique_end_it)*distance(frontier_begin_it,frontier_end_it);
    quant_edges =
        distance(star_begin_it,star_end_it)-1+ //Aristas de la estrella
        (distance(clique_begin_it,clique_end_it)*(distance(clique_begin_it,clique_end_it)-1)/2)+ //aristas de la clique
        frontier_max+ //Aristas de la frontera
        distance(bridge_begin_it,bridge_end_it)+1; //Aristas del puente

    //Comenzamos a meter los ejes
    output << quant_nodes << ' ' << quant_edges << endl;
    random_star_graph(output,star_begin_it,star_end_it);
    random_complete_graph(output,clique_begin_it,clique_end_it);
    random_bipartite_graph(output,
                            clique_begin_it,
                            clique_end_it,
                            frontier_begin_it,
                            frontier_end_it,
                            frontier_max,
                            true);
    join_by_bridge(output,*(star_begin_it+1),*clique_begin_it,bridge_begin_it,bridge_end_it);
}
