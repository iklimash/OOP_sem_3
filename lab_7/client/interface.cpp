#include "interface.h"

Interface::Interface(QWidget *parent)
{

    setWindowTitle(QString::fromStdString("Лабораторная работа №7 "));
    setFixedSize(700, 600);

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

    numberSets = new QButtonGroup();
    functions = new QButtonGroup();


    RealMode = new QRadioButton("Вещественные числа", this);
    RealMode->setGeometry(50, 275, 200, 25);
    ComplexMode = new QRadioButton("Комплексные числа", this);
    ComplexMode->setGeometry(270, 275, 200, 25);
    RealMode->setChecked(true);

    numberSets->addButton(RealMode);
    numberSets->addButton(ComplexMode);

    outputLabel = new QLabel("Вывод:", this);
    outputLabel->setGeometry(50, 300, 600, 25);

    // Sin и Si
    trigonometry = new QLabel("Функции Sin и Si", this);
    trigonometry->setGeometry(25, 350, 200, 25);

    SinMode = new QRadioButton("Функция Sin", this);
    SinMode->setGeometry(50, 375, 200, 25);
    SiMode = new QRadioButton("Функция Si", this);
    SiMode->setGeometry(270, 375, 200, 25);
    SinMode->setChecked(true);
    functions->addButton(SinMode);
    functions->addButton(SiMode);

    decompositionDegreeLabel = new QLabel("Степень разложения: ",this);
    decompositionDegreeLabel->setGeometry(50, 425, 150, 25);
    funcDegree = new QLineEdit(this);
    funcDegree->setGeometry(200, 425, 25, 25);

    ValueToDecomposeLabel = new QLabel("X: ", this);
    ValueToDecomposeLabel->setGeometry(280, 425, 30, 25);
    ReValueToDecompose = new QLineEdit(this);
    ReValueToDecompose->setGeometry(300, 425, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(325, 425, 25, 25);
    ImValueToDecompose = new QLineEdit(this);
    ImValueToDecompose->setGeometry(350, 425, 25, 25);

    printFuncDecomposition = new QPushButton("Показать разложение", this);
    printFuncDecomposition->setGeometry(50, 450, 220, 30);

    decompositionLabel = new QLabel("Вывод: ", this);
    decompositionLabel->setGeometry(50, 500, 300, 30);


    connect(addRootBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(addLeadCoeffBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(calculateValueInPointBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(printCanonBtn ,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(printWithRootsBTN ,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(changeRootBTN ,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(printFuncDecomposition ,SIGNAL(pressed()), this,SLOT(formRequest()));
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
    delete ComplexMode;
    delete RealMode;
    delete SinMode;
    delete SiMode;
    delete functions;
    delete numberSets;
    delete decompositionLabel;
    delete printFuncDecomposition;
    delete funcDegree;
    delete decompositionDegreeLabel;
    delete ReValueToDecompose;
    delete ImValueToDecompose;
    delete ValueToDecomposeLabel;
}


void Interface::formRequest()
{
    QString msg;
    QPushButton *btn = (QPushButton*)sender();
    if ( RealMode->isChecked()){
        msg << QString().setNum(REAL_MODE);
        if ( btn == addRootBTN ){
            imСoefficientLE->setText("0");
            if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
            msg << QString().setNum(ADD_ROOT_REQUEST);
            msg << reСoefficientLE->text();
        }
        if ( btn == changeRootBTN ) {
            imСoefficientLE->setText("0");
            if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
            msg << QString().setNum(CHANGE_ROOT_REQUEST);
            msg << changeRootLineEdit->text();
            msg << reСoefficientLE->text();
        }
        if ( btn == addLeadCoeffBTN ){
            imСoefficientLE->setText("0");
            if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
            msg << QString().setNum(ADD_COEFFICIENT_REQUEST);
            msg << reСoefficientLE->text() ;
        }
        if ( btn == calculateValueInPointBTN ){
            valueInPointImLe->setText("0");
            if (valueInPointReLe->text() == "") valueInPointReLe->setText("0");
            msg << QString().setNum(VALUE_AT_POINT_REQUEST);
            msg << valueInPointReLe->text();
        }
        if ( btn == printCanonBtn ){
            msg << QString().setNum(PRINT_CANONIC_REQUEST);
        }
        if ( btn == printWithRootsBTN ){
            msg << QString().setNum(PRINT_CLASSIC_REQUEST);
        }
        if (btn == printFuncDecomposition) {
            if (SinMode->isChecked()) {
                msg << QString().setNum(DECOMPOSE_SIN);
            } else {
                msg << QString().setNum(DECOMPOSE_SI);
            }
            msg << funcDegree->text();
            ImValueToDecompose->setText("0");
            if (ReValueToDecompose->text() == "") ReValueToDecompose->setText("0");
            msg << ReValueToDecompose->text();

        }
    }else{
        msg << QString().setNum(COMPLEX_MODE);
        if ( btn == addRootBTN ){
            if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
            if (imСoefficientLE->text() == "") imСoefficientLE->setText("0");
            msg << QString().setNum(ADD_ROOT_REQUEST);
            msg << reСoefficientLE->text() << imСoefficientLE->text();
        }
        if ( btn == changeRootBTN ) {
            if (reСoefficientLE->text() == "") reСoefficientLE->setText("0");
            if (imСoefficientLE->text() == "") imСoefficientLE->setText("0");
            msg << QString().setNum(CHANGE_ROOT_REQUEST);
            msg << changeRootLineEdit->text();
            msg << reСoefficientLE->text() << imСoefficientLE->text();
        }
        if ( btn == addLeadCoeffBTN ){
            if (reLeadСoefficient->text() == "") reLeadСoefficient->setText("0");
            if (imLeadСoefficient->text() == "") imLeadСoefficient->setText("0");
            msg << QString().setNum(ADD_COEFFICIENT_REQUEST);
            msg << reLeadСoefficient->text() << imLeadСoefficient->text();
        }
        if ( btn == calculateValueInPointBTN ){
            if (valueInPointReLe->text() == "") valueInPointReLe->setText("0");
            if (valueInPointImLe->text() == "") valueInPointImLe->setText("0");
            msg << QString().setNum(VALUE_AT_POINT_REQUEST);
            msg << valueInPointReLe->text() <<valueInPointImLe->text();
        }
        if ( btn == printCanonBtn ){
            msg << QString().setNum(PRINT_CANONIC_REQUEST);
        }
        if ( btn == printWithRootsBTN ){
            msg << QString().setNum(PRINT_CLASSIC_REQUEST);
        }
        if (btn == printFuncDecomposition)
        {
            if (SinMode->isChecked()) {
                msg << QString().setNum(DECOMPOSE_SIN);
            } else {
                msg << QString().setNum(DECOMPOSE_SI);
            }
            msg << funcDegree->text();
            if (ReValueToDecompose->text() == "") ReValueToDecompose->setText("0");
            if (ImValueToDecompose->text() == "") ImValueToDecompose->setText("0");
            msg << ReValueToDecompose->text() << ImValueToDecompose->text();

        }
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
    case DECOMPOSE_SIN:
    {
        text = "Вывод: " + text;
        decompositionLabel->setText(text);
        break;
    }

    default:
        break;
    }

    msg = msg.mid(p+1,msg.length()-p-1);

}
