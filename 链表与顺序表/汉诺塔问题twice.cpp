#include<iostream>
using namespace std;
void dfs(int n,char a,char b,char c){
    if(n==1) printf("%c->1->%c\n",a,c);
    else{
    dfs(n-1,a,c,b);
    printf("%c->%d->%c\n",a,n,c);
    dfs(n-1,b,a,c);
    }
}
int main(){
    int n;
    char a,b,c;
    cin>>n>>a>>b>>c;
    dfs(n,a,c,b);
}