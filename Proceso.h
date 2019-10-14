#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Proceso{

    private:

        string id;
        float rafaga;
        int priority;
        float tpoLlegada;
        float currentTime;
        float waitingTime;

    public:

        Proceso();
        ~Proceso();
        void copiarProceso(Proceso);
        void crear(string,float,int,float);
        void show();
        void setRafaga(float);
        void setPriority(int);
        void setCurrentTime(float);
        void setID(string);

        string getId();
        float getRafaga();
        int getPriority();
        float getTpoLlegada();
        float getCurrentTime();
        float getwaitingTime();
        /*bool operator<(const Proceso& llave) const
        {
            return priority < llave.priority;
        }*/
};
