#include <iostream>
#include <string.h>
using namespace std;
//using dynamic array to implement sorting 
void InsertionSort(int *, int);
int *ArrayPush(int *, int, int);
void ArrayDisplay(int *, int);

int main()
{
    int *array;
    int array_size;

    cout << "Enter a size first: ";
    cin >> array_size;

    cout << "Enter a sequence (stop by -1): " << endl;
    array = new int[array_size];
    int wordx, array_pos = -1;

    while (cin >> wordx)
    {
        if (wordx == -1)
            break;

        array_pos++;
        if (array_pos < array_size)
        {
            array[array_pos] = wordx;
        }
        else
        {
            array = ArrayPush(array, array_size, wordx);
            array_size++;
        }
    }

    InsertionSort(array,array_size);
    ArrayDisplay(array, array_size);

    delete[] array;
    return 0;
}

int *ArrayPush(int *vec, int size, int x)
{
    int *tmp = new int[size + 1];
    memcpy(tmp, vec, sizeof(vec) * size); 
    delete []vec;
    vec=tmp;
    vec[size++] = x;

    return vec;
}

void ArrayDisplay(int *vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;
}

void InsertionSort(int *vec, int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = vec[j];
        int i = j - 1;
        while ((i >= 0) && (vec[i] > key))
        {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}