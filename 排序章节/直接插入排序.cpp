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
        int j=i-1;
        while(j>=0&&res[j]>key){
            res[j+1]=res[j];
            j--;
        }
        res[j+1]=key;

        for(auto x:res)
            cout<<x<<" ";
        cout<<endl;
    }
}