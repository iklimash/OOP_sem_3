#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

#include "../common/common.h"
#include "../server/array.h"
#include "../server/polinom.h"

class Interface : public QWidget
{
    Q_OBJECT

    QButtonGroup *numberSets, *functions;

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

    QRadioButton *RealMode;
    QRadioButton *ComplexMode;

    QLabel *outputLabel;

    //Sin, Si
    QLabel *trigonometry;

    QRadioButton *SinMode;
    QRadioButton *SiMode;

    QLabel *decompositionDegreeLabel;
    QPushButton *printFuncDecomposition;
    QLineEdit *funcDegree;
    QLabel *decompositionLabel;

    QLabel *ValueToDecomposeLabel;
    QLineEdit *ReValueToDecompose;
    QLineEdit *ImValueToDecompose;

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
