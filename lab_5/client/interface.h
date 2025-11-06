#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "../common/common.h"
#include "../server/array.h"
#include "../server/number.h"
#include "../server/polinom.h"

class Interface : public QWidget
{
    Q_OBJECT

    QLabel *coefficientLabel, *imIndicator;
    QLineEdit *reСoefficientLE, *imСoefficientLE;

    QPushButton *addRootBTN;

    QPushButton *changeRootBTN;
    QLineEdit *changeRootLineEdit;

    QLabel *leadingСoefficient;
    QLineEdit *reLeadСoefficient, *imLeadСoefficient;

    QPushButton *addLeadCoeffBTN;

    QLabel *calculateValueInPoint;
    QLineEdit *valueInPointReLe;
    QLineEdit *valueInPointImLe;
    QPushButton *calculateValueInPointBTN;
    QLabel *valueInPointLabel;

    QPushButton *printWithRootsBTN;
    QPushButton *printCanonBtn;

    QLabel *outputLabel;

    friend QString& operator<< (QString&,const QString&);


public:

    Interface(QWidget *parent = 0);
    ~Interface();

public slots:
    void answer(QString);

private slots:
    void formRequest();

signals:
    void request(QString);

};

#endif // INTERFACE_H
