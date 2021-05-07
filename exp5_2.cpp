/*
5.2 对Point类重载＋＋和――运算符
    编写C++程序完成以下功能：
Point类的属性包括点的坐标（x，y）；
实现 Point类重载＋＋和――运算符：
++p，--p，p++，p--；
＋＋和――分别表示x，y增加或减少1。
*/

#include<iostream>

class Point{
    public :
    float x;
    float y;
    Point(float x_,float y_):x(x_),y(y_){};
    Point();

    void showLoc() const;
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
};
void Point::showLoc() const{
    std::cout<<"location of Point is ("<<x<<","<<y<<")\n";
}

void Point:: operator++(){
    x++;

}
void Point:: operator ++(int){
    y++;

}
void Point:: operator--(){
    x--;

}
void Point:: operator --(int){
    y--;

}
int main(){
    
    Point point(3,3);
    point.showLoc();
    point++;
    point.showLoc();
    point--;
    point.showLoc();
    ++point;
    point.showLoc();
    --point;
    point.showLoc();
    //std::cout<<__cplusplus;  -->my compiler doesnot support c++11
    return 0;
}