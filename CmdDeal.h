#ifndef _CMDDEAL_H
#define _CMDDEAL_H

#include"Polynomial.h"
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


class CmdDeal{
private:
    vector<Polynomial> Po;
public:
    CmdDeal(){Po.clear();}
    ~CmdDeal(){Po.clear();}
    bool AddPo(int mysize,double* M,string pname);
    bool ScanPo(string name);
};






#endif _CMDDEAL_H