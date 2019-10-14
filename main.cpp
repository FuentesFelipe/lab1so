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
    clock_t tADMinicial, tADMactual, tQueueinicial,tQueueactual;
    int procesos = 0;

    bool termino = false;
    while(modulo!=0){
        modulo = mostrarMenu();
        switch (modulo)
        {
        case 1:

        /**
         * 	clock_t tf,ti;
            int valor = 4;
            ti=clock();
            tf=clock();
            while(valor> double(tf-ti)*10/CLOCKS_PER_SEC){
                system("clear");
                cout<<float( tf-ti)*10/CLOCKS_PER_SEC<<endl;
                tf = clock();
            }
            cout<<float(tf-ti)*10/CLOCKS_PER_SEC;
         */

            while (continuar(procesos)){

                tADMinicial = clock();
                tADMactual = clock();
                
                while(QUANTUMADM > deltaTime(tADMactual,tADMinicial) && !listaDeColas[indexCola]->isEmpty()){
                    
                    procesoEnCPU.copiarProceso(listaDeColas[indexCola]->pop());
                    if(indexCola<2){

                        tQueueinicial = clock();
                        tQueueactual = clock();
                        //termino = true;

                        termino = false;

                        while(listaDeColas[indexCola]->getQuantum()> deltaTime(tQueueactual,tQueueinicial) && !termino){
                            system("clear");
                            cout<<"proces en la lista: "<<listaDeProcesos.size()<<endl;
                            printRealTime(tQueueactual,ti);
                            cout<<endl<<"Atendiendo cola "<<listaDeColas[indexCola]->getNombre()<<endl;
                            printQueueTime(tQueueactual,ti);                            
                            procesoEnCPU.setCurrentTime(deltaTime(tQueueactual,tQueueinicial));
                            
                            showCPU(procesoEnCPU);
                            showAllQueues(listaDeColas);

                            if(!procesoEnCPU.getCurrentTime()>0){
                                termino = true;
                                procesos--;

                            }
                            tQueueactual = clock();
                            
                        }
                        if(!termino){
                            listaDeColas[indexCola+1]->push(procesoEnCPU);
                        } else{
                            procesos--;
                            listaDeProcesos.pop_back();                            
                        }
                        
                    } else{
                        
                        while(procesoEnCPU.getCurrentTime()>0){
                            system("clear");
                            //cout<<"proces en la lista: "<<procesos<<endl;
                            printRealTime(tQueueactual,ti);
                            cout<<endl<<"Atendiendo cola "<<listaDeColas[indexCola]->getNombre()<<endl;
                            printQueueTime(tQueueactual,ti);                          

                            procesoEnCPU.setCurrentTime(deltaTime(tADMactual,tADMinicial));
                            showCPU(procesoEnCPU);
                            showAllQueues(listaDeColas);
                            tADMactual = clock();
                        }
                        
                    }
                    tADMactual = clock();
                }
                if(indexCola==2 && procesoEnCPU.getCurrentTime()>0){
                    listaDeColas[3]->push(procesoEnCPU);
                }
                if(indexCola==3 && procesoEnCPU.getCurrentTime()>0){
                    listaDeColas[0]->push(procesoEnCPU);
                }
                if(indexCola==3){
                    indexCola = -1;
                }
                indexCola++;
                
            }
            cout<<"Pulse algo para salir.."<<endl;
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
                cout<<"Crear más? cualquier tecla.."<<endl;
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
