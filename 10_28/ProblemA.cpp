//
// Created by CHENX on 2020/10/28.
//
#include <iostream>
using namespace std;
class DoubleTree{
    int l;
    int *data;
public:
    DoubleTree(){
        int len;
        cin>>len;
        l=len;
        data=new int[len];
        for(int i=0;i<len;i++){
            cin>>data[i];
        }
    }
    void PreOrder(int i){
        if(data[i]!=0&&i<l){
            cout<<data[i]<<" ";
            PreOrder(2*i+1);//左子树
            PreOrder(2*i+2);//右子树
        }
    }//递归函数
};
int main(){
    int t;
    cin>>t;
    while(t--){
        DoubleTree t1;
        t1.PreOrder(0);//从下标为0的根结点开始
        cout<<endl;
    }
    return 0;
}
