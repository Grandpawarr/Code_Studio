// lab1_1.h
namespace Complex
{
    typedef struct
    {
        double real;
        double image;
    } Cplex;

    const double pi = 3.1416;
    void showComplex(const Cplex &m);
}
/*
namespace Complex
{
    void showComplex(const Cplex &m)
    {
        std::cout << m.real;
        if (m.image < 0)
            std::cout << m.image << "i" << std::endl;
        else
            std::cout << "+" << m.image << "i" << std::endl;
    }
}*/