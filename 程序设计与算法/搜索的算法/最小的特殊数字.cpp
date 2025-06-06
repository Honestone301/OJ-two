#include <iostream>
#include <algorithm>
 
using namespace std;
 
long long n; //几个数字
long long k; //除数
long long ans=0;  //满足条件的最小的数（不含前置0）
long long a[15]; //存放输入的n个数字
long long b[15]; //存放dfs结果的每一位数字
long long book[15]; //标记数组
 
long long getNum()
{
    long long num=0;
    for(int i=1; i<=n; i++)
    {
        num=num*10+b[i];
    }
    return num;
}
 
void dfs(int step)
{
    if(step==n+1)
    {
        if(getNum()%k==0&&ans==0) //！！！必须加上ans==0
        {
            ans=getNum();
        }
        return;
        /*
		注意这个 return 它的作用不是返回主函数，而是返回上一级的dfs函数
		例：如果此时是  dfs(5),遇到这个 return 就会回到上一级的 dfs函数
		也就是dfs(4),但此时dfs(4)的大部分语句已经执行了，只需要接着执行 book[i]=0
		然后继续进入for循环进入下一次的 dfs函数，直到结束。
		*/
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0&&step==1)
        {
            continue;
        }
        if(book[i]==0)
        {
            b[step]=a[i];
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}
 
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if(n==1&&a[1]==0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        sort(a+1,a+n+1); // //数组下标从1开始
        dfs(1);
        if(ans==0)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}