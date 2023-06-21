#include <iostream>
#include <iomanip>
using namespace std;

const int MaxSize = 10;

int fRandom(int min, int max);
void DisplayMatrix(const int[][MaxSize], const int, const int);
void GenerateMatrix(int[][MaxSize], const int, const int);
void SortMatrix(int[][MaxSize], const int, const int);
void InsertionSort(int[], const int);

int main()
{
    int numrows, numcols;
    int IntMatrix[MaxSize][MaxSize];

    cout << "Please enter the number of rows: ";
    cin >> numrows;
    cout << "Please enter the number of columns: ";
    cin >> numcols;

    cout << "The original matrix is" << endl;
    GenerateMatrix(IntMatrix, numrows, numcols);
    DisplayMatrix(IntMatrix, numrows, numcols);
    SortMatrix(IntMatrix, numrows, numcols);
    cout << "The modified matrix is" << endl;
    DisplayMatrix(IntMatrix, numrows, numcols);

    return 0;
}

int fRandom(int min, int max)
{
    int num = max - min + 1;
    int bucket = RAND_MAX / num;
    int r;
    do
    {
        r = rand() / bucket;
    } while (r >= num);

    return r;
}

void GenerateMatrix(int array[][MaxSize], const int numrows, const int numcols)
{
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numcols; j++)
        {
            array[i][j] = fRandom(0, 20);
        }
    }
}

void DisplayMatrix(const int matrix[][MaxSize], const int numrows, const int numcols)
{
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numcols; j++)
        {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

void SortMatrix(int array[][MaxSize], const int numrows, const int numcols)
{
    int vec[MaxSize];
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numcols; j++)
        {
            vec[j] = array[i][j];
        }
        InsertionSort(vec, numcols);
        for (int j = 0; j < numcols; j++)
        {
            array[i][j] = vec[j];
        }
    }
}

void InsertionSort(int vec[], const int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = vec[j];
        int i = j - 1;

        while (i >= 0 && vec[i] < key)
        {
            vec[i + 1] = vec[i];
            --i;
        }
        vec[i + 1] = key;
    }
}