#include<iostream>
using namespace std;
int m;
void hanio(int n,char a,char b,char c){
    if(n==1){printf("%c->1->%c\n",a,c);}
    else{
        hanio(n-1,a,c,b);
        printf("%c->%d->%c\n",a,n,c);
        hanio(n-1,b,a,c);
    }
    
}
int main(){
    char a,b,c;
    cin>>m>>a>>b>>c;
    hanio(m,a,c,b);
}