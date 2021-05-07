/*
5、重载实验
5.1 虚函数
针对题目3的“形状”类，编写C++程序完成以下功能：
将【形状】 中的基类计算面积的方法定义为虚函数，比较与【形状（A）】程序的差异；
将【形状】中的基类定义为抽象类，比较与【形状（A）】程序的差异。
*/
#include<iostream>
#define PI 3.14
using namespace std;
class shape{
    public:
    shape(){cout<<"constructor of shape"<<'\n';}
    ~shape(){cout<<"deconstructor of shape"<<'\n';}
    virtual float calArea()=0;
    float area;
    //calculate area of rectangle
    //virtual float calArea(int r){return PI*r*r;}//calculate area of circle    

};
class circle: public shape{
    public:
    circle(float r){cout<<"constructor of circle"<<"\n";radius=r;}
    ~circle(){cout<<"deconstructor of circle"<<"\n";}
    virtual float calArea(){this->area=this->radius*this->radius*PI;return this->area;}
    float radius;
};
class rectangle: public shape{
    public:
    rectangle(float a_,float b_){cout<<"constructor of rectangle"<<"\n";a=a_,b=b_;}
    ~rectangle(){cout<<"deconstructor of rectangle"<<"\n";}
   virtual float calArea(){this->area= this->a*this->b;return this->area;};
    float a,b;
};
class square:public rectangle{
    public:
    square(float a_=0):rectangle(0,0){a=a_;cout<<"constructor of square"<<"\n";}
    ~square(){cout<<"deconstructor of square"<<"\n";}
    virtual float calArea(){this->area=this->a*this->a;return this->area;};
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

    cout<<"area of square is "<<squa.calArea()<<'\n';
    cout<<"area of circle is "<<circ.calArea()<<'\n';
    cout<<"area of rectangle is "<<rect.calArea()<<'\n';
    }