//
// Created by CHENX on 2020/12/2.
//
#include <iostream>
using namespace std;
int count;

int findIndex(int p[],int n,int find){
    for(int i=0;i<n;i++){
        if(find==p[i])
            return i;
    }
    return -1;
}//返回指数

int findElem(int p[],int index, int k, int find){
    for(int i=index;i<index+k;i++){
        count++;
        if(find==p[i]){
            return i;
        }
    }
    return -1;
}


int main(){
    int n,k,t,i,j,find,temp;
    cin>>n;
    int *p=new int [n];
    for(i=0;i<n;i++)
        cin>>p[i];
    cin>>k;
    temp=n/k;
    int f[k][2];
    for( i=0;i<k;i++) {
        cin >> f[i][0];
        f[i][1]=findIndex(p,n,p[i*temp]);
    }
    cin>>t;
    while(t--) {
        count=0;
        cin >> find;
        for (i = 0; i < k; i++) {
            count++;
            if (find <= f[i][0]) {
                j = f[i][1];
                break;
            }
        }
        int answer=findElem(p, j, n/k, find);
        if (answer== -1){
            cout<<"error"<<endl;
        } else{
            cout<<answer+1<<"-"<<count<<endl;
        }
    }

    return 0;
}