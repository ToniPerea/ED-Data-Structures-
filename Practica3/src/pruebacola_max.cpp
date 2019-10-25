#define CUAL_COMPILA 1
#if CUAL_COMPILA == 1
    #include "Cola_max_vd.hpp"
#else
    #include "Cola_max_pila.hpp"
#endif


int main(){
    Cola_max<int> p;
    p.poner(2);
    cout << "Se introduce el valor 2. El maximo es " << p.maximo() << endl;
    p.poner(5);
    cout << "Se introduce el valor 5. El maximo es " << p.maximo() << endl;
    p.poner(4);
    cout << "Se introduce el valor 4. El maximo es " << p.maximo() << endl;
    p.poner(9);
    cout << "Se introduce el valor 9. El maximo es " << p.maximo() << endl;
    p.poner(7);
    cout << "Se introduce el valor 7. El maximo es " << p.maximo() << endl;
    p.poner(8);
    cout << "Se introduce el valor 8. El maximo es " << p.maximo() << endl;

    cout << "La cola tiene " << p.num_elementos() << endl;
    cout << "El maximo es " << p.maximo() << endl;

    while(!p.vacia()){
        cout << "El frente contiene: " << p.frente() << ". ";
        cout << "El maximo es " << p.maximo() << ". ";
        cout << "Voy a quitar";
        p.quitar();
        cout << "Se quita este valor" << endl;
    }

    return 0;
}