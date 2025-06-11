#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
思路：
    对比两个字符串，
    定义dp数组
    将dp数组与三个方向比对（⬆️ ｜ ↖️ ｜ ⬅️）
        如果是对比到字符串a[i-1]==b[j-1], 那就直接在原有最大dp[i-1][j-1] + 1  即可
        如果说比对不上，那就看看取 max(⬅️,⬆️);
        
*/
int main(){
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}