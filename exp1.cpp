#include<iostream>
using namespace std;
void initiate_matrix(int **a);
void print_matrix(int **a);
void matrix_sub(int **a,int **b,int **c);
void matrix_add(int **a,int **b,int **c);

int main (){
    int **a,**b,**c;//矩阵指针
        a=new int*[4];
        b=new int*[4];
        c=new int*[4];
        for(int q=0;q<4;q++){
            a[q]=new int[5];
            b[q]=new int[5];
            c[q]=new int[5];
        }
        cout<<"请输入矩阵A"<<'\n';
        initiate_matrix(a);
        print_matrix(a);
        cout<<"请输入矩阵B"<<'\n';
        initiate_matrix(b);
        print_matrix(b);
        matrix_sub(a,b,c);
        cout<<"矩阵A-B是"<<'\n';
        print_matrix(c);
        cout<<"\n";
        matrix_add(a,b,c);
        cout<<"矩阵A+B是"<<'\n';
        print_matrix(c);
    }
    void initiate_matrix(int **a){
        for(int i=0;i<4;i++)
        for(int q=0;q<5;q++){cin>>a[i][q];}
    }
    void print_matrix(int **a){
        for(int i=0;i<4;i++){
            for (int q=0;q<5;q++){cout<<a[i][q]<<' ';}
            cout<<'\n';
        }
    }
    void matrix_sub(int **a,int **b,int **c){
         for(int i=0;i<4;i++){
            for (int q=0;q<5;q++){c[i][q]=a[i][q]-b[i][q];}
        }
    }
    void matrix_add(int **a,int **b,int **c){
         for(int i=0;i<4;i++){
            for (int q=0;q<5;q++){c[i][q]=a[i][q]+b[i][q];}
        }
    }