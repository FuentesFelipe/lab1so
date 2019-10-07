#include <iostream>
#include <ctime>
#include "Queue.h"
#include <string>

using namespace std;

int main(){

    unsigned t0, t1;

    t0=clock();

    Queue *priorityQueue;

    priorityQueue = new Queue(0,1);

    Proceso Pa,Pb,Pc,Pd,Pe,Pf,Pg;

    Pa.crear("Pa",1.1,5);
    Pb.crear("Pb",1.5,2);
    Pc.crear("Pc",2.5,1);
    Pd.crear("Pd",3.0,1);
    Pe.crear("Pe",3.0,0);
    Pf.crear("Pf",3.0,5);
    Pg.crear("Pg",3.0,2);
    
    priorityQueue->push(Pb);
    priorityQueue->show();
    priorityQueue->push(Pc);
    priorityQueue->show();
    priorityQueue->push(Pd);
    priorityQueue->show();
    priorityQueue->push(Pe);
    priorityQueue->show();
    priorityQueue->push(Pf);
    priorityQueue->show();
    priorityQueue->push(Pg);
    priorityQueue->show();

    t1=clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    return 0;
}