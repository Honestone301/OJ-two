#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int x=1;
bool comparation(int a,int b){
    a/=x;
    b/=x;
    if((a%10)<(b%10))
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int>res(n, 0);
    int times=0;
    for (auto &i : res)
    {
        cin >> i;
    }
    while(x<=100){
        sort(res.begin(),res.end(),comparation);
        for(int i=0;i<n;i++){
            printf("%03d ",res[i]);
        }
        cout<<endl;
        x*=10;
    }
}