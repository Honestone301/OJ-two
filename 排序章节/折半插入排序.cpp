
//折半逻辑：
//  创建mid变量
//  if mid 大于 key ， 那就




/*
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>res(n);
    for(auto &i:res){
        cin>>i;
    }

    for(int i=1;i<n;i++){
        int key=res[i];
        int left=0;
        int right=i-1;
        int mid=left+(right-left)/2;

        while(left<=right){
            if(res[mid]>key)
                right=mid-1;
            else
                left=mid+1;
            mid=left+(right-left)/2;
        }
        int j=i;
        for(;j>left;j--)
            res[j]=res[j-1];
        res[j]=key;

        for(auto i:res){
            cout<<i<<" ";
        }
        cout<<endl;

    }
}

*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>res(n);
    for(auto &i:res){
        cin>>i;
    }

    for(int i=1;i<n;i++){
        int left=0;
        int right=i-1;
        int key=res[i];

        while(left<=right){
            int mid=(left+right)/2;
            if(res[mid]>key){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        int j=i;
        for(;j>left;j--)
            res[j]=res[j-1];
        res[j]=key;

        for(auto i:res){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}