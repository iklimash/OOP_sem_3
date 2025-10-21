#include "interface.h"
#include "polinom.h"

using namespace std;

Interface::Interface(string title, QWidget *parent) : QWidget(parent)
{
    setWindowTitle(QString::fromStdString(title));
    setFixedSize(700, 400);

    coeffsLabel = new QLabel("Сoefficient:", this);
    coeffsLabel->setGeometry(50, 20, 100, 25);
    reCoefficientLE = new QLineEdit("0", this);
    reCoefficientLE->setGeometry(150, 20, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(180, 20, 25, 25);
    imCoefficientLE = new QLineEdit("0", this);
    imCoefficientLE->setGeometry(210, 20, 25, 25);

    addRootBTN = new QPushButton("Add root", this);
    addRootBTN->setGeometry(50, 50, 150, 30);

    changeRootBTN = new QPushButton("Change root (input index)", this);
    changeRootBTN->setGeometry(250, 50, 200, 30);
    changeRootLE = new QLineEdit(this);
    changeRootLE->setGeometry(455, 50, 30, 30);

    Coefficient = new QLabel("An = ", this);
    Coefficient->setGeometry(50, 90, 25, 25);
    reCoefficient = new QLineEdit(this);
    reCoefficient->setGeometry(90, 90, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(130, 90, 25, 25);
    imCoefficient = new QLineEdit(this);
    imCoefficient->setGeometry(160, 90, 25, 25);
    addCoefficientBTN = new QPushButton("Add An", this);
    addCoefficientBTN->setGeometry(50, 120, 150, 30);

    calculateValueAtPoint = new QLabel("Calculate the value at point x =", this);
    calculateValueAtPoint->setGeometry(50, 150, 250, 25);
    valueAtPointLE = new QLineEdit(this);
    valueAtPointLE->setGeometry(255, 150, 25, 25);
    calculateValueAtPointBTN = new QPushButton("Calculate", this);
    calculateValueAtPointBTN->setGeometry(50, 180, 100, 30);
    valueAtPointLabel = new QLabel("", this);
    valueAtPointLabel->setGeometry(300, 180, 100, 25);

    printWithRootsBTN = new QPushButton("Print with root", this);
    printWithRootsBTN->setGeometry(50, 250, 220, 30);

    printCanonicBtn = new QPushButton("Show in canonical form", this);
    printCanonicBtn->setGeometry(280, 250, 220, 30);

    outputLabel = new QLabel("Output:", this);
    outputLabel->setGeometry(50, 300, 300, 25);

    connect(addRootBTN, SIGNAL(pressed()), this, SLOT(addRoot()));
    connect(changeRootBTN, SIGNAL(pressed()), this, SLOT(changeRoot()));
    connect(addCoefficientBTN, SIGNAL(pressed()), this, SLOT(addCoefficient()));
    connect(calculateValueAtPointBTN, SIGNAL(pressed()), this, SLOT(valueAtPoint()));
    connect(printWithRootsBTN, SIGNAL(pressed()), this, SLOT(printWithRoots()));
    connect(printCanonicBtn, SIGNAL(pressed()), this, SLOT(printWithDegrees()));

}

Interface::~Interface() {
    delete outputLabel;
    delete printCanonicBtn;
    delete printWithRootsBTN;
    delete calculateValueAtPointBTN;
    delete valueAtPointLE;
    delete calculateValueAtPoint;
    delete addCoefficientBTN;
    delete imCoefficient;
    delete Coefficient;
    delete reCoefficient;
    delete changeRootLE;
    delete changeRootBTN;
    delete addRootBTN;
    delete imCoefficientLE;
    delete imIndicator;
    delete reCoefficientLE;
    delete coeffsLabel;
}


number *Interface::pushBack(number *arr, number element)
{
    number* newArr = new number[rootsAmount + 1];

    for(int i = 0; i < rootsAmount; i++){
        *(newArr + i) = *(arr + i);
    }
    rootsAmount++;
    *(newArr + rootsAmount - 1) = element;

    delete []arr;
    arr = newArr;
    return arr;
}



void Interface::addRoot()
{
    if ( reCoefficientLE->text() == "" || imCoefficientLE->text() == "" ){
        outputLabel->setText("Error value");
    }
    else
    {
        double re = reCoefficientLE->text().toDouble();
        double im = imCoefficientLE->text().toDouble();
        number root = TComplex(re, im);
        if ( rootsAmount == 0 )
        {
            roots = new number[0];
        }
        roots = pushBack(roots, root);
        polinom = Polinom().fill(An, roots, rootsAmount+1);
    }

}

void Interface::changeRoot()
{
    if (changeRootLE->text() == ""){
        outputLabel->setText("Error index");
    }else{
        int index = changeRootLE->text().toInt();
        if ( index >= 0 && index < rootsAmount )
        {
            double re = reCoefficientLE->text().toDouble();
            double im = imCoefficientLE->text().toDouble();
            number root(re, im);
            roots[index] = root;
            polinom = Polinom().fill(An, roots, rootsAmount+1);
        }else
        {
            outputLabel->setText("Error index");
        }
    }
}


void Interface::addCoefficient()
{
    if ( reCoefficient->text() == " " || imCoefficient->text() == "" )
    {
        outputLabel->setText("Error value");
    }
    else
    {
        double re = reCoefficient->text().toDouble();
        double im = imCoefficient->text().toDouble();
        An = TComplex(re, im);
        polinom = Polinom().fill(An, roots, rootsAmount+1);
    }
}



void Interface::valueAtPoint()
{
    if ( valueAtPointLE->text() == "")
    {
        outputLabel->setText("Error value");
    }
    else
    {
        number point = TComplex(valueAtPointLE->text().toDouble());
        QString output;
        if ( rootsAmount == 0 ){
            output = QString::fromStdString(An.to_str());
        }else
        {
            number value = polinom->valueInPoint(point);
            output = QString::fromStdString(value.to_str());
        }
        valueAtPointLabel->setText(output);
    }
}

void Interface::printWithDegrees() {
    QString output;
    string out = polinom->polynomWithDegrees().str();
    output = QString::fromStdString(out);
    outputLabel->setText(output);
}

void Interface::printWithRoots() {
    QString output;
    string out = polinom->polynomWithRoots().str();
    output = QString::fromStdString(out);
    outputLabel->setText(output);
}


