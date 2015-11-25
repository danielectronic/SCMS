#include "threadsensores.h"
#include <QtCore>
#include "qdebug.h"
#include "wiringPi.h"

ThreadSensores::ThreadSensores(QObject *parent) :
    QThread(parent)
{

}

void ThreadSensores::run(){
    S1 = 0;
    S2 = 0;

    for (;;){

        if(digitalRead(29) == 0 && S1==0){
            emit sensorChanged("IZQ");
            S1 = 1;
            S2 = 0;
        }else if(digitalRead(25) == 0 && S2==0){
            emit sensorChanged("DER");
            S2 = 1;
            S1 = 0;
        }else{
           msleep(4);
        }


/*

        if(digitalRead(8) == 0){
            if(S1 == 0) {
                emit sensorChanged("IZQ");
                S1 = 1;
                msleep(400);
            }
        }else if(digitalRead(9) == 0){
            if(S2 == 0) {
                emit sensorChanged("DER");
                S2 = 1;
                msleep(400);
            }
        }else{
            S1 = 0;
            S2 = 0;

        }

        msleep(5);
*/
    }


}

void ThreadSensores::stop(){
    this->stop();
}

void ThreadSensores::sleep(int valor){
    msleep(valor);
}
