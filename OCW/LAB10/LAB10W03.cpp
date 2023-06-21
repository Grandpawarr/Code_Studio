#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f_mfc(string str)
{
    str+="/";
    string mystr[100];
    int mystr_num[100]={0};
    int idx = 0;

    while (1)
    {
        string str1;
        for (char &i : str)
        {
            if (isspace(i) || i == '/')
            {
                for (int j = 0; j <= idx; j++)
                {
                    if (str1 != mystr[j]&&j==idx)
                    {
                        mystr[idx] = str1;
                        ++idx;
                        str1 = "";
                        break;
                    }else if(str1==mystr[j]){
                        mystr_num[j]++;
                        break;
                    }
                }
                str1="";
            }
            else
            {
                str1 += i;
            }
        }
        break;
    }
    
    //cout character frequency
    cout<<"The each character frequently is: "<<endl;
    for (int i=0;i<idx;i++)
    {
        cout <<(i+1)<<"."<< mystr[i] << ":"<<mystr_num[i]<<endl;       
    }
}
int main()
{
    // choose fuction
    /*int fuc=0;
    cout<<"Please which fuction do you need"<<endl
        <<"1.Most Frequent Character  Write "<<endl
        <<"2.ReplaceSubstring Funttion"<<endl
        <<"3.User Name "<<endl;
    cin>>fuc;
    switch (fuc)
    {
    case 0:
        f_mfc();
        break;
    default:
        break;
    }*/
    f_mfc("Write a function that accepts either a pointer to a C-String, or a string object, as its argument");

    return 0;
}