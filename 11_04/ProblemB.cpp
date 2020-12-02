//
// Created by CHENX on 2020/11/4.
//
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int MaxW=9999;//假设权值不超过9999

class HuffNode{
public:
    int weight;
    int parent;//父节点下标
    int leftchild;
    int rightchild;
};

class HuffMan{
private:
    void MakeTree();
    void SelectMin(int pos,int *s1,int *s2);//从1到pos的位置找出权值最小的两个点，把结点下标存在s1和s2中
public:
    int len;//结点数量
    int lnum;//叶子数量
    HuffNode *huffTree;
    string *huffCode;
    void MakeTree(int n,int wt[]);
    void Coding();
    void Destroy();
};

void HuffMan::MakeTree(int n,int wt[]){
    int i;
    lnum=n;
    len=2*n-1;
    huffTree=new HuffNode[2*n];
    huffCode=new string[lnum+1];//从位置1开始计算
//huffCode是二维字符数组
    for(i=1;i<=n;i++)
        huffTree[i].weight=wt[i-1];//第1号开始编号
    for(i=1;i<=len;i++){
        if(i>n)
            huffTree[i].weight=0;
        huffTree[i].parent=0;
        huffTree[i].leftchild=0;
        huffTree[i].rightchild=0;
    }
    MakeTree();
}

void HuffMan::SelectMin(int pos, int *s1, int *s2) {
    //找出最小两个权值下标
    //存在s1和s2中
    int w1,w2,i;
    w1=w2=MaxW;
    *s1=*s2=0;
    for(i=1;i<=pos;i++){
        //如果第i结点的权值小于w1且第i结点是未选择的点
        if(huffTree[i].weight<w1&&huffTree[i].parent==0){
            w2=w1;
            *s2=*s1;
            w1=huffTree[i].weight;
            *s1=i;
        } else if(huffTree[i].weight<w2&&huffTree[i].parent==0){
            w2=huffTree[i].weight;
            *s2=i;
        }
        //把w1和s1保存再w2和s2中
        //把i结点的权值和下标给w1和s1
        //否则第i结点的权值小于w2，且第i结点是未选择的结点
        //把第i结点的权值和下标保存到w2和s2中
    }
}


void HuffMan::MakeTree() {
    int i,s1,s2;
    //构造哈夫曼树HuffTree的n-1非叶节点
    for(i=lnum+1;i<=len;i++){
        SelectMin(i-1,&s1,&s2);//找出两个最小权值的下标放入s1和s2中
        //找权值最小的两个合为一棵
        huffTree[s1].parent=i;//结点s1和结点s2的父亲设为i
        huffTree[s2].parent=i;
        huffTree[i].leftchild=s1;
        huffTree[i].rightchild=s2;//结点i的左右孩子分别设为s1和s2
        huffTree[i].weight=huffTree[s1].weight+huffTree[s2].weight;//结点i的权值等于s1和s2的合
    }
}

//销毁树
void HuffMan::Destroy() {
    len=0;
    lnum=0;
    delete [] huffTree;
    delete [] huffCode;
}

void HuffMan::Coding() {
    char *cd;
    int i,c,f,start;
    //求n个叶结点的哈夫曼编码

    cd=new char[lnum];//分配求编码的空间
    cd[lnum-1]='\0';
    for(i=1;i<=lnum;i++){
        start=lnum-1;//编码结束符位置
            for(c=i,f=huffTree[i].parent;f!=0;c=f,f=huffTree[f].parent)
                if(huffTree[f].leftchild==c)
                    cd[--start]='0';
                else
                    cd[--start]='1';
                huffCode[i].assign(&cd[start]);//把cd中从start到末尾的编码复制到huffCode中
        }
    delete [] cd;
}

int main(){
    int t,n,i,j;
    int wt[800];
    HuffMan myHuff;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++)
            cin>>wt[j];
        myHuff.MakeTree(n,wt);
        myHuff.Coding();
        for(j=1;j<=n;j++){
            cout<<myHuff.huffTree[j].weight<<"-";//输出各权值
            cout<<myHuff.huffCode[j]<<endl;//输出各编码
        }
        myHuff.Destroy();
    }
    return  0;
}
