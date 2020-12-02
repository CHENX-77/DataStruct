//
// Created by CHENX on 2020/11/11.
//
#include <iostream>
using namespace std;
const int Maxlen=20;

class Map{
private:
    bool Visit[Maxlen]; //表示每个顶点是否已被访问
    int Martix[Maxlen][Maxlen];//图的临界点阵
    int Vexnum; //顶点数量
    void DFS(int v);//深度优先，私有函数

public:
    void SetMatrix(int vnum,int mx[Maxlen][Maxlen]);
    void DFSTraverse(); //公有函数

};

void Map::SetMatrix(int vnum, int mx[Maxlen][Maxlen]) {
    int i,j;
    Vexnum=vnum;
    for(i=0;i<Maxlen;i++)
        for(j=0;j<Maxlen;j++)
            Martix[i][j]=0;

    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++)
            Martix[i][j]=mx[i][j];
}

void Map::DFSTraverse() {
    int v;
    for(int i=0;i<Maxlen;i++)
        Visit[i]= false;
    for(v=0;v<Vexnum;v++)
        if(!Visit[v])
            DFS(v);
    cout<<endl;
}

void Map::DFS(int v) {
    int w,i,k;

    Visit[v]=true;
    cout<<v<<" ";

    int *AdjVex=new int[Vexnum];
    for(i=0;i<Vexnum;i++)
        AdjVex[i]=-1;
    k=0;
    //搜索邻接矩阵找出与顶点v相连的其他顶点编号
    for(i=0;i<Vexnum;i++)
        if(Martix[v][i]==1){
            AdjVex[k]=i;
            k++;
        }
    i=0;
    for(w=AdjVex[i];w!=-1;i++,w=AdjVex[i]){
        if(!Visit[w])
            DFS(w);
    }

    delete []AdjVex;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int Exam[Maxlen][Maxlen];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>Exam[i][j];
        Map M1;
        M1.SetMatrix(n,Exam);
        M1.DFSTraverse();
    }
    return 0;
}















