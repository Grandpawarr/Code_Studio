#include <iostream>
#include <string>
using namespace std;
// 交錯字串(12):https://apcs.csie.ntnu.edu.tw/wp-content/uploads/2022/10/%E5%AF%A6%E4%BD%9C%E9%A1%8C_%E9%A1%8C%E5%9E%8B%E7%AF%84%E4%BE%8B.pdf

int ffun01(string str, int k)
{
    int maxlen = 0, cnt = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if ((isupper(str[i]) && islower(str[i - 1])) || (islower(str[i]) && isupper(str[i - 1])))
        {
            cnt++;
        }
        else
        {
            if (cnt > 0)
            {
                maxlen = max(maxlen, cnt);
            }
            cnt = 1;
        }
    }

    return maxlen;
}

int ffun02(string str, const int k)
{
    int maxlen = 0, cnt = 0;
    int strnum = k;
    bool start = 0;

    for (int i = 0; i <= str.size(); i++)
    {
        if ((i == 0) && isupper(str[0]) || (isupper(str[i]) && islower(str[i - 1])) || (isupper(str[i]) && start == 0))
        {
            for (int j = i + 1; j < (i + k);)
            {
                if (isupper(str[j]))
                {
                    if (j == (i + k - 1))
                    {
                        if ((!islower(str[j + 1])) && !start)
                        {
                            break;
                        }
                        start = 1;
                        cnt += k;
                        i = j;
                        break;
                    }
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        else if ((i == 0) && islower(str[0]) || (islower(str[i]) && isupper(str[i - 1])) || (islower(str[i]) && (start == 0)))
        {
            for (int j = i + 1; j < (i + k);)
            {
                if (islower(str[j]))
                {
                    if (j == (i + k - 1))
                    {
                        if ((!isupper(str[j + 1])) && !start)
                        {
                            break;
                        }
                        start = 1;
                        cnt += k;
                        i = j;
                        break;
                    }
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (cnt > 0)
            {
                maxlen = max(cnt, maxlen);
            }
            cnt = 0;
        }
    }

    return maxlen;
}

int main()
{
    int k;
    cout << "cin  k:";
    cin >> k;

    string str;
    cout << "cin string: " << endl;
    cin>>str;

    if(k==1){
        cout<<"answer: "<<ffun01(str,k);
    }else if(k>1){
        cout<<"answer: "<<ffun02(str,k);
    }

    return 0;
}