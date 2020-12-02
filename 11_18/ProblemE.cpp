//
// Created by CHENX on 2020/11/18.
//
#include <iostream>
using namespace std;

const int Maxlen=20;
int SUM[20];
int k;
class Map{
private:
    int Martix[Maxlen][Maxlen];//图的临界点阵
    int Vexnum,Arcnum; //顶点数量、边的数量
public:
    int GetVexnum(){return Vexnum;}
    void CreatMatrix();
    void Print_AOV();
    int LocateVex(string find);
    void Print_Sum();
};

void Map::CreatMatrix() {
    int i,j;
    cin>>Vexnum;//输入n个顶点

    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++){
            cin>>Martix[i][j];
            SUM[i]=0;
        }

}
void Map::Print_AOV() {
    int i,j,flag=0;
    for(i=0;i<Vexnum;i++){
        int Count=0;
        for(j=0;j<Vexnum;j++)
            if(Martix[j][i]==0){
                Count++;
                if(Count==Vexnum){
                    flag=1;
                    break;
                }
            }
        if(flag==1)
            break;
    }//找到第一个列是全0
    SUM[k]=i;
    k++;
    for(j=0;j<Vexnum;j++){
        Martix[i][j]=0;
        Martix[j][i]=2;//标记已经输出的列结点，下次就不访问该列
    }

}

void Map::Print_Sum() {
    for(int i=0;i<Vexnum;i++)
        cout<<SUM[i]<<" ";
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        Map M1;
        k=0;
        M1.CreatMatrix();
        for(int i=0;i<M1.GetVexnum();i++)
            M1.Print_AOV();
        M1.Print_Sum();
    }
    return 0;
}


