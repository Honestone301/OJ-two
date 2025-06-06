#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;
int n;
/*
与 《二叉树的宽度》 那题所用的数据结构表示方式不同
这题运用的是基于二维数组的存储方式
    二维向量：
    row为一个节点包含其左右子树编号（若存在） ->  [x][0]   [x][1]   
    col为总共节点数量

dfs求索每一个节点能存储的左右子树深度极限
返回
*/
int dfs(vector<vector<int>>map,int node,int depth){
    if(node==0) return depth;
    else if(!map[node][0]&&!map[node][1]){
        return depth;
    }
    int left=0,right=0;
    if (map[node][0])
    {
        left=dfs(map,map[node][0],depth+1);
    }
    if(map[node][1]){
        right=dfs(map,map[node][1],depth+1);
    }
    return max(left,right);
    
}
int main(){
    cin>>n;
    int m=n-1;
    vector<vector<int>>map(n+1,vector<int>(2,0));
    while(m--){
        int x,y;
        cin>>x>>y;
        if(map[x][0]==0){
            map[x][0]=y;
        }else{
            map[x][1]=y;
        }
    }
    int jing =1,mas=0;
    for(int i=1;i<=n;i++){
        jing=dfs(map,map[i][0],0) + dfs(map,map[i][1],0) + 2;
        mas=max(mas,jing);
    }
    cout<<mas;
}