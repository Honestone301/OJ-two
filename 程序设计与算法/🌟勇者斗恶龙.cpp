#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Description
有n个头的恶龙，你希望雇一些骑士把它杀死（即砍掉所有头）。村里有ｍ个骑士可以雇佣，一个能力值为x的骑士可以砍掉恶龙
一个直径不超过x的头，且需要支付x个金币。如何雇佣骑士才能砍掉恶龙的所有头，且需要支付的金币最少？注意，一个骑士只
能砍一个头（且不能被雇佣两次）
*/

/*输入格式
多组数据，每组数据的第一行为正整数n和m(1<=n,m<=200000)；以下n行每行为一个整数，即恶龙每个头的直径；以下m行每行为
一个整数，即每个骑士的能力。输入结束标志ｎ＝ｍ＝0;


输出格式
输出格式：每组数据，输出最少花费，无解输出"Loowater is doomed!"
*/
// 只需要做到双数组从最小开始 一一对标即可。

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) && n && m)
    {

        vector<int> dragon(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &dragon[i]);
        sort(dragon.begin(), dragon.end());

        vector<int> knight(m);
        for (int i = 0; i < m; i++)
            scanf("%d", &knight[i]);
        sort(knight.begin(), knight.end());

        int i = 0, j = 0, cost = 0;
        while (i < n && j < m)
        {
            if (knight[j] >= dragon[i])
            {
                cost += knight[j];
                i++;
            }
            j++;
        }

        if (i == n)
            printf("%d\n", cost);
        else
            printf("Loowater is doomed!\n");
    }
}