#include <vector>
#include <string>
#include "Proceso.h"

class Queue{

    private:
        string nombre;
        int quantum;
        int type;
        vector <Proceso> queue;

        void priorizar(Proceso);

    public:
        Queue(int, int, string);
        ~Queue();

        string getNombre();
        int getQuantum();
        int getType();
        int getElementos();
        bool isEmpty();

        void setQuantum(double);
        void restartQuantum(int);
        void show();
        void push(Proceso);
        //void ordenar();

        Proceso pop();
        Proceso popFirst();

};
