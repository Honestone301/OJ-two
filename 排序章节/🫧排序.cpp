#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

    for (int i = 0; i < n; i++)
    {
        int record=0;
        for(int j=0;j<n-i-1;j++){
            if(res[j]>res[j+1]){
                int tmp;
                tmp=res[j];
                res[j]=res[j+1];
                res[j+1]=tmp;
                record++;
            }
        }
        for(auto i:res)
            cout << i << " ";
        cout << endl;
        if(record==0) break;
        record=0;
    }

}