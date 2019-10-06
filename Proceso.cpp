#include "Proceso.h"

Proceso::Proceso(){

}

Proceso::~Proceso(){}

//void Proceso::show(){}

void Proceso::crear(string id ,double rafaga ,int priority){
    this->id = id;
    this->rafaga=rafaga;
    this->priority=priority;
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

double Proceso::getCurrentTime(){
    return this->currentTime;
}

double Proceso::getwaitingTime(){
    return this->waitingTime;
}