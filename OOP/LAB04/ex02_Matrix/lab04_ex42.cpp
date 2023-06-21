#include <iostream>
using namespace std;

#include "Matrix.cpp"

int main()
{
    int n;
    cout << "Enter n for n x n matrix: " << endl;
    cin >> n;

    Matrix A, B, C; // create three Matrix objects
    A.assignDimension(n);
    A.assignElements(); // assign elements in Matrix A randomly
    cout << "A = ";
    A.printMatrix(); // output object A
    cout << endl;

    B.assignDimension(n);
    B.assignElements(); // assign elements in Matrix B randomly
    cout << "B = ";
    B.printMatrix(); // output object B
    cout << endl;

    Matrix tA;
    tA.assignMatrix(A);   // copy elements and dimension from A
    tA.transposeMatrix(); // transpose Matrix tA
    cout << "A^t = ";
    tA.printMatrix(); // output object tA
    cout << endl;

    C = A.addMatrix(B); // C = A + B
    cout << "A+B = ";
    C.printMatrix(); // output object C
    cout << endl;

    C = A.subtractMatrix(B); // C = A - B
    cout << "A-B = ";
    C.printMatrix(); // output object C
    cout << endl;

    C = A.multiplyMatrix(B); // C = A * B
    cout << "A*B = ";
    C.printMatrix(); // output object C
    cout << endl;

    return 0;
}
