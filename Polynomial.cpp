#include"Polynomial.h"
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
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

Polynomial::Polynomial(int len,double* m){
    a.clear();
    for(int i=len-1;i>=0;i--){
        a.push_back(m[i]);
    }
    init_legal();
}

Polynomial::Polynomial(const Polynomial &A){
    a.clear();
    string n=A.name;
    this->AssignName(n);
    for(int i=0;i<A.len();i++){
        this->a.push_back(A.a[i]);
    }
    init_legal();
}

void Polynomial::AssignName(string& Pname){
    this->name=Pname;
}


void Polynomial::init_legal(){
    for(int i=this->len()-1;i>0;i--){
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

ostream& operator << (ostream& putout, const Polynomial& A) {
    for (int i = A.len() - 1; i >= 0; i--) {
        if (fabs(A.a[i]) <= min && i != 0)continue;
        if (fabs(A.a[i]) <= min && i == 0 && A.len() == 1)cout << "0";
        if (i != 0 && i != A.len() - 1 && A.a[i] > 0)putout << '+';
        if (i != 0 && i != A.len() - 1 && A.a[i] < 0)putout << '-';
        if (i == 0 && fabs(A.a[0]) > min) {
            if (A.a[0] > 0)putout << '+';
            if (A.a[0] < 0)putout << '-';
        }
        if (i != 0 && fabs(A.a[i] - 1) > min && fabs(A.a[i] + 1) > min)putout << A.a[i];
        if (i == 0 && fabs(A.a[0]) > min)putout << A.a[i];
        if (i != 0)putout << "x^" << i;
    }
    return putout;
}



Polynomial Polynomial::integral() {
    double NUM[1000] = { 0 };
    NUM[len()] = 0;
    for (int i = 0; i < len(); i++) {
        NUM[len()-i-1] = (this->a[i]) / ((double)i + 1);
    }
    Polynomial integ = Polynomial(len() + 1, NUM);
    return integ;
}

double Polynomial::definite_integral(double m_n,double M_n){
    Polynomial integ=this->integral();
    double ans=integ.value(M_n)-integ.value(m_n);
    return ans;
}



Polynomial Polynomial::coefficient() {
    double m[1000] = { 0 };
    if (len() <= 1)return Polynomial();
    for (int i = 1; i < len(); i++) {
        m[len() - 1 - i] = a[i] * i;
    }
    Polynomial ans = Polynomial(len() - 1, m);
    return ans;
}

double Polynomial::value(double x){
    double sum=0;
    for(int index=0;index<(this->len());index++){
        double ans=this->a[index];
        for(int i=0;i<index;i++){
            ans*=x;
        }
        sum+=ans;
    }
    return sum;
}