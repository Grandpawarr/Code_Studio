#include <iostream>
#include <string>
using namespace std;

namespace Evaluation
{
    typedef struct
    {
        int id;
        string name;
        int problem[9] = {0}; // 一位學生有9問題
        int time;
        int score = 0;
    } Student;
    // 取得學生各項數據
    void GetValue(Student &A);
    // 計算分數
    void CalculateScore(Student *st, int linenum);
    // 比較分數並排序
    void SortScore(Student *st, int number);
    void ShowAnswer(Student *st,int *array,int number);
}

namespace Evaluation
{
    void GetValue(Student &A, string mystr)
    {
        int pos = 0;
        int next;
        int iswh = 1; // 表示目前讀取字元是何者(id,name,proble,score)
        while (1)
        {
            pos = mystr.find_first_not_of(" ", pos);
            next = mystr.find_first_of(" ", pos);

            switch (iswh)
            {
            case 1:
                A.id = stoi(mystr.substr(pos, next - pos));
                iswh = 2;
                break;
            case 2:
                A.name = mystr.substr(pos, next - pos);
                iswh = 3;
                break;
            case 3:
                for (int i = 0; i < 9; i++)
                {
                    A.problem[i] = stoi(mystr.substr(pos, pos + 1));
                    if (i < 8)
                    {
                        pos += 2;
                    }
                }
                next = mystr.find_first_of(" ", pos);
                iswh = 4;
                break;
            case 4:
                A.time = stoi(mystr.substr(pos, next - pos));
                break;
            default:
                break;
            }

            pos = next++;

            if ((pos > mystr.size()) || (next <= 0) || (next > mystr.size()))
                break;
        }
    }
    void CalculateScore(Student *st, int linenum)
    {
        for (int i = 1; i < linenum; i++)
        {
            // 比較分，並給總分
            for (int j = 0; j < 9; j++)
            {
                if (st[1].problem[j] == st[i].problem[j])
                {
                    if (j < 3)
                    {
                        st[i].score += 10;
                    }
                    else if (2 < j < 6)
                    {
                        st[i].score += 20;
                    }
                    else if (5 < j)
                    {
                        st[i].score += 30;
                    }
                }
            }
            // 如果分數大於100，就將其化作100
            if (st[i].score > 100)
            {
                st[i].score = 100;
            }
        }
    }
    void SortScore(Student *st, int number)
    {
        // 將id匯入陣列
        int *tmp = new int[number];
        for (int i = 1; i < number; i++)
        {
            tmp[i] = st[i].id;
        }
        // 氣泡排序
        for (int i = 2; i < number; i++)
        {
            for (int j = i + 1; j < number; j++)
            {
                // 比分數
                if (st[tmp[i]].score < st[tmp[j]].score)
                {
                    swap(tmp[i], tmp[j]);
                    // 分數相等看time
                }
                else if ((st[tmp[i]].score == st[tmp[j]].score) && (st[tmp[i]].time > st[tmp[j]].time))
                {
                    swap(tmp[i], tmp[j]);
                }
            }
        }
        //顯示答案
        ShowAnswer(st,tmp,number);

        delete []tmp;
    }
    void ShowAnswer(Student *st,int *array,int number){
        for(int i=1;i<number;i++){
            cout<<st[array[i]].id<<"  "<<st[array[i]].name<<"  "
                <<st[array[i]].score<<"  "<<st[array[i]].time<<endl;
        }
     }
}
