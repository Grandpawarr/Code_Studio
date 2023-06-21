#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//change txt
string fixtxt(string str)
{
    string str1="",str_out="";
    int line_num=0;
    for(int i=0;i<str.length();i++){
        line_num++;
        if(isspace(str[i])){
            if(line_num>60){
                str_out+="\n"+str1+str[i];
                line_num=str1.length()+1;
                str1="";
            }else{
                str_out+=str1+str[i];
                str1="";
            }
        }else if(str[i]==','){
            if(str1.find("$")==0||isspace(str[i+1])){
                str1+=str[i];
                continue;
            }else{
                str_out+=str1+str[i]+" ";
                str1="";
                line_num++;
            }
        }else if(str[i]=='.'){
            str_out+=str1+str[i]+"\n";
            line_num=0;
            str1="";
        }else{
            str1+=str[i];
        }
    }

    return str_out;
}

// write string in txt
void wfile(string filename, string str)
{
    ofstream ofile;
    ofile.open(filename);

    if (ofile.is_open())
    {
        cout << "done" << endl;
    }

    ofile << str;
    ofile.close();
}

int main()
{
    string filename;
    cout<<"Enter the filename to change the txt: ";
    cin>>filename;

    ifstream myfile;
    myfile.open(filename);

    if (myfile.fail())
    {
        cout << "This file is not exist" << endl;
    }else{
        string str;
        getline(myfile, str);
        str=fixtxt(str);
        wfile(filename,str);
    }

    system("pause");

    return 0;
}