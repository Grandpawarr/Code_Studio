#include<iostream>
using namespace std;

//FLOW CONTROL STATEMENT - for 
void task01(){
    for(int i=1;i<=10;i++){
        for(int j=1;j<=i;j++)
           cout<<j<<" ";
        cout<<endl;
    }
}

//FLOW CONTROL STATEMENT - while 
void task02(){
    int i=1;
    while(i<=10)
       cout<<i++<<endl;
}

void exercise01(){
    int size;
    cout<<"Enter the size of multiplication table(1~9): ";
    cin>>size;
    while(size<0||size>9){
        cout<<"The size of multiplication table should be 1~9."<<endl;
        cout<<"Enter the size of multiplication table(1~9): ";
        cin>>size;      
    }
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++)
          cout<<i<<" * "<<j<<" = "<<i*j<<"     ";
        cout<<endl;
    }      
}

void exercise02(){
    int number;
    cout<<"Enter an integer value:"<<endl;
    cin>>number;
    cout<<"All prime numbers below 28 are:"<<endl;
    for(int i=2;i<=number;i++){
        for(int j=2;j<=i;j++){
            if((i%j==0)&&(j!=i)){
                break;
            }else if(j==i){
                cout<<i<<"  ";
            }
        }
    }
}

int main(){
    //task01();
    //task02();
    //exercise01();
    exercise02();


    return 0;
}