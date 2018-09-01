set grid
set key font ",9"
#set key off
set key below horizontal
#set key at 3250,80
#set terminal pdf
set terminal epslatex color
#set title "Tiempo de ejecucion conforme aumenta la cantidad de nodos"
set title "Frontera obtenida segun cantidad de nodos"

#set output "ej4_nodos.pdf"
#set output "ej4_nodos_connected_sparse.tex"
set output "ej4_frontera_connected_sparse.tex"
#set output "ej4_nodos_tree.tex"
#set yrange [100:500000]
#set xrange [1500:5000]
set xlabel "Cantidad de Nodos\n(Escala Lineal)"
set ylabel "Frontera\n(Escala Lineal)"
#set ylabel "Tiempo (microsegundos)\n(Escala Logaritmica)"
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

plot "ej2.backtracking.connected_sparse.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Algoritmo Exacto" with lines,\
    "ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.connected_sparse.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Tabu(n,n,n/2,golosa,sin aspiracion)" with lines,\
    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.connected_sparse.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Tabu(n,n,n/2)" with lines,\
    "ej3.busqueda.mejor_salto_intercambiar.connected_sparse.out.sorted_by_nodes.average.gnuplot" using 1:3 title "BL(mejor vecino,intercambio)" with lines,\
    "ej3.golosa.vecinos_no_ordenados.connected_sparse.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Golosa" with lines

#plot "ej2.backtracking.connected_regular.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Algoritmo Exacto (Regular)" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.connected_regular.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Tabu(n,n,n/2) (golosa,sin aspiracion,regular)" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.connected_regular.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Tabu(n,n,n/2,regular)" with lines,\
#    "ej3.busqueda.mejor_salto_intercambiar.connected_regular.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "BL (mejor vecino,intercambio,regular)" with lines,\
#    "ej3.golosa.vecinos_no_ordenados.connected_regular.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Golosa (regular)" with lines

#plot "ej2.backtracking.connected_dense.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Algoritmo Exacto (Denso)" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.connected_dense.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Tabu(n,n,n/2) (golosa,sin aspiracion,denso)" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.connected_dense.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Tabu(n,n,n/2,denso)" with lines,\
#    "ej3.busqueda.mejor_salto_intercambiar.connected_dense.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "BL (mejor vecino,intercambio,denso)" with lines,\
#    "ej3.golosa.vecinos_no_ordenados.connected_dense.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Golosa (denso)" with lines


#plot "ej2.backtracking.tree.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Algoritmo Exacto" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.tree.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Tabu(n,n,n/2) (golosa,sin aspiracion)" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.tree.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Tabu(n,n,n/2)" with lines,\
#    "ej3.busqueda.mejor_salto_intercambiar.tree.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "BL (mejor vecino,intercambio)" with lines,\
#    "ej3.golosa.vecinos_no_ordenados.tree.out.sorted_by_nodes.average.gnuplot" using 1:($5*1000000) title "Golosa" with lines

#plot "ej2.backtracking.tree.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Algoritmo Exacto" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.golosa.tabu_no_improves.tree.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Tabu(n,n,n/2) (golosa,sin aspiracion)" with lines,\
#    "ej3.tabu.iter_n.down_n.old_n2.tabu_no_improves.aspiration.tree.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Tabu(n,n,n/2)" with lines,\
#    "ej3.busqueda.mejor_salto_intercambiar.tree.out.sorted_by_nodes.average.gnuplot" using 1:3 title "BL (mejor vecino,intercambio)" with lines,\
#    "ej3.golosa.vecinos_no_ordenados.tree.out.sorted_by_nodes.average.gnuplot" using 1:3 title "Golosa" with lines

set out
