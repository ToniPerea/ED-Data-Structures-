#ifndef __COLA_MAX_VD__H
#define __COLA_MAX_VD__H

#include "VD.hpp"
#include <iostream>
using namespace std;

/**
 * @brief T.D.A Cola_max
 * Una instancia @e c del tipo de datos abstracto @c Cola_max es una estructura lineal de datos del tipo T (clase plantilla) con las operaciones necesarias para trabajar con ellos.
 *
 * @autor Antonio Carlos Perea Parras
 * @date Noviembre 2018
 */
template <class T>
class Cola_max{
private:
    /**
	 * @page repConjunto Rep del TDA Cola_max
	 *
	 * @section invConjunto Invariante de la representación
	 * El invariante es r.n < r.reservados
	 *
	 * @section faConjunto función de abstracción
	 *
	 *
	 */
    VD<T> datos;
    int posInicioCola;
    int posFinCola;
    int posMaximoCola;

public:
    /**
	* @brief Constructor por defecto
	*/
    Cola_max();

    /**
	* @brief Poner un elemento en la cola
	* @param x: elemento a introducir en la cola
	*/
    void poner(const T & ele_a_insertar);

    /**
	 * @brief Devuelve el número de elementos existentes en la cola
	 * @return s: número de elementos existentes en cola
	 */
    unsigned int num_elementos();

    /**
	* @brief Devolver el maximo elmento de la cola
	* @return m: elemento máximo introducido en la cola
	*/
    T maximo();

    /**
	* @brief Devuelve si la cola está vacía o no
	* @param v: la condición de vacía
	*/
    bool vacia();

    /**
	* @brief Quita un elemento del frente de la cola
	*/
    void quitar();

    /**
	* @brief Devuelve el elemento que hay al frente de la cola
	* @return f: elemento al frente de la cola
	*/
    T frente();

};

#include "../src/Cola_max_vd.cpp"

#endif
