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
        <<endl<<"rafaga restante: "<<this->rafaga
        <<endl<<"waiting time: "<<this->waitingTime;
}

void Proceso::crear(string nombre ,double rafaga ,int priority, double time){
    this->id = nombre;
    this->rafaga = rafaga;
    this->priority = priority;
    this->tpoLlegada = time;
    this->currentTime = this->rafaga;
    this->waitingTime = 0;
}

void Proceso::setRafaga(double rafaga){
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

double Proceso::getRafaga(){
    return this->rafaga;
}

int Proceso::getPriority(){
    return this->priority;
}

double Proceso::getTpoLlegada(){
    return this->tpoLlegada;
}

double Proceso::getCurrentTime(){
    return this->currentTime;
}

double Proceso::getwaitingTime(){
    return this->waitingTime;
}

void Proceso::setCurrentTime(){
    this->currentTime--;
}
