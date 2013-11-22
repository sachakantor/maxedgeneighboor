#include "../include/strtk/strtk.hpp"
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define strtk_no_tr1_or_boost

/* USAR C++11 PARA COMPILAR*/

int main(int argc, char* argv[])
{
    //Variable local
    unsigned int tam_instancia;
    unsigned int cant = 0;
    double accum = 0,front=0,clique_size=0,ejes=0;
    std::ofstream promedios;
    std::string file_name = argv[1]; //Asumo que esta ordenado por tama\~no de instancia
    strtk::token_grid::options options;
    options.column_delimiters = " ";

    //Abro el archivo
    promedios.open(argv[2],std::ios::app);
    promedios.precision(std::numeric_limits< double >::digits10+2);

    //Programa
    strtk::token_grid grid(file_name,options);

    //Me guardo la cabecera
    for(unsigned int i = 0;i<5;++i)
        promedios << grid.row(0).get<std::string>(i) << ' ';
    promedios << std::endl;

    tam_instancia = grid.row(1).get<unsigned int>(0);
    for(std::size_t r=1;r<grid.row_count();++r){
        strtk::token_grid::row_type row = grid.row(r);
        if(tam_instancia != row.get<unsigned int>(0)){
            /*Cambio el tama\~no de la instancia
             *Escribo en el archivo el promedio
             *Reseteo para calcular el nuevo tama\~no
             */
            promedios << tam_instancia << ' ';
            promedios << std::fixed << ejes/(double)cant << ' ' << front/(double)cant << ' ' << clique_size/(double)cant << ' ' << accum/(double)cant << std::endl;
            tam_instancia = row.get<unsigned int>(0);
            accum = 0;
            front=0;
            clique_size=0;
            ejes=0;
            cant = 0;
        }
        /*Guardo en el acumulador e incremento cant*/
        accum += row.get<double>(4);
        ejes += row.get<unsigned int>(1);
        front += row.get<unsigned int>(2);
        clique_size += row.get<unsigned int>(3);
        ++cant;

        /*En caso de estar en la ultima fila*/
        if(r == grid.row_count()-1){
            /*Escribo en el archivo el promedio*/
            promedios << tam_instancia << ' ';
            promedios << std::fixed << ejes/(double)cant << ' ' << front/(double)cant << ' ' << clique_size/(double)cant << ' ' << accum/(double)cant << std::endl;
            tam_instancia = row.get<unsigned int>(0);
        }
    }

    //Cierro el archivo
    promedios.close();

    return 0;
}
