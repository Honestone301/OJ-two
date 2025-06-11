#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
/*此题解法（25.6.9）：
    无论进行的是奇偶，都要对step进行计数
    原因是，如果要去除的位置为奇数，那么必然丢失当前位置（当前默认最小位置即第一个）
        那么由于之前进行了很多次的ou数➕奇数去除步骤，那必定存在了中间有数字消失
        则当前位置的抹除必然会导致与之相邻的位置肯定是并非当前位置的+1

        */

/*虽然题目分类是递归与分治，但是我总感觉就是有些难
初学者的话 还是搞不太懂分治这种东西
到也不是说难，可以用完全二叉树进行理解
把每个节点都作为一个延伸结果，以根节点为起始
而后开始：左奇右偶，不断遍历到最后面n与3的关系为止。
分治算法，那肯定要进行return 具体return 什么 这可以依据问题解决h h

当给定士兵数之后，输出不可能被选中去巡逻的最少编号位置（如果不存在不可能被选中的位置，则输出0）。

注: 按上法得到少于三士兵的情况不用去巡逻。
*/
int dfs(int n, int minpos, int pos)
{
    if (n == 3)
    {
        return INT_MAX;
    }
    else if (n < 3)
    {
        return minpos;
    }
    int ou = dfs((n + 1) / 2, minpos, pos * 2); // 去除偶数 则第一个数字不变·
    int ji = dfs(n / 2, minpos + pos, pos * 2); // 去除奇数 则每一步的第一位都要被更新
    return min(ou, ji);
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