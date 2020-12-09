//
// Created by CHENX on 2020/12/9.
//
#include <iostream>
using namespace std;

int CountTree(int n,int i,char* Test){
    int L,R;
    if(i>=n||Test[i]=='0')
        return 0;//如果遇到空结点就不计数
    L=CountTree(n,2*i+1,Test);
    R=CountTree(n,2*i+2,Test);
    cout<<Test[i]<<" "<<L-R<<endl;
    return L>R ? L+1:R+1;//+1是返回计数时还要加上自己
}

int main(){
    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        char* Test=new char[n];
        for(i=0;i<n;i++)
            cin>>Test[i];
        CountTree(n,0,Test);
        delete [] Test;
    }
    return 0;
}
