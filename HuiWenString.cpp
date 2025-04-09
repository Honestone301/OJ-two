#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a;
    cin>>a;
    int len=a.size();
    for(int i=0;i<len;i++){
        string y=a;
        reverse(y.begin(),y.end());
        if(y==a){
            break;
        }else{
            a.insert(a.begin()+len,a[i]);
        }
    }
    cout<<a<<endl;
}