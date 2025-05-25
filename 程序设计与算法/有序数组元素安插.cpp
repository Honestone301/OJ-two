#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//  主要是学会使用lower_bound，这是允许在容器内使用的查找函数
//      使用条件是：容器必须有序，无法在哈希内使用
//  在oj提交的时候，偶数部分必须处以的是 “2.0”  而不能使用整数除法
int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (auto &i : res)
        cin >> i;

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int val;
        cin>>val;

        auto it=lower_bound(res.begin(),res.end(),val);
        res.insert(it,val);
        int len=res.size();
        if(len%2==0){
            cout<<(res[len/2]+res[len/2-1])/2.0<<endl;
        }else{
            cout<<res[len/2]<<endl;
        }
    }
    return 0;

}
