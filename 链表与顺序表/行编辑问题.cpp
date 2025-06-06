#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        vector<char>s1;
        char x;
        cin.get(x);
        while(x!='\n'){
            if(x=='#'){
                if(!s1.empty())
                    s1.pop_back();
            }else
            if(x=='@'){
                s1.clear();
            }else
            s1.push_back(x);
            cin.get(x);
        }
        for(auto i:s1){
            cout<<i;
        }
        cout<<endl;
    }
} 
