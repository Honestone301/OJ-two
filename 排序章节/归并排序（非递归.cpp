#include <iostream>
#include <vector>
using namespace std;
/*
    主要原理：利用双循环->嵌套自定义范围语句
    借以实现模拟递归的方式达成归并排序

    具体细节：
        利用widden构造每次范围大小
            利用begging构造每次范围起点终点
                （每次left<=mid<=right,利用min避免越界）

        再构造merge函数
            无论是不是递归，归并排序都是一个原理：
                左右比较，不断填入新数组，
                最终再回填result数组。
    
    大概原理如上。

*/
void merge(vector<int> &res, int left, int mid, int right)
{
    vector<int> copyy(right - left + 1, 0);
    int i = 0, j = mid;
    int zuo = left;
    while (zuo < mid && j < right)
    {
        if (res[j] < res[zuo])
            copyy[i++] = res[j++];
        else
            copyy[i++] = res[zuo++];
    }
    while (zuo < mid)
    {
        copyy[i++] = res[zuo++];
    }
    while (j < right)
    {
        copyy[i++] = res[j++];
    }
    for (int x = 0; x < right - left; x++)
    {
        res[left + x] = copyy[x];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }
    int widen = 0, begging = 0;
    for (widen = 1; widen <= n - 1; widen += widen)
    {
        for (begging = 0; begging <= n - 1; begging += widen * 2)
        {
            merge(res, begging, min(begging + widen, n), min(begging + widen * 2, n));
        }
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}