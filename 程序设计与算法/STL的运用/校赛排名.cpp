/*
N
解题数  时长   名字
4
3 5 Jon
5 100 Smith
3 5 Tom
6 95 Hel
*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
struct student{
    int question;
    int time;
    char name[21];
    int index;
}a;
int main(){
    int N;
    scanf("%d",&N);

    vector<student>b(N);

    for(int i=0;i<N;i++){
        scanf("%d %d %s",&b[i].question,&b[i].time,b[i].name);
        b[i].index=i;
    }

    sort(b.begin(),b.end(),[](const student&a,const student&b){
        if(a.question!=b.question){
            return a.question>b.question;
        }else{
            if(a.time!=b.time){
                return a.time<b.time;
            }else{
                return a.index<b.index;
            }
        }
    });
    for(auto i:b){
        printf("%s\n",i.name);
    }
    return 0;
}