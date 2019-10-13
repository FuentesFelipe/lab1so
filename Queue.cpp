#include "Queue.h"
#include <ctime>
#include <iostream>
//#include <algorithm>

using namespace std;

Queue::Queue(int quantum, int type, string name){
    this->nombre = name;
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

bool Queue::thisProc(string nombre) {
    for (int index = 0; index < this->queue.size(); index++){

        if(nombre == (this->queue[index].getId())) {
            return true;
        }
    }
    return false;
}

int Queue::getIndex(string nombre) {
    for (int index = 0; index < this->queue.size(); index++){

        if(nombre == (this->queue[index].getId())) {
            return index;
        }
    }
    return 9999;
}

void Queue::removeProc(string nombre, int index) {
    this->queue.erase(this->queue.begin()+index);
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

    cout<<endl<<this->nombre<<endl;

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
    if(this->elementos==10){
        cout << "La ready queue se encuentra llena " << endl;
    } else {
        if(this->type==1){
            this->priorizar(proceso);
        } else {

            this->queue.push_back(proceso);
    }
        this->elementos = this->elementos + 1;
}
}

/*void Queue::ordenar(){
    vector <Proceso> Priority;
    Priority.assign(this->queue.begin(), this->queue.end());
    sort(Priority.begin(), Priority.end());
    this->queue.assign(Priority.begin(), Priority.end());
}*/

Proceso Queue::pop(){

    Proceso proceso = this->queue[ this->queue.size() -1];
    this->queue.pop_back();
    this->elementos = this->elementos -1;
    return proceso;
}
