#include <iostream>
#include "funciones.h"

using namespace std;

int mostrarMenu(){
    system("clear");
    int opcion;
    cout<<"1) Ver entorno"<<endl
    <<"2) Crear proceso"<<endl
    <<"0) Salir"<<endl
    <<endl<<"opcion:";
    cin>>opcion;
    system("clear");
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

    proceso.crear(nombre,rafagas,prioridad,float(clock()));  
    system("clear");
}
string space = "     ";

void showCPU(Proceso proceso){
    cout<<endl<<space<<"  CPU"<<endl;
    cout<<space<<" =====  rafagas:"<<proceso.getRafaga()<<endl;
    cout<<space<<" | "<<proceso.getId()<<" |"<< "  tiempo restante: "<<proceso.getCurrentTime()<<endl;
    cout<<space<<" =====  tiempo llegada: "<<proceso.getTpoLlegada()<<endl<<endl;
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
float rafaga(){
    float rafaga;
    cout<<"rafaga : ";
    cin>>rafaga;
    return rafaga;
}

double deltaTime(clock_t final, clock_t inicio){
    
    return double(final - inicio)*10/CLOCKS_PER_SEC;
}

void printRealTime(clock_t time, clock_t inicio){
    cout<<" =============== "<<endl
        <<" TIME : "<<double(double(time-inicio)*10/CLOCKS_PER_SEC)<<endl
        <<" ==============="<<endl;
}

void printQueueTime(clock_t time, clock_t inicio){
    cout<<" Queue TIME : "<< 8 - deltaTime(time,inicio)<<endl;
}

void showAllQueues(vector<Queue*> colas){
    for(int i=0; i<colas.size();i++){
        colas[i]->show();
    }
}

void showAllProcess(vector<Proceso> lista){
    for(int i=0; i<lista.size();i++){
        lista[i].show();
    }
}