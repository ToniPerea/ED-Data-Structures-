#include "Diccionario.h"

Diccionario :: Diccionario ()
: primero(0)
{}

Diccionario :: Diccionario (const Termino & terminoDado)
: Diccionario ()
{
    primero = new Celda;
    primero -> sig = 0;
    primero -> dato = terminoDado;
}

Diccionario :: Diccionario (const Diccionario & aCopiar){
    copiarDatos(aCopiar);
}

Diccionario & Diccionario :: operator = (const Diccionario & aCopiar){
    if (this != &aCopiar){
        liberarMemoria();
        copiarDatos(aCopiar);
    }
    return *this;
}

string Diccionario :: getDefiniciones (string palabraABuscar) const{

    Celda * aux = primero;

    while (aux){
        if ((aux -> dato).getPalabra() == palabraABuscar)
            return "Definiciones de: " + palabraABuscar 
            + "\n" + (aux -> dato).getDefiniciones();

        aux = aux -> sig;
    }

    return "[\"" + palabraABuscar + "\" no está registrada]\n";
}

Termino * Diccionario :: getTerminos () const {
    int numTerminos = getNumTerminos();

    Termino * aDevolver = new Termino [numTerminos];
    Celda * aux = primero;

    for (int i = 0 ; i < numTerminos ; i++, aux = aux -> sig)
        aDevolver[i] = aux -> dato;

    return aDevolver;
}

int Diccionario :: getNumTerminos () const{
    int count = 0;

    Celda * aux = primero;

    while (aux){
        count++;
        aux = aux -> sig;
    }

    return count;
}

void Diccionario :: aniadirTermino (Termino aInsertar){
    Celda * nueva = new Celda;
    nueva -> dato = aInsertar;

    // Si está vacía

    if (!primero){
        primero = nueva;
        primero -> sig = 0;

    }
    // Si el término a insertar no va el primero

    else if (aInsertar > primero -> dato){
        Celda * aux = primero;

        // Avanzamos el puntero hasta encontrar su sitio

        while (aux->sig && (aux -> sig)->dato < aInsertar)
            aux = aux -> sig;

        // Si llegamos al final o encontramos uno posterior a él
        // alfabéticamente

        if (!(aux -> sig) || (aux -> sig) -> dato > aInsertar){
            nueva -> sig = aux -> sig;
            aux -> sig = nueva;
        }

        // si encontramos ese mismo término ya existente

        else
            (aux -> sig) -> dato += aInsertar;
    }

    // Si el término a insertar va el primero

    else{
        // El término ya existe
        if (aInsertar == primero->dato)
            primero->dato += aInsertar;
        //El término no existe
        else{
            nueva -> sig = primero;
            primero = nueva;
        }
    }
}

void Diccionario :: eliminarTermino (string aEliminar){
    Celda * aux = primero;

    // Si es el primero el que hay que borrar

    if ((primero->dato).getPalabra() == aEliminar){
        primero = primero -> sig;
        delete aux;
    }

    // Si es un término del "medio" del diccionario

    else{
        while (aux -> sig && ((aux -> sig)->dato).getPalabra() != aEliminar)
            aux = aux -> sig;

        
        // Si está le eliminamos, sino no hacemos nada
        if (aux -> sig){
            Celda * aBorrar = aux -> sig;
            aux -> sig = aBorrar -> sig;
            delete aBorrar;
        }
    }
}

ostream & operator << (ostream & salida, const Diccionario & aImprimir){
    Celda * aux = aImprimir.primero;

    while (aux){
        salida << aux->dato << endl;
        aux = aux -> sig;
    }

    return salida;
}

istream & operator >> (istream & entrada, Diccionario & aModificar){

    while (!entrada.eof()){
        Termino aAniadir;
        entrada >> aAniadir;
        if (!aAniadir.vacio())
            aModificar.aniadirTermino(aAniadir);
    }
    return entrada;
}

Diccionario Diccionario :: filtrarPorIntervalo (char lower, char upper) const{
    Diccionario aDevolver;

    Celda * aux = primero;

    while (aux && (aux ->dato).getLetraInicial() <= upper){
        if ((aux ->dato).getLetraInicial() >= lower)
            aDevolver.aniadirTermino(aux -> dato);
        
        aux = aux -> sig;
    }

    return aDevolver;
}

Diccionario Diccionario :: filtrarPorPalabraClave (string palabraClave) const{
    Diccionario aDevolver;
    Celda * aux = primero;

    while (aux){
        if ((aux ->dato).contienePalabraClave(palabraClave))
            aDevolver.aniadirTermino(aux -> dato);

        aux = aux -> sig;
    }

    return aDevolver;
}

int Diccionario :: getNumTotalDefiniciones () const{
    int aDevolver = 0;
    Celda * aux = primero;

    while (aux){
        aDevolver += (aux -> dato).numeroDefiniciones();
        aux = aux -> sig;
    }

    return aDevolver;
}

int Diccionario :: getMaxDefinicionesPorPalabra () const{
    int aDevolver = 0;
    Celda * aux = primero;

    while (aux){
        int n = (aux -> dato).numeroDefiniciones();
        if( n > aDevolver)
            aDevolver = n;

        aux = aux -> sig;
    }

    return aDevolver;
}

float Diccionario :: getPromedioDefinicionesPorPalabra() const {
    int total = getNumTotalDefiniciones();

    return total / (float) getNumTerminos();
}

Diccionario :: ~Diccionario (){
    liberarMemoria();
}

void Diccionario :: copiarDatos (const Diccionario & aCopiar){

    if (aCopiar.primero){
        primero = new Celda;
        primero -> dato = aCopiar.primero -> dato;

        Celda * src = aCopiar.primero;
        Celda * dest = primero;

        while (src -> sig){
            src = src -> sig;
            dest -> sig = new Celda;
            dest = dest -> sig;
            dest -> dato = src -> dato;
        }
        dest -> sig = 0;
    }
    else
        primero = 0;
}

void Diccionario :: liberarMemoria (){
    Celda * aux;

    while (primero){
        aux = primero;
        primero = primero -> sig;
        delete aux;
    }

    primero = 0;
}
