/*

 2.2 编写C++程序完成“矩阵”类以下功能：
用类来实现矩阵，定义一个矩阵的类，属性包括：
矩阵大小，用 cols, rows（行、列来表示）；
存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
矩阵类的方法包括：
构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
析构函数，需要释放矩阵的数组指针；
拷贝构造函数，需要申请和复制数组；
输入，可以从cin中输入矩阵元素；
输出，将矩阵格式化输出到cout；
矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵类，但必须矩阵大小相同；
矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵类，但必须矩阵大小相同。
定义三个矩阵：A1、A2、A3；
初始化A1、A2；
计算并输出A3 = A1加A2，A3=A1减A2；（要求及提示：最好能实现对赋值操作符“=”的重载；注意检查“自赋值”、释放“旧元素”）
用new动态创建三个矩阵类的对象：pA1、pA1、pA3；
初始化pA1、pA2；
计算并输出pA3=pA1加pA2，pA3=pA1减pA2；
释放pA1、pA2、pA3。
*/


#define Matrix_col 3
#define Matrix_row 3

#include<iostream>

using namespace std;
class Matrix{
    public:
    int col ;//行数
    int row;//列数
    int **array;
    ~Matrix();//析构函数
    Matrix(int col,int row);//构造函数
    Matrix( const Matrix & A);//复制构造函数 
    void input_ele();
    void output_ele();
    Matrix operator+ (const Matrix &A);//计算A+B储存到C
    Matrix operator- (const Matrix &A);//计算A-B储存到C
    Matrix& operator= (const Matrix &A);


};
Matrix::Matrix(int col,int row){
    this->col=col,this->row=row;
    array=new int*[col];
    for(int i=0 ; i<col;i++)array[i]=new int [row];
    cout<<"Matrix的构造函数\n";
}
Matrix::~Matrix(){
    for(int i=0;i<col;i++)delete []array[i];
    delete []array;
    cout<<"Matrix的析构函数\n";
}
void Matrix:: input_ele(){
    std::cout<<"please input "<<col*row<<" elements."<<'\n';
    for(int i=0;i<col;i++){
        for(int q=0;q<row;q++){
            cin>>array[i][q];
        }
    }
}
void Matrix:: output_ele(){
    for(int i=0;i<col;i++){
        for(int q=0;q<row;q++){
        cout<<array[i][q]<<' ';
        }
        cout<<'\n';
    }
}


Matrix Matrix:: operator+(const Matrix &A){
    Matrix sum(col,row);
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            sum.array[i][j]=array[i][j]+A.array[i][j];
        }
    }
    return sum;
}
Matrix Matrix:: operator-(const Matrix &A){
    Matrix sum(col,row);
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            sum.array[i][j]=array[i][j]-A.array[i][j];
        }
    }
    return sum;
}
Matrix & Matrix:: operator=(const Matrix &A){
    if(this != &A && A.row==row&&A.col==col){//检查自赋值
        for(int i=0;i<col;i++){
            for(int q=0;q<row;q++){
                array[i][q]=A.array[i][q];
            }
        }
    }
    return *this;
}


Matrix:: Matrix ( const Matrix & A){
    col=A.col;
    row=A.row;
    array=new int*[col];
    for(int i=0;i<col;i++)array[i]=new int [row];
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            array[i][j]=A.array[i][j];
        }
    }
    cout<<"Matrix的复制构造函数\n";
}

int main (){
    
    Matrix A(Matrix_col,Matrix_row),B(Matrix_col,Matrix_row),C(Matrix_col,Matrix_row);
    A.input_ele();
    B.input_ele();
    cout<<"content of Matrix A is:"<<'\n';
    A.output_ele();
    cout<<"content of Matrix B is:"<<'\n';
    B.output_ele();
    C=A+B;
    cout<<"result of A+B is"<<'\n';
    C.output_ele();
    C=A-B;
    cout<<"result of A-B is"<<'\n';
    C.output_ele();

return 0;
}