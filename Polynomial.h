#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<vector>


class Polynomial{
private:
    std::vector<double> a;//the coefficient of every member
public:
    int len() const;
    Polynomial();//default init
    ~Polynomial();
    Polynomial(int len,double *m);//use double[] to init
    Polynomial(const Polynomial &A);//copy init
    void init_legal();
    Polynomial& operator+(const Polynomial& A);
    Polynomial& operator-(const Polynomial& A);
    Polynomial& operator*(const Polynomial& A);
    Polynomial& operator/(const Polynomial& A);
};


#endif _POLYNOMIAL_H