#include <iostream>
using namespace std;

// PARAMETER PASSING
void fSwap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void task01()
{
    int x = 5, y = 6;
    cout << "x= " << x << " and y= " << y << endl;
    fSwap(x, y);
    cout << "x= " << x << " and y= " << y << endl;
}

// FUNCTION INPUT & OUTPUT
void sumavg(double n1, double n2, double n3, double &sum, double &avg)
{
    sum = n1 + n2 + n3;
    avg = (n1 + n2 + n3) / 3;
}

void task02()
{
    double n1, n2, n3, sum, avg;
    sum = 0.0;
    avg = 0.0;
    cout << "Please enter score of three students" << endl;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    sumavg(n1, n2, n3, sum, avg);
    cout << "The total score of three students is " << sum << endl;
    cout << "The average score of three students is " << avg << endl;
}

// RECURSION
int ff(int x)
{
    if (x % 2 == 0)
        return x / 2;
    else
        return ff(ff(3 * x + 1));
}

void task03()
{
    cout << "Enter i: ";
    int i;
    cin >> i;
    cout << "f(" << i << ") = " << ff(i) << endl;
}

// w01
long long fDecimal(long long n)
{
    long long i, a[20], b = 0;
    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }

    for (i = i - 1; i >= 0; i--)
    {
        b = b * 10 + a[i];
    }

    return b;
}

void exercise01()
{
    long long a;
    while (a > 0)
    {
        cout << "Enter a decimal value: " << endl;
        cin >> a;
        if (a < 0)
            break;
        cout << "The binary value of (" << a << ") is " << fDecimal(a) << endl;
    }
    cout << "Exit" << endl;
}

// W02z
int fGCD(int a1, int a2)
{
    if (a1 < a2)
    {
        swap(a1, a2);
    }

    if (a2 == 0)
    {
        return a1;
    }

    return fGCD(a2, a1 % a2);
}

int fLCD(int a1, int a2)
{
    return (a1 * a2 / fGCD(a1, a2));
}

void exercise02()
{
    int a[5], gcd, lcd;
    cout << "Input five integer number: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        if (i == 1)
        {
            gcd = fGCD(a[0], a[1]);
            lcd = fLCD(a[0], a[1]);
        }
        else if (i >= 2)
        {
            gcd = fGCD(a[i], gcd);
            lcd = fLCD(a[i], lcd);
        }
    }
    cout << "g.c.d. : " << gcd << endl;
    cout << "l.c.m. : " << lcd << endl;
}

int main()
{
    // task01();
    // task02();
    exercise01();
    exercise02();

    return 0;
}