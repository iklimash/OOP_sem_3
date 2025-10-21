#include "application.h"

#include <iostream>

using namespace std;

Application::Application()
{
}

void Application::mainMenu()
{
    int choice;

    while (true)
    {
        cout << "1 - Work with array\n";
        cout << "2 - Work with polinom\n";
        cout << "0 - Exit\n" << "> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            exec();
            break;
        case 2:
            appPolinom();
            break;
        case 0:
            return;
        default:
            cout << "Error input";
            break;
        }
    }
}

void Application::showMenu()
{
    cout << "1 - Create array\n";
    cout << "2 - Fill array\n";
    cout << "3 - Change array size\n";
    cout << "4 - Print array elements\n";
    cout << "5 - Calculate average\n";
    cout << "6 - Calculate CKO\n";
    cout << "7 - Sort in ascending order\n";
    cout << "8 - Sort in descending order\n";
    cout << "9 - Change element\n";
    cout << "0 - Exit\n" << "> ";
}

int Application::exec() {

    int choice;
    int len, newLen, index;
    number value;
    Array* array = new Array(0);
    while (true)
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter length array:\n" << "> ";
            cin >> len;
            array = new Array(len);
            cout << "Array " << len << " elements has been created \n";
            break;
        case 2:
            cout << "Enter " << array->getLength() << " elements:\n";
            array->insertValue();
            cout << "Array is full\n";
            break;

        case 3:
            cout << "Enter new length: "; cin >> newLen;
            array->resize(newLen);
            break;

        case 4:
            cout << "Array: ";
            array->printArray();
            cout << "\n";
            break;
        case 5:
            cout << "Average value: " << array->avgValue() << "\n";
            break;
        case 6:
            cout << "CKO equally: " << array->CKO() << "\n";
            break;
        case 7:
            array->insertionSortASC();
            cout << "Array is sorted in ascending order\n";
            break;
        case 8:
            array->insertionSortDESC();
            cout << "Array is sorted in descending order\n";
            break;
        case 9:
            cout << "Enter index and value\n>"; cin >> index; cin >> value;
            if (array->changeValue(index, value))
            {
                cout << "Element be changed\n";
            }
            else
            {
                cout << "Error change element\n";
            }
            break;
        case 0:
            delete array;
            return 0;
        default:
            cout << "Error number\n";
            break;
        }
    }

}


void Application::showMenuPolinom()
{
    cout << "1 - Fill polinom\n";
    cout << "2 - Change coefficient polinom\n";
    cout << "3 - Change root polinom\n";
    cout << "4 - Solution polinom in point\n";
    cout << "5 - Print polinom\n";
    cout << "0 - Exit\n" << "> ";
}

int Application::appPolinom()
{
    Polinom* polinom = new Polinom;
    int choice;
    number coefficientAn;
    int rootsCount = 0;
    number root;
    number* roots = NULL;


    while (true)
    {
        showMenuPolinom();
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (roots != nullptr)
            {
                delete[] roots;
                roots = nullptr;
                rootsCount = 0;
            }
            cout << "Input coefficient an = ";
            cin >> coefficientAn;
            cout << "0 - There are no roots\n";
            cout << "1 - Input root polinom\n";
            cout << "> ";
            cin >> choice;
            if (choice != 0)
            {
                cout << "Input root polinom: ";
                roots = new number[rootsCount];
                while (cin >> root)
                {
                    number *temp = new number[rootsCount + 1];
                    for (int i = 0; i < rootsCount; i++)
                    {
                        temp[i] = roots[i];
                    }
                    temp[rootsCount] = root;
                    rootsCount += 1;
                    delete[] roots;
                    roots = temp;
                    if (cin.peek() == '\n')
                    {
                        break;
                    }
                }
            }
            delete polinom;
            polinom = polinom->fill(coefficientAn, roots, rootsCount + 1);
            break;
        case 2:

            cout << "Input coefficient please: ";
            cin >> coefficientAn;
            delete polinom;
            polinom = polinom->fill(coefficientAn, roots, rootsCount + 1);
            cout << *polinom << endl;

            break;

        case 3:
            int index;
            cout << "Input index: ";
            cin >> index;
            if(rootsCount == 0) {
                cout << "Root is nullptr\n";
                break;
            }
            cout << "Input new root: ";
            cin >> *(roots + index);
            delete polinom;
            polinom = polinom->fill(coefficientAn, roots, rootsCount + 1);
            break;

        case 4:

            int point;
            cout << "Input point please: ";
            cin >> point;
            cout << 'P' << '(' << point << ')' << " = " << polinom->valueInPoint(point) << endl;
            break;

        case 5:
            cout << *polinom << endl;
            break;
        case 0:
            delete polinom;
            polinom = nullptr;
            return 0;
        default:
            break;
        }
    }
}






