#include <iostream>   // 输入输出
#include <cstdio>     // C风格输入输出（如 scanf, printf）
#include <cstdlib>    // 标准库函数（如 malloc, atoi）
#include <vector>     // vector容器
#include <algorithm>  // 算法（如 sort, find）
#include <string>     // string类
#include <cstring>    // C字符串处理函数（如 strcpy, strlen）
using namespace std;
int akm(int m,int n){
    if(m==0){
        return n+1;
    }else if(m>0&&n==0){
        return akm(m-1,1);
    }else if(m>0&&n>0){
        return akm(m-1,akm(m,n-1));
    }
    return 0;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<akm(m,n)<<endl;

}