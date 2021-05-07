/*
2.1编写C++程序完成“圆形”以下功能：
定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；
（要求当用户不输入坐标数据时，能够默认为坐标原点（0，0））
定义一个圆形类，其属性包括圆心和半径；
创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果；
观察圆形对象以及Point类成员的构造函数与析构函数的调用。
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用system("pause")进行程序的暂停；2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因） 

*/
#include<iostream>
#include<cmath>
using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(){x=0;y=0;cout<<"construction of Point \n";}
    Point(int a,int b){x=a;y=b;cout<<"construction of Point \n";}
    ~Point(){cout<<"deconstruction of Point\n";}
    double Get_distance(Point a,Point b);
    
};
class Circle{
    public :
    double radius;
    Point center;
    Circle(){radius=0;cout<<"construction of Circle\n";}
    ~Circle(){cout<<"deconstruction of Circle\n";}
};
double Get_distance(Point const &a,Point const &b){
    return sqrt((a.x-b.x)^2+(a.y-b.y)^2);
}

int main (){

    Circle A,B;
    int dis;
    cout<<"plz enter center location and radius of circle A"<<'\n';
    cin>>A.center.x>>A.center.y>>A.radius;
    cout<<"plz enter center location and radius of circle B"<<'\n';
    cin>>B.center.x>>B.center.y>>B.radius;
    dis=Get_distance(A.center,B.center);
    if(dis<=A.radius+B.radius&&dis>=abs(A.radius-B.radius))cout<<"two circle are intersected\n";
    else cout<<"two circles are not intersected\n";


    return 0;
}