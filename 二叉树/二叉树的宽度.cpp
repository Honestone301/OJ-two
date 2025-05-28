#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> lchind(n + 1, 0);
    vector<int> rchild(n + 1, 0);
    vector<int> appear(n + 1, -1);

    n--;
    cout<<"n是"<<n<<endl;
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
    vector<int>deptth(n+1,0);
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