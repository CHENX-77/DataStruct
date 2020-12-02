//
// Created by CHENX on 2020/12/2.
//
#include <iostream>
using namespace std;

int findMiddel(int find,int p[],int n){
    int low=0;
    int height=n;
    int mid;
    while(low<=height){
        mid=(low+height)/2;
        if(find==p[mid])
            return mid;
        else if(find<p[mid])
            height=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main(){
    int n,t,find;
    cin>>n;
    int *p=new int [n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    cin>>t;
    while(t--){
        cin>>find;
        if(findMiddel(find,p,n)==-1)
            cout<<"error"<<endl;
        else
            cout<<findMiddel(find,p,n)+1<<endl;
    }
    delete [] p;
    return 0;
}