#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario

   cout << mi_diccionario;
   
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    Algunas sugerencias: 
    - Obtener las definiciones asociadas a una palabra   
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes 
   */

  // Probamos que devuelve un diccionario filtrado

    // Tanto alfabéticamente
  cout << mi_diccionario.filtrarPorIntervalo('b', 'c');
    // Como por palabra clave
  cout << mi_diccionario.filtrarPorPalabraClave("music");

  // Probamos a obtener las definiciones de una palabra

  cout << mi_diccionario.getDefiniciones("internet") << endl;

  // Probamos a obtener el número total de:
    
    // Definiciones
  cout << "Número total de definiciones: " << mi_diccionario.getNumTotalDefiniciones() << endl;
    //Términos
  cout << "Número total de terminos: " << mi_diccionario.getNumTerminos() << endl;

  // Máximo de definiciones por palabra

  cout << "Número máximo de definiciones asociadas a una palabra: " << mi_diccionario.getMaxDefinicionesPorPalabra()
       << endl;

  // Promedio de definiciones 

  cout << "Promedio de definiciones asociadas a una palabra: " << mi_diccionario.getPromedioDefinicionesPorPalabra()
       << endl << endl;

  // Obtenemos un array de términos

  Termino * array_de_terminos = mi_diccionario.getTerminos();
  cout << array_de_terminos[4];

  // Probamos a eliminar un término

  mi_diccionario.eliminarTermino("internet");
  cout << mi_diccionario.getDefiniciones("internet");


}
