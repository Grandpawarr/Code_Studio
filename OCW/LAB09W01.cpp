#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void exercise01()
{
    // type string
    string st;
    cout << "Enter a sentence:" << endl;
    getline(cin, st);
    cout << "your type is: " << st << endl;

    // calculate
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
    cout << "There are " << stnum << " words in your sentence." << endl;

    // show characters
    pos = next = 0;
    cout << "They are ";
    while (1)
    {
        pos = st.find_first_not_of(" ", pos);
        next = st.find_first_of(" ", pos);
        if (pos < st.length())
        {
            cout << "\"" << st.substr(pos, next - pos) << "\"";
            stnum--;
            if (stnum > 1)
            {
                cout << ",";
            }
            else if (stnum < 1)
            {
                break;
            }
            else
            {
                cout << " and ";
            }
        }
        else
        {
            break;
        }
        pos++;
    }
}

int main()
{
    exercise01();

    return 0;
}
