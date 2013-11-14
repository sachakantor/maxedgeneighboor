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
    node_id banana_center,star_center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    random_shuffle(it_begin,it_end);

    //Nos guardamos el centro de la banana
    banana_center = *it_begin;
    ++it_begin;

    //Imprimimos la salida segun el formato pedido
    for(uint star = 0;star<quant_star;++star){
        star_center = *it_begin;
        ++it_begin;
        output << banana_center << ' ' << *it_begin << endl;
        for(uint point = 0;point < star_size-1;++point){
            output << star_center << ' ' << *it_begin << endl;
            ++it_begin;
        }
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

    random_bipartite_graph(output,v1_size,quant_nodes-v1_size,v1_size*(quant_nodes-v1_size));
}

/************************* BIPARTIE **************************/
void random_bipartite_graph(ostream& output,uint quant_nodes,float density){
    //Variables locales
}

void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,float density){
    //Variables locales
}

void random_bipartite_graph(ostream& output,uint quant_nodes){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    uint v1_size = rand() % (quant_nodes-1)+1; //Me aseguro nodos en ambas particiones

    random_bipartite_graph(output,v1_size,quant_nodes-v1_size,rand()%(v1_size*(quant_nodes-v1_size))+1);
}

void random_bipartite_graph(ostream& output,
    vector<node_id>::iterator it_v1_begin,
    vector<node_id>::iterator it_v1_end,
    vector<node_id>::iterator it_v2_begin,
    vector<node_id>::iterator it_v2_end,
    uint quant_edges)
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

    //Comenzamos a meter los ejes
    for(uint edge = 0; edge<quant_edges; ++edge){
        int offset = rand()%(
            distance(
                it_begin_smallest_node_partition,
                it_end_smallest_node_partition
            ) + 1 //Para no dividir por 0
        ) - 1; //Para suplir el fix para no dividir por 0
        node_src_it = it_begin_smallest_node_partition+max(0,offset); //Por si el offset quedo -1

        node_dest = possible_neighbors[*node_src_it].back();
        output << *node_src_it << ' ' << node_dest << endl;

        /*Borramos esta opcion de ambos nodos*/
        possible_neighbors[*node_src_it].pop_back();
        if(possible_neighbors[*node_src_it].empty()){
            iter_swap(node_src_it,it_end_smallest_node_partition-1);
            --it_end_smallest_node_partition;
        }
    }
}

void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,uint quant_edges){
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
        quant_edges
    );
}

/************************* TREE **************************/
void random_tree_graph(ostream& output,uint quant_nodes){
    random_connected_graph(output,quant_nodes,quant_nodes-1);
}

/************************* CONNECTED **************************/
void random_connected_graph(ostream& output,uint quant_nodes,float density){
    //Variables locales
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
