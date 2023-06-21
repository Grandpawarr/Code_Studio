#include<iostream>
#include<iomanip>
using namespace std;

//BASIC STRUCTURE OF A C++ PROGRAM 
int task01(){
    cout<<"I_am_Lin.\nMy_number_in_ROCKETS_is_7."<<endl;
    cout<<"I_am_Lin. << endl << My_number_in_ROCKETS_is_7."; 

    return 0;
}

//CONSOLE INPUT FUNCTION – cin 
int task02(){
    int a,b,sum;
    cout<<"Enter the first integer"<<endl;
    cin>>a;
    cout<<"Enter the second integer"<<endl;
    cin>>b;
    sum=a+b;
    cout<<"Their sum is "<<sum<<endl;

    return 0;
}

//CONSOLE OUTPUT cout WITH MANIPULATORS 
int task03(){
    //setw:設定列印時的欄位寬度，若為浮點數，小數點也佔一位。(右對齊)
    //fixed:固定小數點
    //scientific:以科學計法寫浮點值
    float a=716.54564;
    cout<<"The original number is "<<a<<endl;
    cout<<"The number with set precision 3 is "<<setprecision(3)<<a<<endl;
    cout<<"The number with set precision 6 is "<<setprecision(6)<<a<<endl;
    cout<<"The number in showpoint decimal notation is "<<setw(10)<<showpoint<<setprecision(6)<<a<<endl;
    cout<<"The number in fix-point decimal notation is "<<setw(10)<<fixed<<showpoint<<setprecision(6)<<a<<endl;
    cout<<"The number in exponential notation is "<<setw(10)<<scientific<<setprecision(3)<<a<<endl;

    return 0;
}

//DATA TYPES AND DECLARATION 
int task04(){
    char a;
    int b;
    float c;
    double d;

    cout<<"Byte of one character:\t"<<sizeof(a)<<endl
        <<"Byte of one integer:\t"<<sizeof(b)<<endl
        <<"Byte of one float:\t"<<sizeof(c)<<endl
        <<"Byte of one doble:\t"<<sizeof(d)<<endl;

    int intResult=7/3;
    float fltResult=7/3;

    cout<<intResult<<endl
        <<fltResult<<endl;
    
    intResult=int(12.6/3);
    fltResult=12.6/3;
    cout<<intResult<<endl
        <<fltResult<<endl;

        return 0;
}

//VARIABLE ASSIGNMENT 
int task05(){
    int x,y;
    cout<<"x ="<<x<<endl;
    cout<<"y ="<<y<<endl;
    
    y=25;
    cout<<"x ="<<x<<endl;
    cout<<"y ="<<y<<endl;
    
    x=10;
    cout<<"current value of x is ="<<x++<<endl;
    cout<<"current value of x is ="<<++x<<endl;
    cout<<"current value of x is ="<<x<<endl;    
    
    return 0;
}

int exercises(){
    int x,y;
    cout<<"Enter the first number"<<endl;
    cin>>x;
    cout<<"Enter the second number"<<endl;
    cin>>y;
    cout<<x<<"+"<<y<<"="<<(x+y)<<endl
        <<x<<"-"<<y<<"="<<(x-y)<<endl
        <<x<<"*"<<y<<"="<<(x*y)<<endl
        <<x<<"/"<<y<<"="<<(x/y)<<endl;
    
    float z;
    cout<<"Please enter the base floating point number:"<<endl;
    cin>>z;
    cout<<"10 to the power of 1,2,3 and 4 are"<<endl
        <<setw(10)<<fixed<<setprecision(3)<<z*1<<endl
        <<setw(10)<<fixed<<setprecision(3)<<z*z<<endl
        <<setw(10)<<fixed<<setprecision(3)<<z*z<<endl
        <<setw(10)<<fixed<<setprecision(3)<<z*z*z*z<<endl;

    return 0;

}


int main(){
    //task01();
    //task02();
    //task03();
    //task04();
    //task05();
    exercises();
    return 0;
}