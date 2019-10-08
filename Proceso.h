#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Proceso{

    private:

        string id;
        double rafaga;
        int priority;
        double tpoLlegada;
        double currentTime;
        double waitingTime;

    public:

        Proceso();
        ~Proceso();
        void crear(string,double,int);
        void show();
        void setRafaga(double);
        void setPriority(int);
        void setID(string);

        string getId();
        double getRafaga();
        int getPriority();
        double getTpoLlegada();
        double getCurrentTime();
        double getwaitingTime();
        /*bool operator<(const Proceso& llave) const
        {
            return priority < llave.priority;
        }*/
};
