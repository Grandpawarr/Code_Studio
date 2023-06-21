#include <iostream>
using std::cout;
using std::endl;

//#include "Complex.h"
#include "Complex.cpp"

int main()
{
    Complex a, b, c; // create three Complex objects
    a.assign(1.0, 7.0);
    b.assign(9.0, 2.0);

    a.printComplex(); // output object a
    cout << " + ";
    b.printComplex(); // output object b
    cout << " = ";
    c = a.add(b);     // invoke add function and assign to object c
    c.printComplex(); // output object c
    cout << endl;
 
    a.printComplex(); // output object a
    cout << " - ";
    b.printComplex(); // output object b
    cout << " = ";
    c = a.subtract(b); // invoke subtract function and assign to object c
    c.printComplex();  // output object c
    cout << endl;

    a.printComplex(); // output object a
    cout << " * ";
    b.printComplex(); // output object b
    cout << " = ";
    c = a.multiply(b); // invoke multiply function and assign to object c
    c.printComplex();  // output object c
    cout << endl;

    a.printComplex(); // output object a
    cout << " / ";
    b.printComplex(); // output object b
    cout << " = ";
    c = a.division(b); // invoke division function and assign to object c
    c.printComplex();  // output object c
    cout << endl;

    return 0;
}