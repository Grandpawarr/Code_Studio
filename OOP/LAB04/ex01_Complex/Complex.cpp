#include <iostream> 
using std::cout; 
 
#include "Complex.h" 
// Member-function definitions for class Complex. 
inline void Complex::assign(double n1,double n2)
 {
    x=n1;
    y=n2;
 }

 inline void Complex::printComplex(){
    cout<<"("<<x<<","<<y<<")";
 }

 Complex Complex::add(Complex b){
    Complex c;
    c.x=(x+b.x);
    c.y=(y+b.y);

    return c;
 }

  Complex Complex::subtract(Complex b){
    Complex c;
    c.x=(x-b.x);
    c.y=(y-b.y);

    return c;
 }

  Complex Complex::multiply(Complex b){
    Complex c;
    c.x=(x*b.x)-(y*b.y);
    c.y=(x*b.y)+(y*b.x);

    return c;
 }

  Complex Complex::division(Complex b){
    Complex c;
    c.x=(x/b.x);
    c.y=(y/b.y);

    return c;
 }