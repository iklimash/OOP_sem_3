#pragma once
#include <cmath>
#include <iostream>
using namespace std;

class TComplex
{
    double re;
    double im;

public:

    TComplex();
    TComplex(double re, double im);
    TComplex(double re);

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

    friend TComplex pow(const TComplex& complex, double n);
    friend istream& operator>>(istream& is, TComplex& c);
    friend ostream& operator<<(ostream& os, const TComplex& c);

    string to_str() const;

};

