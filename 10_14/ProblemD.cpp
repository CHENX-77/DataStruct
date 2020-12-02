//
// Created by CHENX on 2020/10/14.
//
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
class Window{
public:
    int endtime;
};
class People{
public:
    int arrivetime,waittime,keeptime;
};

int FindMinWindow(Window*W,int n){
    int min=W[0].endtime;
    int mT=0;
    for(int i=0;i<n;i++){
        if(min>W[i].endtime){
            min=W[i].endtime;
            mT=i;
        }
    }
    return mT;
}//找到窗口中还需要处理时间最小的

int main(){
    int N,NTemp,K,T,P,L=0;
    int Max_time,Last_time;
    double Overage_time;
    Overage_time=Max_time=Last_time=0;
    cin>>N;
    NTemp=N;
    People persons[N];
    for(int i=0;i<N;i++){
        cin>>T>>P;
        persons[i].arrivetime=T;
        persons[i].waittime=0;
        persons[i].keeptime=P;
    }//给顾客的业务赋值
    cin>>K;
    Window windows[K];
    for(int i=0;i<K;i++){
        windows[i].endtime=0;
    }
    //给窗口等待时间的初始值都赋值0
    while(L<N){
        bool isWait=true;//判断客户是否需要等待
        int index=-1;//记录客户下标
        int Minendtime;
        for(int i=0;i<K;i++){
            if(persons[L].arrivetime>=windows[i].endtime){
                windows[i].endtime=persons[L].arrivetime+persons[L].keeptime;//更新窗口的结束时间
                isWait= false;//下一个就需要等
                L++;
            }
        }
        if(isWait){
            Minendtime=FindMinWindow(windows,K);// 找到结束时间最小的窗口的标号
            index=Minendtime;
            persons[L].waittime+=windows[index].endtime-persons[L].arrivetime;//更新客户的等待时间
            Overage_time+=windows[index].endtime-persons[L].arrivetime;
            if(Max_time<windows[index].endtime-persons[L].arrivetime)
                Max_time=windows[index].endtime-persons[L].arrivetime;
            windows[index].endtime+=persons[L].keeptime;
            L++;
        }
    }
    for(int i=0;i<K;i++){
        if(Last_time<windows[i].endtime)
            Last_time=windows[i].endtime;
    }
    Overage_time/=NTemp;
    cout<<fixed<<setprecision(1)<<Overage_time<<" "<<Max_time<<" "<<Last_time<<endl;
    return 0;
}
