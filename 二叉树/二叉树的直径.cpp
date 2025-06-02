#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;
int n;
int dfs(vector<vector<int>>map,int node,int depth){
    if(node==0) return depth;
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
    vector<vector<int>>map(n,vector<int>(2,0));
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