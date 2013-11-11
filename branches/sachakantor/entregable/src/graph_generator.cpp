#include<iostream>
#include<fstream>
#include<string>
#include<random_graphs_generators.hpp>

using namespace std;

uint from_how_many_nodes(){
    uint nodes;
    cout << "Cantidad de nodos de la instancia mas chica: ";
    cin >> nodes;
    cout << endl;

    return nodes;
}

uint to_how_many_nodes(){
    uint nodes;
    cout << "Cantidad de nodos de la instancia mas grande: ";
    cin >> nodes;
    cout << endl;

    return nodes;
}

string ask_output_file(){
    string name;
    cout << "¿Donde desea guardar el resultado?: ";
    cin >> name;
    cout << endl;

    return name;
}

int main(int argc,char* argv[]){
    //Variables locales
    uint choice,nodes_lower,nodes_upper;
    ofstream output_file;

    //Pedimos data al usuario
    nodes_lower = from_how_many_nodes();
    nodes_upper = to_how_many_nodes();
    output_file.open(ask_output_file().c_str(),std::ios::app);
    cout << "0.  Agujero" << endl;
    cout << "1.  Estrella" << endl;
    cout << "2.  Rueda" << endl;
    cout << "3.  Banana Tree" << endl;
    cout << "4.  Completo" << endl;
    cout << "5.  Bipartito" << endl;
    cout << "6.  Arbol" << endl;
    cout << "7.  Conexo" << endl;
    cout << "Seleccione una opcion: ";
    cin >> choice;

    switch(choice){
        case 0:
            for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
                random_hole_graph(output_file,nodes);
            output_file << '0' << endl;
            break;

        case 1:
            for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
                random_star_graph(output_file,nodes);
            output_file << '0' << endl;
            break;

        case 2:
            for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
                random_wheel_graph(output_file,nodes);
            break;

        case 3:
            for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes){
                for(uint quant_star = 1;quant_star<nodes;++quant_star){
                    random_banana_tree_graph(output_file,quant_star,(nodes-1)/quant_star);
                }
            }
            output_file << '0' << endl;
            break;

        case 4:
            for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
                random_complete_graph(output_file,nodes);
            output_file << '0' << endl;
            break;

        case 5:
            for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
                random_bipartite_graph(output_file,nodes);
            output_file << '0' << endl;
            break;

        case 6:
            //for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
            //    random_tree_graph(output_file,nodes);
            output_file << '0' << endl;
            break;

        case 7:
            //for(uint nodes = nodes_lower; nodes<=nodes_upper;++nodes)
            //    random_connected_graph(output_file,nodes,uint quant_edges);
            output_file << '0' << endl;
            break;

        default:
            cout << "Opcion no existente" << endl;
            break;
    }

    output_file.close();
    return 0;
}
