//
// Created by CHENX on 2020/11/25.
//
#include <iostream>
using namespace std;
#define MaxNum 100

class Arcell{
public:
    bool isUsed;
    int cost;//路程花费
};

class Graph{
    Arcell arc[MaxNum][MaxNum];
    int arcnum;

public:
    Graph();
    int prim();
    int localIndex(int find);
};

int Graph::localIndex(int find) {
    int i;
    for(i=0;i<arcnum;i++)
    {
        if((find-1)==i){
            return i;
        }
    }
    return -1;
}

Graph::Graph() {
    int i,j;
    cin>>arcnum;
    for(i=0;i<arcnum;i++)
        for(j=0;j<arcnum;j++){
            cin>>arc[i][j].cost;
            arc[i][j].isUsed=false;
        }
    int n,m,l;
        cin>>n;
        while(n--){
            int a,b;
            cin>>a>>b;
            m=localIndex(a);
            l=localIndex(b);
            arc[m][l].isUsed=arc[l][m].isUsed=true;
        }
}

int Graph::prim() {
    int index=0;
    int sum=0;
    int visit[arcnum];
    int dist[arcnum];
    int pos[arcnum];
    visit[index]=true;
    for(int i=0;i<arcnum;i++){
        dist[i]=arc[index][i].cost;
        pos[i]=index*100+i;
    }



}

int main(){
    while(1){
        Graph G1;
        G1.prim();
        cout<<endl;
    }
    return 0;
}