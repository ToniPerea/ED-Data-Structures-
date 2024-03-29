// file VD.hpp
#ifndef __VD
#define __VD

#include <iostream>
using namespace std;


/**
 * @brief T.D.A Vector dinámico
 * Una instancia @e c del tipo de datos abstracto @c VD es una estructura lineal de datos del tipo T ( clase plantilla) con las operaciones necesarias para trabajar con ellos.
 *
 * @autor Antonio Carlos Perea Parras
 * @date Octubre 2018
 */

template <class T>
class VD{
 private:
  /**
   * @page repConjunto Rep del TDA Vector Dinámico
   *
   * @section invConjunto Invariante de la representación
   * El invariante es r.n < r.reservados
   *
   * @section faConjunto función de abstracción
   *
   *
   */
  T *datos ;
  int n ;
  int reservados ;
  void resize(int nuevotam);
  void Copiar(const VD<T> &v);
  void Liberar();
 public:
  /**
   * @brief Constructor por defecto con parámetro
   * @param tam: elementos a reservar para el vector dinámico
   * @note si no se proporciona un valor, toma 10 por defecto.
   */

  VD(int tam = 10) ;

  /**
   * @brief Constructor de copia
   * @param original: vector dinamico de origen
   */

  VD(const VD<T> &original) ;

  /**
   * @brief Destructor: elimina la memoria asociada al VD
   */
  ~VD();

  /**
   * @brief Operador de asignación
   * @param v: vector dinámico fuente
   * @return una ferencia al objeto al que apunta this
   */
  VD<T> &operator=(const VD<T> &v);
  /**
   * @brief Obtiene el número de elementos almacenados en el vector dinámico.
   */
  unsigned size() const { return (unsigned)n ; }

  /**
   * @brief Consulta y modifica el elemento i-esimo
   * @param i: posición del elemento
   * @return una referencia al elemento i-esimo del vector dinamico
   */

   T &operator[](int i){ return datos[i] ;}
   const T &operator[](int i) const {return datos[i] ;}

   /**
    * @brief Inserta un objeto en la posición pos del VD.
    * @param d: objeto a insertar
    * @param pos: posición donde insertar
    * @pre pos debe estar comprendido entre 0 y size()
    * @post aumenta en uno el vector dinámico
    */
   void Insertar(const T &d, int pos);

   /**
    * @brief Elimina el elemento en la posición post
    * @param pos: posición del elemento a borrar.
    */

   void Borrar(int pos) ;

   bool buscar( T& elemento) ; 

   friend ostream & operator<<(ostream & os, VD<T> & v){
        for(int i = 0; i < v.size(); i++){
            os << v[i] << " ";
        }
        os << "\n";
        return os;
    }

} ;


#include "../src/VD.cpp"



#endif 