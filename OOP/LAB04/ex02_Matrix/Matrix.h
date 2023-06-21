class Matrix
{
private:
    int row;
    int **array;
    int RandBucket(int Min, int Max); // create  random number
public:
    void assignDimension(int n);     // create three Matrix objects
    void assignElements();           // assign elements in Matrix A randomly
    void printMatrix();              // output object A
    void assignMatrix(Matrix A);     // copy elements and dimension from A
    void transposeMatrix();          //  transpose Matrix tA
    Matrix addMatrix(Matrix B);      // C = A + B
    Matrix subtractMatrix(Matrix B); // C = A - B
    Matrix multiplyMatrix(Matrix B); // C = A * B
};
