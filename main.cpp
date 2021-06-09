#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(){
    Node nodo1(10);
    cout<<"\n Nodo1 / "<<nodo1<<"\n";
    
    LinkedList lista;
    lista.remove_pos(3);

    cout<<"\n __INSERTAR__ \n";
    lista.insertar(5); // INSERTAR PRIMER ELEMENTO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / elem 5 __ "<< lista;
    lista.insertar(1); // INSERTAR ANTES DE PRIMER ELEMENTO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / elem 1 __ "<< lista;
    lista.insertar(2); // INSERTAR EN INTERMEDIO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / elem 2 __ "<< lista;
    lista.insertar(3); // INSERTAR EN INTERMEDIO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / elem 3 __ "<< lista;
    lista.insertar(6); // INSERTAR ULTIMO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / elem 6 __ "<< lista;

    cout<<"\n\n __REMOVE__ \n";
    lista.remove_pos(0); // ELIMINAR PRIMER ELEMENTO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / pos 0 __ "<< lista;
    lista.remove_pos(3); // ELIMINAR ULTIMO ELEMENTO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / pos 3 __ "<< lista;

    cout<<"\n\n __INSERT Y REMOVE__ \n";
    lista.insertar(4); // INSERTAR EN INTERMEDIO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / elem 4 __ "<< lista;
    lista.remove_pos(3); // ELIMINAR ELEMENTO INTERMEDIO
    cout<<"\n Lista / size= "<<lista.getSize()<<" / pos 3 __ "<< lista;

    cout<<"\n\n __CLEAR__ \n";
    lista.clear();
    cout<<"\n Lista / size= "<<lista.getSize()<<" __ "<< lista;
    cout<<endl;

    return 0;
}