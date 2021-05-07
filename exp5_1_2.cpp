#include<iostream>
#define PI 3.14
using namespace std;
class shape{
    public:
    shape(){cout<<"constructor of shape"<<'\n';}
    ~shape(){cout<<"deconstructor of shape"<<'\n';}
    virtual float calArea()=0;//calculate area of rectangle
    //float calArea(int r){return PI*r*r;}//calculate area of circle    

};
class circle: virtual public shape{
    public:

    circle(float r){cout<<"constructor of circle"<<"\n";radius=r;}
    ~circle(){cout<<"deconstructor of circle"<<"\n";}

    float area;
    float radius;
    virtual float calArea(){this->area=this->radius*this->radius*PI;return this->area;}

};
class rectangle: virtual public shape{
    public:
    rectangle(float a_,float b_){cout<<"constructor of rectangle"<<"\n";a=a_,b=b_;}
    ~rectangle(){cout<<"deconstructor of rectangle"<<"\n";}
    virtual float calArea(){this->area= this->a*this->b;return this->area;};

    float area;
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