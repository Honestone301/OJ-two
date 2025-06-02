#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
/*
思路：对于题给定的数据输入形式，现有一种应对方式：
    创建三数组（左子树，右子树，根节点）进行存储
        然后基于queue进行层序遍历（同时使用widen进行记录横向记录）
        
        数据类型为：make_pair<int,int>  ->  根节点node ｜  深度depth 
        每当进行到node时候，在对应depth数组的depth进行自增操作

    最后遍历一遍depth数组找出最大值即可
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> lchind(n + 1, 0);
    vector<int> rchild(n + 1, 0);
    vector<int> appear(n + 1, -1);

    int m=n;
    n--;
    while (n--)
    {
        int p, q;
        cin >> p >> q;
        appear[p]++;
        if (appear[p] == 0)
        {
            lchind[p] = q;
        }
        else if (appear[p] == 1)
        {
            rchild[p] = q;
        }
    }

    queue<pair<int, int>> q1;
    vector<int>deptth(m+1,0);
    q1.push({1, 1});
    while (!q1.empty())
    {
        int node = q1.front().first;
        int depth = q1.front().second;
        q1.pop();
        if (lchind[node])
        {
            q1.push({lchind[node], depth + 1});
        }
        if(rchild[node]){
            q1.push({rchild[node],depth+1});
        }
        deptth[depth]++;
    }
    int max_depth=0;
    for(auto i:deptth){
        max_depth=max(max_depth,i);
    }
    cout<<max_depth;
}