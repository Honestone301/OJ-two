/*
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

    int d=n/2;

    for(;d>0;d/=2){
        for(int i=d;i<n;i++){
            int key=res[i];
            int j=i-d;
            while(j>=0&&res[j]>key){
                res[j+d]=res[j];
                j-=d;
            }
            res[j+d]=key;
        }
        for(auto i:res)
            cout<<i<<" ";
        cout<<endl;
    }
}





*/



#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

    int d=n/2;
    for(;d>=1;d/=2){
        for(int i=d;i<n;i++){
            int key=res[i];
            int j=i-d;
            while(key<res[j]&&j>=0){
                res[j+d]=res[j];
                j-=d;
            }
            res[j+d]=key;
        }
        for(auto i:res)
            cout<<i<<" ";
        cout<<endl;
    }
}