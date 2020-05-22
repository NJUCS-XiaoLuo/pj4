#include"Window.h"
#include"CmdDeal.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

Window::Window(){cmd=new CmdDeal;};
Window::~Window(){delete cmd;};


void Window::show(){
    cout<<"=================多项式计算器================="<<endl;
    cout<<"1.输入 2.混合运算 3.求逆元 4.除法 5.求根 6.查看"<<endl;
    cout<<"============================================="<<endl;
    cout<<"请选择；";
    int cmd;
    while(1){
        cin>>cmd;
        switch (cmd){
        case 1:add();break;
        case 2:calculate();break;
        case 3:inverse();break;
        case 4:divideormod();break;
        case 5:getroot();break;
        case 6:scan();break;
        default:break;
        }
    }
}

void Window::add(){
    cout<<"您要添加的多项式的长度为：";
    int len;
    cin>>len;
    double* m=new double[1000];
    for(int i=0;i<1000;i++)m[i]=0;
    cout<<"请输入每一项（用空格隔开）：";
    for(int i=0;i<len;i++){
        cin>>m[i];
    }
    string pname;
    cout<<"请给他命名（英文字母表示）：";
    cin>>pname;
    if(!(cmd->AddPo(len,m,pname)))cout<<"您输入的多项式不符合要求，请重新输入"<<endl;
    else {
        cout<<"恭喜你，添加成功！"<<endl;
        this->show();
    }
    return;
}
void Window::calculate(){
    cout<<"请输入表达式：";
    string ex;
    cmd->analy(ex,0);
    return;
}
void Window::divideormod(){
    return;
}
void Window::inverse(){
    return;
}
void Window::getroot(){
    return;
}
void Window::scan(){
    cout<<"请输入多项式的名字：";
    string Pname;
    cin>>Pname;
    if(!(this->cmd->ScanPo(Pname))){
        cout<<"该多项式不存在！"<<endl;
        this->show();
    }
    this->show();
    return;
}