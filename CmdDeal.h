#ifndef _CMDDEAL_H
#define _CMDDEAL_H

#include"Polynomial.h"
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


class CmdDeal{
private:
    vector<Polynomial> Po;
public:
    CmdDeal(){Po.clear();}
    ~CmdDeal(){Po.clear();}
    bool AddPo(int len,int* m,string name);
};






#endif _CMDDEAL_H