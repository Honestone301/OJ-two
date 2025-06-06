#include<iostream>
#include<vector>
using namespace std;
int QueenPos[100];//用来标记Queen的行列位置
int res=0;//用来累积皇后数量
int N;
//算法用于穷尽所有行列里N皇后数量
void dfs(int k){
    if(k==N){
        res++;
        return ;
    }
    for(int i=0;i<N;i++){
        int j=0;
        for(;j<k;j++){
            if(QueenPos[j]==i||abs(QueenPos[j]-i)==abs(k-j)){
                break;
            }
        }
        if(j==k){
            QueenPos[j]=i;
            dfs(k+1);
        }
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>N;
        res=0;
        dfs(0);
        cout<<res<<endl;
    }
}