/*#include <iostream>
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

    while (counters<=n)
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
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<vec[i][j+1];
    }
}
    */
   #include<iostream>
   #include<stdio.h>
   using namespace std;
   int list[20][20] = {0};
   int main(){
   
       int n,x = 1,y = 0;
       cin >> n;
       int k = 1;
       while(k<=n*n){
           while(y < n && list[x][y + 1] == 0) list[x][++y] = k++;
           while(x < n && list[x + 1][y] == 0) list[++x][y] = k++;
           while(y > 1 && list[x][y - 1] == 0) list[x][--y] = k++;
           while(x > 1 && list[x - 1][y] == 0) list[--x][y] = k++;
       }
       for(int i = 1;i <= n;i++){
           for(int j = 1;j <= n;j++){
               printf("%3d",list[i][j]);
           }
           printf("\n");
       }
   }
   
   
