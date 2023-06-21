#include<iostream>
using namespace std;

//FLOW CONTROL STATEMENT - if 
int task01(){
    int x=3,y=5;
    if(x==3)
      cout<<"x= "<<x<<endl;
    if(y!=5)
      cout<<"y= "<<y<<endl;
    
    cout<<"Please enter one number"<<endl;
    cin>>x;
    if((x>=5)&&(x<2))
      cout<<"HIT"<<endl;
    else
      cout<<"x= "<<x<<" is not in range"<<endl;

    return 0;
}

// FLOW CONTROL STATEMENT – if Chain 
int task02(){
    float score;
    char grade;
    cout<<"Enter your score: ";
    cin>>score;
    if(score >=80.0)
    grade='A';
    else if(score >=70.0)
    grade='B';
    else if(score >=60)
    grade='C';
    else
    grade='F';

    cout<<"Your get level "<<grade<<endl;

    return 0;
}

//FLOW CONTROL STATEMENT –  switch  
int task03(){
    char sym;
    cout<<"Enter a symbol: ";
    cin>>sym;
    
    switch (sym)
    {
    case 'a':
        cout<<"The symbol is one 'a'"<<endl;
        break;
    case 'b':
        cout<<"The symbol is one 'b'"<<endl;
        break;
    case 'c':
        cout<<"The symbol is one 'c'"<<endl;
        break;
    default:
        cout<<"The symbol is not 'a','b' or 'c'"<<endl;
        break;
    }

    return 0;
}

//mora
int exercises01(){
    char p1,p2;
    cout<<"Enter s,r,p for player1: ";
    cin>>p1;
    cout<<"Enter s,r,p for player2: ";
    cin>>p2;
    switch (p1)
    {
    case 's':
        if(p2=='s') cout<<"Two players tie"<<endl;
        else if(p2=='r') cout<<"Player2 win!"<<endl;
        else if(p2=='p') cout<<"Player1 win!"<<endl;
        break;
    case 'r':
        if(p2=='s') cout<<"Player1 win!"<<endl;
        else if(p2=='r') cout<<"Two players tie"<<endl;
        else if(p2=='p') cout<<"Player2 win!"<<endl;
        break;
    case 'p':
        if(p2=='s') cout<<"Player2 win!"<<endl;
        else if(p2=='r') cout<<"Player1 win!"<<endl;
        else if(p2=='p') cout<<"Two players tie"<<endl;
        break;
    default:
        break;
    }

    return 0;
}
// book-buying system. 
int exercises02(){
    char type;
    int cost,number;
    bool buy=0;
    cout<<"Welcome to the book-buying system!!"<<endl
        <<"The following are the list and the cost:"<<endl
        <<"(A)Computer Science: An Overview   $30"<<endl
        <<"(B)Absolute C++   $20"<<endl
        <<"(C)C++ How to Program   $40"<<endl
        <<"Please enter A, B, C to choose the book:"<<endl;
    cin>>type;
    switch (type)
    {
    case 'A':
        cost=30;
        buy=1;
        break;
    case 'B':
        cost=20;
        buy=1;
        break;
    case 'C':
        cost=40;
        buy=1;
        break;    
    default:
        cout<<"Sorry,item ("<<type<<") doesn't on our list"<<endl;
        buy=0;
        break;
    }
     
    if(buy){
        cout<<"Now enter the quantity of books: ";
        cin>>number;
        cout<<"The total cost of item ("<<type<<") is "<<cost*number<<". Thanks for your coming."<<endl;
    }

    return 0;
}

int main(){
    //task01();
    //task02();
    //task03();
    exercises01();
    //exercises02();
    system("pause");

    return 0;
}