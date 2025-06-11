/*
#include <iostream>
using namespace std;
int n;
int data[1001];
int temp[1001];

void merge_sort(int *A, int x, int y, int *T)
{
  if (y - x > 1)
  {
    // 计算中间点，分割为左右两部分
    int m = x + (y - x) / 2;
    // 递归排序左半部分 [x, m)
    merge_sort(A, x, m, T);
    // 递归排序右半部分 [m, y)
    merge_sort(A, m, y, T);

    // 合并两个有序子数组
    int p = x, q = m, i = x;
    while (p < m || q < y)
    {
      // 选择较小的元素放入临时数组
      if (q >= y || (p < m && A[p] <= A[q]))
        T[i++] = A[p++];
      else
        T[i++] = A[q++];
    }
    // 将合并后的数据拷贝回原数组
    for (i = x; i < y; i++)
      A[i] = T[i];
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> data[i];
  merge_sort(data, 0, n, temp);
  for (int i = 0; i < n; i++)
    cout << data[i];
  cout << endl;
}

*/

#include <iostream>
#include <vector>
#include <algorithm>
// 查找跨越中点的最大子数组和
int maxCrossingSum(const std::vector<int> &arr, int low, int mid, int high)
{
  // 计算包含中点向左的最大和
  int leftSum = 0;
  int maxLeftSum = -999999;
  for (int i = mid; i >= low; --i)
  {
    leftSum += arr[i];
    if (leftSum > maxLeftSum)
    {
      maxLeftSum = leftSum;
    }
  }
  // 计算包含中点向右的最大和
  int rightSum = 0;
  int maxRightSum = -999999;
  for (int i = mid + 1; i <= high; ++i)
  {
    rightSum += arr[i];
    if (rightSum > maxRightSum)
    {
      maxRightSum = rightSum;
    }
  }
  return maxLeftSum + maxRightSum;
}
// 分治法求解最大子数组和
int maxSubArraySum(const std::vector<int> &arr, int low, int high)
{
  if (low == high)
  {
    return arr[low];
  }
  int mid=(low+high)/2;
  int leftMax=maxSubArraySum(arr,low,mid);
  int crossMax=maxSubArraySum(arr,low,high);
  int rightMax=maxSubArraySum(arr,mid,high);
  return std::max({leftMax, rightMax, crossMax});
}
int main()
{
  std::vector<int> arr;
  int n, data;
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    std::cin >> data;
    arr.push_back(data);
  }
  int maxSum = maxSubArraySum(arr, 0, n);
  std::cout << maxSum << std::endl;
  return 0;
}
