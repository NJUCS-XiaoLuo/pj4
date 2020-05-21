#include"CmdDeal.h"
#include"Polynomial.h"
#include"Window.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool CmdDeal::AddPo(int mysize,double* M,string pname){
    for(int i=0;i<pname.size();i++){
        if(!((pname[i]>='A'&&pname[i]<='Z')||(pname[i]>='a'&&pname[i]<='z')))return false;
    }
    Polynomial P=Polynomial(mysize,M);
    P.AssignName(pname);
    Po.push_back(P);
    return true;
}

bool CmdDeal::ScanPo(string name){
    for(int i=0;i<Po.size();i++){
        if(name==Po[i].GetName()){
            cout<<name<<"="<<Po[i]<<endl;
            return true;
        }
    }
    return false;
}

