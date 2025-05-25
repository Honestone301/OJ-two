#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*
“丑数”是指除了质因子2,3，5，不含其它质因子的正整数，例如由小到大前10个“丑数”为
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
*/

/*
    丑数满足递推关系：任意的丑数都是有可能从 某一个小丑数   x2 /  x3  / x5   得来的，
    因而如果要求第n的丑数，那就从第一个开始推导过去。

    而每一个相邻的丑数，都是由接邻的上面几个丑数✖️2 / 3 / 5得来的，
    因为每次算出三个结果之后，求取最小就得出答案。
*/
int Find(int n){
    int i1=0,i2=0,i3=0;
    int a=0,b=0,c=0;
    vector<int>dp(n);
    dp[0]=1;
    for(int i=1;i<n;i++){
        a=dp[i1]*2;
        b=dp[i2]*3;
        c=dp[i3]*5;

        dp[i]=min(a,min(b,c));
        if(dp[i]==a) i1++;
        if(dp[i]==b) i2++;
        if(dp[i]==c) i3++;
    }
    return dp[n-1];
}



int main(){
    vector<int>res;
    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        cout<<Find(val)<<endl;
    }
        return 0;

}