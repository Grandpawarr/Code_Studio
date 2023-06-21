#include <iostream>
using namespace std;

void fshowpoly(int size, int array[])
{
    bool isbegan; // 判斷此數值是否為陣列開始

    for (int i = 0; i <= size; i++)
    {
        if (i == 0)
        {
            if (array[i] == 0)
            {
                isbegan = 0;
                continue;
            }
            else
            {
                isbegan = 1;
                cout << array[i] << "X^" << (size - i) << " ";
            }
        }
        else if (i == size) // 表最後一個不用X
        {
            if (array[i] == 0)
            {
                continue;
            }
            else if (array[i] < 0)
            {
                cout << "- " << array[i] * (-1) << " ";
            }
            else
            {
                if (!isbegan)
                {
                    isbegan = 1;
                    cout << array[i] << " ";
                }
                else
                {
                    cout << " +" << array[i] << " ";
                }
            }
        }
        else // 中間的要X
        {
            if (array[i] == 0)
            {
                continue;
            }
            else if (array[i] < 0)
            {
                if (array[i] == -1)
                {
                    cout << "- X^" << (size - i) << " ";
                }
                else
                {
                    cout << "- " << array[i] * (-1) << "X^" << (size - i) << " ";
                }
            }
            else
            {
                if (array[i] == 1)
                {
                    if (!isbegan)
                    {
                        isbegan = 1;
                        cout << " X^" << (size - i) << " ";
                    }
                    else
                    {
                        cout << "+ X^" << (size - i) << " ";
                    }
                }
                else
                {
                    if (!isbegan)
                    {
                        isbegan = 1;
                        cout << array[i] << "X^" << (size - i) << " ";
                    }
                    else
                    {

                        cout << "+ " << array[i] << "X^" << (size - i) << " ";
                    }
                }
            }
        }
    }
    cout << endl;
}

void fadd(const int c1[], const int p1, const int c2[], const int p2)
{
    int gap = p1 - p2; // p1 p2間距

    cout << "Sum = ";
    if (gap == 0)
    { // 代表p1 p2相等
        int tatol[p1+1];
        for (int i = 0; i <= p1; i++)
        {
            tatol[i] = c1[i] + c2[i];
        }
        fshowpoly(p1, tatol);
    }
    else if (gap > 0)
    { // 代表p1>p2
        int tatol[p1+1];
        for (int i = 0; i <= p1; i++)
        {
            if (i >= gap)
            {
                tatol[i] = c1[i] + c2[i - gap];
            }
            else
            {
                tatol[i] = c1[i];
            }
        }
        fshowpoly(p1, tatol);
    }
    else if (gap <= 0)
    { // 代表p1<p2
        int tatol[p2];
        for (int i = 0; i < p2; i++)
        {
            if (i >= (gap * -1))
            {
                tatol[i] = c1[i - gap] + c2[i];
            }
            else
            {
                tatol[i] = c2[i];
            }
        }

        fshowpoly(p2, tatol);
    }

    cout << endl;
}
// EXERCISES
void exercise01()
{
    // polynomial 1
    int p1;
    cout << "Please enter the degree of polynomial 1: ";
    cin >> p1;

    int c1[p1 + 1];
    cout << "Please enter the coefficient in order: ";
    for (int &i : c1)
    {
        cin >> i;
    }

    cout << "Polynomial 1 is ";
    fshowpoly(p1, c1);

    // polynomial 2
    int p2;
    cout << "Please enter the degree of polynomial 2: ";
    cin >> p2;

    int c2[p2 + 1];
    cout << "Please enter the coefficient in order: ";
    for (int &i : c2)
    {
        cin >> i;
    }

    cout << "Polynomial 2 is ";
    fshowpoly(p2, c2);

    fadd(c1, p1, c2, p2);
}

int main()
{
    exercise01();
    return 0;
}