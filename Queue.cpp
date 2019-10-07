#include "Queue.h"
#include <ctime>
#include <iostream>

using namespace std;

Queue::Queue(int quantum, int type){
    this->quantum = quantum;
    this->type = type;
    this->elementos = 0;
}

Queue::~Queue(){}

string Queue::getNombre(){
    return this->nombre;
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

bool Queue::isEmpty(){

    bool response = false;

    if(this->queue.size()==0){
        response = true;
    }
    return response;
}

void Queue::setQuantum(int quantum){
    this->quantum = quantum;
}

void Queue::priorizar(Proceso proceso){
    vector<Proceso> vectorTemporal; 
    bool notFinish=true;
    while(notFinish){
        if(this->isEmpty()){
            this->queue.push_back(proceso);
            notFinish = false;
        } else{
            Proceso lastProcess = this->queue[this->queue.size() -1];
            if(lastProcess.getPriority() > proceso.getPriority()){
                vectorTemporal.push_back(lastProcess);
                this->queue.pop_back();

            } else{
                this->queue.push_back(proceso);
                notFinish = false;
            }
        }

    }
    
    while(vectorTemporal.size()>0){
        this->queue.push_back(vectorTemporal[vectorTemporal.size() -1]);
        vectorTemporal.pop_back();
    }
    vectorTemporal.clear();
}

void Queue::show(){

    //cout<<endl<<"Nombre Cola: "<<this->nombre<<endl;
    cout<<endl<<"Tipo cola: "<<this->type<<endl;
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
    cout<<endl<<endl;

}

void Queue::push(Proceso proceso){
    if(this->type==1){
        this->priorizar(proceso);
    }
    else{
        this->queue.push_back(proceso);
    }
    this->elementos = this->elementos + 1;
}

Proceso Queue::pop(){

    Proceso proceso = this->queue[ this->queue.size() -1];
    this->queue.pop_back();
    this->elementos = this->elementos -1;
    return proceso;
}
