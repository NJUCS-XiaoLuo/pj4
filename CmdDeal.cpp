#include"CmdDeal.h"
#include"Polynomial.h"
#include"Window.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cctype>
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


int CmdDeal::findpo(string name){
    for(int i=0;i<this->Po.size();i++){
        if(name==this->Po[i].GetName())return i;
    }
    return -1;
}

int CmdDeal::analy(string ex,int p){
    if(p>=ex.size())return 0;
    if(p==0){
        tempn.clear();
        dot=0;
        de=0;
    }
    if(isalpha(ex[p])){
        tempn+=ex[p];
    }
    else{
        //如果遇到的不是字母，而tempn里面有东西，这说明多项式的名字已经结束了，可以推进栈
        if(!tempn.empty()){
            int index=findpo(tempn);
            if(index==-1)return -1;
            else {
                Polynomial temp=Po[index];
                mypo.push(temp);
            }
        }
        tempn.clear();
        /****************************************************/
        /***************以上是对于字母（多项式名称）的处理
         **************以下要对操作符号进行处理****************/
        /****************************************************/
        if(isdigit(ex[p])){
            if(dot==0)num=num*10+ex[p];
            else if(dot!=0){
                num=num+ex[p]*pow(10,-dot);
                dot++;
            }
        }
        else if(ex[p]=='.')dot==1;
        else{
            dot=0;
            num=0;
            if(de==1)num=num*(-1.0);

            /******************进行接下来的操作*************************/
        }
    }
    analy(ex,p+1);
}



int CmdDeal::calculate(string ex){

}