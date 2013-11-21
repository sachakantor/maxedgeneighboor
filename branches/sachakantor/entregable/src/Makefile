CXX=g++
CXXFLAGS=-Wall -O2 -std=c++0x
IDIR=-I../include/
LDFLAGS=
EXTRACXXFLAGS=
SOURCES=graph.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
BACKTRACKING=ej2.backtracking ej2.backtracking_golosa

GOLOSA=ej3.golosa.vecinos_no_ordenados \
	   ej3.golosa.vecinos_ordenados

BUSQUEDA=ej3.busqueda.primer_salto \
		 ej3.busqueda.primer_salto_golosa \
		 ej3.busqueda.primer_salto_intercambiar \
		 ej3.busqueda.primer_salto_intercambiar_golosa \
		 ej3.busqueda.mejor_salto \
		 ej3.busqueda.mejor_salto_golosa \
		 ej3.busqueda.mejor_salto_intercambiar \
		 ej3.busqueda.mejor_salto_intercambiar_golosa

TABU_IMPROVES=ej3.tabu.iter_nlogn.down_2n.old_nlogn \
			  ej3.tabu.iter_nlogn.down_2n.old_n \
			  ej3.tabu.iter_nlogn.down_2n.old_n2 \
			  ej3.tabu.iter_nlogn.down_n.old_nlogn \
			  ej3.tabu.iter_nlogn.down_n.old_n \
			  ej3.tabu.iter_nlogn.down_n.old_n2 \
			  ej3.tabu.iter_nlogn.down_n2.old_nlogn \
			  ej3.tabu.iter_nlogn.down_n2.old_n \
			  ej3.tabu.iter_nlogn.down_n2.old_n2 \
			  ej3.tabu.iter_n.down_2n.old_nlogn \
			  ej3.tabu.iter_n.down_2n.old_n \
			  ej3.tabu.iter_n.down_2n.old_n2 \
			  ej3.tabu.iter_n.down_n.old_nlogn \
			  ej3.tabu.iter_n.down_n.old_n \
			  ej3.tabu.iter_n.down_n.old_n2 \
			  ej3.tabu.iter_n.down_n2.old_nlogn \
			  ej3.tabu.iter_n.down_n2.old_n \
			  ej3.tabu.iter_n.down_n2.old_n2 \
			  ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa \
			  ej3.tabu.iter_nlogn.down_2n.old_n.golosa \
			  ej3.tabu.iter_nlogn.down_2n.old_n2.golosa \
			  ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa \
			  ej3.tabu.iter_nlogn.down_n.old_n.golosa \
			  ej3.tabu.iter_nlogn.down_n.old_n2.golosa \
			  ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa \
			  ej3.tabu.iter_nlogn.down_n2.old_n.golosa \
			  ej3.tabu.iter_nlogn.down_n2.old_n2.golosa \
			  ej3.tabu.iter_n.down_2n.old_nlogn.golosa \
			  ej3.tabu.iter_n.down_2n.old_n.golosa \
			  ej3.tabu.iter_n.down_2n.old_n2.golosa \
			  ej3.tabu.iter_n.down_n.old_nlogn.golosa \
			  ej3.tabu.iter_n.down_n.old_n.golosa \
			  ej3.tabu.iter_n.down_n.old_n2.golosa \
			  ej3.tabu.iter_n.down_n2.old_nlogn.golosa \
			  ej3.tabu.iter_n.down_n2.old_n.golosa \
			  ej3.tabu.iter_n.down_n2.old_n2.golosa

TABU_NO_IMPROVES=ej3.tabu.iter_nlogn.down_2n.old_nlogn.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_2n.old_n.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_2n.old_n2.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n.old_nlogn.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n2.old_nlogn.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves \
				 ej3.tabu.iter_n.down_2n.old_nlogn.tabu_no_improves \
				 ej3.tabu.iter_n.down_2n.old_n.tabu_no_improves \
				 ej3.tabu.iter_n.down_2n.old_n2.tabu_no_improves \
				 ej3.tabu.iter_n.down_n.old_nlogn.tabu_no_improves \
				 ej3.tabu.iter_n.down_n.old_n.tabu_no_improves \
				 ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves \
				 ej3.tabu.iter_n.down_n2.old_nlogn.tabu_no_improves \
				 ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves \
				 ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_2n.old_n.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_2n.old_n2.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n.old_n.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n.old_n2.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n2.old_n.golosa.tabu_no_improves \
				 ej3.tabu.iter_nlogn.down_n2.old_n2.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_2n.old_nlogn.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_2n.old_n.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_2n.old_n2.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_n.old_nlogn.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_n.old_n.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_n2.old_nlogn.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_n2.old_n.golosa.tabu_no_improves \
				 ej3.tabu.iter_n.down_n2.old_n2.golosa.tabu_no_improves

