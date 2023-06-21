#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;

#include "Matrix.h"

int Matrix::RandBucket(int Min, int Max)
{
    // srand(0);

    int number = Max - Min + 1;
    const int bucket = RAND_MAX / (number);
    int r;
    do
    {
        r = rand() / bucket;
    } while (r >= number);

    return Min + r;
}

void Matrix::assignDimension(int n)
{
    row = n;
    array = new int *[row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new int[row];
    }
}

void Matrix::assignElements()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            array[i][j] = RandBucket(0, 20);
        }
    }
}

void Matrix::printMatrix()
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << std::setw(5) << array[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::assignMatrix(Matrix A)
{
    assignDimension(A.row);
    // 拷貝ARRAY
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            array[i][j] = A.array[i][j];
        }
    }
}

void Matrix::transposeMatrix()
{
    // 創建轉置矩陣
    int **transpos = new int *[row];
    for (int i = 0; i < row; i++)
    {
        transpos[i] = new int[row];
    }

    // 轉置矩陣
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            transpos[i][j] = array[j][i];
        }
    }
    // 釋放記憶體
    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }

    delete[] array;

    // 將轉置矩陣放入Class陣列中
    array = transpos;

    return;
}

Matrix Matrix::addMatrix(Matrix B)
{
    // create class.C
    Matrix C;
    C.assignDimension(row);

    // add
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            C.array[i][j] = array[i][j] + B.array[i][j];
        }
    }

    return C;
}

Matrix Matrix::subtractMatrix(Matrix B)
{
    // create class.C
    Matrix C;
    C.assignDimension(row);

    // SUB
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            C.array[i][j] = array[i][j] - B.array[i][j];
        }
    }

    return C;
}

Matrix Matrix::multiplyMatrix(Matrix B)
{
    // create class.C
    Matrix C;
    C.assignDimension(row);

    // multiply
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            C.array[i][j] = array[i][j] * B.array[i][j];
        }
    }

    return C;
}
