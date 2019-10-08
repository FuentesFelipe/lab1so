#include "Proceso.h"
#include <iostream>
#include <ctime>

Proceso::Proceso(){

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

void Proceso::crear(string id ,double rafaga ,int priority){
    unsigned tiempo = clock();
    this->id = id;
    this->rafaga = rafaga;
    this->priority = priority;
    this->tpoLlegada = double(tiempo/CLOCKS_PER_SEC);
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
