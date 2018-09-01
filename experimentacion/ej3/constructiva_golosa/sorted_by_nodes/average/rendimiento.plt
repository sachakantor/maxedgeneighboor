set grid
set key font ",9"
#set key top left
set key below
set key horizontal
#set terminal pdf
set terminal epslatex color
set title "Tiempo de ejecución conforme aumenta la cantidad de nodos"

set output "ej3_nodos_disruptivas.tex"
#set yrange [1:1000000]
#set xrange [1:3000]
set xlabel "Cantidad de Nodos\n(Escala Lineal)"
set ylabel "Tiempo (microsegundos)\n(Escala Lineal)"
#set   autoscale
#set logscale x
#set logscale y
#set xtics 1
#set key samplen 10

#Lineal
#f(n) = n/80 + 10
#g(n) = n*2

#Polinomial
f(n) = (n**2)/60000
#g(n) = ((n/10)**5)

#Logaritmico
#f(n) = -500 + n*(log10(n)/log(131072))
#g(n) = +600 + n*(log10(n)/log(131072))

#Exponencial
#f(n) = (n/100000000**2)*2**n

plot "ej3.golosa.star_cmf.gnuplot" using 1:($5*1000000) title "Estrella+CMF" with linespoints,\
    "ej3.golosa.star_bridge_cmf.gnuplot" using 1:($5*1000000) title "Estrella+Puente+CMF" with linespoints,\
    f(x) title "Cota teórica superior $\\mathcal O(n^2)$" with lines lw 6

    #g(x) title "Cota teórica superior $\\mathcal O(n)$" with lines lw 6

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
set out
