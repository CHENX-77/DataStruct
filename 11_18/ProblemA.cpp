//
// Created by CHENX on 2020/11/18.
//
//#include <iostream>
//using namespace std;
////析构二维数组
//void dele(int **p,int n){
//    for(int i=0;i<n;i++)
//        delete [] p[i];
//    delete []p;
//}
//
//int main(){
//    int k,n,i,j,m;
//    int flag;
//    flag=0;
//    cin>>k;
//    while(k--){
//        cin>>n;
//        //生成邻接矩阵
//        int **Martix=new int*[n];
//        for(i=0;i<n;i++)
//            Martix[i]=new int[n];
//        for(i=0;i<n;i++)
//            for(j=0;j<n;j++)
//                cin>>Martix[i][j];
//
//        for(m=0;m<n;m++)
//        {
//            //更新n次数组
//            for(i=0;i<n;i++)
//            {
//                for(j=0;j<n;j++)
//                {
//                    if(Martix[i][j]==0&&Martix[i][m]==1&&Martix[m][j]==1)
//                        Martix[i][j]=1;
//                }
//            }
//        }
//        //检查数组更新之后是否对称为1
//        for(i=0;i<n;i++)
//            for(j=0;j<n;j++){
//                if(j==i)
//                    continue;
//                else{
//                    if(Martix[i][j]!=1)
//                        flag=1;
//                }
//            }
//        if(!flag)
//            cout<<"Yes"<<endl;
//        else
//            cout<<"No"<<endl;
//        dele(Martix,n);
//    }
//    return 0;
//}
#include <iostream>
using namespace std;
const int Maxlen=20;
int SUM;
class Map{
private:
    bool Visit[Maxlen]; //表示每个顶点是否已被访问
    int Martix[Maxlen][Maxlen];//图的临界点阵
    int Vexnum; //顶点数量
    void DFS(int v);//深度优先，私有函数

public:
    void SetMatrix(int vnum,int mx[Maxlen][Maxlen]);
    void DFSTraverse(int v); //公有函数
    bool Judge();
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

void Map::DFSTraverse(int v) {
    for(int i=0;i<Maxlen;i++)
        Visit[i]= false;
    DFS(v);
}

void Map::DFS(int v) {
    int w,i,k;
    Visit[v]=true;
    SUM++;
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
bool Map::Judge() {
    for(int i=0;i<Vexnum;i++){
        for(int j=0;j<Vexnum;j++)
            Visit[j]= false;
        SUM=0;
        DFSTraverse(i);
        if(SUM!=Vexnum)
            return false;
    }
    return true;
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
        if(M1.Judge())
            cout<<"Yes";
        else
            cout<<"No";
        cout<<endl;
    }
    return 0;
}