//
// Created by CHENX on 2020/11/18.
//
#include <iostream>
using namespace std;
const int Maxlen=20;
int SUM;
class Map{
private:
    bool Visit[Maxlen]; //表示每个顶点是否已被访问
    int Martix[Maxlen][Maxlen];//图的临界点阵
    string Vertex[20];
    int Vexnum,Arcnum; //顶点数量、边的数量
    int DFS(int v);//深度优先，私有函数

public:
    int Count=0;
    void CreatMatrix();
    int DFSTraverse(); //公有函数
    bool Judge();
    void Print_Graph();
    int LocateVex(string find);
};

int Map::LocateVex(string find){
    int i;
    for(i=0;i<Vexnum;i++){
        if(find==Vertex[i])
            return i;
    }
    return -1;
}

void Map::CreatMatrix() {
    int i,j;
    cin>>Vexnum;
    for(i=0;i<Vexnum;i++)
        cin>>Vertex[i];//输入顶点n
    cin>>Arcnum;//输入边数m

    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++)
            Martix[i][j]=0;
    string St,Ed;
    for(int k=0;k<Arcnum;k++){
        cin>>St>>Ed;
        i=LocateVex(St);
        j=LocateVex(Ed);
        Martix[j][i]=Martix[i][j]=1;
    }
}

int Map::DFSTraverse() {
    int i,j=0;
    for(i=0;i<Vexnum;i++)
        Visit[i]= false;
    while(Count!=Vexnum){//如果计数器的值不等于结点值就一直循环
        i=0;
        while (Visit[i])
            i++;
        j+=DFS(i);//调用一次DFS说明有一个集合
    }
    return j;
}

int Map::DFS(int v) {
    int w,i,k;
    Visit[v]=true;
    Count++;
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
    return 1;
}
bool Map::Judge() {
    for(int i=0;i<Vexnum;i++){
        for(int j=0;j<Vexnum;j++)
            Visit[j]= false;
        SUM=0;
        DFSTraverse();
        if(SUM!=Vexnum)
            return false;
    }
    return true;
}

void Map::Print_Graph() {
        int i,j;
        for(i=0;i<Vexnum;i++)
            cout<<Vertex[i]<<" ";
        cout<<endl;
        for(i=0;i<Vexnum;i++){
            for(j=0;j<Vexnum;j++){
                cout<<Martix[i][j]<<" ";
            }
            cout<<endl;
        }
}



int main(){
    int t;
    cin>>t;
    while(t--){
        Map M1;
        M1.CreatMatrix();
        M1.Print_Graph();
        cout<<M1.DFSTraverse()<<endl;
        cout<<endl;
    }
    return 0;
}
