#include<iostream>
#include<string>
#include<vector>
#include<algo3InputParser.hpp>
#include<graph.hpp>
#include<ej2.hpp>

typedef unsigned int parameter;

using namespace std;

int main(int argc,char* argv[]){
    /* Variables Locales */
    algo3InputParser<parameter,vector<parameter> > parser(std::cin);
    vector<parameter> input;
    parameter quant_nodes,quant_edges,terminator_char=0;
    vector<node_id> clique;
    #ifndef _OPENMP
    uint frontera;
    #else
    vector<graph*> problems;
    #endif//_OPENMP

    /* Leemos toda la entrada hasta encontrar
     * a "terminator" (definido arriba) y guardamos cada
     * int en la lista input
     * para luego crear nuestros grafos
     * y llamar a sus funciones
     */
    parser.copy_to_container(input,terminator_char);

    /* Instancio un grafo correspondiente a cada instancia del
     * input, y luego llamo a sus metodos que resuelven el
     * problema dado
     */

    for(vector<parameter>::const_iterator it_param = input.cbegin();
        it_param < input.cend();
        ++it_param)
    {
        quant_nodes = *it_param;
        ++it_param;
        quant_edges = *it_param;
        ++it_param;

    #ifndef _OPENMP
        /*Instanciamos el grafo*/
        graph grafo(quant_nodes,quant_edges,it_param);
        //cout << grafo << endl;;

        /*Calculamos su frontera maxima por backtracking*/
        clique.clear();
        frontera = grafo.cmf_backtracking(clique);

        /*Imprimimos el resultado por pantallas*/
        cout << frontera << ' ' << clique.size() << ' ';
        for(vector<node_id>::const_iterator it = clique.cbegin();
            it<clique.cend();
            ++it)
        {
            cout << *it << ' ';
        }
        cout << endl;

        /* Terminamos el bucle*/
        --it_param; //Esto se debe a que el constructor de grafo
                    //deja it_param ya incrementado (que luego indrementa
                    //el for)
    }

    #else
        /*Instanciamos el grafo y nos guardamos un puntero al mismo*/
        problems.push_back(new graph(quant_nodes,quant_edges,it_param));

        /* Terminamos el bucle*/
        --it_param; //Esto se debe a que el constructor de grafo
                    //deja it_param ya incrementado (que luego indrementa
                    //el for)
    }
    vector<string> results(problems.size());
    /*Resuelvo el CMF para todos los problemas con distintos threads*/
    #pragma omp parallel for schedule(dynamic) default(none) collapse(1)\
        private(clique)\
        shared(results,problems)
    for(uint i = 0; i<problems.size(); ++i){
        results[i] = to_string(problems[i]->cmf_backtracking(clique));
        results[i] += ' '+to_string(clique.size());
        for(vector<node_id>::const_iterator it = clique.cbegin();
            it<clique.cend();
            ++it)
        {
            results[i]+= ' '+to_string(*it);
        }
    }

    /*Imprimo los resultados*/
    for(vector<string>::const_iterator it = results.cbegin();
        it != results.cend();
        ++it)
    {
        cout << *it << endl;
    }
    #endif//_OPENMP

    return 0;
}
