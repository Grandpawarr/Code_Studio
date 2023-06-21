#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// FILE INPUT STREAM
void task01()
{
    ifstream in_file;
    in_file.open("lab10-1.txt");

    int vali;
    double vald;
    char valc[50];

    in_file >> vali >> vald >> valc;

    cout << "Integer number in file: " << vali << endl;
    cout << "Floating number in file: " << vald << endl;
    cout << "Character in file: " << valc << endl;

    in_file.close();
}

// FILE OUTPUT STREAM
void task02()
{
    char *filename;
    cout << "Enter the filename :";
    cin >> filename;

    ofstream out_file(filename);

    int n;
    cout << "Enter an number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        out_file << i << endl;
    }

    cout << "Write file lab10-2.txt done!" << endl;
    out_file.close();
}

// FILE INPUT STREAM: IFSTREAM
void task03()
{
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream in_file;
    in_file.open(filename.c_str());//convert the data type from string to c-string. 
    if (in_file.fail())
    {
        cout << "File " << filename << "does not exist!!" << endl;
        exit(1);
    }

    int num, count = 0;

    while (in_file >> num)
    //returns true if the read operation succeeds and returns false when the program attempts to read beyond the end of the file. 
    {
        cout << count << ": " << num << endl;
        ++count;
    }

    in_file.close();
}

void task032(string filename)
{
    ifstream in_file(filename);
    if (in_file.fail())
    {
        cout << "File " << filename << "does not exist!!" << endl;
        exit(1);
    }

    string textline;
    int count = 0;
    while (getline(in_file, textline, '\n'))
    {
        cout << count << " : " << textline << endl;
        ++count;
    }

    in_file.close();
}

//FILE OUTPUT STREAM: OFSTREAM 
void task04(){
    ofstream myfile;
    myfile.open("lab10-4.txt",ios::app);
    /*ios::in, ios::out and ios::app are three types of mode to open a file. 
    ios::in and ios::out mean the files are of read and write states, respectively. 
    In ios::out mode, the stream will clean out the information in an existing file and write the text in the beginning of file. 
    However, the program writes the new text from the end of file under the ios::app mode.*/
    myfile<<"new words"<<endl;
    myfile.close();
}
int main()
{
    // task01();
    // task02();
    //task03();
    //task032("lab10-4.txt");
    task04();

    return 0;
}