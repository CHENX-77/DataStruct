//
// Created by CHENX on 2020/11/18.
//
#include <iostream>
using namespace std;
int SUM;//计算总权值
//==========================================
typedef struct ArcCell{
    int adj;//线路的权重
}ArcCell,AdjMatrix[20][20];

typedef struct edge{
    int lowcose;//u到该点最小权值
    string adjvex;//u到该点最近的点的名称
}edge,Edge[20];

typedef struct {
    string vertex[20];//保存顶点字符
    AdjMatrix arcs;//二维数组
    int vexnum,arcnum;//顶点数，边数
}AMGraph;

int LocateVex( AMGraph &G,string find){
    int i;
    for(i=0;i<G.vexnum;i++){
        if(find==G.vertex[i])
            return i;
    }
    return -1;
}

void CreatUGraph(AMGraph &U){
    int i,j;
    cin>>U.vexnum;
    for(i=0;i<U.vexnum;i++)
        cin>>U.vertex[i];//输入顶点n
    cin>>U.arcnum;//输入边数m
    for(i=0;i<U.vexnum;i++)
        for(j=0;j<U.vexnum;j++)
            U.arcs[i][j].adj=9999;//初始化邻接矩阵

    string St,Ed;
    int w;
    for(int k=0;k<U.arcnum;k++){
        cin>>St>>Ed>>w;
        i=LocateVex(U,St);
        j=LocateVex(U,Ed);
        U.arcs[j][i].adj=U.arcs[i][j].adj=w;
    }
}

int Findmin(Edge clo,AMGraph &G){
    int Min,index,i,j;
    i=0;
    while(!clo[i].lowcose)//找到第一个非零值，赋给Min
        i++;
    Min=clo[i].lowcose;
    index=i;
    for(j=i+1;j<G.vexnum;j++) {
            if (clo[j].lowcose < Min&&clo[j].lowcose>0) {
                Min = clo[j].lowcose;
                index = j;
        }
    }
    return index;
}

void Prim(AMGraph G,string u){
    Edge closedge;
    int k=LocateVex(G,u);

    for(int j=0;j<G.vexnum;j++){
            closedge[j].adjvex=u;
            closedge[j].lowcose=G.arcs[k][j].adj;
    }
    closedge[k].lowcose=0;//将v加入到u中
    string P_Answer[G.vexnum-1][2];
    int P_Answer_N[G.vexnum-1];
    for(int i=1;i<G.vexnum;i++){
        k=Findmin(closedge,G);
        SUM+=closedge[k].lowcose;
//        cout<<closedge[k].adjvex<<" "<<G.vertex[k]<<" "<<closedge[k].lowcose<<endl;检查输出
        //保存搜索结果
        P_Answer[i-1][0]=closedge[k].adjvex;
        P_Answer[i-1][1]=G.vertex[k];
        P_Answer_N[i-1]=closedge[k].lowcose;//保存权值
        closedge[k].lowcose=0;
        for(int j=0;j<G.vexnum;j++){
            if(G.arcs[k][j].adj<closedge[j].lowcose){
                closedge[j].adjvex=G.vertex[k];
                closedge[j].lowcose=G.arcs[k][j].adj;
            }
        }
    }
    cout<<SUM<<endl;
    cout<<"prim:"<<endl;
    for(int i=0;i<G.vexnum-1;i++){
        for(int j=0;j<2;j++){
            cout<<P_Answer[i][j]<<" ";
        }
        cout<<P_Answer_N[i]<<endl;
    }
}

void Kruskal(AMGraph &G){
    cout<<"kruskal:"<<endl;
    int i,j;
    int father[G.vexnum]; //每个点所属的集体，所有结点相互独立
    for(i=0;i<G.vexnum;i++)
        father[i] = i;

    bool isExist[G.vexnum][G.vexnum];//判断点是否被选过

    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            isExist[i][j]= false;

    for(int k=0;k<G.vexnum-1;k++) //只能有vexnum-1条边
    {
        //找最小权值边,并标记该线为true，已加入集团
        int Min=99999,x=0,y=0;
        for(i=0;i<G.vexnum;i++)
        {
            for( j=0;j<G.vexnum;j++)
            {
                if(father[i] == father[j])     //如果在同一个集体里面，则不找其边
                    continue;
                if(G.arcs[i][j].adj<Min && !isExist[i][j])
                {
                    Min = G.arcs[i][j].adj;
                    x = i;
                    y = j;
                }
            }
        }
        isExist[x][y] = isExist[y][x] = true;

        //加入集团
        if(x<y)//使得输出的前面边的序号是小的
        {
            cout<<G.vertex[x]<<" "<<G.vertex[y]<<" "<<Min<<endl;
            for(i=0;i<G.vexnum;i++)
                if(father[i] == father[y] && i!=y)
                    father[i] = father[x];
            father[y] = father[x];//让两个点的集团相等
        }
        else
        {
            cout<<G.vertex[y]<<" "<<G.vertex[x]<<" "<<Min<<endl;
            for(i=0;i<G.vexnum;i++)
                if(father[i] == father[x] && i!=x)
                    father[i] = father[y];
            father[x] = father[y];
        }
    }
}


int main(){
    string v1;
    AMGraph M1;
    SUM=0;
    CreatUGraph(M1);
    cin>>v1;
    Prim(M1,v1);
    Kruskal(M1);
    return 0;
}