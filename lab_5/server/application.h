#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include "polinom.h"

#include "../common/communicator.h"
#include "../common/common.h"

class ServerApplication : public QCoreApplication {
Q_OBJECT


    TCommunicator *comm;

    Polinom* polinom = new Polinom;

    number* roots;

    number An = 0;

    int rootsAmount = 0;

public:

    number* pushBack(number *arr, number elem);
    ServerApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};


#endif // APPLICATION_H
