#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        res[i] = val;
    }
// 0 1 2 3 4 5 6 7 8 9
    for (int d = n / 2; d >= 1; d /= 2)
    {
        // 这层是用于分别对组操作的
        for (int i = d; i < n; i++)
        {
            // 这层是每次分组的内部插入排序
            int key=res[i];
            int j=i-d;
            while(key<res[j]&&j>=0){
                res[j+d]=res[j];
                j-=d;
            }
            // 这里使用j+d 的原因是因为 j已经在while里面被更新过了
            res[j+d]=key;
        }
        for(auto i:res)
            cout<<i<<" ";
        cout<<endl;
    }
}