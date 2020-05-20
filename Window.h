#ifndef _WINDOW_H
#define _WINDOW_H
#include<iostream>
#include"Polynomial.h"
#include"CmdDeal.h"
using namespace std;

class Window{
private:
    CmdDeal* cmd;
public:
    Window();
    ~Window();
    void show();
    void add();
    void calculate();
    void divideormod();
    void inverse();
    void getroot();
    void scan();
};

#endif _WINDOW_H