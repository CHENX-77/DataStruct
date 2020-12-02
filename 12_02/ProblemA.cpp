//
// Created by CHENX on 2020/12/2.
//

#include <iostream>
using namespace  std;

int main(){
    int n,index,find,t,answer;
    cin>>n;
    int *p=new int [n+1];
    for(int i=1;i<=n;i++)
        cin>>p[i];
    cin>>t;
    while(t--){
        cin>>find;
        p[0]=find;
        answer=0;
        for(index=1;index<=n;index++)
            if(p[index]==find){
                answer=index;
                break;
            }
        if(answer==0)
            cout<<"error"<<endl;
        else
            cout<<answer<<endl;
    }
    delete [] p;
    return 0;
}