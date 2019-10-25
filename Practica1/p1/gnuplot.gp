#!/bin/usr/gnuplot

# Ejercicio 1
# set term png
# set output "burbuja.png"

# set xlabel "Tamaño de elementos a ordenar (n)"
# set ylabel "Tiempo (s)

# plot "tiempos_ordenacion_burbuja.dat" title "Ordenacion Burbuja Empirico" 



# Ejercicio 2
# set term png
# set output "burbuja_ajuste.png"

# set xlabel "Tamaño de elementos a ordenar (n)"
# set ylabel "Tiempo (s)

# f(x)=a*x**2+b*x+c
# fit f(x) "tiempos_ordenacion_burbuja.dat" via a,b,c

# plot "tiempos_ordenacion_burbuja.dat", f(x) title "Ordenacion Burbuja Empirico" 


# Ejercicio 3
set term png
set output "desc.png"

set xlabel "Tamaño de elementos a ordenar (n)"
set ylabel "Tiempo (s)


plot "tiempos_desc.dat" title "Busqueda Binaria"

