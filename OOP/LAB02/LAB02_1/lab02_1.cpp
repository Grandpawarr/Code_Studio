#include <fstream>
#include "Evaluation.h"
using namespace Evaluation;

//******第一固定為答案

// 取得文件行數
int GetLineNum(string);
//取得Student_setting
Student *GetSetting(string,int);

int main()
{
    string filename = "score.text";
    //取得行數
    int line_num = GetLineNum(filename);
    //取得各學生參數
    Student *st=GetSetting(filename,line_num);
    //計算總分
    CalculateScore(st,line_num);
    //排序+顯示
    SortScore(st,line_num);

    return 0;

    delete []st;
}

int GetLineNum(string filename)
{
    ifstream infile(filename);

    string textline;
    int line_num = 0;
    while (getline(infile, textline, '\n'))
    {
        line_num++;
    }
    infile.close();

    return (line_num);
}

Student *GetSetting(string filename,int linenum){
    ifstream infile(filename);

    Student *tmp=new Student[linenum];
    string textline;
    int i = 0;
    // 建立資料庫student
    while (getline(infile, textline, '\n'))
    {
        GetValue(tmp[i], textline);
        i++;
    }

    return tmp;
}