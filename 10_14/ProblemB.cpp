//
// Created by CHENX on 2020/10/14.
//
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

double GetPoint(double n){
    double Temp=n-(int)n;
    return Temp;
}//获取输入数字的小数部分

void ChangetoK(double num,int k){
    double Point=GetPoint(num);
    int N=(int)num;//获取整数部分
    stack<char>zhengshu;
    queue<char>xiaoshu;
    double yushu,mul;
    while(N){
        yushu=N%k;
        if(yushu>=10)
            zhengshu.push((char)('A'+yushu-10));//余数大于10就换成字母
        else
            zhengshu.push((char)(yushu+'0'));
        N/=k;
    }
    int count=0;
    int flag=0;
    while(count<3){
        mul=Point*k;
        double P=GetPoint(mul);
        int Z=(int)mul;
        if(mul>=10)
            xiaoshu.push((char)('A'+Z-10));//乘积大于10就换成字母
        else if(GetPoint(Point)==0) {
            xiaoshu.push('0');
            flag=1;//让标志位为1，防止下一次循环多执行一次xiaoshu的push
        }
        else if(flag==0)
            xiaoshu.push((char)('0'+mul));
        Point=P;
        count++;
    }
    while(zhengshu.empty()== false){
        cout<<zhengshu.top();
        zhengshu.pop();
    }

    cout<<".";
    while(xiaoshu.empty()== false){
        cout<<xiaoshu.front();
        xiaoshu.pop();
    }
    cout<<endl;
}

int main(){
    int t,k;
    double n;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ChangetoK(n,k);
    }
    return 0;
}
