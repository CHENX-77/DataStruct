//
// Created by CHENX on 2020/11/11.
//
#include <iostream>
using namespace std;

//==========================================
typedef struct ArcCell{
    int adj;//0或者1
}ArcCell,AdjMatrix[20][20];

typedef struct {
    string vertex[20];//保存顶点字符
    AdjMatrix arcs;//二维数组
    int vexnum,arcnum;//顶点数，边数
    char Kind;//图的种类
}AMGraph;

int LocateVex( AMGraph &G,string find){
    int i;
    for(i=0;i<G.vexnum;i++){
        if(find==G.vertex[i])
            return i;
    }
}

void CreatUGraph(AMGraph &U,int n){
    int i,j;
    U.vexnum=n;
    for(i=0;i<n;i++)
        cin>>U.vertex[i];//输入顶点信息
    cin>>U.arcnum;//输入边数
    for(i=0;i<U.vexnum;i++)
        for(j=0;j<U.vexnum;j++)
            U.arcs[i][j].adj=0;
    string St,Ed;
    for(int k=0;k<U.arcnum;k++){
        cin>>St>>Ed;
        i=LocateVex(U,St);
        j=LocateVex(U,Ed);
        U.arcs[i][j].adj=1;
        U.arcs[j][i].adj=U.arcs[i][j].adj;
    }
}

void Print_U(AMGraph &U){
    int Count[U.vexnum];
    for(int i=0;i<U.vexnum;i++){
        Count[i]=0;
        for(int j=0;j<U.vexnum;j++){
            if(U.arcs[i][j].adj==1){
                Count[i]++;
            }
            cout<<U.arcs[i][j].adj<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<U.vexnum;i++){
        if(Count[i]!=0){
         cout<<U.vertex[i]<<": "<<Count[i]<<endl;
        } else if(Count[i]==0){
            cout<<U.vertex[i]<<endl;
        }
    }
}

void CreatDGraph(AMGraph &D,int n){
    int i,j;
    D.vexnum=n;
    for(i=0;i<n;i++)
        cin>>D.vertex[i];//输入顶点信息
    cin>>D.arcnum;//输入边数
    for(i=0;i<D.vexnum;i++)
        for(j=0;j<D.vexnum;j++)
            D.arcs[i][j].adj=0;
    string St,Ed;
    for(int k=0;k<D.arcnum;k++){
        cin>>St>>Ed;
        i=LocateVex(D,St);
        j=LocateVex(D,Ed);
        D.arcs[i][j].adj=1;
    }
}

void Print_D(AMGraph &D){
    int Count[D.vexnum][2];
    for(int i=0;i<D.vexnum;i++){
        Count[i][0]=0;
        Count[i][1]=0;
        for(int j=0;j<D.vexnum;j++){
            if(D.arcs[i][j].adj==1){
                Count[i][0]++;
            }
            cout<<D.arcs[i][j].adj<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<D.vexnum;i++){
        for(int j=0;j<D.vexnum;j++){
            if(D.arcs[j][i].adj==1){
                Count[i][1]++;
            }
        }
    }

    for(int i=0;i<D.vexnum;i++){
        cout<<D.vertex[i];
        if(Count[i][0]!=0||Count[i][1]!=0)
            cout<<": "<<Count[i][0]<<" "<<Count[i][1]<<" "<<Count[i][0]+Count[i][1]<<endl;
        else
            cout<<endl;
    }
}

int main(){
    int t,n;
    char T;
    cin>>t;
    while(t--){
        cin>>T>>n;
        if(T=='D'){
            AMGraph P1;
            CreatDGraph(P1,n);
            Print_D(P1);

        }else if(T=='U'){
            AMGraph P2;
            CreatUGraph(P2,n);
            Print_U(P2);
        }
    }
    return 0;
}