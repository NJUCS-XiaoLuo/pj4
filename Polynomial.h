#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include<vector>
#include<iostream>
#include<string>

using namespace std;


class Polynomial{
private:
    std::vector<double> a;//the coefficient of every member
public:
    string name;
    int len() const;
    Polynomial();//default init
    ~Polynomial();
    Polynomial(int len,double *m);//use double[] to init
    Polynomial(const Polynomial &A);//copy init
    void AssignName(string Pname);
    string GetName(){return this->name;}
    void init_legal();
    Polynomial& operator+(const Polynomial& A);
    Polynomial& operator-(const Polynomial& A);
    Polynomial& operator*(const Polynomial& A);
    Polynomial& operator/(const Polynomial& A);
    friend ostream &operator << (ostream &putout, const Polynomial &A);
};


#endif _POLYNOMIAL_H