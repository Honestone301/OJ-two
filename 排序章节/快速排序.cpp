#include <iostream>
#include <vector>
using namespace std;
/*
     快速排序核心：每次都划分两片区域，取一中间值，
        左边的小于该值，右边的大于。

     具体实现：分两个函数：
        第一个函数用以实现单次中间值的所有划分操作。
        一定要用‘<=’或者‘>=’，不然会死循环！！！！
        在全相同的数组里面，指针不会移动。
        and
        如果遇见了相同元素，这两个值不会交换，这意味着递归深度变大，
        复杂度变高了

        第二个函数用以实现取完所有的中间值。

*/
int sortting(vector<int> &res, int left, int right)
{
    int pivot = res[left];
    while (left < right)
    {
        while (res[right] >= pivot && left < right)
            right--;
        res[left] = res[right];
        while (res[left] <= pivot && left < right)
            left++;
        res[right] = res[left];
    }
    res[left] = pivot;
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return left;
}

void sorttion(vector<int> &res, int left, int right)
{
    if (left >= right)
        return;
    int pviotindex = sortting(res, left, right);
    sorttion(res, left, pviotindex - 1);
    sorttion(res, pviotindex + 1, right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (auto &i : nums)
    {
        cin >> i;
    }

    sorttion(nums, 0, nums.size() - 1);
    return 0;
}