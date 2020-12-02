//
// Created by CHENX on 2020/12/2.
//
#include <iostream>
using namespace std;


struct BiTreeNode{
public:
    int data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode(){
        LeftChild=RightChild=NULL;
    }
};

void InsertTree( BiTreeNode *&T,int e)
{
    if(!T){
        BiTreeNode *S=new BiTreeNode();
        S->data=e;
        S->LeftChild=S->RightChild=NULL;
        T=S;
    } else if(e<T->data)
        InsertTree(T->LeftChild,e);
    else if(e>T->data)
        InsertTree(T->RightChild,e);
}

void PrintTree(BiTreeNode* &Root){
    if(Root){
        PrintTree(Root->LeftChild);
        cout<<Root->data<<" ";
        PrintTree(Root->RightChild);
    }
}//中序输出

int main(){
    int t,n,m,num;
    cin>>t;
    while(t--){
        cin>>n;
        int *p=new int[n];
        BiTreeNode *Tree=new BiTreeNode();
        for(int i=0;i<n;i++){
            cin>>p[i];
            if(i==0)//将第一个输入的结点当作根节点
                Tree->data=p[i];
             else
                InsertTree(Tree,p[i]);//剩下输入的值就进行比较插入
        }
        PrintTree(Tree);
        cout<<endl;
        cin>>m;
        while(m--){
            cin>>num;
            InsertTree(Tree,num);
            PrintTree(Tree);
            cout<<endl;
        }
        delete [] p;
    }
    return 0;
}


