/**
 * @file Termino.h
 * @author Alejandro Menor (alexmenor@correo.ugr.es)
 * @brief Fichero cabecera del TDA Termino
 * @date 21-10-2018
 * 
 */

#ifndef TERMINO
#define TERMINO

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief T.D.A. Termino
 * 
 * El tipo de datos abstracto término, representa una
 * relación entre una palabra sus significados o 
 * definiciones.
 * Puede estar vacio (no tener palabra que representar) 
 * 
 * Este estado se puede consultar por el método vacio().
 * 
 * Además, puede contener una palabra pero no definiciones.
 * 
 * Un término se representa como una entrada de diccionario:
 * Palabra: 0 ... 1 
 * Definiciónes 0 ... n
 * 
 * Se almacena almacena su palabra y definiciones en
 * memoria dinámica, es mutable.
 * 
 * @author Antonio Carlos Perea Parras
 * @date 21-10-2018
 */

class Termino {
    private:
        /**
         * @page repTermino Rep del TDA Termino
         * @section invTermino Invariante de la representatción
         * 
         * Se debe cumplir:
         * 
         *- Un término no puede contener definiciones
         * sino contiene antes una palabra
         *- El número de palabras de un término es ninguna o una. 
         *- El número de definiciones de un término es como mínimo 0, "sin máximo".
         * 
         * @section faTermino Función de abstracción
         * 
         * Palabra -> Objeto string 
         * Definiciones -> Array de objetos string uno por cada definición
         * 
         * He elegido este tipo rep, pero he considerado usar también una lista
         * enlazada para las definiciones.
         * Ya que no nos va a hacer falta eliminar ni insertar definiciones,
         * solo añadir, por simplicidad he implementado un vector dinámico para alojar
         * las definiciones.
         * 
         */

        string palabra; /**< Palabra del término*/
        string * definiciones; /**<Definiciones*/
        int numDefiniciones; /**<Número de definiciones que contiene término*/
        int definicionesReservadas; /**<Espacio reservado para nuevas definiciones*/

    public:

        /**
         * @brief Constructor por defecto de la clase
         * inicializa un término vacío sin palabra ni definiciones
         * 
         */
        Termino ();

       /**
        * @brief Constructor con dos parámetros
        * inicia un término a una palabra y a una definición
        * @param palabraDada 
        * @param definicion 
        */
        Termino (const string & palabraDada, const string & definicion);

        /**
         * @brief Constructor con un parámetro inicia
         * el término a una palabra, sin definición
         * @param palabraDada 
         */

        Termino (const string & palabraDada);

        /**
         * @brief Constructor de copia
         * 
         * @param aCopiar término a copiar 
         */

        Termino (const Termino & aCopiar);

        /**
         * @brief Consultor de la palabra del término
         * 
         * @return palabra del término 
         */

        string getPalabra() const ;

        /**
         * @brief Junta todas las definiciones en un objeto
         * string y lo devuelve 
         * 
         * @return string con todas las definciones del término 
         */

        string getDefiniciones() const;

        /**
         * @brief Devuelve el número de definiciones que alberga
         * actualmente el término
         * 
         * @return número de definiciones 
         */

        int numeroDefiniciones() const;

        /**
         * @brief Modificador de palabra 
         * 
         * @param palabraDada nueva palabra del término
         */

        void setPalabra(const string & palabraDada);

        /**
         * @brief Especifica si el término tiene o
         * no una palabra
         * 
         * @return true (esta vacío) false (no lo está)
         */

        bool vacio () const;

        /**
         * @brief Añade otra definición al término
         * 
         * @param nuevaDefinicion Definición a añadir 
         */

        void aniadirDefinicion(const string & nuevaDefinicion);

        /**
         * @brief Operador de asignación
         * 
         * @param aCopiar Operador derecho de la asignación 
         * 
         * @return Referencia a termino (concatenación) 
         */

        Termino & operator = (const Termino & aCopiar);

        /**
         * @brief Operador de flujo de salida
         * 
         * @param salida Objeto ostream de salida 
         * @param aImprimir Objeto término a imprimir por el objeto salida 
         * @return Referencia al objeto implícito (concatenación) 
         */

        friend ostream & operator << (ostream & salida, const Termino & aImprimir);

        /**
         * @brief Operador de flujo de entrada
         * 
         * El formato de entrada es:
         * 
         * palabra;definicion
         * 
         * @param entrada Objeto istream de entrada 
         * @param aIntroducir Objeto término a modificar por el flujo de entrada
         * @return Referencia al objeto istream (concatenación) 
         */

        friend istream & operator >> (istream & entrada, Termino & aIntroducir);

        /**
         * @brief Busca una palabra en las definiciones del término
         * 
         * @param palabraClave Palabra a buscar 
         * @return Devuelve true si se encuentra 
         */

        bool contienePalabraClave (string palabraClave) const;

        /**
         * @brief Devuelve la letra inicial de la palabra del término
         * o el carácter nulo, si esta está vacía 
         * 
         * @return Primer carácter de la palabra del término 
         */

        char getLetraInicial () const;

        /**
         * @brief Operador menor
         * 
         * @param aComparar Termino a comparar con el operador izquierdo
         * @return Devuelve true si la palabra del término de la izquierda
         * está antes alfabéticamente hablando que la del término de la derecha
         * del operador
         */

        bool operator < (const Termino & aComparar) const;

        /**
         * @brief Operador igual
         * 
         * @param aComparar Termino a comparar con el operador izquierdo
         * @return Devuelve true si la palabra del término de la izquierda
         * es igual a la del término de la derecha
         */

        bool operator == (const Termino & aComparar) const;

        /**
         * @brief Operador mayor
         * 
         * @param aComparar Termino a comparar con el operador izquierdo
         * @return Devuelve true si la palabra del término de la izquierda
         * está después alfabéticamente hablando que la del término de la derecha
         * del operador
         */

        bool operator > (const Termino & aComparar) const;

        /**
         * @brief Operador suma
         * 
         * @param aSumar Termino de la derecha del operador 
         * @return Devuelve un término copia del término de la izquierda
         * que además contiene las definiciones del de la derecha
         *  
         */

        Termino operator + (const Termino & aSumar) const;

        /**
         * @brief Realiza la misma operación que el operador suma
         * pero modificando el operador de la izquierda, es decir,
         * incorcopora las definiciones del término de la derecha al de la
         * izquierda.
         * @param aSumar Termino de la derecha del operador 
         * @return Referencia al objeto de la izquierda para concatenar operaciones 
         */

        Termino & operator += (const Termino & aSumar);

        /**
         * @brief Destructor de la clase
         * 
         */

        ~Termino();

    private:

        /**
         * @brief Método privado que reserva memoria para un nuevo número de reservados
         * 
         * @param nuevoReservados Nuevo número de reservados, se comprueba que sea mayor o igual
         * que el número de definiciones actuales
         */

        void resizeDefiniciones (int nuevoReservados);

        /**
         * @brief Método privado que libera la memoria reservada por el objeto
         * 
         */

        void liberarMemoria();

        /**
         * @brief aCopiar Método de ayuda privado para copiar los datos
         * de otro objeto término
         * 
         * @param aCopiar Termino del que copiar datos
         * 
         */

        void copiarDatos (const Termino & aCopiar);

        /**
         * @brief Método de ayuda privado usado por los operadores
         * de comparación
         * @param aComparar Termino a comparar con el argumento implícito 
         * @return -1 si el argumento implícito está antes alfabéticamente,
         * 1 si ocurre lo contrario y 0 si son iguales
         */

        int comparar (const Termino & aComparar) const;
};

#endif