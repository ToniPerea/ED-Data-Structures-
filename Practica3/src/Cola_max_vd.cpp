template <class T>
Cola_max<T>::Cola_max(){
    posInicioCola = 0;
    posFinCola = 0;
    posMaximoCola = 0;
}

template <class T>
void Cola_max<T>::poner(const T & ele_a_insertar){
    datos.Insertar(ele_a_insertar, posFinCola);
        
    if(ele_a_insertar > datos[posMaximoCola]){
        posMaximoCola = posFinCola;
    }

    posFinCola++;
}

template <class T>
unsigned int Cola_max<T>::num_elementos(){
    // Tenemos en cuenta que posFinCola está desplazado una unidad
    // Normalmente para calcular cuantos elementos hay en un rango es:
    // rangoMax - rangoMin + 1, pero rangoMax ya está desplazado una unidad
    return posFinCola - posInicioCola;
}

template <class T>
T Cola_max<T>::maximo(){
    return datos[posMaximoCola];
}

template <class T>
bool Cola_max<T>::vacia(){
    return num_elementos()==0;
}

template <class T>
void Cola_max<T>::quitar(){
    // Borramos en la posicionInicioCola pero el VD internamente desplaza los datos a la izquierda
    datos.Borrar(posInicioCola);
    posFinCola--;

    T maximo = datos[posInicioCola];
    int posMaximo = posInicioCola;
    for(int i = posInicioCola; i < posFinCola; i++){
        if(datos[i] > maximo){
            maximo = datos[i];
            posMaximo = i;
        }
    }
    posMaximoCola = posMaximo;

}

template <class T>
T Cola_max<T>::frente(){
    return datos[posInicioCola];
}
