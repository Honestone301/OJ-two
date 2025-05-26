#include <iostream>
#include <vector>
using namespace std;
/*
oj的快速排序是：
    基于已有的数组进行先 递归 ！！！！  
    递归是指：每次都进行数组的划分排序
    通过每一次的快排得到pivotindex值，
    再依据pivotindex值进行左右划分区域排序。

    如果要oj的ac，递归是精髓，不能忘。
    如果要理解快排，那另一个函数才是经典！！
*/

int sortting(vector<int> &res, int left, int right)
{
    int pivot = res[left];
    while (left < right)
    {
        while (res[right] >= pivot && right > left)
        {
            right--;
        }
        res[left] = res[right];
        while (res[left] <= pivot && right > left)
        {
            left++;
        }
        res[right] = res[left];
    }
    res[left] = pivot;
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return left;
}
void fastsort(vector<int> &res, int left, int right)
{
    if (left >= right)
        return;
    int pivotindex = sortting(res, left, right);
    fastsort(res, left, pivotindex - 1);
    fastsort(res, pivotindex + 1, right);
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

    fastsort(res, 0, n - 1);
}