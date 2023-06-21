#include<iostream>
#include<cmath>
using namespace std;

//loop
void task01(){
    int a;
    cout<<"please enter the size of rectangle"<<endl; 
    cin>>a;
    for(int i=1;i<=a;i++){
        if(i==1||i==a)
          for(int j=1;j<=a;j++)
            cout<<"*";
        else
          for(int j=1;j<=a;j++)
            if(j==1||j==a)
              cout<<"*";
            else
              cout<<" "; 
        cout<<endl;
    }
}

// MATH CALCULATION 
void task02(){
    double x;
    cout<<"Enter a value: ";
    cin>>x;

    cout<<"sqrt("<<x<<")= "<<sqrt(x)<<endl;
    cout<<"floor("<<x<<")= "<<floor(x)<<endl;
    cout<<"ceil("<<x<<")= "<<ceil(x)<<endl;

}

//RAND
void Rand(){
    srand(0);

    cout<<"generate random number (1 to 10):"<<endl;
    for(int idx=0;idx<10;idx++){
        int x=rand()%10 +1;
        cout<<x<<" ";
    }
    cout<<endl;
}

int RandBucket(int Min,int Max){
    int number=Max-Min+1;
    const int bucket=RAND_MAX/(number);
    int r;
    do{
        r=rand()/bucket;
    }while(r>=number);

    return Min+r;
}

float fRand(float fMin,float fMax){
    float f=(double)rand()/RAND_MAX;

    return fMin+f*(fMax-fMin);
}

void Swap(int& a,int& b){
    int c=a;
    a=b;
    b=c;
}

int GCD(int v1,int v2){
    if(v1<v2)
      swap(v1,v2);
    if(v2==0)
      return v1;
    
    return GCD(v2,v1%v2);
}

int LCM(int v1,int v2){
    return v1*v2/GCD(v1,v2);
}

void exerices(){
    int v1,v2;
    cout<<"Input value 1:"<<endl;
    cin>>v1;
    cout<<"Input value 2:"<<endl;
    cin>>v2;

    cout<<"g.c.d.: "<<GCD(v1,v2)<<endl;
    cout<<"l.c.m.: "<<LCM(v1,v2);
}


int main(){
    //task01();
    //task02();
    //task03();
    /*for(int idx=1;idx<=10;idx++){
        cout<<RandBucket(100,2000)<<endl;
    }*/
    exerices();

    return 0;
}
