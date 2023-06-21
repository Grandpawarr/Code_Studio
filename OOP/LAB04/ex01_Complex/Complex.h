#ifndef COMPLEX_H 
#define COMPLEX_H 
 
/* Write class definition for Complex */ 
 class Complex
 {
 private:
    double x;
    double y;
 public:
    void assign(double n1,double n2);
    void printComplex();
    Complex add(Complex b);
    Complex subtract(Complex b);
    Complex multiply(Complex b);
    Complex division(Complex b);
 };

#endif