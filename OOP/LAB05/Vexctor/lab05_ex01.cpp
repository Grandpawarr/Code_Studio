#include <string>
#include "Vec.cpp"

int size;
// read numbers from screen for array
int *ReadArray(int *);
void Equaltype(bool); // is two array equal?
void isfindInVec(bool,int);// is find target number in array?

int main()
{
    int *array1, *array2;
    int dim1, dim2;

    array1 = ReadArray(array1);
    dim1 = size;
    array2 = ReadArray(array2);
    dim2 = size;

    Vec vec1(array1, dim1);
    Vec vec2(array2, dim2);
    cout << "vec1(sorted) : ";
    vec1.sort();
    vec1.printVec();

    cout << "vec2(sorted) : ";
    vec2.sort();
    vec2.printVec();

    bool isEqual = vec1.isEqual(vec2);
    Equaltype(isEqual);

    Vec vec3;
    vec3.unionSet(vec1, vec2); // vec3 is union set of vec1 and vec2

    vec3.sort();
    cout << "vec3(sorted) : ";
    vec3.printVec();

    cout << "Min in vec1 and vec2 : " << vec3.min() << endl;
    cout << "Max in vec1 and vec2 : " << vec3.max() << endl;

    int target = 10;
    bool findInVec = vec3.find(target);
    isfindInVec(findInVec,target);

    Vec vec4;
    vec4 = vec3.inpendetSet();
    cout << "vec4 : ";
    vec4.printVec();

    delete[] array1;
    delete[] array2;

    return 0;
}

int *ReadArray(int *array)
{
    cout << "Enter the elements for array (-1 to end):" << endl;

    string element; // type element in array

    int num = 0; // array number;
    while (cin >> element)
    {

        if (element == "-1")
        {
            break;
        }
        num++;
        // first time setting array
        if ((num)-1 == 0)
        {
            array = new int[num - 1];
        }
        else
        {
            int *tmp = new int[num];
            for (int i = 0; i < num; i++)
            {
                tmp[i] = array[i];
            }
            delete[] array;
            array = tmp;
        }
        array[num - 1] = stoi(element);
    }
    // return arraysize to dim
    size = num;
    return array;
}

void Equaltype(bool isequal)
{
    if (isequal)
    {
        cout << "vec1 is equal to vec2 " << endl;
    }
    else
    {
        cout << "vec1 is not equal to vec2 " << endl;
    }
}

void isfindInVec(bool i,int x){
    if(i){
        cout<<"Target "<<x<<" is found in vec1 or vec2 "<<endl;
    }else{
        cout<<"Target "<<x<<" cannot be found in vec1 or vec2 "<<endl;
    }
}