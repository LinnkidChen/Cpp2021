/*
4、I/O流实验
编写C++程序完成猜价格游戏的以下功能：
假定有一件商品，程序用随机数指定该商品的价格（1-1000的整数）；
提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
直到猜对为止，并给出提示。
（提示及要求：1，要求使用C++的输入输出方式（cin, cout），不能使用C语言的printf等；2，注意检查输入的合法性）
*/
#include<iostream>
#include<random>
#define maxPrice 1000
using namespace std;
int main (){
    int Price,correct,input;
    correct=0;//0=没猜对
    //uniform_int_distribution<int> ran(1,maxPrice);
    Price=rand() % maxPrice;

    cout<<"initialized successfully.please enter your prediction.\n";
    cin>>input;
    while(!correct&&!cin.eof()){
        
        if(cin.fail()){cout<<"input error,please enter again.\n";cin.clear();}
        else {
            if(input<0||input>maxPrice){cout<<"prediction out of range.try again!\n";}
            else{
            if(input==Price){correct=1;break;}
            else{
                if(input>Price)cout<<"your guess is higher than answer,try again!\n";
                else cout<<"your guess is lower than answer,try again!\n";}
            
        }}
        cin>>input;
    }
    if(correct==1)cout<<"Corrct!congrats!\n";
    else cout<<"nice try.better luck next time!\n";


    return 0;
    

}




