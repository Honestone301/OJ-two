#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;
/*
学会使用一个函数：
string substr(size_t pos = 0, size_t len = npos) const;
参数说明
pos：子字符串的起始位置（索引），从 0 开始计数。
len：需要提取的字符个数。如果省略或 len 超出字符串长度，则提取到字符串末尾。

本体做题原理：
后序遍历 = 左子树 + 右子树 + 根节点



输入样例
abcde
bcade

输出样例
cbeda
*/


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
