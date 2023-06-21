#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class Data
{
public:
    Data(string str);
    void show() const;
    void AddValue(int a,int b);//計算Damage,Armor數值
    string showObject(int i) const;
    int obj_num() const; // 回傳obj數量

private:
    string player;
    vector<string> obj;
    int Damage = 0;
    int Armor = 0;
};

Data::Data(string str)
{
    bool isfirst = 1; // 判斷是否為player
    string str_temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            str_temp += str[i];
        }
        else
        {
            if (isfirst)
            {
                player = str_temp;
                isfirst = 0;
            }
            else
            {
                obj.push_back(str_temp);
            }
            str_temp = "";
        }
    }
}

void Data::show() const
{
    cout << player << ": ";
    cout<<"Damage:"<<Damage<<',';
    cout<<"Armor:"<<Armor<<endl;
}

void Data::AddValue(int a,int b){
    Damage+=a;
    Armor+=b;
}
string Data::showObject(int i) const
{
    return (obj[i]);
}

int Data::obj_num() const
{
    return (obj.size());
}