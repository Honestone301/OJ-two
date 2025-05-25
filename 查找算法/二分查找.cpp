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
    int key;
    cin>>key;
    int left=0,right=n-1;

    while(left<=right){
            int mid=left+(right-left)/2;
        if(res[mid]==key){
            cout<<"The element position is "<<mid<<".";
            return 0;
        }else if(res[mid]>key){            
            right=mid-1;
        }else if(res[mid]<key){
            left=mid+1;
        }
    }
    cout<<"The element is not exist."<<endl;
    
}