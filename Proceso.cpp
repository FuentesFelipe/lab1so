#include "Proceso.h"
#include <iostream>
#include <ctime>

Proceso::Proceso(){


}
void Proceso::copiarProceso(Proceso proceso){

        this->id= proceso.getId();
        this->priority = proceso.getPriority();
        this->rafaga = proceso.getRafaga();
        this->tpoLlegada = proceso.getTpoLlegada();
        this->currentTime = proceso.getCurrentTime();
        this->waitingTime = proceso.getwaitingTime();
    }

Proceso::~Proceso(){}

void Proceso::show(){

    cout<<endl<<"Nombre: "<<this->id
        <<endl<<"Rafaga: "<<this->rafaga
        <<endl<<"Prioridad: "<<this->priority
        <<endl<<"Tpo Llegada: "<<this->tpoLlegada
        <<endl<<"rafaga restante: "<<this->rafaga<<endl<<endl;
}

void Proceso::crear(string nombre ,float rafaga ,int priority, float t0){
    this->id = nombre;
    this->rafaga = rafaga;
    this->priority = priority;
    this->tpoLlegada = float(clock() - t0)*10/CLOCKS_PER_SEC;
    this->currentTime = this->rafaga;
    this->waitingTime = 0;
}

void Proceso::setRafaga(float rafaga){
    this->rafaga = rafaga;
}

void Proceso::setPriority(int priority){
    this->priority = priority;
}

void Proceso::setID(std::string id){
    this->id = id;
}

std::string Proceso::getId(){
    return this->id;
}

float Proceso::getRafaga(){
    return this->rafaga;
}

int Proceso::getPriority(){
    return this->priority;
}

float Proceso::getTpoLlegada(){
    return this->tpoLlegada;
}

float Proceso::getCurrentTime(){
    return this->currentTime;
}

float Proceso::getwaitingTime(){
    return this->waitingTime;
}

void Proceso::setCurrentTime(float tiempo){
    this->currentTime -= tiempo;
}
