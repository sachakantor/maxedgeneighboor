#include<algorithm>
#include<fstream>
//#include<ctime>
#include<chrono>
#include<iostream>
//#include<limits>
#include<vector>

#ifdef _OPENMP
#include<deque>
#endif//_OPENMP

#include<algo3InputParser.hpp>
#include<graph.hpp>
#include<typedefs.hpp>

typedef unsigned int parameter;
typedef unsigned long long int ullong;
typedef std::chrono::high_resolution_clock high_res_clock;

using namespace std;

int main(int argc,char* argv[]){
    /* Por parametros de invocacion del programa me (deben) llega(n/r):
     * cant de ejecuciones por instancia = argv[1]
     * archivo de salida = argv[2]
     */

    /* Variables locales */
    algo3InputParser<parameter,vector<parameter> > parser(std::cin);
    vector<parameter> input;
    parameter quant_nodes,quant_edges,terminator_char=0;
    ofstream output_file;
    uint frontera;
    uint cant_ejec_por_inst = std::stoi(argv[1]);
    std::chrono::duration<double> t_span,t_min; //Segundos
    high_res_clock::time_point t_begin,t_end;
    #ifdef _OPENMP
    deque<parameter> quant_nodes_deque,quant_edges_deque;
    deque<vector<parameter>::const_iterator> edges_it_deque;
    #endif//_OPENMP

    /* Abro el archivo (4to parametro) */
    output_file.open(argv[2],std::ios::app);

    /* Imprimimos los encabezados */
    output_file << "Nodos Aristas Frontera |CMF| Segundos" << endl;

    /* Configuramos cout para imprimir la max cantidad de decimales
     * posibles sin notacion cientifica
     */
    output_file.precision(std::numeric_limits< double >::digits10+2);

    /* Comenzamos */

    /* Leemos toda la entrada hasta encontrar
     * a "terminator" (definido arriba) y guardamos cada
     * uint en la lista input
     * para luego crear nuestros grafos
     * y llamar a sus funciones
     */
    parser.copy_to_container(input,terminator_char);

    /* Instancio un grafo correspondiente a cada instancia del
     * input, y luego llamo a sus metodos que resuelven el
     * problema dado
     */
    for(uint i = 0; i<input.size(); i += 2*(quant_edges+1))
    {
        quant_nodes = input[i];
        quant_edges = input[i+1];

        #ifdef _OPENMP
        quant_nodes_deque.push_back(quant_nodes);
        quant_edges_deque.push_back(quant_edges);
        edges_it_deque.push_back(input.cbegin()+i+2);

        #else
        /*Variables local*/
        vector<parameter>::const_iterator it_param = input.cbegin()+i+2;
        vector<node_id> clique;

        /*Instanciamos el grafo*/
        graph grafo(quant_nodes,quant_edges,it_param);

        /*Calculamos su frontera maxima por backtracking*/
        t_min = std::chrono::duration<ullong,milli>::max();

        for(uint ejec=0;ejec<cant_ejec_por_inst;++ejec){
            clique.clear();
            t_begin = high_res_clock::now();
                #if defined(_HEUR_GOLOSA)
                frontera = grafo.cmf_golosa(clique);

                #elif defined(_HEUR_BUSQUEDA)
                frontera = grafo.cmf_busqueda_local(clique);

                #elif defined(_HEUR_BUSQUEDA_GOLOSA)
                grafo.cmf_golosa(clique);
                frontera = grafo.cmf_busqueda_local(clique);

                #elif defined(_HEUR_TABU)
                frontera = grafo.cmf_tabu_search(clique);

                #elif defined(_BACKTRACKING_GOLOSA)
                frontera = grafo.cmf_golosa(clique);
                frontera = grafo.cmf_backtracking(frontera,clique);

                #else
                frontera = grafo.cmf_backtracking(clique);

                #endif
            t_end = high_res_clock::now();
            t_span = std::chrono::duration_cast<std::chrono::duration<double> >(t_end - t_begin);

            t_min = min(t_span,t_min);
        }

        /*Guardamos el resultado*/
        output_file << quant_nodes;
        output_file << ' ' << quant_edges;
        output_file << ' ' << frontera;
        output_file << ' ' << clique.size();
        output_file << ' ' << std::fixed << t_min.count() << endl;

        #endif//_OPENMP
    }

    #ifdef _OPENMP

    #pragma omp parallel for schedule(dynamic) default(none) collapse(1)\
        private(frontera,t_begin,t_end,t_span,t_min)\
        firstprivate(cant_ejec_por_inst)\
        shared(output_file,input,quant_nodes_deque,quant_edges_deque,edges_it_deque,cout)
    for(uint i = 0; i<quant_nodes_deque.size(); ++i){
        /*Variables local*/
        vector<node_id> clique;

        /*Instanciamos el grafo*/
        graph grafo(quant_nodes_deque[i],quant_edges_deque[i],edges_it_deque[i]);

        /*Calculamos su frontera maxima por backtracking*/
        t_min = std::chrono::duration<ullong,milli>::max();

        for(uint ejec=0;ejec<cant_ejec_por_inst;++ejec){
            clique.clear();
            t_begin = high_res_clock::now();
                #if defined(_HEUR_GOLOSA)
                frontera = grafo.cmf_golosa(clique);

                #elif defined(_HEUR_BUSQUEDA)
                frontera = grafo.cmf_busqueda_local(clique);

                #elif defined(_HEUR_BUSQUEDA_GOLOSA)
                grafo.cmf_golosa(clique);
                frontera = grafo.cmf_busqueda_local(clique);

                #elif defined(_HEUR_TABU)
                frontera = grafo.cmf_tabu_search(clique);

                #elif defined(_BACKTRACKING_GOLOSA)
                frontera = grafo.cmf_golosa(clique);
                frontera = grafo.cmf_backtracking(frontera,clique);

                #else
                frontera = grafo.cmf_backtracking(clique);

                #endif
            t_end = high_res_clock::now();
            t_span = std::chrono::duration_cast<std::chrono::duration<double> >(t_end - t_begin);

            t_min = min(t_span,t_min);
        }

        /*Guardamos el resultado*/
        #pragma omp critical(write_output)
        {
        output_file << quant_nodes_deque[i];
        output_file << ' ' << quant_edges_deque[i];
        output_file << ' ' << frontera;
        output_file << ' ' << clique.size();
        output_file << ' ' << std::fixed << t_min.count() << endl;
        }
    }

    #endif//_OPENMP

    /* Cierro el archivo */
    output_file.close();

    return 0;
}
