#include "Queue.h"


void showCPU(Proceso);
int mostrarMenu();
bool continuar(int);
Proceso crearProceso();
string nombre();
float rafaga();
int prioridad();
double deltaTime(clock_t,clock_t);
void printRealTime(clock_t,clock_t);
void printQueueTime(clock_t,clock_t);
void showAllQueues(vector<Queue*>);
void showAllProcess(vector<Proceso>);

