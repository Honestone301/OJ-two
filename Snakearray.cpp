#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    int i = 0, j = 0, k = 0, l = 0;
    int order=0; //row
    int counters=1;
    while (true)
    {
        while (order<n&&vec[i][order]==0){
            vec[i][order++]=++counters;
        }
        while(vec[i+1][order]==0&&i+1<n){
            vec[++i][order]=++counters;
        }
        while(vec[i][order-1]==0&&order-1>=0){
            vec[i][--order]=++counters;
        }
        while(vec[i-1][order]==0&&i-1>=0){
            vec[--i][order]=++counters;
        }
        if(vec[i-1][order]!=0&&vec[i+1][order]!=0&&vec[i][order+1]!=0&&vec[i][order-1]!=0&&
        i-1>=0&&i+1<n&&order-1>=0&&order+1<n){
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<vec[i][j+1];
    }
}