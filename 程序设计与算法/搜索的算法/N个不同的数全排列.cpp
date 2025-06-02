#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> res;
/*
输入样例：
3
3 9 1

输出样例：
1 3 9
1 9 3
3 1 9
3 9 1
9 1 3
9 3 1
*/
vector<int> used;
void dfs(int n, vector<int>&re)
{
    if (re.size() == n)
    {
        for (auto i : re)
        {
            cout << i << " ";
        }
        cout << endl;
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            re.push_back(res[i]);
            dfs(n, re);
            used[i] = 0;
            re.pop_back();
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
    cin>>n;
    res.resize(n, 0);
    used.resize(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

    sort(res.begin(),res.end());
    vector<int> re;
    dfs(n, re);
}