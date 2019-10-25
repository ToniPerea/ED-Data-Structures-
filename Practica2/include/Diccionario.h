/**
 * @file Diccionario.h
 * @author Alejandro Menor (alexmenor@correo.ugr.es)
 * @brief Fichero cabecera del TDA Diccionario
 * @date 21-10-2018
 * 
 */

#ifndef DICCIONARIO 
#define DICCIONARIO
#include "Termino.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Struct celda para implementar la
 * lista enlazada de términos en la clase
 * diccionario
 * 
 */

struct Celda{
    Termino dato; /**<Término que contiene cada celda*/
    Celda * sig; /**<Puntero a la siguiente celda*/
};


/**
 * @brief T.D.A. Diccionario
 * 
 * El tipo de datos abstracto Diccionario, representa un
 * conjunto de términos o palabras.
 * 
 * Estos términos a su vez son otro tipo de datos que 
 * contiene una palabra y sus definiciones
 * 
 * Los términos que contiene están ordenados alfabéticamente
 * y se proporcionan múltiples operaciones para obtener
 * información sobre el diccionario y sus términos
 * 
 * Almacena sus términos en memoria dinámica, es mutable.
 * 
 * Ejemplo de uso:
 * @include pruebadiccionario.cpp
 * 
 * @author Antonio Carlos Perea Parras
 * @date 21-10-2018
 */


class Diccionario{
    private:

    /**
         * @page repDiccionario Rep del TDA Diccionario
         * @section invDiccionario Invariante de la representatción
         * 
         * Se debe cumplir:
         * 
         *- Un Diccionario no puede incluir términos vacíos 
         *- Los términos están en todo momento ordenados alfabéticamente
         *- No pueden existir dos términos que contengan la misma palabra
         * aunque sus definiciones sean diferentes 
         * 
         * @section faDiccionario Función de abstracción
         * 
         * 
         * Para representar cada palabra del diccionario se utiliza otro
         * TDA que representa un término con su palabra y definiciones.
         * 
         * El TDA Diccionario es un contenedor para estos términos y además
         * una interfaz para manipularlos y obtener la información deseada
         * sobre un término o sobre el conjunto de ellos.
         * 
         * Al requerir el constante orden de los términos, además de operaciones
         * de inserción y borrado, he decidido que el tipo rep sea una lista
         * enlazada. 
         * 
         * Por tanto, cada término está encapsulado de una celda autoreferenciada que 
         * contiene el término y un puntero a otra celda, que es posterior a ella
         * alfabéticamente hablando (por el término que contiene).
         * 
         * La celda que contiene el primer término del diccionario está apuntada
         * por un miembro de la clase.
         */

        Celda * primero; /**< Puntero a la primera celda*/
    
    public:

        /**
         * @brief Constructor por defecto de Diccionario
         * 
         */

        Diccionario ();

        /**
         * @brief Constructor que crea un diccionario
         * con un término
         * 
         * @param terminoDado Primer término del nuevo diccionario 
         */

        Diccionario (const Termino & terminoDado);

        /**
         * @brief Constructor de copia
         * 
         * @param aCopiar Diccionario a copiar 
         */

        Diccionario (const Diccionario & aCopiar);

        /**
         * @brief Operador de asignación
         * 
         * @param aCopiar Diccionario que se asigna al operador de la izquierda 
         * @return Referencia al argumento implícito, para concatenar 
         */

        Diccionario & operator = (const Diccionario & aCopiar);

        /**
         * @brief Busca las definiciones de un término
         * 
         * @param palabraABuscar Palabra del término a buscar 
         * @return Devuelve las definciones del término si lo a encontrado,
         * de lo contrario, devuelve un string advirtiendo de ello
         */

        string getDefiniciones (string palabraABuscar) const;

        /**
         * @brief Crea un array con todos sus términos
         * y lo devuelve 
         * @return Puntero al array creado 
         */

        Termino * getTerminos () const;

        /**
         * @brief Cuenta todos los términos del diccionario
         * 
         * @return Devuelve el número de términos contados 
         */

        int getNumTerminos () const;

        /**
         * @brief Inserta el término alfabéticamente
         * en el diccionario, si ya existe, fusiona las definiciones
         * del viejo y del existente
         * 
         * @param aInsertar Término a añadir 
         */

        void aniadirTermino (Termino aInsertar);

        /**
         * @brief Elimina del diccionario
         * el término especificado
         * 
         * @param aEliminar Palabra del término a eliminar 
         */

        void eliminarTermino (string aEliminar);

        /**
         * @brief Operador de flujo de salida
         * 
         * @param salida Objeto ostream de salida
         * @param aImprimir Operador derecho (Diccionario a imprimir)
         * @return Referencia al objeto ostream (concatenación)
         * 
         */

        friend ostream & operator << (ostream & salida, const Diccionario & aImprimir);

        /**
         * @brief Operador de flujo de entrada
         * 
         * El formato de entrada es:
         * 
         * palabra;definicion
         * 
         * (Una línea por término)
         * 
         * @param entrada Objeto istream de entrada
         * @param aModificar Operador derecho (Diccionario a modificar)
         * @return Referencia al objeto istream (concatenación)
         * 
         */

        friend istream & operator >> (istream & entrada, Diccionario & aModificar);

        /**
         * @brief Crea un subdiccionario que contiene
         * todos los términos entre las letras que 
         * se especifican como parámetro
         * 
         * @param lower Carácter mínimo 
         * @param upper Carácter máximo 
         * @return Subdiccionario creado, puede estar vacío 
         */

        Diccionario filtrarPorIntervalo (char lower, char upper) const;

        /**
         * @brief Crea un subdiccionario que contiene
         * todos los términos que en sus definiciones 
         * contengan la palabra especificada
         * 
         * @param palabraClave Palabra clave que han de contener los términos
         * que forman el subdiccionario
         * @return Subdiccionario creado, puede estar vacío 
         */

        Diccionario filtrarPorPalabraClave (string palabraClave) const;

        /**
         * @brief Recuenta las definiciones de todos los términos
         * 
         * 
         * @return Definiciones totales del diccionario 
         */

        int getNumTotalDefiniciones () const;

        /**
         * @brief Busca el término que más definiciones tiene
         * 
         * @return El número de definiciones que tiene dicho término
         */

        int getMaxDefinicionesPorPalabra () const;

        /**
         * @brief Calcula el promedio de definiciones entre todos los 
         * términos del diccionario
         * 
         * @return Número de coma flotante, que es la media de definiciones 
         */

        float getPromedioDefinicionesPorPalabra() const;

        /**
         * @brief Destructor de la clase diccionario
         * 
         */

        ~Diccionario();

    private:

        /**
         * @brief Método privado de ayuda para copiar los datos
         * de un diccionario a otro
         * 
         * @param aCopiar Diccionario a copiar 
         */

        void copiarDatos (const Diccionario & aCopiar);

        /**
         * @brief Método privado que libera la memoria resrevada
         * por el objeto
         * 
         */

        void liberarMemoria();

};
#endif