CXX=g++
CXXFLAGS=-Wall -O2 -std=c++0x
IDIR=-I../include/ -I../include/OGDF/
LDFLAGS=-lpthread
EXTRACXXFLAGS=
SOURCES=experimentacion.cpp ../src/graph.cpp
OGDF=../include/OGDF/_release/libOGDF.a
#OBJECTS=$(SOURCES:.cpp=.o)

BACKTRACKING=experimentacion.ej2.backtracking experimentacion.ej2.backtracking_golosa

GOLOSA=experimentacion.ej3.golosa.vecinos_no_ordenados \
	   experimentacion.ej3.golosa.vecinos_ordenados

BUSQUEDA=experimentacion.ej3.busqueda.primer_salto \
		 experimentacion.ej3.busqueda.primer_salto_golosa \
		 experimentacion.ej3.busqueda.primer_salto_intercambiar \
		 experimentacion.ej3.busqueda.primer_salto_intercambiar_golosa \
		 experimentacion.ej3.busqueda.mejor_salto \
		 experimentacion.ej3.busqueda.mejor_salto_golosa \
		 experimentacion.ej3.busqueda.mejor_salto_intercambiar \
		 experimentacion.ej3.busqueda.mejor_salto_intercambiar_golosa

TABU=experimentacion.ej3.tabu.iter_nn.down_2n.old_nlogn \
	 experimentacion.ej3.tabu.iter_nn.down_2n.old_n \
	 experimentacion.ej3.tabu.iter_nn.down_2n.old_n2 \
	 experimentacion.ej3.tabu.iter_nn.down_n.old_nlogn \
	 experimentacion.ej3.tabu.iter_nn.down_n.old_n \
	 experimentacion.ej3.tabu.iter_nn.down_n.old_n2 \
	 experimentacion.ej3.tabu.iter_nn.down_n2.old_nlogn \
	 experimentacion.ej3.tabu.iter_nn.down_n2.old_n \
	 experimentacion.ej3.tabu.iter_nn.down_n2.old_n2 \
	 experimentacion.ej3.tabu.iter_nlogn.down_2n.old_nlogn \
	 experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n \
	 experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n2 \
	 experimentacion.ej3.tabu.iter_nlogn.down_n.old_nlogn \
	 experimentacion.ej3.tabu.iter_nlogn.down_n.old_n \
	 experimentacion.ej3.tabu.iter_nlogn.down_n.old_n2 \
	 experimentacion.ej3.tabu.iter_nlogn.down_n2.old_nlogn \
	 experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n \
	 experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n2 \
	 experimentacion.ej3.tabu.iter_n.down_2n.old_nlogn \
	 experimentacion.ej3.tabu.iter_n.down_2n.old_n \
	 experimentacion.ej3.tabu.iter_n.down_2n.old_n2 \
	 experimentacion.ej3.tabu.iter_n.down_n.old_nlogn \
	 experimentacion.ej3.tabu.iter_n.down_n.old_n \
	 experimentacion.ej3.tabu.iter_n.down_n.old_n2 \
	 experimentacion.ej3.tabu.iter_n.down_n2.old_nlogn \
	 experimentacion.ej3.tabu.iter_n.down_n2.old_n \
	 experimentacion.ej3.tabu.iter_n.down_n2.old_n2 \
	 experimentacion.ej3.tabu.iter_nn.down_2n.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_2n.old_n.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_2n.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_n.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_n.old_n.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_n.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_n2.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_n2.old_n.golosa \
	 experimentacion.ej3.tabu.iter_nn.down_n2.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_n.old_n.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_n.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n.golosa \
	 experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_n.down_2n.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_n.down_2n.old_n.golosa \
	 experimentacion.ej3.tabu.iter_n.down_2n.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_n.down_n.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_n.down_n.old_n.golosa \
	 experimentacion.ej3.tabu.iter_n.down_n.old_n2.golosa \
	 experimentacion.ej3.tabu.iter_n.down_n2.old_nlogn.golosa \
	 experimentacion.ej3.tabu.iter_n.down_n2.old_n.golosa \
	 experimentacion.ej3.tabu.iter_n.down_n2.old_n2.golosa

EXECUTABLES=graph_generator promedio $(BACKTRACKING) $(GOLOSA) $(BUSQUEDA) $(TABU)

all: $(EXECUTABLES)
backtracking: $(BACKTRACKING)
golosa: $(GOLOSA)
busqueda: $(BUSQUEDA)
generador: graph_generator
tabu: $(TABU)

#Archivos ejecutables
experimentacion.ej2.backtracking: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

experimentacion.ej2.backtracking_golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_BACKTRACKING_GOLOSA -o $@ $^

experimentacion.ej3.golosa.vecinos_no_ordenados: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_GOLOSA -o $@ $^

experimentacion.ej3.golosa.vecinos_ordenados: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_GOLOSA -D_VECINOS_ORDENADOS -o $@ $^

experimentacion.ej3.busqueda.primer_salto: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_BUSQUEDA -o $@ $^

experimentacion.ej3.busqueda.primer_salto_golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_BUSQUEDA_GOLOSA -o $@ $^

experimentacion.ej3.busqueda.primer_salto_intercambiar: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_BUSQUEDA -D_INTERCAMBIAR -o $@ $^

experimentacion.ej3.busqueda.primer_salto_intercambiar_golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_INTERCAMBIAR -D_HEUR_BUSQUEDA_GOLOSA -o $@ $^

experimentacion.ej3.busqueda.mejor_salto: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_BUSQUEDA -D_VECINOS_ORDENADOS -o $@ $^

experimentacion.ej3.busqueda.mejor_salto_golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_HEUR_BUSQUEDA_GOLOSA -o $@ $^

experimentacion.ej3.busqueda.mejor_salto_intercambiar: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_BUSQUEDA -D_VECINOS_ORDENADOS -D_INTERCAMBIAR -o $@ $^

experimentacion.ej3.busqueda.mejor_salto_intercambiar_golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_INTERCAMBIAR -D_HEUR_BUSQUEDA_GOLOSA -o $@ $^

promedio: promedio.cpp
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

graph_generator: graph_generator.cpp random_graphs_generators.cpp $(OGDF)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

$(OGDF):
		cd ../include/OGDF/; python2.7 makeMakefile.py && $(MAKE)

experimentacion.ej3.tabu.iter_nn.down_2n.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_2n.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_2n.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n2.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n2.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n2.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_2n.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n2.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_2n.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_2n.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_2n.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n2.old_nlogn: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n2.old_n: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n2.old_n2: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_2n.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_2n.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_2n.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n2.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n2.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nn.down_n2.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_2n.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_nlogn.down_n2.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_2n.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_2n.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_2n.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n2.old_nlogn.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n2.old_n.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

experimentacion.ej3.tabu.iter_n.down_n2.old_n2.golosa: $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_HEUR_TABU_GOLOSA -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

clean:
		@$(RM) $(EXECUTABLES)
