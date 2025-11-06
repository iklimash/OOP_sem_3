#include "interface.h"

Interface::Interface(QWidget *parent)
{

    setWindowTitle(QString::fromStdString("Лабораторная работа №5 "));
    setFixedSize(700, 400);

    coefficientLabel = new QLabel("Коэффициент:", this);
    coefficientLabel->setGeometry(50, 20, 100, 25);
    reСoefficientLE = new QLineEdit("", this);
    reСoefficientLE->setGeometry(150, 20, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(180, 20, 25, 25);
    imСoefficientLE = new QLineEdit("", this);
    imСoefficientLE->setGeometry(210, 20, 25, 25);

    addRootBTN = new QPushButton("Добавить корень", this);
    addRootBTN->setGeometry(50, 50, 150, 30);

    changeRootBTN = new QPushButton("Изменить корень с индексом", this);
    changeRootBTN->setGeometry(250, 50, 200, 30);
    changeRootLineEdit = new QLineEdit(this);
    changeRootLineEdit->setGeometry(455, 50, 30, 30);

    leadingСoefficient = new QLabel("an = ", this);
    leadingСoefficient->setGeometry(50, 90, 25, 25);
    reLeadСoefficient = new QLineEdit(this);
    reLeadСoefficient->setGeometry(90, 90, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(130, 90, 25, 25);
    imLeadСoefficient = new QLineEdit(this);
    imLeadСoefficient->setGeometry(160, 90, 25, 25);
    addLeadCoeffBTN = new QPushButton("Добавить an", this);
    addLeadCoeffBTN->setGeometry(50, 120, 150, 30);

    calculateValueInPoint = new QLabel("Вычислить значение в точке x = ", this);
    calculateValueInPoint->setGeometry(50, 150, 250, 25);
    valueInPointReLe = new QLineEdit(this);
    valueInPointReLe->setGeometry(255, 150, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(285, 150, 25, 25);
    valueInPointImLe = new QLineEdit(this);
    valueInPointImLe->setGeometry(305, 150, 25, 25);
    calculateValueInPointBTN = new QPushButton("Вычислить", this);
    calculateValueInPointBTN->setGeometry(50, 180, 100, 30);
    valueInPointLabel = new QLabel("", this);
    valueInPointLabel->setGeometry(300, 180, 100, 25);

    printWithRootsBTN = new QPushButton("Показать с корнями", this);
    printWithRootsBTN->setGeometry(50, 250, 220, 30);

    printCanonBtn = new QPushButton("Показать в каноническом виде", this);
    printCanonBtn->setGeometry(280, 250, 220, 30);

    outputLabel = new QLabel("Вывод:", this);
    outputLabel->setGeometry(50, 300, 600, 25);

    connect(addRootBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(addLeadCoeffBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(calculateValueInPointBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(printCanonBtn ,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(printWithRootsBTN ,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(changeRootBTN ,SIGNAL(pressed()), this,SLOT(formRequest()));
}

Interface::~Interface() {
    delete outputLabel;
    delete printCanonBtn;
    delete printWithRootsBTN;
    delete calculateValueInPointBTN;
    delete valueInPointReLe;
    delete valueInPointImLe;
    delete calculateValueInPoint;
    delete addLeadCoeffBTN;
    delete imLeadСoefficient;
    delete leadingСoefficient;
    delete reLeadСoefficient;
    delete changeRootLineEdit;
    delete changeRootBTN;
    delete addRootBTN;
    delete imСoefficientLE;
    delete imIndicator;
    delete reСoefficientLE;
    delete coefficientLabel;
}


void Interface::formRequest()
{
    QString msg;
    QPushButton *btn = (QPushButton*)sender();

    if ( btn == addRootBTN )
    {
        if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
        if (imСoefficientLE->text() == "") imСoefficientLE->setText("0");
        msg << QString().setNum(ADD_ROOT_REQUEST);
        msg << reСoefficientLE->text() << imСoefficientLE->text();
    }

    if ( btn == changeRootBTN )
    {
        if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
        if (imСoefficientLE->text() == "") imСoefficientLE->setText("0");
        msg << QString().setNum(CHANGE_ROOT_REQUEST);
        msg << changeRootLineEdit->text();
        msg << reСoefficientLE->text() << imСoefficientLE->text();
    }

    if ( btn == addLeadCoeffBTN )
    {
        if (reLeadСoefficient->text() == "") reLeadСoefficient->setText("0");
        if (imLeadСoefficient->text() == "") imLeadСoefficient->setText("0");
        msg << QString().setNum(ADD_COEFFICIENT_REQUEST);
        msg << reLeadСoefficient->text() << imLeadСoefficient->text();
    }
    if ( btn == calculateValueInPointBTN )
    {
        if (valueInPointReLe->text() == "") valueInPointReLe->setText("0");
        if (valueInPointImLe->text() == "") valueInPointImLe->setText("0");
        msg << QString().setNum(VALUE_AT_POINT_REQUEST);
        msg << valueInPointReLe->text() <<valueInPointImLe->text();
    }
    if ( btn == printCanonBtn )
    {
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    }
    if ( btn == printWithRootsBTN )
    {
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    }
    emit request(msg);
}

void Interface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-1);

    p = msg.indexOf(separator);
    text = msg.left(p);

    switch (t)
    {
    case VALUE_AT_POINT_ANSWER:
        valueInPointLabel->setText(text);
        break;

    case PRINT_POLYNOM_ANSWER:
        outputLabel->setText(text);
        break;

    default:
        break;
    }

    msg = msg.mid(p+1,msg.length()-p-1);

}
