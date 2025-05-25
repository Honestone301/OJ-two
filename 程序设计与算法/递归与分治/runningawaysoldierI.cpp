#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
/*虽然题目分类是递归与分治，但是我总感觉就是有些难
初学者的话 还是搞不太懂分治这种东西
到也不是说难，可以用完全二叉树进行理解
把每个节点都作为一个延伸结果，以根节点为起始
而后开始：左奇右偶，不断遍历到最后面n与3的关系为止。

分治算法，那肯定要进行return 具体return 什么 这可以依据问题解决
此处利用了一个精妙的方法，即创立一个step，来算出每一个step对应的“第一个数”
*/

int dfs(int n, int minx, int step)
{
    if (n == 3)
    {
        return INT_MAX;
    }
    else if (n < 3)
    {
        return minx;
    }
    int right = dfs((n + 1) / 2, minx, step * 2); // 去除偶数 则第一个数字不变
    int left = dfs(n / 2, minx + step, step * 2); // 去除奇数 则每一步的第一位都要被更新
    return min(left, right);
}

int main()
{
    int x;
    cin >> x;
    while (x != 0)
    {
        int val=dfs(x,1,1);
        cout << ((val==INT_MAX)?0:val) << endl;
        cin >> x;
    }
}