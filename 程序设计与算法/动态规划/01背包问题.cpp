#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
有一个容积为C的背包和N件物品。第i件物品的体积W[i]，价值是V[i]。
求解将哪些物品装入背包可使价值总和最大。每种物品只有一件，
可以选择放或者不放入背包。
*/
int main(){
    int n,m;
    //n是物品数量，m是最大容量
    cin>>m>>n;;
    vector<int>W(n+1),V(n+1);
    for(int i=1;i<=n;i++){
        cin>>W[i]>>V[i];
    }
//这里初始化dp数组为0，原因是0物品为0，0重量也为0
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        //该层为物品编号,外层是从上到下
        for(int j=0;j<=m;j++){
            //该层为遍历背包容量，内层是从左至右（0到最大容量）
            if(j<W[i]) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+V[i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}