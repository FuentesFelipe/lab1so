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

    

    cout<<"finish";
    //t1=clock();

    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution Time: " << time << endl;

    return 0;
}
