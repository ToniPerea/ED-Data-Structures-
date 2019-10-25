all: ej3

ej1:
	g++ ordenacion_burbuja.cpp -o ordenacion_burbuja
	tcsh ejecuciones_burbuja.csh
	gnuplot gnuplot.gp

ej3:
	g++ ejercicio_desc.cpp -o ejercicio_desc
	tcsh ejecuciones_desc.csh
	gnuplot gnuplot.gp

clean:
	rm -f ordenacion_burbuja tiempos_ordenacion.dat ordenacion_burbuja tiempos_ordenacion_burbuja.dat  ejercicio_desc tiempos_desc.dat
