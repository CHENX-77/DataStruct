//
// Created by CHENX on 2020/11/4.
//
#include<iostream>
#include <string>
using namespace std;

string str;
int wt[100];
int index,Index;
int count;
typedef struct BiTNode{
    char data;
    int weight;
    int height;
    struct BiTNode *lchild,*rchild;//左孩子指针、右孩子指针
}BiTNode,*BiTree;
//先序建立二叉树
BiTree CreateBiTree(int w[],int preheight){
    BiTree T;
    char ch;
    ch=str[index];
    index++;
    if(ch=='0')
        T=NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->height=preheight+1;
        if(T->data>='A'&&T->data<='Z'){
            T->weight=w[Index];
            Index++;
        }
        T->lchild = CreateBiTree(w,T->height);
        T->rchild = CreateBiTree(w,T->height);
    }
    return T;//返回根节点
}

void leef(BiTree T) {
    if(T){
        count=count+T->weight*T->height;
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
        Root = CreateBiTree(wt,-1);//建立二叉树
        count=0;
        Root->height=1;
        leef(Root);
        cout<<count<<endl;
    }
    return  0;
}

