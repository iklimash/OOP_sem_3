#ifndef POLINOM_H
#define POLINOM_H
#include "iostream"
#include <sstream>

using namespace std;

template <class number>
class Polinom
{
    number* coefficients = nullptr;
    number* roots = nullptr;
    int degree = 0;
public:
    Polinom();

    Polinom* fill(number coefficientAn, number* roots, int rootsCount);

    number valueInPoint (number point);

    template<class T>
    friend ostream& operator<< (ostream& os, const Polinom &polinom);

    ostringstream polinomWithDegrees();

    ostringstream polinomWithRoots();
};

template <class number>
Polinom<number>::Polinom(): coefficients(nullptr), roots(nullptr), degree(0) {}

template <class number>
Polinom<number> *Polinom<number>::fill(number leadingCoefficient, number* roots, int rootsCount)
{
    Polinom* polinom = new Polinom();
    polinom->roots = roots;
    polinom->coefficients = new number [rootsCount];
    polinom->coefficients[0] = leadingCoefficient;
    if(rootsCount > 1){
        polinom->degree = rootsCount - 1;
        for (int i = 1; i <= polinom->degree; ++i) {
            polinom->coefficients[i] = 0;
        }
        for (int i = 0; i < polinom->degree; ++i) {
            number root = roots[i];
            for (int j = i; j >= 0; --j) {
                polinom->coefficients[j + 1] += polinom->coefficients[j];
                polinom->coefficients[j] *= root * -1;
            }
        }
        for(int i = 0; i < rootsCount / 2; i++){
            swap(polinom->coefficients[i], polinom->coefficients[rootsCount - i - 1]);
        }
    }else polinom->degree = 0;
    return polinom;
}

template <class T>
ostream& operator<< (ostream& os, const Polinom<T> &polinom)
{
    os << "P(x) = ";
    if(polinom.roots == nullptr) {
        os << *(polinom.coefficients);
        return os;
    }
    if (*(polinom.coefficients) != 0){
        if(*(polinom.coefficients) != 1) os << " (" << *(polinom.coefficients) << ")x^" << polinom.degree;
        else os << "x^" << polinom.degree;
    }
    for ( int i = 1; i < polinom.degree - 1; i++ ){
        if (*(polinom.coefficients + i) != 0){
            os << " ";
            if(*(polinom.coefficients + i) > 0) os << "+ ";
            if (*(polinom.coefficients + i) != 1) os << "(" <<  *(polinom.coefficients + i) << ")x^" << polinom.degree - i;
            else os << "x^" << polinom.degree - i;
        }
    }
    if ( *(polinom.coefficients + polinom.degree - 1) != 0 ){
        if(*(polinom.coefficients + polinom.degree - 1) > 0){
            os << " + (" << *(polinom.coefficients + polinom.degree - 1) << ")x";
        }else os << " (" << *(polinom.coefficients + polinom.degree - 1) << ")x";
    }
    if ( *(polinom.coefficients + polinom.degree) != 0 ){
        if(*(polinom.coefficients + polinom.degree) > 0 ) os << " +" ;
        os << " (" << *(polinom.coefficients + polinom.degree) << ")";
    }
    return os;
}

template <class number>
number Polinom<number>::valueInPoint(number point)
{
    number sum = 0;
    if(degree == 0) return *(coefficients);
    for(int i = 0; i < degree; i++){
        number a = *(coefficients + i);
        number b = pow(point, degree - i);
        sum += a * b;
    }
    sum += *(coefficients + degree);
    return sum;
}

template <class number>
ostringstream Polinom<number>::polinomWithRoots()
{
    ostringstream s;
    s <<  "p(x) = ";
    if(*(coefficients) != 0) {
        if(*(coefficients) != 1) s << *(coefficients);
        for(int i = 0; i < degree; i++){
            if(*(roots + i) != 0){
                if (*(roots + i) > 0) {
                    s << "(x -" << *(roots + i) << ")";
                } else {
                    s << "(x +" << (*(roots + i) * -1) << ")";
                }
            }else{
                s << "x";
            }
        }
    }else{
        s << "0";
    }
    return s;
}



template <class number>
ostringstream Polinom<number>::polinomWithDegrees() {
    ostringstream s;
    s << "p(x) = ";
    if(roots == nullptr) {
        s << *(coefficients);
        return s;
    }
    if (*(coefficients) != 0){
        if(*(coefficients) != 1) s << " (" << *(coefficients) << ") x^" << degree;
        else s << "x^" << degree;
    }
    for ( int i = 1; i < degree - 1; i++ ){
        if (*(coefficients + i) != 0){
            s << " ";
            if(*(coefficients + i) > 0) s << "+";
            if (*(coefficients + i) != 1) s << "(" <<  *(coefficients + i) << ") x^" << degree - i;
            else s << "x^" << degree - i;
        }
    }
    if ( *(coefficients + degree - 1) != 0 ){
        if(*(coefficients + degree - 1) > 0){
            s << " + (" << *(coefficients + degree - 1) << ")x";
        }else s << " (" << *(coefficients + degree - 1) << ")x";
    }
    if ( *(coefficients + degree) != 0 ){
        if(*(coefficients + degree) > 0 ) s << " +" ;
        s << " (" << *(coefficients + degree) << ")";
    }
    return s;
}

#endif // POLINOM_H
