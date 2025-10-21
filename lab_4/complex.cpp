#include "complex.h"
#include "number.h"
#include <iostream>
#include <sstream>

using namespace std;

TComplex::TComplex ()
{
    re = 0;
    im = 0;
}

TComplex::TComplex(double re, double im)
{
    this->re = re;
    this->im = im;
}

TComplex::TComplex(double re)
{
    this->re = re;
    im = 0;
}

double TComplex::getRe() const {
    return this->re;
}


double TComplex::getIm() const {
    return this->im;
}


double TComplex::module(TComplex *complex) {
    double a = pow(complex->getRe(),2);
    double b = pow(complex->getIm(), 2);
    return pow(a + b, 0.5);
}

TComplex TComplex::operator+(TComplex& second) const
{
    return TComplex(re + second.re, im + second.im);
}

TComplex TComplex::operator-(TComplex& second) const
{
    return TComplex(re - second.re, im - second.im);
}

TComplex TComplex::operator*(TComplex& second) const
{
    double a = re * second.re - im * second.im;
    double b = re * second.im + im * second.re;
    return TComplex(a, b);
}

TComplex TComplex::operator*(int second) const
{
    double a;
    double b;
    a = re * second;
    b = im * second;
    return TComplex(a, b);
}

TComplex TComplex::operator/(TComplex& second) const
{
    double a = (re * second.re + im * second.im) / (second.re * second.re + second.im * second.im);
    double b = (im * second.re - re * second.im) / (second.re * second.re + second.im * second.im);
    return TComplex(a, b);
}

TComplex& TComplex::operator+=(TComplex second)
{
    re += second.re;
    im += second.im;
    return *this;
}

TComplex& TComplex::operator-=(TComplex second)
{
    re -= second.re;
    im -= second.im;
    return *this;
}

TComplex& TComplex::operator*=(TComplex second)
{
    double a = re * second.re - im * second.im;
    double b = re * second.im + im * second.re;
    re = a; im = b;
    return *this;
}

TComplex& TComplex::operator/=(TComplex second)
{
    double a = (re * second.re + im * second.im) / (second.re * second.re + second.im * second.im);
    double b = (im * second.re - re * second.im) / (second.re * second.re + second.im * second.im);
    re = a; im = b;
    return *this;
}

TComplex& TComplex::operator+=(double second) {
    re += second;
    return *this;
}


TComplex& TComplex::operator/=(double second) {
    double a = (re * second) / (second * second);
    double b = (second * im) / (second * second);
    re = a;
    im = b;
    return *this;
}

TComplex& TComplex::operator=(double& second)
{
    re = second;
    im = 0;
    return *this;
}

bool TComplex::operator==(TComplex& second) const
{
    if (re == second.re && im == second.im)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool TComplex::operator!=(TComplex& second) const
{
    if (re == second.re && im == second.im)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool TComplex::operator!=(int second) const{
    if(re == second && im == 0) return false;
    return true;
}

bool TComplex::operator<(TComplex& second)
{
    if (re != second.re)
    {
        return re < second.re;
    }
    return im < second.im;
}

bool TComplex::operator>(TComplex& second)
{
    if (re != second.re)
    {
        return re > second.re;
    }
    return im > second.im;
}

bool TComplex::operator>(int second) {
    if(module(this) > second) return true;
    if(module(this) == second){
        if(atan(this->im/this->re) > atan(0))return true;
    }
    return false;
}
TComplex pow(const TComplex& complex, double n) {

    double arg = atan2(complex.getIm(), complex.getRe());

    double mod = sqrt(pow(complex.getRe(), 2) + pow(complex.getIm(), 2));

    // формулу Муавра
    double new_mod = pow(mod, n);
    double new_arg = arg * n;

    return TComplex(new_mod * cos(new_arg),
                    new_mod * sin(new_arg));
}


istream& operator>>(istream& is, TComplex& c)
{
    is >> c.re >> c.im;
    return is;
}

ostream& operator<<(ostream& os, const TComplex& c)
{
    if (c.im < 0 && c.re != 0)
    {
        os << c.re << c.im << 'i';
    }
    else if (c.im > 0 && c.re != 0)
    {
        os << c.re << '+' << c.im << 'i';
    }
    else if (c.im == 0 && c.re != 0)
    {
        os << c.re;
    }
    else if (c.im != 0 && c.re == 0)
    {
        os << c.im << 'i';
    }
    else
    {
        os << '0';
    }
    return os;
}

string TComplex::to_str() const
{
    ostringstream s;
    if (im == 0) {
        s << re;
    }
    else if (im < 0) {
        s << re << " - " << -im << "i";
    }
    else {
        s << re << " + " << im << "i";
    }
    return s.str();
}




