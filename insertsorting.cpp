#include<iostream>
#include<vector>
using namespace std;
// 直接插入排序
int main(){
    int n;
    cin>>n;
    vector<int>res(n,0);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        res[i]=val;
    }
    for(int i=1;i<n;i++){
        int key=res[i]; //记录此时下标为i的值
        int j=i-1;
        while(j>=0&&res[j]>key){
            // 把key往前移
            res[j+1]=res[j];
            j--;
        }
        res[j+1]=key;
        // 输出本趟结果
        for (int k = 0; k < n; k++) {
            cout << res[k];
            if (k != n-1) cout << " ";
        }
        cout << endl;
    }
}