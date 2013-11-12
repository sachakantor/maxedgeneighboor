CXX=g++
CXXFLAGS=-Wall -O2 -std=c++0x
IDIR=-I../include/
LDFLAGS=
EXTRACXXFLAGS=
SOURCES=
#OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLES=graph_generator promedio

all: $(EXECUTABLES)

#Archivos ejecutables
promedio: promedio.cpp
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

graph_generator: graph_generator.cpp random_graphs_generators.cpp
		$(CXX) $(CXXFLAGS) $(IDIR) $(EXTRACXXFLAGS) -o $@ $^

clean:
		@$(RM) $(EXECUTABLES)
