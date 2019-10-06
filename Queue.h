#include <vector>
#include <string>
#include "Proceso.h"

using namespace std;

class Queue{

    private:
        string nombre;
        int capacity;
        int quantum;
        int type;
        int elementos;

        vector <Proceso> queue;
    
    public:
        //Queue(quantum,capacity,type)
        Queue(int, int, int);
        ~Queue();
        
        string getNombre();
        int getCapacity();
        int getQuantum();
        int getType();
        int getElementos();
        bool isFull();

        void setCapacity(int);
        void setQuantum(int);

        void show();
        
        void push(Proceso);
        Proceso pop();

};