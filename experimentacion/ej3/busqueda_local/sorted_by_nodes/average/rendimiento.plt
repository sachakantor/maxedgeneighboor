set grid
set key font ",9"
set key off
set key below horizontal
#set key at 3250,80
#set key horizontal
#set terminal pdf
set terminal epslatex color
#set title "Tiempo de ejecución conforme aumenta la cantidad de nodos"
set title "Relacion Frontera/Nodos"

#set output "ej3_nodos.pdf"
set output "ej3_frontera_star+cmf.tex"
#set yrange [1:80]
#set xrange [1500:5000]
set xlabel "Cantidad de Nodos\n(Escala Lineal)"
set ylabel "Frontera\n(Escala Logaritmica)"
#set ylabel "Tiempo ($nanosegundos^{\\sfrac{1}{5}}$)\n(Escala Lineal)"
#set   autoscale
#set logscale x
set logscale y
#set xtics 1
#set key samplen 10

#Lineal
f(n) = 40 +n/600
g(n) = n

#Polinomial
#f(n) = (n**4)/10000000
#g(n) = (n**5)/10000000

#Logaritmico
#f(n) = -500 + n*(log10(n)/log(131072))
#g(n) = +600 + n*(log10(n)/log(131072))

#Exponencial
#f(n) = (n/100000000**2)*2**n

plot "ej3.busqueda.primer_salto.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino" with linespoints,\
    "ej3.busqueda.primer_salto_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino con golosa" with linespoints,\
    "ej3.busqueda.primer_salto_intercambiar.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino con intercambio" with linespoints,\
    "ej3.busqueda.primer_salto_intercambiar_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino con intercambio y golosa" with linespoints,\
    "ej3.busqueda.mejor_salto.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino" with linespoints,\
    "ej3.busqueda.mejor_salto_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino con golosa" with linespoints,\
    "ej3.busqueda.mejor_salto_intercambiar.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino con intercambio" with linespoints,\
    "ej3.busqueda.mejor_salto_intercambiar_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino con intercambio y golosa" with linespoints

    #f(x) title "Cota teórica superior $\\mathcal O(n)$" with linespoints lw 6

    #g(x) title "Cota teórica superior $\\mathcal O(n^5)$" with lines lw 6

    #BUSQUEDA LOCAL
    #"ej3.busqueda.primer_salto.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino" with linespoints,\
    #"ej3.busqueda.primer_salto_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino con golosa" with linespoints,\
    #"ej3.busqueda.primer_salto_intercambiar.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino con intercambio" with linespoints,\
    #"ej3.busqueda.primer_salto_intercambiar_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino con intercambio y golosa" with linespoints,\
    #"ej3.busqueda.mejor_salto.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino" with linespoints,\
    #"ej3.busqueda.mejor_salto_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino con golosa" with linespoints,\
    #"ej3.busqueda.mejor_salto_intercambiar.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino con intercambio" with linespoints,\
    #"ej3.busqueda.mejor_salto_intercambiar_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino con intercambio y golosa" with linespoints,\
    f(x) title "Cota teórica superior $\\mathcal O(n)$" with lines lw 6

    ##GOLOSA##
    #"ej3.golosa.star_cmf.gnuplot" using 1:($5*1000000) title "Estrella+CMF" with linespoints,\
    #"ej3.golosa.star_bridge_cmf.gnuplot" using 1:($5*1000000) title "Estrella+Puente+CMF" with linespoints,\
    #"ej3.golosa.star.gnuplot" using 1:($5*1000000) title "Estrellas" with linespoints,\
    #"ej3.golosa.wheel.gnuplot" using 1:($5*1000000) title "Ruedas" with linespoints,\
    #"ej3.golosa.banana.gnuplot" using 1:($5*1000000) title "Banana Tree" with linespoints,\
    #"ej3.golosa.connected_bipartite.gnuplot" using 1:($5*1000000) title "Bipartitos" with linespoints,\
    #"ej3.golosa.tree.gnuplot" using 1:($5*1000000000) title "Arboles" with linespoints,\
    #"ej3.golosa.hole.gnuplot" using 1:($5*1000000000) title "Circulares" with linespoints,\
    #"ej3.golosa.complete.gnuplot" using 1:($5*1000000000) title "Grafos Completos" with linespoints,\
    #g(x) title "Cota teórica superior $\\mathcal O(n)$" with lines lw 6
set out
