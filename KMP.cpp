#include <iostream>
#include <string>
using namespace std;

// 计算字符串的next数组
void getnext(string a, int next[]) {
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < a.size(); i++) {
        while (j > 0 && a[i] != a[j]) {
            j = next[j - 1];
        }
        if (a[i] == a[j]) {
            j++;
        }
        next[i] = j;
    }
}

int main() {
    string a;
    cin >> a;
    int* next = new int[a.size()];
    getnext(a, next);
    string b;
    int j=0;
    cin>>b;

    for(int i=0;i<b.size();i++){

        while(j>0&&b[i]!=a[j]){
            j=next[j-1];
        }
        if(b[i]==a[j]){
            j++;
        }
        if(j==a.size()){
            cout<<i-j+1<<endl;
            break;
        }
    }
    // 释放动态分配的内存
    delete[] next;
    return 0;
}

/*#include<iostream>
#include<string>
using namespace std;
void getnext(string a,int next[]){
    int j=0;
    next[0]=0;
    for(int i=1;i<a.size();i++){
        while(j>0&&a[i]!=a[j]){
            j=next[j];
        }
        if(a[i]==a[j]){
            next[i]=++j;
        }
    }
}

int main(){
    string a;
    cin>>a;
    int* next=new int[a.size()];
    getnext(a,next);
    for(int i=0;i<a.size();i++){
        cout<<next[i];
    }
}
    */