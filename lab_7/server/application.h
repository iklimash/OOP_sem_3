#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include "polinom.h"

#include "../common/communicator.h"
#include "../common/common.h"
#include "complex.h"

class ServerApplication : public QCoreApplication {
Q_OBJECT


    TCommunicator *comm;

    Polinom<TComplex>* polinom = new Polinom<TComplex>;
    Polinom<float>* floatPolinom = new Polinom<float>;

    TComplex* roots;
    float* floatRoots;

    TComplex An = 0;
    float floatAn = 0;

    int rootsAmount = 0;

public:

    TComplex* pushBack(TComplex *arr, TComplex elem);
    float* pushBack(float *arr, float elem);
    ServerApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};


#endif // APPLICATION_H
