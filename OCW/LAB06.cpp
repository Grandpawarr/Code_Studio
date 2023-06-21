#include <iostream>
using namespace std;

double fS1(double n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += ((double)1 / i);
    }

    return sum;
}

double fS2(double n)
{
    double num = 1, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        num *= i;
        sum += double(1 / num);
    }

    return sum;
}
// w01
void exercises01()
{
    int n;
    cout << "Enter an integer value for the number of order n: ";
    cin >> n;
    cout << "The result of S1 and S2 are:" << endl;
    cout << "S1 = " << fS1(n) << endl;
    cout << "S2 = " << fS2(n) << endl;
}

void fRect()
{
    float length, width;
    cout << "Please enter the Length and Width respectively." << endl;
    cin >> length;
    cin >> width;
    cout << "The perimeter of a rectangular with (Length,Width) = (" << length << "," << width << ") is "
         << (length + width) * 2 << endl;
}

void fSquare()
{
    float length;
    cout << "Please enter the Length." << endl;
    cin >> length;
    cout << "The perimeter of a square with (Length) = (" << length << ") is "
         << length * 4 << endl;
}

void fCircle()
{
    float radius;
    cout << "Please enter the radius of the circle. " << endl;
    cin >> radius;
    cout << "The perimeter of a circle with (Radius) = (" << radius << ") is "
         << 2 * radius * 3.14 << endl;
}
// w02
void exercises02()
{
    int choose;

    while (choose != 4)
    {
        cout << "===================" << endl
             << "1.Rectangular 2.Square 3.Circle 4.Exit" << endl
             << "Choose the type of perimeter you want to calculate:" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            fRect();
            break;
        case 2:
            fSquare();
            break;
        case 3:
            fCircle();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Please follow the instruction carefully." << endl;
            break;
        }
    }
}
int main()
{
    // exercises01();
    exercises02();
    system("pause");
    return 0;
}