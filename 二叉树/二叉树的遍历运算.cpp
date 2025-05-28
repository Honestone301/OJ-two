#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;
/*
输入样例
abcde
bcade

输出样例
cbeda
*/
// 后序遍历 = 左子树 + 右子树 + 根节点

string dfs(string preorder, string iniorder)
{
    if (preorder.size() == 0 || iniorder.size() == 0)
        return "";
    char root = preorder[0];
    auto i = iniorder.find(root);
    string inoright = iniorder.substr(i + 1);
    string inoleft = iniorder.substr(0, i);
    int leftinlength = inoleft.size();
    string preleft = preorder.substr(1, leftinlength);
    string preright = preorder.substr(leftinlength + 1);
    return dfs(preleft, inoleft) + dfs(preright, inoright) + root;
}
int main()
{
    string inorder;
    string preorder;
    cin>>preorder>>inorder;
    cout << dfs(preorder, inorder)<< endl;
}
