#include <iostream>
#include <cstring> //old
#include <cctype>
#include <string> //new
using namespace std;

// C-STRING
void task01()
{
    char stringA[20] = {'C', '+', '+', '\0'};
    char stringB[20] = "Programming";

    cout << "length of " << stringA << " is " << strlen(stringA) << endl;
    cout << "length of " << stringB << " is " << strlen(stringB) << endl;

    char stringC[20];

    // Copy stringA to stringC
    strcpy(stringC, stringA);
    cout << stringC << endl;

    // Concatenate " " and stringB to stirngC
    strcat(stringC, " ");
    strcat(stringC, stringB);
    cout << stringC << endl;

    // Clear StringC
    // strcpy(stringC, "");

    // compare characters of two strings(true:0/false:-1)
    cout << "Enter a new word :";
    cin.getline(stringC, 20);
    if (!strcmp(stringC, stringB))
        cout << "the two strings are same!" << endl;
    else
        cout << "the two strings are different @@" << endl;
}

// CCTYPE(strlen is in cstring)
void task02()
{
    char stringA[80];
    cout << "Enter a sentence:" << endl;
    cin.getline(stringA, 80);

    int numalpha = 0, numdigit = 0, numspace = 0,
        len = strlen(stringA);
    for (int i = 0; i < len; i++)
    {
        char c = stringA[i];
        if (isalpha(c))
        {
            stringA[i] = toupper(c);
            numalpha++;
        }
        else if (isdigit(c))
        {
            numdigit++;
        }
        else if (isspace(c))
        {
            numspace++;
        }
    }

    cout << "New sentence is: " << endl;
    cout << stringA << endl;
    cout << "Number of alphas is " << numalpha << endl;
    cout << "Number of digits is " << numdigit << endl;
    cout << "Number of spaces is " << numspace << endl;
}

// CLASS STRING
void task03()
{
    string heading = "Hello";
    string ending("Welcome to my house !!");
    string name;
    cout << "Enter your name : ";
    cin >> name;

    string sentence = heading + ", " + name + "!!" + ending;
    cout << sentence << endl;
}

// CLASS STRING  MEMBER FUNCTION
void task04()
{
    string str;
    cout << "Enter a sentence :" << endl;
    getline(cin, str);
    int pos = str.find("nctu");//return "nctu" position
    if (pos == string::npos)
    {
        cout << "nctu is not found !!" << endl; 
    }
    else
    {
        cout << "nctu is found at pos : " << pos << endl;
    }
    cout << "Substring from str[2] to str[4] is " << str.substr(2, 3) << endl;

}


int main()
{
    // task01();
    //task02();
    //task03();
    //task04();


    return 0;
}