TABU_NO_IMPROVES_ASPIRATION=ej3.tabu.iter_nlogn.down_2n.old_nlogn.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_2n.old_n.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_2n.old_n2.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n.old_nlogn.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n2.old_nlogn.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_2n.old_nlogn.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_2n.old_n.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_2n.old_n2.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n.old_nlogn.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n.old_n.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n2.old_nlogn.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_2n.old_n.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_2n.old_n2.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n.old_n.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n.old_n2.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n2.old_n.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_nlogn.down_n2.old_n2.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_2n.old_nlogn.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_2n.old_n.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_2n.old_n2.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n.old_nlogn.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n.old_n.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n2.old_nlogn.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n2.old_n.golosa.tabu_no_improves.aspiration \
							ej3.tabu.iter_n.down_n2.old_n2.golosa.tabu_no_improves.aspiration

TABU=$(TABU_IMPROVES) $(TABU_NO_IMPROVES) $(TABU_NO_IMPROVES_ASPIRATION)

EJ2_EXECUTABLES=$(BACKTRACKING)
EJ3_EXECUTABLES=$(GOLOSA) $(BUSQUEDA) $(TABU)
EXECUTABLES=$(EJ2_EXECUTABLES) $(EJ3_EXECUTABLES) $(GRAPHS_GENERATOR)

all: $(EXECUTABLES)
backtracking: $(BACKTRACKING)
golosa: $(GOLOSA)
busqueda: $(BUSQUEDA)
tabu: $(TABU)
tabu_improves: $(TABU_IMPROVES)
tabu_no_improves: $(TABU_NO_IMPROVES)
tabu_no_improves_aspiration: $(TABU_NO_IMPROVES_ASPIRATION)

#Archivos ejecutables
ej2.backtracking: ej2.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

ej2.backtracking_golosa: ej2.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_BACKTRACKING_GOLOSA -o $@ $^

ej3.golosa.vecinos_no_ordenados: ej3_constructiva_golosa.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

ej3.golosa.vecinos_ordenados: ej3_constructiva_golosa.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -o $@ $^

ej3.busqueda.primer_salto: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

ej3.busqueda.primer_salto_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_GOLOSA -o $@ $^

ej3.busqueda.primer_salto_intercambiar: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_INTERCAMBIAR -o $@ $^

ej3.busqueda.primer_salto_intercambiar_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_INTERCAMBIAR -D_GOLOSA -o $@ $^

ej3.busqueda.mejor_salto: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -o $@ $^

ej3.busqueda.mejor_salto_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_GOLOSA -o $@ $^

ej3.busqueda.mejor_salto_intercambiar: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_INTERCAMBIAR -o $@ $^

ej3.busqueda.mejor_salto_intercambiar_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_INTERCAMBIAR -D_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_nlogn: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n2: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_nlogn: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n2: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_nlogn: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n2: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

ej3.tabu.iter_n.down_2n.old_nlogn: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

ej3.tabu.iter_n.down_2n.old_n: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

ej3.tabu.iter_n.down_2n.old_n2: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

ej3.tabu.iter_n.down_n.old_nlogn: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

ej3.tabu.iter_n.down_n.old_n: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

ej3.tabu.iter_n.down_n.old_n2: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

ej3.tabu.iter_n.down_n2.old_nlogn: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -o $@ $^

ej3.tabu.iter_n.down_n2.old_n: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -o $@ $^

ej3.tabu.iter_n.down_n2.old_n2: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n2.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n2.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n2.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_2n.old_nlogn.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_2n.old_n.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_2n.old_n2.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_n.old_nlogn.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_n.old_n.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_n.old_n2.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_n2.old_nlogn.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_n2.old_n.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_n.down_n2.old_n2.golosa: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_nlogn.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n2.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_nlogn.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_nlogn.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_2n.old_nlogn.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_2n.old_n.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_2n.old_n2.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n.old_nlogn.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n.old_n.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n2.old_nlogn.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n2.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n2.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n2.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_2n.old_nlogn.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_2n.old_n.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_2n.old_n2.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n.old_nlogn.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n.old_n.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n2.old_nlogn.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n2.old_n.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_n.down_n2.old_n2.golosa.tabu_no_improves: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_nlogn.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n2.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_nlogn.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_nlogn.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_2n.old_nlogn.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_2n.old_n.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_2n.old_n2.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n.old_nlogn.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n.old_n.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n2.old_nlogn.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_nlogn.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_2n.old_n2.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_nlogn.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n.old_n2.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_nlogn.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_nlogn.down_n2.old_n2.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n*log2(n)" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_2n.old_nlogn.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_2n.old_n.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_2n.old_n2.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="2*n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n.old_nlogn.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n.old_n.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n2.old_nlogn.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n*log2(n)" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n2.old_n.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

ej3.tabu.iter_n.down_n2.old_n2.golosa.tabu_no_improves.aspiration: ej3_tabu_search.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_TABU_GLOBAL_COUNTER="n" -D_TABU_GOING_DOWN_COUNTER="n/2" -D_TABU_HOW_OLD_COUNTER="n/2" -D_TABU_GOLOSA -D_TABU_NO_IMPROVE -D_ASPIRATION -o $@ $^

clean:
		@$(RM) $(EXECUTABLES)
