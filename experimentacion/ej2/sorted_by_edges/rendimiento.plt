set grid
set key font ",9"
set key bottom right
#set key below
#set key horizontal
#set terminal pdf
set terminal epslatex color
set title "Tiempo de ejecución conforme aumenta la cantidad de ejes"

set output "ej2_ejes_golosa.tex"
#set yrange [1:1000000]
#set xrange [1:3000]
set xlabel "Cantidad de ejes\n(Escala Logaritmica)"
set ylabel "Tiempo (milisegundos)\n(Escala Logaritmica)"
#set   autoscale
set logscale x
set logscale y
#set xtics 1
#set key samplen 10

#Lineal
#f(n) = n
#g(n) = n/400 + 3

#Polinomial
#f(n) = n**5
#g(n) = ((n/10)**5)

#Logaritmico
#f(n) = -500 + n*(log10(n)/log(131072))
#g(n) = +600 + n*(log10(n)/log(131072))

#Exponencial
f(n) = (n/1000000**10)*(2**n)

#plot "ejercicio2.complejidad.familia2.lst" using 1:($2*1000000) title "Familia 2" with lines lt 1 lw 1,\
#	"ejercicio2.complejidad.familia3.lst" using 1:($2*1000000) title "Familia 3" with lines lt 2 lw 1,\
#	"ejercicio2.complejidad.familia4.lst" using 1:($2*1000000) title "Familia 4" with lines lt 3 lw 1,\
#	f(x) title "Cota teórica inferior Omega(nlog(n))" with lines lt 4 lw 6 ,\
#	g(x) title "Cota teórica superior O(nlog(n))" with lines lt 5 lw 6

plot "ej2.backtracking_golosa.connected_sparse.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Poco denso (Golosa)" with lines,\
    "ej2.backtracking_golosa.connected_regular.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Regular (Golosa)" with lines,\
    "ej2.backtracking_golosa.connected_dense.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Denso (Golosa)" with lines

    #"ej2.backtracking_golosa.connected_sparse.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Poco denso (Golosa)" with lines,\
    #"ej2.backtracking.connected_regular.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Regular" with lines,\
    #"ej2.backtracking_golosa.connected_regular.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Regular (Golosa)" with lines,\
    #"ej2.backtracking.connected_dense.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Denso" with lines,\
    #"ej2.backtracking_golosa.connected_dense.out.sorted_by_edges.edges_first.average" using 1:($5*1000) title "Denso (Golosa)" with lines#,\
    #f(x) title "Cota teórica superior $\\mathcal O(n \\cdot 2^n)$" with lines lt 5 lw 6

set out
