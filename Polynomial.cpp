#include"Polynomial.h"
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

#define min 1e-6

int Polynomial::len() const{
    return a.size();
}

Polynomial::~Polynomial(){
    a.clear();
}
Polynomial::Polynomial(){
    a.clear();
}

Polynomial::Polynomial(int len,double *m){
    a.clear();
    for(int i=len-1;i>=0;i--){
        a.push_back(m[i]);
    }
    init_legal();
}

Polynomial::Polynomial(const Polynomial &A){
    a.clear();
    for(int i=0;i<A.len();i++){
        this->a.push_back(A.a[i]);
    }
    init_legal();
}

void Polynomial::AssignName(string Pname){
    this->name=Pname;
}


void Polynomial::init_legal(){
    for(int i=this->len()-1;i<this->len();i--){
        if(a[i]==0)a.pop_back();
    }
    return;
}


Polynomial& Polynomial::operator+(const Polynomial& A){
    Polynomial front(*this);
    Polynomial back(A);
    if(front.len()<back.len()){
        for(int i=0;i<back.len()-front.len();i++){
            front.a.push_back(0);
        }
    }
    else if(front.len()>back.len()){
        for(int i=0;i<front.len()-back.len();i++){
            back.a.push_back(0);
        }
    }
    int size=max(front.len(),back.len());
    double* tem=new double[50];
    for(int i=0;i<size;i++){
        tem[i]=front.a[i]+back.a[i];
    }
    Polynomial ans(size,tem);
    return ans;
}



Polynomial& Polynomial::operator-(const Polynomial& A){
    Polynomial front(*this);
    Polynomial back(A);
    if(front.len()<back.len()){
        for(int i=0;i<back.len()-front.len();i++){
            front.a.push_back(0);
        }
    }
    else if(front.len()>back.len()){
        for(int i=0;i<front.len()-back.len();i++){
            back.a.push_back(0);
        }
    }
    int size=max(front.len(),back.len());
    double* tem=new double[50];
    for(int i=0;i<size;i++){
        tem[i]=front.a[i]-back.a[i];
    }
    delete []tem;
    Polynomial ans(size,tem);
    return ans;
}
Polynomial& Polynomial::operator*(const Polynomial& A){
    Polynomial front(*this);
    Polynomial back(A);
    int newlen=front.len()+back.len()-1;
    double tem[1000]={0};
    for(int i=0;i<newlen;i++){
        for(int j=0;j<=i-j;j++){
            tem[i]+=front.a[j]*back.a[i-j];
        }
    }
    Polynomial ans(newlen,tem);
    return ans;
}
Polynomial& Polynomial::operator/(const Polynomial& A){
    Polynomial k;
    return k;
}

ostream &operator << (ostream &putout, const Polynomial &A){
    for(int i=A.len()-1;i>=0;i++){
        if(fabs(A.a[i]<=min))continue;
        if(i!=A.len()-1&&A.a[i]>0)putout<<'+';
        if(i!=A.len()-1&&A.a[i]<0)putout<<'-';
        if(i!=0&&fabs(A.a[i]-1)>min&&fabs(A.a[i]+1)>min)putout<<A.a[i];
        if(i==0)putout<<A.a[i];
        if(i!=0)putout<<'x^'<<i;
    }
    if(!A.len())putout<<'0';
    return putout;
}