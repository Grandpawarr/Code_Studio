#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// ENUM
enum baseball
{
    FIRSTBAT = 1,
    SECONDBAT = 2,
    THIRDBAT = 3,
    FOURTHBAT = 4
};
void task01()
{

    baseball BatOrder = baseball(3);
    if (BatOrder == THIRDBAT)
    {
        cout << "The BatOrder is THIRDBAT" << endl;
    }
}

// STRUCTURE
struct Time
{
    int hours;
    int minutes;
    int seconds;
};
Time fSetTime()
{
    Time now;
    cout << "Please Enter Current Time" << endl;
    cout << "Current hour: ";
    cin >> now.hours;
    cout << "Current minute:";
    cin >> now.minutes;
    cout << "Current second:";
    cin >> now.seconds;

    return now;
}
void fShowSeconds(const Time &now)
{
    int seconds = 0;
    seconds = now.hours * 3600 + now.minutes * 60 + now.seconds;
    cout << "Total seconds of today: " << seconds << endl;
}
void task02()
{
    Time t = {0, 0, 0};
    t = fSetTime();

    fShowSeconds(t);
}

// ARRAY AS ARGUMENT
void fDisplayArray(int vec[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void fInsertionSort(int vec[], int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = vec[j];
        int i = j - 1;

        while (i >= 0 && vec[i] > key)
        {
            vec[i + 1] = vec[i];
            --i;
        }
        vec[i + 1] = key;
    }
}
int fRandBucket(int min = 1, int max = 100)
{
    int number = max - min;
    const int bucket = RAND_MAX / number;
    int r;
    do
    {
        r = rand() / bucket;
    } while (r >= number);

    return r;
}
void task03()
{
    const int MaxSize = 10;
    int array[MaxSize];
    for (int i = 0; i < MaxSize; i++)
    {
        array[i] = fRandBucket();
    }
    fDisplayArray(array, MaxSize);
    fInsertionSort(array, MaxSize);
    fDisplayArray(array, MaxSize);
}

// TWO-DIMENSIONAL ARRAY
const int numrows = 3, numcols = 4;
void fFun(int vec[][numcols])
{
    cout << "Display the multiplied elements";
    // int val[numrows][numcols];
    int val[numrows][numcols] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < numrows; i++)
    {
        cout << endl;
        for (int j = 0; j < numcols; j++)
        {
            // val[i][j] = fRandBucket(0, 999);
            cout << left << setw(5) << val[i][j];
        }
    }
}
void task04()
{
    int vel[numrows][numcols];
    fFun(vel);
}

// C-STRING
void task05()
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

    cout << "Enter a sentence: ";
    cin.getline(stringA, 20);

    cout << "Enter another  sentence: ";
    cin.getline(stringB, 20);

    // compare A and B
    if (strcmp(stringA, stringB))
    {
        cout << stringA << " != " << stringB << endl;
    }
    else
    {
        cout << stringA << " == " << stringB << endl;
    }
}

// HOME WORK01
struct Student
{
    long id;
    char gender;
    int age;
    int money;
};
Student fSet(int num, Student std[])
{
    cout << "Please enter your student " << num + 1 << " id:";
    cin >> std[num].id;

    cout << "Gender (M/F): ";
    cin >> std[num].gender;

    cout << "Age: ";
    cin >> std[num].age;

    cout << "The amount of money in your own: ";
    cin >> std[num].money;

    return std[num];
}
void fShow(int num, const Student std[])
{
    string a, b, c;

    // age
    if (std[num].age < 21)
    {
        a = "young";
    }
    else
    {
        a = "adult";
    }

    // money
    if (std[num].money > 10000)
    {
        b = "rick";
    }
    else
    {
        b = "poor";
    }

    // Gender
    if (std[num].gender == 'M')
    {
        c = "Male";
    }
    else
    {
        c = "Female";
    }

    // show
    cout << "id " << std[num].id << " is a " << a << " & " << b << " " << std[num].gender << "! " << endl;
}
void fTotal(int num, const Student std[])
{
    float years, cash;
    for (int i = 0; i < num; i++)
    {
        years += std[i].age;
        cash += std[i].money;
    }
    cout << "This group is " << (years / num) << " years old in average. " << endl;
    cout << "This group has $" << (cash) << " now." << endl;
}
void exercise01()
{
    int num = 2;
    Student std[num];
    for (int i = 0; i < num; i++)
    {
        fSet(i, std);
    }

    for (int i = 0; i < num; i++)
    {
        fShow(i, std);
    }
    fTotal(num, std);
}

int main()
{
    // task01();
    // task02();
    task03();
    // task04();
    // task05();
    //exercise01();

    return 0;
}