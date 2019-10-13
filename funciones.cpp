#include <iostream>
#include "funciones.h"

using namespace std;

int mostrarMenu(){
    system("clear");
    int opcion;
    cout<<"1) Ver entorno"<<endl
    <<"2) Crear proceso"<<endl
    <<"3) Modificar proceso"<<endl
    <<"4) Eliminar proceso"<<endl
    <<"5) Reiniciar todo"<<endl
    <<"0) Salir"<<endl
    <<endl<<"opcion:";
    cin>>opcion;
    system("clear");
    return opcion;
}
Proceso crearProceso(double seconds){

    Proceso proceso;
    string nombre;
    double rafagas;
    int prioridad;
    int nada;

    cout<<endl<<"Crear nuevo proceso."<<endl<<endl<<"Nombre: ";
    cin>>nombre;
    cout<<endl<<"rafagas: ";
    cin>>rafagas;
    cout<<endl<<"Prioridad: ";
    cin>>prioridad;
    proceso.crear(nombre,rafagas,prioridad,seconds);  
}
string space = "     ";

void showCPU(Proceso proceso){
    cout<<endl<<space<<"  CPU"<<endl;
    cout<<space<<" ====="<<endl;
    cout<<space<<" | "<<proceso.getId()<<" |"<< "tiempo restante: "<<proceso.getCurrentTime()<<endl;
    cout<<space<<" ====="<<endl<<endl;
}

bool continuar(int continuar){

    if(continuar !=0){
        return true;
    } else{
        return false;
    }
    
}

string nombre(){
    string nombre;
    cout<<"Nombre : ";
    cin>>nombre;
    return nombre;
}

int prioridad(){
    int prioridad;
    cout<<"prioridad : ";
    cin>>prioridad;
    return prioridad;
}
int rafaga(){
    int rafaga;
    cout<<"rafaga : ";
    cin>>rafaga;
    return rafaga;
}