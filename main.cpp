#include <iostream>
#include <ctime>
#include "funciones.h"
#include <string>
#include <stdlib.h>

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
    vector <Proceso*> listaDeTerminados;
    roundrobinQ2 = new Queue(2,1,"R-R Q = 2");
    roundrobinQ4 = new Queue(4,1,"R-R Q = 4");
    priorityQueue = new Queue(0,2, "Priority no apropiative");
    fcfs =  new Queue(0,3,"FCFS");

    listaDeColas.push_back(roundrobinQ2);
    listaDeColas.push_back(roundrobinQ4);
    listaDeColas.push_back(priorityQueue);
    listaDeColas.push_back(fcfs);

    //cout<<"first queue in vector: "<<listaDeColas[0].getNombre();

    double seconds = 1.0;
    int indexCola = 0;
    int modulo=1;
    int procesosTotales = 0;
    bool quedanProcesos = true;
    int quantum = 8;
    int opcion = 1;
    bool seguir;
    Proceso proceso;
    Proceso procesoEnCPU;
    
    while(modulo!=0){
        modulo = mostrarMenu();
        switch (modulo)
        {
        case 1:
            quedanProcesos = continuar(listaDeProcesos.size());
            seguir  = true;
            while(indexCola<4 && seguir){
                
                seguir = true;
                            
                while(quantum >0 && seguir){

                    cout<<"Atendiendo procesos de la cola "<<listaDeColas[indexCola]->getNombre()<<endl;
                    procesoEnCPU.copiarProceso(listaDeColas[indexCola]->popFirst());
                    while (listaDeColas[indexCola]->getQuantum()>0)
                    {
                        listaDeColas[indexCola]->setQuantum();
                        procesoEnCPU.setCurrentTime();
                        quantum--;                            

                        if(procesoEnCPU.getCurrentTime()<=0){
                            listaDeTerminados.push_back(&procesoEnCPU);
                            break;
                        } else{

                            cout<<endl<<"Tiempo actual en quantum: "<<seconds<<endl;
                            cout<<endl<<"Quedan "<<quantum<<" quantum para los procesos de esta cola."<<endl;
                            showCPU(procesoEnCPU);
                            cout<<endl<<"Quantum restantes para este proceso: "<<listaDeColas[indexCola]->getQuantum();
                            cout<<endl<<"Ready Queues:"<<endl<<endl;
                            roundrobinQ2->show();
                            roundrobinQ4->show();
                            priorityQueue->show();
                            fcfs->show();
                            cout<<" Presione cualquier número para contiuar, cero para terminar:";
                            cin>>opcion;
                            system("clear");
                            seguir = continuar(opcion);
                            if(continuar){
                                seconds++;
                            }

                        }
                    }
                    if(procesoEnCPU.getCurrentTime()>0){
                        listaDeColas[indexCola+1]->push(procesoEnCPU);
                    }
                    if(listaDeColas[indexCola]->isEmpty()){
                        seguir=false;
                    } else{

                        listaDeColas[indexCola]->restartQuantum(indexCola);
                    }
                    
                    
                }
                if(quantum==0){
                    quantum=8;
                    indexCola++;
                }
            }

            break;

        case 2:

            cout<<endl<<"Crear nuevo proceso."<<endl;
            proceso.crear(nombre(),rafaga(),prioridad(),seconds);
            roundrobinQ2->push(proceso);
            listaDeProcesos.push_back(proceso);
            procesosTotales++;

            break;
        case 3:

            cout<<"hoola";
            cout<<" Presione cualquier número para contiuar, cero para terminar:";
            cin>>opcion;
            seguir = continuar(opcion);
            break;
        case 4:

            cout<<"hoola";
            cout<<" Presione cualquier número para contiuar, cero para terminar:";
            cin>>opcion;
            seguir = continuar(opcion);
            break;
        case 5:

            cout<<"hoola";
            cout<<" Presione cualquier número para contiuar, cero para terminar:";
            cin>>opcion;
            seguir = continuar(opcion);
            break;

        default:
            
            break;
        }
    }

    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution Time: " << time << endl;

    return 0;
}
