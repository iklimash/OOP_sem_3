#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>


#include "interface.h"
#include "../common/communicator.h"


class ClientApplication : public QApplication{
    Q_OBJECT

    TCommunicator *comm;
    Interface *interface;

public:
    ClientApplication(int, char**);

public slots:
    void fromCommunicator(QByteArray);
    void toCommunicator(QString);
};

#endif // APPLICATION_H
