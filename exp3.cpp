/*
 3、继承与派生实验
编写C++程序完成“形状”的以下功能：
声明一个基类Shape（形状），其中包含一个方法来计算面积；
从Shape派生两个类：矩形类和圆形类；
从矩形类派生正方形类；
分别实现派生类构造函数、析构函数和其他方法；
创建派生类的对象，观察构造函数、析构函数调用次序；
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用system("pause")进行程序的暂停；2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因）
对不同对象计算面积。
*/


#include<iostream>
#define PI 3.14
using namespace std;
class shape{
    public:
    shape(){cout<<"constructor of shape"<<'\n';}
    ~shape(){cout<<"deconstructor of shape"<<'\n';}
    float area;
    virtual float calArea(int a,int b){return a*b;}//calculate area of rectangle
    virtual float calArea(int r){return PI*r*r;}//calculate area of circle    

};
class circle: public shape{
    public:
    circle(float r){cout<<"constructor of circle"<<"\n";radius=r;}
    ~circle(){cout<<"deconstructor of circle"<<"\n";}

    float radius;
};
class rectangle: public shape{
    public:
    rectangle(float a_,float b_){cout<<"constructor of rectangle"<<"\n";a=a_,b=b_;}
    ~rectangle(){cout<<"deconstructor of rectangle"<<"\n";}
    virtual float calArea(int a,int b){return a*b;}
    float a,b;
};
class square:public rectangle{
    public:
    square(float a_=0):rectangle(0,0){a=a_;cout<<"constructor of square"<<"\n";}
    ~square(){cout<<"deconstructor of square"<<"\n";}
    virtual float calArea(int a){return a*a;}
    float a;
} ;  
int main (){
    float temp1,temp2;
    cin>>temp1;
    square squa(temp1);
    cin>>temp1>>temp2;
    rectangle rect(temp1,temp2);
    cin>>temp1;
    circle circ(temp1);

    cout<<"area of square is "<<squa.calArea(squa.a)<<'\n';
    cout<<"area of circle is "<<circ.calArea(circ.radius)<<'\n';
    cout<<"area of rectangle is "<<rect.calArea(squa.a,squa.b)<<'\n';
    }