#include <iostream>
#include <vector>
using namespace std;
struct grades
{
    int question;
    int time;
    char name[21];
    int index;
} a;

int main()
{
    int n;
    cin >> n;
    vector<grades> res(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %s", &res[i].question, &res[i].time, res[i].name);
        res[i].index = i;
    }
    sort(res.begin(), res.end(), [](const grades &a, const grades &b)
         {
        if(a.question!=b.question){
            return a.question>b.question;
        }else if(a.time !=b.time){
            return a.time<b.time;
        }else {
            return a.index<b.index;
        } });
    for (auto i : res)
    {
        printf("%s\n", i.name);
    }
    return 0;
}