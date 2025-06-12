#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> res;
/*
从键盘输入N个整数N<=10,要求输出这N个整数的全排列，且每一个排列当中，相邻两个数不能同为奇数。

输入样例：
3
1 1 2

输出样例：
1 2 1
*/
vector<int> used;
int inde = 0;
void dfs(int n, vector<int> &re)
{
    if (inde == n)
    {
        for (auto i : re)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            if (inde > 0 && re[inde - 1] % 2 != 0 && res[i] % 2 != 0 || i > 0 && used[i - 1] == 0 && res[i] == res[i - 1])
                continue;
            used[i] = 1;
            re.push_back(res[i]);
            inde++;
            dfs(n, re);
            used[i] = 0;
            re.pop_back();
            inde--;
        }
        else
        {
            continue;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    res.resize(n, 0);
    used.resize(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

    sort(res.begin(), res.end());
    vector<int> re;
    dfs(n, re);
}