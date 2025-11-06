#include "array.h"
#include <iostream>

using namespace std;

Array::Array(int length)
{
    if (length < 0)
    {
        this->length = 0;
        cout << "Значение не может быть меньше 0";
    }
    else
    {
        this->length = length;
    }
    arr = new number[this->length];
}

Array::~Array()
{
    delete[]arr;
}

int Array::getLength()
{
    return this->length;
}
void Array::insertValue()
{
    for (int i = 0; i < length; i++)
    {
        cin >> *(arr + i);
    }
}
bool Array::resize(int newLength)
{
    if (newLength < 0)
    {
        return false;
    }
    number* newArray = new number[newLength];
    int copySize = (length < newLength) ? length : newLength;

    for (int i = 0; i < copySize; i++) {
        newArray[i] = arr[i];
    }

    for (int i = length; i < newLength; i++) {
        newArray[i] = 0;
    }

    delete[] arr;
    arr = newArray;
    length = newLength;

    return true;
}
void Array::printArray()
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i];
        if (i != (length - 1))
        {
            cout << ", ";
        }

    }
}
number  Array::avgValue()
{
    if (length == 0) return 0;
    number sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += *(arr + i);
    }

    sum /= ((double)length);
    return sum;
}
number Array::CKO()
{
    if (length <= 1) return 0;
    number ckoValue = 0;
    number avg = avgValue();
    if (length <= 1)
    {
        return ckoValue;
    }
    for (int i = 0; i < length; i++)
    {
        ckoValue += pow(*(arr + i) - avg, 2);
    }
    ckoValue /= ((double)length - 1);
    ckoValue = pow(ckoValue, 0.5);
    return ckoValue;
}

void Array::insertionSortASC()
{
    for (int i = 1; i < length; i++)
    {
        number key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Array::insertionSortDESC()
{
    for (int i = 1; i < length; i++)
    {
        number key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
bool Array::changeValue(int index, number value)
{
    if (index < 0 || index >= length)
    {
        return false;
    }
    *(arr + index) = value;
    return true;
}
