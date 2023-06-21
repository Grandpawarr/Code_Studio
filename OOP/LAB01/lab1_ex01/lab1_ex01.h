// lab1_ex01.h
#include <iostream>
#include <string>
using namespace std;

namespace Complex
{
    typedef struct
    {
        double number_int;
        double number_img;
    } Cplex;
    // 從輸入取的整數和虛數值
    void GetValue(string str, const Cplex &A);
    // 計算各函式(A+B)
    void ShowComplex(const Cplex &A, const Cplex &B);
}

namespace Complex
{
    void GetValue(Cplex &A)
    {
        string mystr;
        cout << "Please type number: " << endl;
        cin >> mystr;

        string str_in, str_im;
        bool isin = 1; // 判斷目前是讀取整數還是虛數
        for (int i = 0; i < (mystr.size() - 1); i++)
        {
            if ((mystr[i] == '+') || (mystr[i] == '-') && (isin) && (i != 0))
            {
                str_im += mystr[i];
                isin = 0;
            }
            else if (isin == 1)
            {
                str_in += mystr[i];
            }
            else if (isin == 0)
            {
                str_im += mystr[i];
            }
        }

        A.number_int = stof(str_in);
        A.number_img = stof(str_im);
        // cout << str_in << ',' << str_im << endl;
    }

    void ShowComplex(const Cplex &A, const Cplex &B)
    {
        float answer_int;
        float answer_img;

        answer_int = A.number_int + B.number_int;
        answer_img = A.number_img + B.number_img;

        if (answer_img >= 0)
        {
            cout << answer_int << '+' << answer_img << 'i' << endl;
        }
        else
        {
            cout << answer_int << answer_img << 'i' << endl;
        }
    }
}