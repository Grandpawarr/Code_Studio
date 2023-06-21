#include <iostream>
#include "lab1_1.h"
//#include"lab1_1.cpp"
using namespace Complex;
// NAMESPACES 

namespace Complex
{
    void showComplex(const Cplex &m)
    {
        std::cout << m.real;
        if (m.image < 0)
            std::cout << m.image << "i" << std::endl;
        else
            std::cout << "+" << m.image << "i" << std::endl;
    }
}

int main()
{
    Cplex n;
    n.real = 1 * pi;
    n.image = -0.5;
    showComplex(n);

    return 0;
}