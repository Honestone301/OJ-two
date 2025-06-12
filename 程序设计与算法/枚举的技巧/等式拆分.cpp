#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
描述：
输入一个正整数，找到所有的正整数x>=y,使得1/k=1/x+1/y

输入格式：
一个正整数n，n<=100000

输出格式：
一行一个分式等式
小的分数显示在前面；多个等式，等式右边第一个分数小的先输出

输入样例：
2

输出样例：
1/2=1/6+1/3
1/2=1/4+1/4
*/

/*
解题原理：有一个转换关系 使得1/k=1/x+1/y  ➡️   (x-n)(y-n)=n^2
    通过设 a=(x-n) 、 b=(y-n)  
    使得 n*n / b ==0 ，判断通过就能得出a的值了
    那么输出答案就可以得到了
    ( x=a+n |  y=b+n )
        输出顺序 ➡️ 总体循环从 b从1开始计数，直到b<=n
*/
int main()
{
    // 以防万一，最好整道题都能使用 long long
    long long n;
    if(!(cin>>n)) return 0;
    long long nn = n * n;
    long long a = 1, b = 1;
     // 枚举 b = y - n，从 1 到 n，保证 a = n^2 / b >= b
    for (; b <= n; b++)
    {
        if (nn % b == 0)
        {
            a = nn / b;
            long long x = a + n;
            long long y = b + n;
            //这里允许了b从小开始计数，那么a就是从大的开始计数了
            //也就是x从小开始（分母越大，值越小）
            cout << "1/" << n
                 << "=1/" << x
                 << "+1/" << y
                 << endl;
        }
    }
    return 0;
}