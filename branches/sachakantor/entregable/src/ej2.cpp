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
    parameter quant_nodes,quant_edges,terminator_char=0;

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

        graph grafo(quant_nodes,quant_edges,it_param);
        cout << grafo << endl;;
        --it_param; //Esto se debe a que el constructor de grafo
                    //deja it_param ya incrementado (que luego indrementa
                    //el for)
    }

    return 0;
}
