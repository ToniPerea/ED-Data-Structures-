//VD.cpp
template<class T>
VD<T>::VD(int tam){
  this->n = 0 ;
  this->reservados = 10 ;
  this->datos = new T[reservados] ; 
}

template<class T>
void VD<T>::resize(int nuevotam){
  T *aux = new T[nuevotam] ;
  int minimo = (n<nuevotam)?n:nuevotam ;
  for(int i = 0 ; i < minimo ; i++)
    aux[i] = datos[i] ;
  this->reservados = nuevotam ;
  this->n = minimo ;
  delete [] datos ;
  this->datos = aux ;

}

template <class T>
void VD<T>::Copiar(const VD<T> &v){
  this->reservados = v.reservados ;
  this->n = v.n ;
  this->datos = new T[reservados] ;
  for(int i = 0 ; i < n ; i++)
    this->datos[i] = v.datos[i] ;

}

template <class T>
void VD<T>::Liberar(){ 
  delete [] datos ;
}


template <class T>
VD<T>::VD(const VD<T> &original){
  Copiar(original) ; 
}

template <class T >
VD<T>::~VD(){
  Liberar() ; 
}

template <class T>
VD<T> & VD<T>::operator=(const VD<T> & v){
  if(this != &v){
    Liberar() ;
    Copiar(v) ; 
  }
  return *this ;
}

template <class T>
void VD<T>::Insertar(const T &d, int pos){
  if( n >= (reservados/2))
    resize(2*reservados) ;
  for(int i = n ; i > pos ; i--)
    this->datos[i] = datos[i-1] ;
  this->datos[pos] = d;
  this->n++ ;
}

template<class T>
void VD<T>::Borrar(int pos){
  for(int i = pos ; i < n-1 ; i++){
    this->datos[i] = datos[i+1] ;
  }
    this->n-- ;
    if(n<(reservados/4))
      resize(reservados/2) ;
  

}

template<class T>
bool VD<T>::buscar( T& elemento){
  bool salida = false ; 
  for(int i = 0 ; i < this->size() ; i++){
    salida = elemento == this[i] ;
  }
  return salida ;
}

