#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
为了选择合适的士兵, 多次进行如下操作: 
如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵, 
或者是去除掉所有站立位置为偶数的士兵。
直到不超过三个战士，他们将被送去侦察。
现要求统计按这样的方法，总共可能有多少种不同的正好三个士兵去侦察的士兵组合方案。
*/
int dfs(int n){
    if(n==3){
        return 1;
    }else if(n<3){
        return 0;
    }else{
        if(n%2==0){
            return 2*dfs(n/2);
        }else{
            // 对于n是奇数的话，有两种划分方式：
            //  奇数划分 ｜ 偶数划分
            int n1=dfs(n/2+1);
            int n2=dfs(n/2);
            return n1+n2;
        }
    }
}

int main(){
    int n;
    while(scanf("%d",&n)&&(n!=0)){
        printf("%d",dfs(n));
    }
}