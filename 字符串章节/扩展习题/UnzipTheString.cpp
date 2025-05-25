/*
#include<iostream>
#include<string>
#include<utility>
using namespace std;
//S仅包含大写字母、[、]、|;
pair<int,int> search(string x,int left,int right){
    while(left!=right&&x[left]!='['||x[right]!=']'){
        if(x[left]=='['){
            right--;
            continue;
        }else if(x[right]==']'){
            left++;
            continue;
        }
        if(x[left]=='['&&x[right]==']'){
            break;
        }
        left++;right--;
    }
    if(left==right){
        return make_pair(0,0);
    }
    return make_pair(left,right);
}

string unzip(string x,int lens,int left,int right){
    pair<int, int> result = search(x, left, right);
    if(result.first==0&&result.second==0){
        return 0;
    }
    left=result.first;
    right=result.second;
    int beishu=x[++left]-'0';
    //寻找第二个括号匹配项目
    pair<int,int>result2=search(x,left,right);
    if(result2.first==0&&result2.second==0){
        return 0;
    }
    left=++result2.first;
    right=--result2.second;

    unzip(x.substr(++left,--right)))
    return 
}

int main(){
    string zip;
    cin>>zip;
    string y;

    unzip(zip,0,0,zip.size()-1);
}

*/
#include<iostream>
#include<string>
#include<utility>
using namespace std;
string search(string x,int &i){
    string y="";
    while(i<x.size()&&x[i]!=']'){
        if(x[i]>='A'&&x[i]<='Z'){
            y+=x[i++];
        }else{//此时非字母，为‘【’
            int sum=0;
            i++;//此时为数字
            while(isdigit(x[i])){
                sum=sum*10+x[i++]-'0';
            }
            i++;//此时为 ‘｜’ 下一个
            string add=search(x,i);
            i++;// ']'
            while(sum--){
                y+=add;
            }
        }
    }
    return y;
}

int main(){
    string x;
    cin>>x;
    int i=0;
    cout<<search(x,i)<<endl;


}