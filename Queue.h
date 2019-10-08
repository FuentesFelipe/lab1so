#include <vector>
#include <string>
#include "Proceso.h"

class Queue{

    private:
        string nombre;
        int quantum;
        int type;
        int elementos;
        vector <Proceso> queue;

        void priorizar(Proceso);

    public:
        //Queue(quantum,type)
        Queue(int, int);
        ~Queue();

        string getNombre();
        int getQuantum();
        int getType();
        int getElementos();
        bool isEmpty();

        void setQuantum(int);
        void show();
        void push(Proceso);
        //void ordenar();

        Proceso pop();

};
