#include "Queue.h"
#include <ctime>
#include <iostream>

using namespace std;

Queue::Queue(int quantum, int capacity, int type){
    this->quantum = quantum;
    this->capacity = capacity;
    this->type = type;
    this->elementos = 0;
}

Queue::~Queue(){}

string Queue::getNombre(){
    return this->nombre;
}

int Queue::getCapacity(){
    return this->capacity;
}

int Queue::getQuantum(){
    return this->quantum;
}

int Queue::getType(){
    return this->type;
}

int Queue::getElementos(){

    return this->elementos;
}

bool Queue::isFull(){
    bool response = false;

    if(this->capacity<=this->elementos){
        response = true;
    }
    return response;

}

void Queue::setCapacity(int capacity){
    this->capacity = capacity;
}

void Queue::setQuantum(int quantum){
    this->quantum = quantum;
}

void Queue::show(){

    //cout<<endl<<"Nombre Cola: "<<this->nombre<<endl;
    cout<<"Tipo cola: "<<this->type<<endl;
    if(this->type==1){
        cout<<"Quantum: "<<this->quantum<<endl;
    }
    cout<<"Elementos: "<<this->elementos<<endl;

    /**
     * PROVISORIO
     * 
     */
    cout<<"Ready Queue: "<<endl;
    for (int index = 0; index < this->queue.size(); index++){
        
        cout<<"| "<<this->queue[index].getId()<<" |";
    }
    cout<<endl;

}

void Queue::push(Proceso Proceso){
    this->queue.push_back(Proceso);
    this->elementos = this->elementos ++;
}

Proceso Queue::pop(){

    Proceso proceso = this->queue[0];
    this->queue.pop_back();
    return proceso;
}
