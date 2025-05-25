#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=i*2+1,right=i*2+2;
    
    if(left<n&&arr[left]>arr[largest])
        largest=left;
    if(right<n&&arr[right]>arr[largest])
        largest=right;
    
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapssort(vector<int>&arr){
    int n=arr.size();
    // 先从非叶子节点进行比较
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for (auto i : arr) cout << i << " ";
    cout << endl;

    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
        for (auto i : arr) cout << i << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
        cin >> res[i];

    heapssort(res);
}