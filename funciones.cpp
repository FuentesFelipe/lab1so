#include <iostream>
#include <stdlib.h>
#include "funciones.h"

using namespace std;

int mostrarMenu(){
    system("CLS");
    int opcion;
    cout<<"1) Ver entorno"<<endl
    <<"2) Crear proceso"<<endl
    <<"3) Modificar proceso"<<endl
    <<"4) Eliminar proceso"<<endl
    <<"5) Reiniciar todo"<<endl
    <<"0) Salir"<<endl
    <<endl<<"opcion:";
    cin>>opcion;
    system("CLS");
    return opcion;
}
Proceso crearProceso(){

    Proceso proceso;
    string nombre;
    double rafagas;
    int prioridad;

    cout<<endl<<"Crear nuevo proceso."<<endl<<endl<<"Nombre: ";
    cin>>nombre;
    cout<<endl<<"rafagas: ";
    cin>>rafagas;
    cout<<endl<<"Prioridad: ";
    cin>>prioridad;

    proceso.crear(nombre,rafagas,prioridad);
    system("clear");
    return proceso;
}
string space = "     ";

void showCPU(Proceso &proceso){
    cout<<endl<<space<<"  CPU"<<endl;
    cout<<space<<" ====="<<endl;
    cout<<space<<" | "<<proceso.getId()<<" |"<< "tiempo restante: "<<proceso.getCurrentTime()<<endl;
    cout<<space<<" ====="<<endl<<endl;
}

void eliminarProceso(Queue &Q0, Queue &Q1, Queue &Q2, Queue &Q3, string nombre) {
    int index;
    if(Q0.thisProc(nombre)){
        index = Q0.getIndex(nombre);
        Q0.removeProc(nombre, index);
        cout << "Se ha eliminado el proceso " << nombre << " de la cola " << Q0.getNombre() << endl;
    } else {
        if(Q1.thisProc(nombre)){
            index = Q1.getIndex(nombre);
            Q1.removeProc(nombre, index);
            cout << "Se ha eliminado el proceso " << nombre << " de la cola " << Q1.getNombre() << endl;
        } else {
            if(Q2.thisProc(nombre)){
                index = Q2.getIndex(nombre);
                Q2.removeProc(nombre, index);
                cout << "Se ha eliminado el proceso " << nombre << " de la cola " << Q2.getNombre() << endl;
            } else {
                if(Q3.thisProc(nombre)){
                    index = Q3.getIndex(nombre);
                    Q3.removeProc(nombre, index);
                    cout << "Se ha eliminado el proceso " << nombre << " de la cola " << Q3.getNombre() << endl;
                } else {
                    cout << "No existe ese proceso" << endl;
                }
            }
        }
    }
}
bool continuar(int continuar){

    if(continuar !=0){
        return true;
    } else{
        return false;
    }

}
