#include<algorithm>     // std::random_shuffle,generate_n
#include<numeric>       // std::iota
#include<chrono>        // std::chrono::system_clock
#include<cstdlib>       // std::rand, std::srand
#include<ctime>         // std::time
#include<iostream>      // std::cout
#include<random>        // std::default_random_engine
#include<vector>
#include<deque>

#include<random_graphs_generators.hpp>
#include<typedefs.hpp>

using namespace std;

/* Generadores de grafos con numeros exactos */
void random_hole_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Imprimimos la salida segun el formato pedido
    output << quant_nodes << ' ' << quant_nodes << endl;
    for(vector<node_id>::const_iterator it = nodes.cbegin();
        it < nodes.cend()-1;
        ++it)
        output << *it << ' ' << *(it+1) << endl;

    output << nodes.back() << ' ' << nodes.front() << endl;
}

void random_star_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);
    node_id center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Nos guardamos el centro de la estrella
    center = nodes.back();
    nodes.pop_back();

    //Imprimimos la salida segun el formato pedido
    output << quant_nodes << ' ' << quant_nodes-1 << endl;
    for(vector<node_id>::const_iterator it = nodes.cbegin();
        it < nodes.cend();
        ++it)
        output << center << ' ' << *it << endl;
}

void random_wheel_graph(ostream& output,uint quant_nodes){
    //Variables locales
    vector<node_id> nodes(quant_nodes);
    node_id center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Nos guardamos el centro de la estrella
    center = nodes.back();
    nodes.pop_back();

    //Imprimimos la salida segun el formato pedido
    if(quant_nodes<=2){
        output << quant_nodes << ' ' << quant_nodes-1 << endl;
        if(quant_nodes == 2)
            output << center << ' ' << nodes.back() << endl;

    } else if(quant_nodes == 3){
        output << quant_nodes << ' ' << quant_nodes << endl;
        output << nodes.back() << ' ' << nodes.front() << endl;
        output << center << ' ' << nodes.front() << endl;
        output << center << ' ' << nodes.back() << endl;

    } else {
        output << quant_nodes << ' ' << 2*(quant_nodes-1) << endl;
        for(vector<node_id>::const_iterator it = nodes.cbegin();
            it < nodes.cend()-1;
            ++it)
        {
            output << *it << ' ' << *(it+1) << endl;
            output << center << ' ' << *it << endl;
        }
        output << nodes.back() << ' ' << nodes.front() << endl;
        output << center << ' ' << nodes.back() << endl;
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
    node_id banana_center,star_center;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(nodes.begin(),nodes.end(),1);
    random_shuffle(nodes.begin(),nodes.end());

    //Nos guardamos el centro de la banana
    banana_center = nodes.back();
    nodes.pop_back();

    //Imprimimos la salida segun el formato pedido
    output << quant_nodes << ' ' << quant_star*star_size << endl;
    for(uint star = 0;star<quant_star;++star){
        star_center = nodes.back();
        nodes.pop_back();
        output << banana_center << ' ' << nodes.back() << endl;
        for(uint point = 0;point < star_size-1;++point){
            output << star_center << ' ' << nodes.back() << endl;
            nodes.pop_back();
        }
    }
}

void random_complete_graph(ostream& output,uint quant_nodes){
    output << quant_nodes << ' ' << (quant_nodes*(quant_nodes-1))/2 << endl;
    for(uint node = 1;node<quant_nodes;++node){
        for(uint nodes_left = node+1;nodes_left<=quant_nodes;++nodes_left)
            output << node << ' ' << nodes_left << endl;
    }
}

void random_complete_bipartite_graph(ostream& output,uint quant_nodes){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    uint v1_size = rand() % (quant_nodes-1)+1; //Me aseguro nodos en ambas particiones

    random_bipartite_graph(output,v1_size,quant_nodes-v1_size,v1_size*(quant_nodes-v1_size));
}

void random_bipartite_graph(ostream& output,uint quant_nodes){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    uint v1_size = rand() % (quant_nodes-1)+1; //Me aseguro nodos en ambas particiones

    random_bipartite_graph(output,v1_size,quant_nodes-v1_size,rand()%(v1_size*(quant_nodes-v1_size))+1);
}

void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,uint quant_edges){
    //Variables locales
    vector<vector<node_id> > possible_neighbors(quant_nodes_V1+quant_nodes_V2);
    vector<node_id> V1_nodes(quant_nodes_V1+quant_nodes_V2),V2_nodes(quant_nodes_V2);
    uint node_src_pos,node_src,node_dest;

    //Seteamos la semilla para el random
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Comenzamos
    std::iota(V1_nodes.begin(),V1_nodes.end(),1);
    random_shuffle(V1_nodes.begin(),V1_nodes.end());

    //Dividimos en dos vectores correspondientes a cada particion
    std::move(V1_nodes.begin()+quant_nodes_V1,V1_nodes.end(),V2_nodes.begin());
    V1_nodes.erase(V1_nodes.begin()+quant_nodes_V1,V1_nodes.end());

    //Generamos una lista de posibles vecinos
    vector<node_id>& smallest_node_partition = (V1_nodes.size()<V2_nodes.size()?V1_nodes:V2_nodes);
    vector<node_id>& largest_node_partition = (V1_nodes.size()<V2_nodes.size()?V2_nodes:V1_nodes);
    for(vector<node_id>::const_iterator it = smallest_node_partition.cbegin();
        it != smallest_node_partition.cend();
        ++it)
    {
        possible_neighbors[*it-1].reserve(largest_node_partition.size());
        possible_neighbors[*it-1] = largest_node_partition;
        std::random_shuffle(possible_neighbors[*it-1].begin(),possible_neighbors[*it-1].end());
    }

    //Comenzamos a meter los ejes
    output << quant_nodes_V1 + quant_nodes_V2 << ' ' << quant_edges << endl;
    for(uint edge = 0; edge<quant_edges /*&& !smallest_node_partition.empty()*/; ++edge){
        node_src_pos = rand()%smallest_node_partition.size();
        node_src = smallest_node_partition[node_src_pos];
        node_dest = possible_neighbors[node_src-1].back();
        output << node_src << ' ' << node_dest << endl;

        /*Borramos esta opcion de ambos nodos*/
        possible_neighbors[node_src-1].pop_back();
        if(possible_neighbors[node_src-1].empty()){
            swap(smallest_node_partition[node_src_pos],smallest_node_partition[smallest_node_partition.size()-1]);
            smallest_node_partition.pop_back();
        }
    }

}

void random_tree_graph(ostream& output,uint quant_nodes){
    random_connected_graph(output,quant_nodes,quant_nodes-1);
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


/* Generadores de grafos por densidad de nodos */
void random_bipartite_graph(ostream& output,uint quant_nodes,float density){
    //Variables locales
}

void random_bipartite_graph(ostream& output,uint quant_nodes_V1,uint quant_nodes_V2,float density){
    //Variables locales
}

void random_connected_graph(ostream& output,uint quant_nodes,float density){
    //Variables locales
}
