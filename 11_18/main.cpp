//void PRIM(MGraph &G,VertexType u)
//{
//    int i,j,k;
//    minside closedge;
//    k=LocateVex(G,u);
//    for(j=0;j<G.vexnum;++j) // 辅助数组初始化
//    {
//        if(j!=k)
//        {
//            strcpy(closedge[j].adjvex,u);
//            closedge[j].lowcost=G.arcs[k][j].adj;
//        }
//    }
//    closedge[k].lowcost=0; // 初始,U={u}
//    printf("\t\t最小代价生成树的各条边及权值为:\n");
//    printf("\n");
//    printf("\t\t<起点->终点>\t权值\n");
//    for(i=1;i<G.vexnum;++i)
//    { // 选择其余G.vexnum-1个顶点
//        k=minimum(closedge,G); // 求出T的下一个结点：第K顶点
//        printf("<%s-%s>\t\t%d\n",closedge[k].adjvex,G.vexs[k],closedge[k].lowcost); // 输出生成树的边
//        closedge[k].lowcost=0; // 第K顶点并入U集
//        for(j=0;j<G.vexnum;++j)
//            if(G.arcs[k][j].adj<closedge[j].lowcost)
//            {
//// 新顶点并入U集后重新选择最小边
//                strcpy(closedge[j].adjvex,G.vexs[k]);
//                closedge[j].lowcost=G.arcs[k][j].adj;
//            }
//    }
//}
//
//int LocateVex(MGraph G,VertexType u) //若G中存在顶点u，则返回该顶点在图中的位置，否则返回-1
//{
//    int i;
//    for(i = 0; i < G.vexnum; ++i)
//        if( strcmp(u, G.vexs[i]) == 0)
//            return i;
//    return -1;
//}
//
//int minimum(minside S,MGraph G) //求closedge.lowcost的最小值
//{
//    int i=0,j,k,min;
//    while(!S[i].lowcost)
//        i++;
//    min=S[i].lowcost; // 第一个不为0的值
//    k=i;
//    for(j=i+1;j<G.vexnum;j++)
//        if(S[j].lowcost>0)
//            if(min>S[j].lowcost)
//            {
//                min=S[j].lowcost;
//                k=j;
//            }
//    return k;
//}

#include <iostream>
using namespace std;
//析构二维数组
void dele(int **p,int n){
    for(int i=0;i<n;i++)
        delete [] p[i];
    delete []p;
}

int main(){
    int t,n,i,j,k;
    int flag;
    flag=0;
    cin>>t;
    while(t--){
        cin>>n;
        //生成邻接矩阵
        int **Martix=new int*[n];
        for(i=0;i<n;i++)
            Martix[i]=new int[n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>Martix[i][j];

        for(k=0;k<n;k++)
        {
            //通过floyd算法判断是否连通
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(Martix[i][j]==0&&Martix[i][k]==1&&Martix[k][j]==1)//如果没有直接连接但是通过其他点间接连接上了
                        Martix[i][j]=1;
                }
            }
        }
        //检查数组更新之后是否对称为1
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(j==i)
                    continue;
                else{
                    if(Martix[i][j]!=1)
                        flag=1;
                }
            }
        if(!flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        dele(Martix,n);
    }
    return 0;
}
