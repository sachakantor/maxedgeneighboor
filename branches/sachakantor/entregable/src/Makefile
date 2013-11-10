CXX=g++
CXXFLAGS=-Wall -O2 -std=c++0x
IDIR=-I../include/
LDFLAGS=
EXTRACXXFLAGS=
SOURCES=graph.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
BACKTRACKING=ej2

GOLOSA=ej3_constructiva_golosa_vecinos_no_ordenados \
	   ej3_constructiva_golosa_vecinos_ordenados

BUSQUEDA=ej3_busqueda_local_primer_salto \
		 ej3_busqueda_local_primer_salto_golosa \
		 ej3_busqueda_local_primer_salto_intercambiar \
		 ej3_busqueda_local_primer_salto_intercambiar_golosa \
		 ej3_busqueda_local_mejor_salto \
		 ej3_busqueda_local_mejor_salto_golosa \
		 ej3_busqueda_local_mejor_salto_intercambiar \
		 ej3_busqueda_local_mejor_salto_intercambiar_golosa

#TABU=

EJ2_EXECUTABLES=$(BACKTRACKING)
EJ3_EXECUTABLES=$(GOLOSA) $(BUSQUEDA)# $(TABU)
EXECUTABLES=$(EJ2_EXECUTABLES) $(EJ3_EXECUTABLES)

all: $(EXECUTABLES)
backtracking: $(BACKTRACKING)
golosa: $(GOLOSA)
busqueda: $(BUSQUEDA)
#tabu: $(TABU)

#Archivos ejecutables
ej2: ej2.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

ej3_constructiva_golosa_vecinos_no_ordenados: ej3_constructiva_golosa.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

ej3_constructiva_golosa_vecinos_ordenados: ej3_constructiva_golosa.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -o $@ $^

ej3_busqueda_local_primer_salto: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

ej3_busqueda_local_primer_salto_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_GOLOSA -o $@ $^

ej3_busqueda_local_primer_salto_intercambiar: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_INTERCAMBIAR -o $@ $^

ej3_busqueda_local_primer_salto_intercambiar_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_INTERCAMBIAR -D_GOLOSA -o $@ $^

ej3_busqueda_local_mejor_salto: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -o $@ $^

ej3_busqueda_local_mejor_salto_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_GOLOSA -o $@ $^

ej3_busqueda_local_mejor_salto_intercambiar: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_INTERCAMBIAR -o $@ $^

ej3_busqueda_local_mejor_salto_intercambiar_golosa: ej3_busqueda_local.cpp $(SOURCES)
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -D_VECINOS_ORDENADOS -D_INTERCAMBIAR -D_GOLOSA -o $@ $^

clean:
		@$(RM) $(EXECUTABLES)
