#include "../include/Termino.h"

Termino::Termino(){
    palabra = "";
    definiciones = NULL;
}

Termino::Termino(string palabra, Vector<string> definiciones){
    this.palabra = palabra;
    this.definiciones = definiciones;
}

Termino::Termino(const Termino &otro){
    this.palabra = otro.palabra;
    this.definiciones = otro.definiciones;
}

string Termino::getPalabra(){
    return palabra;
}

 Vector<string>  Termino::getDefiniciones(){
     return definiciones;
 }

 int Termino::NumeroDeficiones(){
     return definiciones.size_;
 }

 void Termino::setPalabra(string otra_palabra){
     this.palabra = otra_palabra;
 }