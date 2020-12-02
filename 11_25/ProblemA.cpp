//
// Created by CHENX on 2020/11/25.
//

#include <iostream>
using namespace std;
const int Maxlen=20;
const int MaxDist=9999;

class Map{
private:
    int Martix[Maxlen][Maxlen];
    int Vexnum;
public:
    void SetMatrix(int vnum,int mx[Maxlen][Maxlen]);
    void ShortesPath_DIJ(int v0);
};


void Map::SetMatrix(int vnum, int mx[Maxlen][Maxlen]) {
    int i,j;
    Vexnum=vnum;
    for(i=0;i<Maxlen;i++){
        for(j=0;j<Maxlen;j++)
            Martix[i][j]=MaxDist;
    }

    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++){
            if(mx[i][j])
                Martix[i][j]=mx[i][j];
        }
}

void Map::ShortesPath_DIJ(int v0) {
    int i,j,v,w,min;
    int *dist=new int[Vexnum];
    bool *final=new bool [Vexnum];
    int path[Maxlen][Maxlen];
    int len[Maxlen];

    for(i=0;i<Vexnum;i++){
        final[i]= false;
        dist[i]=Martix[v0][i];
    }

    for(i=0;i<Maxlen;i++)
        for(j=0;j<Maxlen;j++)
            path[i][j]=-1;

    //初始化v0到其他顶点的路径
    for(i=0;i<Vexnum;i++){
        path[i][0]=v0;
        path[i][1]=i;
        len[i]=2;
        }

    dist[v0]=0;
    final[v0]= true;
    for(i=0;i<Vexnum;i++){
        min=MaxDist;
        //寻找离v0最近的顶点w
        for(j=0;j<Vexnum;j++)
            if(!final[j]&&min>dist[j]){
                min=dist[j];
                v=j;
            }

            final[v]=true;
            for(j=0;j<Vexnum;j++){
                if(!final[j]&&Martix[v][j]+min<dist[j]){
                    dist[j]=Martix[v][j]+min;
                    for(w=0;w<len[v];w++){
                        path[j][w]=path[v][w];
                    }
                    len[j]=len[v]+1;
                    path[j][len[j]-1]=j;
                }
            }

    }

    for(i=0;i<Vexnum;i++){
        if(i!=v0){
            cout<<v0<<"-"<<i<<"-"<<dist[i]<<"----[";
            for(j=0;j<len[i];j++){
                cout<<path[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
    delete [] dist;
    delete [] final;

}


int main(){
    int i,j,k,t;
    int vnum,v0;
    int mx[Maxlen][Maxlen];
    Map myMap;
    cin>>t;
    while(t--){
        for(i=0;i<Maxlen;i++)
            for(j=0;j<Maxlen;j++)
                mx[i][j]=0;

        cin>>vnum;

        for(i=0;i<vnum;i++)
            for(j=0;j<vnum;j++)
                cin>>mx[i][j];

        myMap.SetMatrix(vnum,mx);
        cin>>v0;
        myMap.ShortesPath_DIJ(v0);
    }
    return 0;
}


