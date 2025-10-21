#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

#include "array.h"
#include "polinom.h"

using namespace std;

class Interface : public QWidget
{
    Q_OBJECT

    QLabel *coeffsLabel, *imIndicator;
    QLineEdit *reCoefficientLE, *imCoefficientLE;

    QPushButton *addRootBTN;

    QPushButton *changeRootBTN;
    QLineEdit *changeRootLE;

    QLabel *Coefficient;
    QLineEdit *reCoefficient, *imCoefficient;

    QPushButton *addCoefficientBTN;

    QLabel *calculateValueAtPoint;
    QLineEdit *valueAtPointLE;
    QPushButton *calculateValueAtPointBTN;
    QLabel *valueAtPointLabel;

    QPushButton *printWithRootsBTN;
    QPushButton *printCanonicBtn;

    QLabel *outputLabel;

    Polinom *polinom;
    number *roots;
    int rootsAmount = 0;
    number An = 0;



public:

    Interface(std::string title, QWidget *parent = nullptr);
    ~Interface();
    number *pushBack(number *arr, number element);

public slots:

    void addRoot();

    void changeRoot();

    void addCoefficient();

    void valueAtPoint();

    void printWithDegrees();

    void printWithRoots();


};

#endif // INTERFACE_H
