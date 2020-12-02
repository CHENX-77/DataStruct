//
// Created by CHENX on 2020/10/14.
//
#include <queue>
#include <iostream>
using namespace std;
int main(){
    queue<int>myQA;
    queue<int>myQB;
    queue<int>myQC;
    int n,i;
    int Alen,Blen,Clen;
    int sum=0;
    Alen=Blen=Clen=0;//队列长度
    cin>>n;
    char *type=new char[n];
    int *time=new int[n];
    for(i=0;i<n;i++)
        cin>>type[i];//输入n个客户
    for(i=0;i<n;i++)
            cin>>time[i];//输入n个时间

    for(i=0;i<n;i++){
        switch (type[i]) {
            case 'A':
                myQA.push(time[i]);
                Alen++;
                break;
            case 'B':
                myQB.push(time[i]);
                Blen++;
                break;
            case 'C':
                myQC.push(time[i]);
                Clen++;
                break;
            default:
                cout<<"error"<<endl;
                return 0;
        }
    }
    while(myQA.empty()==false){
        sum+=myQA.front();
        myQA.pop();
    }
    cout<<sum/Alen<<endl;
    sum=0;
    while(myQB.empty()== false){
        sum+=myQB.front();
        myQB.pop();
    }
    cout<<sum/Blen<<endl;
    sum=0;
    while (myQC.empty()== false){
        sum+=myQC.front();
        myQC.pop();
    }
    cout<<sum/Clen<<endl;
    return 0;
}