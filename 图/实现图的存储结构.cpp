#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>res(n,vector<int>(n,0));

    int p,m;
    while(q--){
        cin>>p>>m;
        res[p-1][m-1]=1;
    }

    // 打印填充后的二维数组
    for (const auto& row : res) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
}