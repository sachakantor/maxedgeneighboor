set grid
set key font ",9"
#set key off
set key below horizontal
#set key at 3250,80
#set terminal pdf
set terminal epslatex color
#set title "Tiempo de ejecucion conforme aumenta la cantidad de nodos"
set title "Frontera obtenida segun cantidad de nodos"

#set output "ej3_nodos.pdf"
set output "ej3_frontera_star_bridge_double_star.tex"
#set output "ej3_nodos_n_complete_bipartite.tex"
#set output "ej3_nodos_nlogn_star+bridge+double_star_sin_aspiracion_golosa.tex"
#set output "ej3_nodos_n_star+bridge+double_star_sin_aspiracion_golosa.tex"
set yrange [1:10]
#set xrange [1:5000]
set xlabel "Cantidad de Nodos\n(Escala Lineal)"
set ylabel "Frontera\n(Escala Lineal)"
#set ylabel "Tiempo (microsegundos)\n(Escala Lineal)"
#set ylabel "Tiempo ($microsegundos^{\\sfrac{1}{5}}$)\n(Escala Lineal)"
#set   autoscal
#set logscale x
#set logscale y
#set xtics 1
#set key samplen 10

#Lineal
#f(n) = 40 +n/600
#g(n) = n

#Polinomial
#f(n) = (n**3)*log(n)/50000 + 250000
#g(n) = (n**3)/100000 +250000

#Logaritmico
#f(n) = 
#g(n) = +600 + n*(log10(n)/log(131072))

#Exponencial
#f(n) = (n/100000000**2)*2**n

#plot "ej3.tabu.iter_nlogn.down_n.old_n.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n" with lines lw 10,\
#    "ej3.tabu.iter_nlogn.down_n.old_n2.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n2" with lines lw 9,\
#    "ej3.tabu.iter_nlogn.down_n2.old_n.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n" with lines lw 8,\
#    "ej3.tabu.iter_nlogn.down_n2.old_n2.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n2" with lines lw 7,\
#    "ej3.tabu.iter_n.down_n.old_n.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n" with lines lw 6,\
#    "ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n2" with lines lw 5,\
#    "ej3.tabu.iter_n.down_n2.old_n.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n" with lines lw 4,\
#    "ej3.tabu.iter_n.down_n2.old_n2.golosa.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n2" with lines lw 3,\
#    6 title "Solucion optima" with lines lw 3

#plot "ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n" with lines lw 10,\
#    "ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n2" with lines lw 9,\
#    "ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n" with lines lw 8,\
#    "ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n2" with lines lw 7,\
#    "ej3.tabu.iter_n.down_n.old_n.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n" with lines lw 6,\
#    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n2" with lines lw 5,\
#    "ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n" with lines lw 4,\
#    "ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n2" with lines lw 3,\
#    6 title "Solucion optima" with lines lw 3

plot "ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n" with lines lw 10,\
    "ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n2" with lines lw 9,\
    "ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n" with lines lw 8,\
    "ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n2" with lines lw 7,\
    "ej3.tabu.iter_n.down_n.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n" with lines lw 6,\
    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n2" with lines lw 5,\
    "ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n" with lines lw 4,\
    "ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n2" with lines lw 3,\
    6 title "Solucion optima" with lines lw 3

    #f(x) title "Cota teórica superior $\\mathcal O(n)$" with lines lw 6
    #f(x) title "Cota teórica superior $\\mathcal O(n)$" with linespoints lw 6
#    f(x) title "Cota teórica superior $\\mathcal O(n^3 \\cdot log(n))$" with lines lw 6
#    g(x) title "Cota teórica superior $\\mathcal O(n^3)$" with lines lw 6

    #g(x) title "Cota teórica superior $\\mathcal O(n^5)$" with lines lw 6

    #TABU COMPLEJIDAD
    #plot "ej3.tabu.iter_nlogn.down_n.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n" with lines,\
    #    "ej3.tabu.iter_nlogn.down_n.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=nlog(n),Sin Mejorar=n,Tiempo Tabu=n2" with lines,\
    #    "ej3.tabu.iter_nlogn.down_n2.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n" with lines,\
    #    "ej3.tabu.iter_nlogn.down_n2.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=nlog(n),Sin Mejorar=n2,Tiempo Tabu=n2" with lines,\
    #    f(x) title "Cota teórica superior $\\mathcal O(n^3 \\cdot log(n))$" with lines lw 6

    #plot "ej3.tabu.iter_n.down_n.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n" with lines,\
    #    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=n,Sin Mejorar=n,Tiempo Tabu=n2" with lines,\
    #    "ej3.tabu.iter_n.down_n2.old_n.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n" with lines,\
    #    "ej3.tabu.iter_n.down_n2.old_n2.tabu_no_improves.aspiration.star_bridge_double_star.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Iter=n,Sin Mejorar=n2,Tiempo Tabu=n2" with lines,\
    #    g(x) title "Cota teórica superior $\\mathcal O(n^3)$" with lines lw 6

    #BUSQUEDA LOCAL FRONTERA
    #"ej3.busqueda.primer_salto.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino" with linespoints,\
    #"ej3.busqueda.primer_salto_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino con golosa" with linespoints,\
    #"ej3.busqueda.primer_salto_intercambiar.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino con intercambio" with linespoints,\
    #"ej3.busqueda.primer_salto_intercambiar_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Primer Vecino con intercambio y golosa" with linespoints,\
    #"ej3.busqueda.mejor_salto.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino" with linespoints,\
    #"ej3.busqueda.mejor_salto_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino con golosa" with linespoints,\
    #"ej3.busqueda.mejor_salto_intercambiar.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino con intercambio" with linespoints,\
    #"ej3.busqueda.mejor_salto_intercambiar_golosa.star_cmf.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Mejor Vecino con intercambio y golosa" with linespoints

    #BUSQUEDA LOCAL COMPLEJIDAD
    #"ej3.busqueda.primer_salto.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino" with linespoints,\
    #"ej3.busqueda.primer_salto_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino con golosa" with linespoints,\
    #"ej3.busqueda.primer_salto_intercambiar.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino con intercambio" with linespoints,\
    #"ej3.busqueda.primer_salto_intercambiar_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/4)) title "Primer Vecino con intercambio y golosa" with linespoints,\
    #"ej3.busqueda.mejor_salto.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino" with linespoints,\
    #"ej3.busqueda.mejor_salto_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino con golosa" with linespoints,\
    #"ej3.busqueda.mejor_salto_intercambiar.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino con intercambio" with linespoints,\
    #"ej3.busqueda.mejor_salto_intercambiar_golosa.banana.out.sorted_by_nodes.average.gnuplot" using 1:(($5*1000000000)**(1.0/5)) title "Mejor Vecino con intercambio y golosa" with linespoints,\

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
