class Vec
{
private:
    int dim;
    int *array;

public:
    Vec():dim(0){};
    Vec(int *vec, int dimension) : array(vec), dim(dimension) {}
    ~Vec();

    void printVec();     // print array;
    void sort();         // sort array
    bool isEqual(Vec B); // judge the message if vec1 and vec2 are the same or not
    void unionSet(Vec A,Vec B);  // union set of vec1 and vec2 
    int min();//return minimun in array
    int max();//returm maximun in array
    bool find(int target);//find target in array
    Vec inpendetSet();//find inpendentSet in array

    void tt(Vec A,Vec B);
};