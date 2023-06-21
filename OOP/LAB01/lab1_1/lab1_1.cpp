#include <iostream>
#include "lab1_1.h"
///*******have some problem**********
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
