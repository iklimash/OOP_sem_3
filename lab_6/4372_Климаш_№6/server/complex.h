#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <QString>
#include <iostream>
using namespace std;

class TComplex
{
    double re;
    double im;
    static QChar SEPARATOR;

public:

    TComplex();
    TComplex(double re, double im);
    TComplex(double re);
    TComplex(const QByteArray&);

    double getRe() const;
    double getIm() const;
    double module(TComplex* complex);

    TComplex operator+(TComplex& second) const;
    TComplex operator-(TComplex& second) const;
    TComplex operator*(TComplex& second) const;
    TComplex operator*(int second) const;
    TComplex operator/(TComplex& second) const;

    TComplex& operator+=(TComplex second);
    TComplex& operator-=(TComplex second);
    TComplex& operator*=(TComplex second);
    TComplex& operator/=(TComplex second);

    TComplex& operator+=(double second);
    TComplex& operator/=(double second);
    TComplex& operator=(double& second);

    bool operator==(TComplex& second) const;
    bool operator==(int second) const;
    bool operator!=(TComplex& second) const;
    bool operator!=(int second) const;
    bool operator<(TComplex& second);
    bool operator>(TComplex& second);
    bool operator>(int second);

    static void setSeparator(QChar);

    operator QString ();

    friend TComplex pow(const TComplex& complex, double n);
    friend istream& operator>>(istream& is, TComplex& c);
    friend ostream& operator<<(ostream& os, const TComplex& c);
    friend QByteArray& operator>>(QByteArray&,TComplex&);

    string to_str() const;

};

#endif // COMPLEX_H
