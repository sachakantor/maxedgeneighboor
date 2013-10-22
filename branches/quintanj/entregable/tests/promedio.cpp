#include "../include/strtk/strtk.hpp"
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>

#define strtk_no_tr1_or_boost

/* USAR C++11 PARA COMPILAR*/

int main(int argc, char* argv[])
{
	//Variable local
	unsigned int tam_instancia = 1;
	unsigned int cant = 0;
	float accum = 0;
	std::ofstream promedios;
	std::string file_name = argv[1]; //Asumo que esta ordenado por tama\~no de instancia
	strtk::token_grid::options options;
	options.column_delimiters = " ";

	//Abro el archivo
	promedios.open(argv[2],std::ios::app);

	//Programa
	strtk::token_grid grid(file_name,options);
	for(std::size_t r=0;r<grid.row_count();++r){
		strtk::token_grid::row_type row = grid.row(r);
		if(tam_instancia != row.get<unsigned int>(0)){
		/*Cambio el tama\~no de la instancia
		 *Escribo en el archivo el promedio
		 *Reseteo para calcular el nuevo tama\~no
		 */
		promedios << tam_instancia << ' ' << std::fixed << accum/(float)cant << std::endl;
		tam_instancia = row.get<unsigned int>(0);
		accum = 0;
		cant = 0;
		}
		/*Guardo en el acumulador e incremento cant*/
		accum += row.get<float>(1);
		++cant;
	}
	
	//Cierro el archivo
	promedios.close();

	return 0;
}
