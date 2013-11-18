#include<iostream>
#include<vector>
#include<algo3InputParser.hpp>
#include<graph.hpp>

typedef unsigned int parameter;

using namespace std;

int main(int argc,char* argv[]){
    /* Variables Locales */
    algo3InputParser<parameter,vector<parameter> > parser(std::cin);
    vector<parameter> input;
    vector<parameter>::const_iterator it_param;
    parameter quant_nodes,quant_edges,terminator_char=0;
    #ifndef _OPENMP
    vector<node_id> clique;
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
    for(uint i = 0; i<input.size(); i += 2*(quant_edges+1))
    {
        quant_nodes = input[i];
        quant_edges = input[i+1];
        it_param = input.cbegin()+i+2;

    #ifndef _OPENMP
        /*Instanciamos el grafo*/
        graph grafo(quant_nodes,quant_edges,it_param);
        //cout << grafo << endl;;

        /*Calculamos su frontera maxima por tabu search*/
        clique.clear();
        #ifdef _TABU_GOLOSA
        frontera = grafo.cmf_golosa(clique);
        frontera = grafo.cmf_tabu_search(clique);

        #else
        frontera = grafo.cmf_tabu_search(clique);
        #endif//_TABU_GOLOSA

        /*Imprimimos el resultado por pantallas*/
        cout << frontera << ' ' << clique.size();
        for(vector<node_id>::const_iterator it = clique.cbegin();
            it<clique.cend();
            ++it)
        {
            cout << ' ' << *it;
        }
        cout << endl;
    }

    #else
        /*Instanciamos el grafo y nos guardamos un puntero al mismo*/
        problems.push_back(new graph(quant_nodes,quant_edges,it_param));
    }
    vector<string> results(problems.size());
    /*Resuelvo el CMF para todos los problemas con distintos threads*/
    #pragma omp parallel for schedule(dynamic) default(none) collapse(1)\
        shared(results,problems)
    for(uint i = 0; i<problems.size(); ++i){
        vector<node_id>* clique_ptr = new vector<node_id>;
        #ifdef _TABU_GOLOSA
        uint frontera = problems[i]->cmf_golosa(*clique_ptr);
        results[i] = to_string(problems[i]->cmf_tabu_search(*clique_ptr));

        #else
        results[i] = to_string(problems[i]->cmf_tabu_search(*clique_ptr));
        #endif//__BACKTRACKING_GOLOSA

        results[i] += ' '+to_string(clique_ptr->size());
        for(vector<node_id>::const_iterator it = clique_ptr->cbegin();
            it<clique_ptr->cend();
            ++it)
        {
            results[i]+= ' '+to_string(*it);
        }

        delete clique_ptr;
        delete problems[i];
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
