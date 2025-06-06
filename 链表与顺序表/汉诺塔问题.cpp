#include<iostream>
using namespace std;
int m;
void hanio(int n,char a,char b,char c){
    if(n==1){printf("%c->1->%c\n",a,c);}
    else{
        //把n-1个盘都借助c挪动到b
        hanio(n-1,a,c,b);
        // 把第n个盘从a挪动到c
        printf("%c->%d->%c\n",a,n,c);
        //  把n-1个盘子从b移动到c，借助a
        hanio(n-1,b,a,c);
    }
}
int main(){
    char a,b,c;
    cin>>m>>a>>b>>c;
    // 区别在于：题目要求的是从a移动到b，借助c
    // 但是hanoi的函数传值是严格按照： 源柱 辅助柱 目标柱
    hanio(m,a,c,b);
}