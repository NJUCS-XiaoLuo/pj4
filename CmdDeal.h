#ifndef _CMDDEAL_H
#define _CMDDEAL_H


#include"Polynomial.h"
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;


class CmdDeal{
private:
    vector<Polynomial> Po;
public:
    string tempn;//临时多项式名称，用于拆出多项式的名字
    stack<Polynomial> mypo;
    int dot;//判断小数点是否已经出现
    double num;
    int de;
    CmdDeal(){Po.clear();}
    ~CmdDeal(){Po.clear();}
    bool AddPo(int mysize,double* M,string pname);
    bool ScanPo(string name);
    int findpo(string name);
    int calculate(string ex);
    int analy(string ex,int p);
    struct ope{
        char op;
        int integ;
        int add;
        int de;
        int coe;
        int x,y;
        Polynomial a,b;
        ope():integ(0),add(0),de(0),coe(0){};
    };
    stack<ope> myop;
};






#endif _CMDDEAL_H