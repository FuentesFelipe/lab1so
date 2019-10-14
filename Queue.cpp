#include "Queue.h"
#include <ctime>
#include <iostream>
//#include <algorithm>

using namespace std;

Queue::Queue(int quantum, int type, string name){
    this->nombre = name;
    this->quantum = quantum;
    this->type = type;
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

    return this->queue.size();
}

bool Queue::isEmpty(){

    bool response = false;

    if(this->queue.size()==0){
        response = true;
    }
    return response;
}

void Queue::setQuantum(double quantum){
    this->quantum --;
}

void Queue::restartQuantum(int index){
    if(index==1){
        this->quantum = 2;
    } else if (index==2){
        this->quantum = 4;
    }
    {
        /* code */
    }

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
    int elementos = this->getElementos();
    
    if(this->type==1){
        cout<<"Quantum: "<<this->quantum<<endl;
    }
    cout<<"Elementos: "<<elementos<<endl;

    /**
     * PROVISORIO
     *
     */
    if(this->getElementos()!=0){
        cout<<"Ready Queue: "<<endl;
        for (int index = 0; index < this->queue.size(); index++){

            cout<<"| "<<this->queue[index].getId()<<" |";
        }
    }
    cout<<endl;

}

void Queue::push(Proceso proceso){
    if(this->getElementos()==10){
        cout << "La ready queue se encuentra llena " << endl;
    } else {
        if(this->type==1){
            this->priorizar(proceso);
        } else {

            this->queue.push_back(proceso);
            /**
             * this->queue.push_back(proceso);
                for (int i = this->queue.size() -1; i > 0; i--){
                    this->queue[i] = this->queue[i--];
                }
                
                this->queue[0] = proceso;   
             *  */        

            }
    }
}

/*void Queue::ordenar(){
    vector <Proceso> Priority;
    Priority.assign(this->queue.begin(), this->queue.end());
    sort(Priority.begin(), Priority.end());
    this->queue.assign(Priority.begin(), Priority.end());
}*/

Proceso Queue::pop(){

    int final = this->queue.size()-1;
    Proceso proceso;
    proceso.crear(this->queue[final].getId(),this->queue[final].getRafaga(),this->queue[final].getPriority(),this->queue[final].getTpoLlegada());
    this->queue.pop_back();
    return proceso;
}

Proceso Queue::popFirst(){

    Proceso primerProcesoEnCola;
    primerProcesoEnCola.crear(this->queue[0].getId(),this->queue[0].getRafaga(),this->queue[0].getPriority(),this->queue[0].getTpoLlegada());
    for(int i=0;i<this->queue.size() -1;i++){
        this->queue[i] = this->queue[i+1];
    }
    this->queue.pop_back();
    return primerProcesoEnCola;
}
