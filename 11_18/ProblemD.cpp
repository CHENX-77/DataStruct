//
// Created by CHENX on 2020/11/19.
//
#include <iostream>
using namespace std;
#define MaxNum 30
#define zero 0
class money{
public:
    string Vertex[MaxNum];
    float arcs[MaxNum][MaxNum];
    float Path[MaxNum][MaxNum];
    int Type_money;
    int Type_Rate;
    money();
    int FindLocation(string find);
    bool FindRoute();
};

money::money() {
    cin>>Type_money>>Type_Rate;
    int i,j,k;
    string str1,str2;
    float rate;
    for(i=0;i<Type_money;i++)
        for(j=0;j<Type_money;j++){
            arcs[i][j]=zero;
            Path[i][j]=zero;
        }

    for(i=0;i<Type_money;i++)//输入货币种类
        cin>>Vertex[i];
    for(i=0;i<Type_Rate;i++){
        cin>>str1>>rate>>str2;
        j=FindLocation(str1);
        k=FindLocation(str2);
        arcs[j][k]=rate;
    }
}

int money::FindLocation(string find) {
    int i;
    for(i=0;i<Type_money;i++){
        if(find==Vertex[i])
            return i;
    }
    return -1;
}

bool money::FindRoute() {
    int i,j,k;
    for(k=0;k<Type_money;k++)
        for(i=0;i<Type_money;i++)
            for(j=0;j<Type_money;j++){
                if(arcs[i][k]*arcs[k][j]>arcs[i][j]){//用邻接矩阵存储汇率，如果汇率通过经过其他货币到达的比自身的大，就更新汇率
                    arcs[i][j]=arcs[i][k]*arcs[k][j];
                }
            }
			
//比如矩阵  0   1   0
//        0   0   1
//        1   0   0
//    A跟C不知道连不连接[0,2]=0;
//    所以要把B作为中间结点，就是K=1才能看到
//    然后遍历数组，遇到[0,1]*[1,2]>[0,2]
//    也就是[i,k]*[k,j]>[i][j]
//    就更新那个[0,2]这个点的值
//    表示A跟C是相连接的并且值为2
//    当所有两个点的路径都确认了就是k=2的时候，就可以再次遍历数组，然后更新自己到自己的最大路径值
    for(i=0;i<Type_money;i++){
        if(arcs[i][i]>1)
            return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        money M;
        if(M.FindRoute())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}