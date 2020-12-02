//
// Created by CHENX on 2020/11/11.
//
#include <iostream>
using namespace std;

typedef struct ArcNode{
    int adjvex;//该弧所指向的顶点的位置
    struct ArcNode *nextarc;//指向下一条弧的指针
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;//指向第一条依附该顶点的边
}VNode,AdjList[20];

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;//点的数目和边的数目
}ALGraph;

int LocateVex(ALGraph &G,char find){
    int i;
    for(i=0;i<G.vexnum;i++){
        if(find==G.vertices[i].data)
            return i;
    }
}

void CreateGraph(ALGraph &G){
    char St,Ed;
    int i,j,k;
    ArcNode *q;
    cin>>G.vexnum>>G.arcnum;//输入顶点数、边数
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;//输入顶点
        G.vertices[i].firstarc=NULL;//初始化链表头指针为空
    }
    for(k=0;k<G.arcnum;k++)
    {
        cin>>St>>Ed;
        i=LocateVex(G,St);
        j=LocateVex(G,Ed);

            ArcNode *pi=new ArcNode();
            pi->adjvex=j;//储存弧头
            pi->nextarc=NULL;
            q=G.vertices[i].firstarc;
            if(q==NULL){
                G.vertices[i].firstarc=pi;
            } else{//如果第i个顶点的边表结点不为空
                while(q->nextarc){//p==NULL
                    q=q->nextarc;
                }
                q->nextarc=pi;//尾部插入表结点
            }
    }
}

void Print_Adlist(ALGraph &L){
    ArcNode *q;
    for(int i=0;i<L.vexnum;i++){
        cout<<i<<" "<<L.vertices[i].data<<"-";
        q=L.vertices[i].firstarc;
        while(q){
            cout<<q->adjvex<<"-";
            q=q->nextarc;
        }if(q==NULL){
            cout<<"^"<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ALGraph G;
        CreateGraph(G);
        Print_Adlist(G);
    }
    return 0;
}