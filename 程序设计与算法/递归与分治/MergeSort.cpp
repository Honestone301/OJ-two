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