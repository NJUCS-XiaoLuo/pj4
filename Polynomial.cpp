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


Polynomial Polynomial::operator+(const Polynomial& A){
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
        tem[size-1-i]=front.a[i]+back.a[i];
    }
    Polynomial ans(size,tem);
    delete[] tem;
    return ans;
}


Polynomial Polynomial::operator-(const Polynomial& A) {
    Polynomial front=Polynomial(*this);
    Polynomial back=Polynomial(A);
    int a = front.len(), b = back.len();
    if (front.len() < back.len()) {
        for (int i = 0; i < b-a; i++) {
            front.a.push_back(0);
        }
    }
    else if (front.len() > back.len()) {
        for (int i = 0; i <a-b; i++) {
            back.a.push_back(0);
        }
    }
    int size = max(front.len(), back.len());
    double* tem = new double[500];
    for (int i = 0; i < size; i++) {
        tem[size-1-i] = front.a[i] - back.a[i];
    }
    Polynomial ans(size, tem);
    delete[] tem;
    return ans;
}


Polynomial Polynomial::operator*(const Polynomial& A) {
    Polynomial front(*this);
    Polynomial back(A);
    int newlen = front.len() + back.len() - 1;
    double tem[1000] = { 0 };
    for (int i = 0; i < newlen; i++) {
        for (int j = 0; j <=i; j++) {
            if (j<front.len()&&i-j<back.len()) {
                tem[newlen-i-1] += front.a[j] * back.a[i - j];
            }
        }
    }
    Polynomial ans(newlen, tem);
    return ans;
}

Polynomial Polynomial::operator/(const Polynomial& A){
    Polynomial k;
    return k;
}

ostream& operator << (ostream& putout, const Polynomial& A) {
    for (int i = A.len() - 1; i >= 0; i--) {
        if (fabs(A.a[i]) <= min && i != 0)continue;
        if (fabs(A.a[i]) <= min && i == 0 && A.len() == 1)cout << "0";
        if (i != 0 && i != A.len() - 1 && A.a[i] > 0)putout << '+';
        if (i != 0 && A.a[i] < 0)putout << '-';
        if (i == 0 && fabs(A.a[0]) > min) {
            if (A.a[0] > 0)putout << '+';
            if (A.a[0] < 0)putout << '-';
        }
        if (i != 0 && fabs(A.a[i] - 1) > min && fabs(A.a[i] + 1) > min)putout << fabs(A.a[i]);
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

double Polynomial::root(){
    Polynomial coe=this->coefficient();
    double x1=1;
    double x2=0;
    while(fabs(x1-x2)>min){
        x2=x1;
        x1=x1-(this->value(x1))/(coe.value(x1));
    }
    return x1;
}

Polynomial Polynomial::mod(int n) {
    double m[1000];
    for (int i = 0; i < n; i++) {
        m[i] = this->a[n - i-1];
    }
    Polynomial P = Polynomial(n + 1, m);
    return P;
}



Polynomial Polynomial::inverse(int n){
    double m1[5];
    m1[0]=1.0/(this->a[0]);
    Polynomial P1=Polynomial(1,m1);
    if(n==1)return P1;
    Polynomial P0INV=inverse(ceil(n/2));
    double m2[5];
    m2[0]=2;
    Polynomial P2=Polynomial(1,m2);
    Polynomial PINV=P0INV*(P2-(*this)*P0INV);
    return PINV;
}