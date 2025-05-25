#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

//    核心思想：先利用k寻找出每一趟循环中的数组最小值，然后再赋值。
    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(res[k]>res[j])
                k=j;
        }
        swap(res[k],res[i]);
        for(auto i:res)
        cout<<i<<" ";
        cout<<endl;
    }
}