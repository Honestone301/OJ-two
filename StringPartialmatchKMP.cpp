
#include <iostream>
#include <cstring>
using namespace std;

int Next[100005]={0};
char s[100005];
int lens;

//void get_next(char T[],int next[]){
//    // 算法4.7
//    // 求模式串T的next函数值并存入数组next
//        // 请补全代码
//    next[1]=0;//初始化也是初始化下标为1的next
//    //注意字符串是从下标1开始录入的噢，下标0是用来存放长度的噢
//    int i=1,j=0;//i是字符串的下标，j是next的下标
//    while(i<=T[0]+1)
//    {
//        if((j==0)||T[i]==T[j])next[++i]=++j;//j这里有下标和当前next的值两个意思
//        else j=next[j];
//    }
//}

void getNext(){
	int cur=0;
    Next[1]=cur;
    for(int i=2;i<=lens;i++){
        while(cur&&Next[i]!=Next[cur+1]){
            cur=Next[cur];
        }
        if(Next[i]==Next[cur+1]){
            cur++;
        }
        Next[i]=cur;
    }
}

int main()
{
    scanf("%s",s+1);
    lens=strlen(s+1);
    getNext();
    int p=Next[lens];
    if(lens%(lens-p)==0)
    {
        cout<<lens/(lens-p);
    }
    else cout<<"1";
    return 0;
}


