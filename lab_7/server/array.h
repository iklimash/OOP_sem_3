#ifndef ARRAY_H
#define ARRAY_H

#include "iostream"

using namespace std;

template <class number>
class Array
{
public:

    Array(int length = 0);
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

template <class number>
Array<number>::Array(int length)
{
    if (length < 0){
        this->length = 0;
        std::cout << "Неверно введена длина\n"
                     "длина = 0";
    }
    this->length = length;
    arr = new number[length];
}

template <class number>
Array<number>::~Array()
{
    delete[]arr;
}
template <class number>
int Array<number>::getLength()
{
    return this->length;
}
template <class number>
void Array<number>::insertValue()
{
    for (int i = 0; i < length; i++)
    {
        cin >> *(arr + i);
    }
}
template <class number>
bool Array<number>::resize(int newLength)
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
template <class number>
void Array<number>::printArray()
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
template <class number>
number  Array<number>::avgValue()
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
template <class number>
number Array<number>::CKO()
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
template <class number>
void Array<number>::insertionSortASC()
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
template <class number>
void Array<number>::insertionSortDESC()
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
template <class number>
bool Array<number>::changeValue(int index, number value)
{
    if (index < 0 || index >= length)
    {
        return false;
    }
    *(arr + index) = value;
    return true;
}


#endif // ARRAY_H
