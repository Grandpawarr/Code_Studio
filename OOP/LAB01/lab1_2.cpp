#include <iostream>

//  SCOPE OPERATOR(::)
const int n = 1000;
void task01(){
    int n = 10;
    std::cout << n << " " << ::n << std::endl;
    /*Scope operator can also indicate the member function under global namespace,
     as ::n is in this example */
}

// INLINE FUNCTIONS 
#define Area(x,y) ((x)*(y))
void task02(){
    double n=Area(3,5.1);
    std::cout<<"Area(3,5.1) = "<<n<<std::endl;
}
//***inline 是用來加速C++的執行速度，在程式碼的語法上不會有什麼太大的差異，但是在Compiler編譯時，卻會有不一樣的效果
inline double Area01(double x, double y){
    return x*y;
}
void task021(){
    double n=Area01(3,5.1);
    std::cout<<"Area(3,5.1) = "<<n<<std::endl;
}

//DIRECTIVES 
#ifndef PI
#define PI 3.14159
#endif
void task03(){
    std::cout<<PI<<std::endl;
}

int main()
{
    task01();
    task02();
    task021();
    task03();

    return 0;
}