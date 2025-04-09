// 19144 判断士兵是否会被选中巡逻
//  solution 1: 利用上一个的算法（偷懒的士兵1） 然后判断x是否在 minx 的 step倍数 上，如若是，则是逃跑位。

// 做久了做傻了，忘记题目求啥了：把x留到最后，看是小于3，还是等于3！！！
//  solution 2: 依据题目给定的x（奇数or偶数），分化问题，
//  如果是奇数  就一直计算它变化后的位置，结合队列长度，判断是否出局
//  如果是偶数  同样如上
//  ——————屏蔽————————
//  队列长度为偶，求取x为偶，队列要去除奇个数字，x变为x/2；
//  队列长度为偶，求取x为奇，队列要去除偶数个，x变为x/2+1；
// 队列长度为奇，求取x为偶，队列要去除奇个，x变为x/2；
// 队列长度为奇，求取x为奇，队列要去除偶数，x变为x/2+1；
//  ——————屏蔽————————

// 屏蔽以上区域内算法，是我想复杂了，有更加简单的算法。
// x是奇数 队列只去除偶数，判断终极条件下，x是否在3内。
// x是偶数，队列只去除奇数。
#include <iostream>
using namespace std;
int dfs(int n, int x)
{
    if (n < 3)
    {
        return false;
    }
    else if (n == 3)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        int newx = x / 2;
        int newn = n / 2;
        return dfs(newn, newx);
    }
    if (n % 2 == 1)
    {
        int newx = (x + 1) / 2;
        int newn = (n + 1) / 2;
        return dfs(newn, newx);
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    while (n!=0)
    {

        cout<<(dfs(n,x)?"Y\n":"N\n");
        cin>>n>>x;
    }
}