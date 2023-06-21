#include <cstdlib>
#include "Data.h"
#include "Item.h"
/*
差區間實作
*/

// 讀取txt01+建立data數據
vector<Data> readfile_data(string);
vector<Item> readfile_item(string);

int main()
{
    
    vector<Data> DataObjects=readfile_data("ex8_1_1.txt");
    vector<Item> ItemObjects=readfile_item("ex8_1_2.txt");
    
    for(auto &i:DataObjects){
        for(int j=0;j<i.obj_num();j++){
            for(auto &k:ItemObjects){
                if(i.showObject(j)==k.names){
                    i.AddValue(k.Damage,k.Armor);
                }
            }
        }
    }

    for(auto &i:DataObjects){
        i.show();
    }


    return 0;
}

vector<Data> readfile_data(string filename)
{
    ifstream infile(filename);

    string word;
    vector<Data> dataObjects;
    while (getline(infile, word))
    {
        Data newData(word);
        dataObjects.push_back(newData);
    }

    infile.close();

    return dataObjects;
}

vector<Item> readfile_item(string filename)
{
    ifstream infile(filename);

    if (!infile)
    {
        std::cerr << "無法打開文件！" << std::endl;
    }

    vector<Item> ivec;

    Item newitem;
    string word;
    while (getline(infile, word))
    {
        if (word.substr(0,1) == "}")
        {
            //cout << newitem.names << ':' << newitem.Damage << ',' << newitem.Armor << endl;
            ivec.push_back(newitem);
        }
        else if (word.substr(0, 4) == "Item")
        {
            int temppoision=word.find('{')-1;
            newitem.names = word.substr(5,(temppoision-5));
        }
        else if (word.substr(4, 5) == "Armor")
        {
            newitem.Armor = stoi(word.substr(10, 2));
        }
        else if (word.substr(4, 6) == "Damage")
        {
            newitem.Damage = stoi(word.substr(11, 2));
        }
    }

    infile.close();

    return ivec;
}