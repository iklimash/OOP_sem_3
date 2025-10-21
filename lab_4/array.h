#include "number.h"
#include "iostream"

#pragma once
class Array
{
public:

    Array(int length);
    ~Array();
    int getLength();
    void insertValue();
    bool resize(int newLength);
    void printArray();
    number avgValue();
    number CKO();
    void insertionSortASC();
    void insertionSortDESC();
    bool changeValue(int index, number value);
private:
    int length;
    number* arr;
};
