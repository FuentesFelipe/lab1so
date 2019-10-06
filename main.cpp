#include <iostream>
#include <ctime>
#include "Queue.h"
#include <string>

using namespace std;

int main(){

    unsigned t0, t1;

    t0=clock();

    Queue *roundRobinQ2;

    roundRobinQ2 = new Queue(2,5,1);

    roundRobinQ2->setCapacity(8);

    string id = "Pa";
    Proceso Pa;

    Pa.crear(id,1.1,5);
    //Pa.setID(id);
    //Pa.setPriority(1);
    //Pa.setRafaga(1.1);

    roundRobinQ2->push(Pa);
    roundRobinQ2->push(Pa);
    //cout<< roundRobinQ2->pop().getId()<<endl;

    roundRobinQ2->show();
    
    t1=clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    return 0;
}