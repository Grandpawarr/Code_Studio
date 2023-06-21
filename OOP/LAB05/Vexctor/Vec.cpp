#include <iostream>
using namespace std;

#include "Vec.h"

Vec::~Vec(){
    delete[] array;
    //cout<<"Constructor executed"<<endl;
}

void Vec::printVec()
{
    for (int i = 0; i < dim; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Vec::sort()
{
    for (int i = 1; i < dim; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] < array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}

bool Vec::isEqual(Vec B)
{
    bool isequal;
    if (dim != B.dim)
    {
        cout << "Dimension is not same" << endl;
        isequal = 0;
    }
    else
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < B.dim; j++)
            {
                if (array[i] != array[j])
                {
                    isequal = 0;
                }
            }
        }
    }

    return isequal;
}

void Vec::unionSet(Vec A, Vec B)
{
    dim = A.dim + B.dim;
    array = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        if (i < A.dim)
        {
            array[i] = A.array[i];
        }
        else
        {
            array[i] = B.array[i - A.dim];
        }
    }
}

int Vec::min()
{
    return array[0];
}

int Vec::max()
{
    return array[dim - 1];
}

bool Vec::find(int target)
{
    int b;
    for (int i = 0; i < dim; i++)
    {
        if (target == array[i])
        {
            b = 1;
        }
        else
        {
            b = 0;
        }
    }

    return b;
}

Vec Vec::inpendetSet()
{
    Vec A;
    for (int i = min(); i <= max(); i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i == array[j])
            {
                A.dim++;
                if ((A.dim) - 1 == 0)
                {
                    A.array = new int[1];
                }
                else
                {
                    int *tmp = new int[A.dim];
                    for (int idx = 0; idx < A.dim; idx++)
                    {
                        tmp[idx] = A.array[idx];
                    }
                    delete[] A.array;
                    A.array = tmp;
                }
                A.array[A.dim - 1] = i;
                break; 
            }
        }
    }

    return A;
}

void Vec::tt(Vec A, Vec B)
{
    cout << A.dim << "," << B.dim << "," << dim << endl;
}