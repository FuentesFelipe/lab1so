#include <iostream>
#include <ctime>
#include "funciones.h"
#include <string>
#include <ctime>
#include <stdlib.h>
#define QUANTUMADM 8
using namespace std;

int main(){

    /**
     * Inicialización de colas y variables globales
     */

    Queue *priorityQueue;
    Queue *roundrobinQ2;
    Queue *roundrobinQ4;
    Queue *fcfs;

    vector <Queue*> listaDeColas;
    vector <Proceso> listaDeProcesos;
    roundrobinQ2 = new Queue(2,1,"R-R Q = 2");
    roundrobinQ4 = new Queue(4,1,"R-R Q = 4");
    priorityQueue = new Queue(0,2, "Priority no apropiative");
    fcfs =  new Queue(0,3,"FCFS");

    listaDeColas.push_back(roundrobinQ2);
    listaDeColas.push_back(roundrobinQ4);
    listaDeColas.push_back(priorityQueue);
    listaDeColas.push_back(fcfs);

    unsigned t0, t1;
    clock_t ti,tf;

    t0=clock();
    ti = clock();

    int indexCola = 0;
    int modulo=1;
    int opcion = 1;
    bool seguir;
    Proceso proceso;
    Proceso procesoEnCPU;
    clock_t tADMinicial, tADMactual, tQueueinicial,tQueueactual, tPF;
    int procesos = 0;

    bool terminado;
    while(modulo!=0){
        modulo = mostrarMenu();
        switch (modulo)
        {
        case 1:
            
            while(continuar(listaDeProcesos.size())){
                
                tADMinicial = clock();
                tADMactual = clock();
                while( QUANTUMADM > (double(tADMactual - tADMinicial))*10/CLOCKS_PER_SEC && !listaDeColas[indexCola]->isEmpty()  ){
                    
                    procesoEnCPU.copiarProceso(listaDeColas[indexCola]->pop());
                    tADMactual= clock();                
                    
                    if(indexCola<2){
                        
                        tQueueinicial = clock();
                        tQueueactual = clock();
                        terminado = false;

                        while(listaDeColas[indexCola]->getQuantum() > (double(tQueueactual - tQueueinicial))*10/CLOCKS_PER_SEC && !terminado){

                            system("clear");
                            printRealTime(tADMactual, ti);
                            cout<<"atendiendo a "<<listaDeColas[indexCola]->getNombre()<<endl;

                            procesoEnCPU.setCurrentTime(tQueueactual,tQueueinicial);
                            
                            showCPU(procesoEnCPU);
                            showAllQueues(listaDeColas);
                            
                            if(!procesoEnCPU.getCurrentTime()>0){
                                terminado = true;                                
                                listaDeProcesos.pop_back();                            
                            }

                            tQueueactual = clock();
                        }
                        if(!terminado){
                            procesoEnCPU.setRafaga(procesoEnCPU.getCurrentTime());
                            listaDeColas[indexCola+1]->push(procesoEnCPU);
                        }


                    } else{

                        tPF = clock();
                        
                        terminado = false;
                        while(procesoEnCPU.getCurrentTime()>0 && QUANTUMADM > (double(tADMactual - tPF))*10/CLOCKS_PER_SEC ){
                            
                            system("clear");
                            printRealTime(tADMactual, ti);
                            cout<<"atendiendo a "<<listaDeColas[indexCola]->getNombre()<<endl;
                            procesoEnCPU.setCurrentTime(tADMactual,tPF);
                            showCPU(procesoEnCPU);
                            showAllQueues(listaDeColas);
                    
                            if(!procesoEnCPU.getCurrentTime()>0){
                                terminado = true;                                
                                listaDeProcesos.pop_back();
                            }

                            tADMactual = clock();

                        }

                    }
                    

                }
                if(indexCola==2 && procesoEnCPU.getCurrentTime()>0){
                    procesoEnCPU.setRafaga(procesoEnCPU.getCurrentTime());
                    listaDeColas[3]->push(procesoEnCPU);
                }
                if(indexCola==3){

                    if(procesoEnCPU.getCurrentTime()>0){
                        procesoEnCPU.setRafaga(procesoEnCPU.getCurrentTime());
                        listaDeColas[0]->push(procesoEnCPU);
                    }
                    indexCola = -1;
                }
                indexCola++;
                
            }
            cout<<"Finalizado.."<<endl;
            cout<<" 0 para salir.";
            cin>>opcion;
            seguir = continuar(opcion);
  
            break;

        case 2:
            seguir = true;
            while (seguir)
            {
                system("clear");
                showAllProcess(listaDeProcesos);
                cout<<endl<<"Crear nuevo proceso."<<endl;
                proceso.crear(nombre(),rafaga(),prioridad(),ti);
                roundrobinQ2->push(proceso);
                listaDeProcesos.push_back(proceso);
                procesos ++;
                cout<<"Crear más? PRESIONE DEL 1 AL 9 CUALQUIER NUMERO.."<<endl;
                cout<<" 0 para salir.";
                cin>>opcion;
                seguir = continuar(opcion);
            }

            break;

        default:
            
            break;
        }
    }
    t1= clock();
    double time = (double(t1-t0)*10/CLOCKS_PER_SEC);
    cout <<endl<< "Execution Time: " << time << endl;

    return 0;
}
