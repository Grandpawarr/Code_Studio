#include <iostream>
#include <string>
using namespace std;

// FUNCTION PASSING DYNAMIC ARRAY
//*****1D*************
int *New1DArray(const int n)
{
    int *vec = new int[n];
    return vec;
}

void Initial1DArray(int *vec, const int n)
{
    for (int idx = 0; idx < n; idx++)
    {
        vec[idx] = idx;
    }
}

void Display1DArray(int *vec, const int n)
{
    for (int idx = 0; idx < n; idx++)
    {
        cout << vec[idx] << " ";
    }
    cout << endl;
}

void Delete1DArray(int *vec)
{
    delete[] vec;
}

void task01()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int *vec = New1DArray(n);
    Initial1DArray(vec, n);
    Display1DArray(vec, n);
    Delete1DArray(vec);
}

//*****2D*************
int **New2DArray(const int m, const int n)
{
    int **mat = new int *[m];
    for (int idx = 0; idx < m; idx++)
        mat[idx] = new int[n];

    return mat;
}

void Initial2DArray(int **mat, const int m, const int n)
{
    for (int idx = 0; idx < m; idx++)
    {
        for (int jdx = 0; jdx < n; jdx++)
            mat[idx][jdx] = idx + jdx;
    }
}

void Display2DArray(int **mat, const int m, const int n)
{
    for (int idx = 0; idx < m; idx++)
    {
        for (int jdx = 0; jdx < n; jdx++)
            cout << mat[idx][jdx] << " ";
        cout << endl;
    }
}

void Delete2DArray(int **mat, const int n)
{
    for (int idx = 0; idx < n; idx++)
        delete[] mat[idx];

    delete[] mat;
}

void task011()
{
    int m, n;
    cout << "Enter the size of column : " << endl;
    cin >> m;
    cout << "Enter the size of raw : " << endl;
    cin >> n;

    int **vec = New2DArray(m, n);
    Initial2DArray(vec, m, n);
    Display2DArray(vec, m, n);
    Delete2DArray(vec, n);
}

// POINTER TO STRUCTURE
//----NORMAL--------
typedef struct
{
    long id;
    string name;
    int age;
    char gender;
} student;

student AssignStudent(long id, string name, int age, char gender)
{
    student member;
    member.id = id;
    member.name = name;
    member.age = age;
    member.gender = gender;
    return member;
}

void DisplayStudent(const student &member)
{
    cout << "name: " << member.name << endl;
    cout << "id: " << member.id << endl;
    cout << "age: " << member.age << endl;
    cout << "gender: " << member.gender << endl;
}

void task02()
{
    student uee_a = AssignStudent(9823014, "Tommy", 20, 'F');
    student uee_b = AssignStudent(9823183, "Mary", 21, 'M');

    DisplayStudent(uee_a);
    DisplayStudent(uee_b);
}

//----pointer--------
student *AssignStudent01(long id, string name, int age, char gender)
{
    student *member = new student;

    //Note that you have to use operator -> to access the member of a pointer type object. 
    member->id = id;
    member->name = name;
    member->age = age;
    member->gender = gender;
    return member;
}

void task021()
{
    student *uee_a = AssignStudent01(9823014, "Tommy", 20, 'F');
    student *uee_b = AssignStudent01(9823183, "Marry", 21, 'M');

    DisplayStudent(*uee_a);
    DisplayStudent(*uee_b);

    delete uee_a;
    delete uee_b;
}
int main()
{
    task01();
    cout<<"......................."<<endl;
    task011();
    cout<<"......................."<<endl;
    task02();
    cout<<"......................."<<endl;
    task021();
    cout<<"......................."<<endl;

    return 0;
}