#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//計算txt字元數
int calchar(string st)
{   
    // calculate characters
    int stnum = 0, pos = 0, next = 0;
    for (int i = 0; i < st.length(); i++)
    {
        pos = st.find_first_not_of(" ", pos);
        next = st.find_first_of(" ", pos);
        if (pos < st.length())
        {
            if (isspace(st[pos]))
            {
                break;
            }
            else
            {
                stnum++;
            }

            if (next == -1)
            {
                break;
            }
        }
        else
        {
            break;
        }
        pos = next + 1;
    }

    return stnum;
}

//cout character in string
void lineout(int stnum,string st){
    st.erase(st.length()-1);//erase the last character in string
    // show characters
    int  pos = 0, next = 0;
    while (1)
    {
        pos = st.find_first_not_of(" ", pos);
        next = st.find_first_of(" ", pos);
        if (pos < st.length())
        {
            cout << " \"" << st.substr(pos, next - pos) << "\" ";
            if (stnum > 1)
            {
                cout << ",";
            }else if(stnum==1){
                break;
            }
        }
        else
        {
            break;
        }
        stnum--;
        pos=next+1;
    }
}

//create new txt
void createtxt(string filename)
{
    ofstream newfile;
    newfile.open(filename);

    newfile << "I am Charles." << endl
            << "I am a handsome boy." << endl
            << "I love C++ programing." << endl;
    newfile.close();
}

void exercise01(string filename)
{
    createtxt(filename);

    ifstream myfile;
    myfile.open(filename);

    if(myfile.fail()){
        cout<<"This file is not exist"<<endl;
    }

    int linenum=1;
    string line;
    while (getline(myfile,line))
    {
        int stnum=calchar(line);
        cout<<"line "<<linenum<<" has "<<stnum<<" words,";
        lineout(stnum,line);
        cout<<endl;
        linenum++;
    }
}

int main()
{
    exercise01("lab10ex10-1.1.txt");
}