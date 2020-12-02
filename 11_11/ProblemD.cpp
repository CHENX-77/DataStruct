//
// Created by CHENX on 2020/11/11.
//
#include <iostream>
#include <queue>
using namespace std;
const int Maxlen=20;

class Map{
private:
    bool Visit[Maxlen]; //表示每个顶点是否已被访问
    int Martix[Maxlen][Maxlen];//图的临界点阵
    int Vexnum; //顶点数量
    void BFS(int v);//广度优先
public:
    void BFSTraverse();
    void SetMatrix(int vnum,int mx[Maxlen][Maxlen]);
};

void Map::BFSTraverse() {
    BFS(0);
}

void Map::BFS(int v) {
    int w,u;
    int i,k;
    int *AdjVex =new int[Maxlen];
    queue<int>Q;
    for(i=0;i<Maxlen;i++)
        Visit[i]=false;

    for(v=0;v<Vexnum;++v){
        if(!Visit[v]){
            Visit[v]= true;
            Q.push(v);

            while(!Q.empty()){
                u=Q.front();
                cout<<u<<" ";
                Q.pop();

                for(i=0;i<Maxlen;i++)
                    AdjVex[i]=-1;

                int index=0;
                for(k=0;k<Vexnum;k++)
                    if(Martix[u][k]==1){
                        AdjVex[index]=k;
                        index++;
                    }
                i=0;
                    for(w=AdjVex[i];w!=-1;w=AdjVex[i],i++){
                        if(!Visit[w]){
                            Visit[w]= true;
                            Q.push(w);
                        }
                    }
            }
        }
    }
    cout<<endl;

}


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

int main(){
    int t,n;
    cin>>t;
    while(t--){
        Map M1;
        cin>>n;
        int Exam[Maxlen][Maxlen];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>Exam[i][j];
        M1.SetMatrix(n,Exam);
        M1.BFSTraverse();
    }
    return 0;
}

