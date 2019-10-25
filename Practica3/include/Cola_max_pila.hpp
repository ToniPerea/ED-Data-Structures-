// Cola_max.cpp
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<typename T>

/**
 * @brief T.D.A Cola_max
 * Una instancia @e c del tipo de datos abstracto @c Cola_max es una estructura lineal de datos del tipo T (clase plantilla) con las operaciones necesarias para trabajar con ellos.
 *
 * @autor Antonio Carlos Perea Parras
 * @date Noviembre 2018
 */
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
	stack<T> _stack1;
	stack<T> _stack2;
    T maximoElemento;
public:
	/**
	* @brief Constructor por defecto
	*/
	Cola_max();

	/**
	* @brief Poner un elemento en la cola
	* @param x: elemento a introducir en la cola
	*/
	void poner(const T&x);

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
	T& frente();

};

#include "../src/Cola_max_pila.cpp"