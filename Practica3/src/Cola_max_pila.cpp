template <class T>
Cola_max<T>::Cola_max(){

}

template <class T>
void Cola_max<T>::poner(const T & x){
    if(x > maximoElemento){
        maximoElemento = x;
    }
    _stack1.push(x);
}

template <class T>
unsigned int Cola_max<T>::num_elementos(){
    if(_stack1.empty()){
        return _stack2.size();
    }
    return _stack1.size();
}

template <class T>
T Cola_max<T>::maximo(){
    return maximoElemento;
}

template <class T>
bool Cola_max<T>::vacia(){
    return (_stack1.empty()) && (_stack2.empty());
}

template <class T>
void Cola_max<T>::quitar(){
    assert(!_stack1.empty() || !_stack2.empty());
    if (_stack2.empty()){
        maximoElemento = _stack1.top();
        while (_stack1.size() > 0)
        {
            T&tmp = _stack1.top();
            _stack1.pop();
            _stack2.push(tmp);
            if(tmp > maximoElemento){
                maximoElemento = tmp;
            }
        }
    }
    _stack2.pop();
    if(_stack2.size()>0){
        stack<T> auxiliar = _stack2;
        maximoElemento = auxiliar.top();
        while(!auxiliar.empty()){
            if(auxiliar.top() > maximoElemento){
                maximoElemento = auxiliar.top();
            }
            auxiliar.pop();
        }
    }
}

template <class T>
T & Cola_max<T>::frente(){
    assert(!_stack1.empty() || !_stack2.empty());
    if (_stack2.empty()){
        while (_stack1.size() > 0){
            T&tmp = _stack1.top();
            _stack1.pop();
            _stack2.push(tmp);
        }
    }
    return _stack2.top();
}
