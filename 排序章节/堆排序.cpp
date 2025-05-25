#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//此函数用于对指定子树进行重新调整（包括其子树在内）
void heapify(vector<int>&res,int key,int len){
    int largest=key;
    int left=key*2+1;
    int right=key*2+2;

    if(left<len&&res[largest]<res[left])
        largest=left;
    if(right<len&&res[largest]<res[right])
        largest=right;
    
    //这里进行递归操作->用于彻底调整好所在子树的顶堆
    if(largest!=key){
        swap(res[key],res[largest]);
        heapify(res,largest,len);
    }
}

// 这个是堆排序的主要整体框架
void heapssort(vector<int>&res){
    int len=res.size();

    //这个进行的应该是第一次对整体数组进行堆排序
    for(int i=len/2-1;i>=0;i--){
        heapify(res,i,len);
    }

    for (auto i : res) cout << i << " ";
    cout << endl;

    //  现在轮到了依次进行一次次的 底 & 顶 换位
    //  进以实现最大变为树叶
    for(int i=len-1;i>0;i--){
        swap(res[i],res[0]);
        // 因为更换的是根节点
        //  所以从根节点进行顶堆排序
        heapify(res,0,i);
        for (auto i : res) cout << i << " ";
        cout << endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }

    heapssort(res);
    return 0;
}