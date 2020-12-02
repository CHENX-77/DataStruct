//
// Created by CHENX on 2020/10/14.
//

#include <queue>
#include <iostream>
#include <string>
using namespace std;
int len[10]={0};

bool FindNumber(int *L,int num,int group){
    for(int i=0;i<len[group];i++){
        if(L[i]==num){
            return true;
        }
    }
    return false;
}
int main() {
    int t,N;
    cin >> t;
    int **number=new int*[t];
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        len[i]=n;//记录每组的数字个数
        number[i] =new int[n];
        int j=0;
        while(n--){
            cin >> N;
            number[i][j]=N;
            j++;
        }
    }
    string str;
    int m=0;
    int *prior=new int[t];//prior用来存放输出组的序号
    queue<int>Line[t];//生成n个组
   while(cin>>str&&str!="STOP"){
       int In_number;
       if(str=="ENQUEUE"){
           cin>>In_number;
           for(int i=0;i<t;i++){
               if(FindNumber(number[i],In_number,i))//在对应的组里面找到了该数值
               {
                   if(Line[i].empty())//判断输入的队列是否为空
                       prior[m]=i;//如果为空就让prior[m]的值为i,记录优先顺序
                   m++;
                   Line[i].push(In_number);
                   break;
               }
           }
       }
       else if(str=="DEQUEUE"){
           for(int i=0;i<t;i++){
               if(!Line[prior[i]].empty()){//依照优先级输出
                       cout<<Line[prior[i]].front()<<endl;
                       Line[prior[i]].pop();
                       break;
                   }
               }
           }
       }
    return 0;
}



















