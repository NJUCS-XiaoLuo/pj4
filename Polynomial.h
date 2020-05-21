#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include<vector>
#include<iostream>
#include<string>

using namespace std;


class Polynomial{
private:
    string name;
    //vector<double> a;//the coefficient of every member
public:
    vector<double> a;//the coefficient of every member
    int len() const;//获得多项式的长度
    Polynomial();//default init
    ~Polynomial();
    Polynomial(int len,double* m);//use double[] to init
    Polynomial(const Polynomial &A);//copy init
    void AssignName(string& Pname);//给多项式赋予名字
    string GetName(){return this->name;}//获得多项式的名字
    void init_legal();//将多项式标准化
    //加减乘除
    Polynomial& operator+(const Polynomial& A);
    Polynomial& operator-(const Polynomial& A);
    Polynomial& operator*(const Polynomial& A);
    Polynomial& operator/(const Polynomial& A);
    friend ostream &operator << (ostream &putout, const Polynomial &A);//对输出的重载
    Polynomial integral();//求不定积分函数（默认C=0）
    Polynomial coefficient();//求导
    double definite_integral(double m_n,double M_n);//求定积分函数
    double value(double x);//求值函数，用来算出函数在某点的值

};


#endif _POLYNOMIAL_H