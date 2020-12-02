//
// Created by CHENX on 2020/11/4.
//
#include<iostream>
#include <string>
using namespace std;

string str;
int wt[100];
int index,Index;
int sum,temp;

typedef struct BiTNode{
    char data;
    int weight;
    int sumdata;
    struct BiTNode *lchild,*rchild;//左孩子指针、右孩子指针
}BiTNode,*BiTree;
//先序建立二叉树
BiTree CreateBiTree(int w[],int pre){
    BiTree T;
    char ch;
    ch=str[index];
    index++;
    if(ch=='0')
        T=NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->sumdata=0;
        if(T->data>='A'&&T->data<='Z'){
            T->weight=w[Index];
            Index++;
            T->sumdata=pre+T->weight;
        }
        T->lchild = CreateBiTree(w,T->sumdata);
        T->rchild = CreateBiTree(w,T->sumdata);
    }
    return T;//返回根节点
}

void leef(BiTree T) {
    if(T){
        if(!T->lchild&&!T->rchild)
            temp=T->sumdata;
        if(temp>sum)
            sum=temp;
        leef(T->lchild);
        leef(T->rchild);
    }
}
//主函数

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>str;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>wt[i];
        BiTree Root;
        index=Index=0;
        Root = CreateBiTree(wt,0);//建立二叉树
        sum=temp=0;
        leef(Root);
        cout<<sum<<endl;
    }
    return  0;
}

