#include<iostream>
#include "lab1_ex01.h"
using namespace std;
using namespace Complex;



int main(){
    Cplex N1;
    Cplex N2;

    GetValue(N1);
    GetValue(N2);

    ShowComplex(N1,N2);
    

    return 0;
}