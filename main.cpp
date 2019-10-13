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

    roundrobinQ2 = new Queue(2,1,"R-R Q = 2");
    roundrobinQ4 = new Queue(4,1,"R-R Q = 4");
    priorityQueue = new Queue(0,2, "Priority no apropiative");
    fcfs =  new Queue(0,3,"FCFS");

    double seconds = 0;
    int indexCola = 0;
    int modulo=1;
    int procesosTotales = 0;

    bool quedanProcesos = true;
    int quantum=0;
    int opcion = 1;
    bool seguir;
    string nombre;

    while(modulo!=0){
        modulo = mostrarMenu();
        switch (modulo)
        {
        case 1:
            seguir  = true;
            while(seguir){

                while(indexCola<4 && seguir){

                    while(quantum < 8 && seguir){

                        system("clear");
                        cout<<endl<<"Tiempo actual en quantum: "<<seconds<<endl;
                        //showCPU(procesoDespachado(indexCola));
                        cout<<endl<<"Ready Queues:"<<endl<<endl;
                        roundrobinQ2->show();
                        roundrobinQ4->show();
                        priorityQueue->show();
                        fcfs->show();
                        cout<<" Presione cualquier número para contiuar, cero para terminar:";
                        cin>>opcion;
                        seguir = continuar(opcion);
                        if(continuar){
                            seconds++;
                        }


                    }
                }

            }
            break;

        case 2:
            roundrobinQ2->push(crearProceso());

            break;

        case 3:
            cout << "Ingresar nombre del proceso" << endl;
            cin>>nombre;
            int index;
            eliminarProceso(*roundrobinQ2, *roundrobinQ4, *priorityQueue, *fcfs, nombre);
            /*if(roundrobinQ2->thisProc(nombre)){
                index = roundrobinQ2->getIndex(nombre);
                roundrobinQ2->removeProc(nombre, index);
            } else {
                if(roundrobinQ4->thisProc(nombre)){
                    index = roundrobinQ4->getIndex(nombre);
                    roundrobinQ4->removeProc(nombre, index);
                } else {
                    if(priorityQueue->thisProc(nombre)){
                        index = priorityQueue->getIndex(nombre);
                        priorityQueue->removeProc(nombre, index);
                    } else {
                        if(fcfs->thisProc(nombre)){
                            index = fcfs->getIndex(nombre);
                            fcfs->removeProc(nombre, index);
                        } else {
                            cout << "No existe ese proceso " << endl;
                        }
                    }
                }
            }*/
            cout<<"hoola";
            cout<<" Presione cualquier número para contiuar, cero para terminar:";
            cin>>opcion;
            seguir = continuar(opcion);
            break;
        case 4:
            cout << "Ingresar nombre del proceso" << endl;
            cin>>nombre;
            int index;
            eliminarProceso(*roundrobinQ2, *roundrobinQ4, *priorityQueue, *fcfs, nombre);
            cout<<"hoola";
            cout<<" Presione cualquier número para contiuar, cero para terminar:";
            cin>>opcion;
            seguir = continuar(opcion);
            break;
        case 5:
            delete roundrobinQ2;
            delete roundrobinQ4;
            delete priorityQueue;
            delete fcfs;
            roundrobinQ2 = new Queue(2,1,"R-R Q = 2");
            roundrobinQ4 = new Queue(4,1,"R-R Q = 4");
            priorityQueue = new Queue(0,2, "Priority no apropiative");
            fcfs =  new Queue(0,3,"FCFS");
            quantum = 0;
            seconds = 0;
            indexCola = 0;
            procesosTotales = 0;
            modulo = 1;
            cout<<"hoola";
            cout<<" Presione cualquier número para contiuar, cero para terminar:";
            cin>>opcion;
            seguir = continuar(opcion);
            break;

        default:

            break;
        }
    }



    cout<<"finish";
    //t1=clock();

    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution Time: " << time << endl;

    return 0;
}
