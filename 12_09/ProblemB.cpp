//
// Created by CHENX on 2020/12/9.
//

#include <iostream>
using namespace std;


struct BiTreeNode{
public:
    int sum;
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

int FindTree(BiTreeNode* &T,int key,int s){
    if(!T)
        return -1;
    T->sum=s;
    if(key==T->data){
        T->sum++;
        return T->sum;
    }else if(key<T->data){
        T->sum++;
        T->sum=FindTree(T->LeftChild,key,T->sum);
    }else if(key>T->data){
        T->sum++;
        T->sum=FindTree(T->RightChild,key,T->sum);
    }

}

void DelTreeNode(BiTreeNode* &T,int key){
    BiTreeNode *p=T;
    BiTreeNode *q;
    BiTreeNode *f=NULL;
    BiTreeNode *s;
    while(p){//找到要删除的结点p和父节点f
        if(p->data==key)
            break;
        f=p;
        if(p->data>key)
            p=p->LeftChild;
        else
            p=p->RightChild;
    }
    if(!p)
        return;
//    p有左孩子和右孩子
    if(p->LeftChild&&p->RightChild){
        q=p;
        s=p->LeftChild;
        while(s->RightChild){
            q=s;
            s=s->RightChild;
        }
        p->data=s->data;
        if(q!=p)
            q->RightChild=s->LeftChild;
        else
            q->LeftChild=s->LeftChild;
        delete s;
    }

//    p只有左孩子
    else if(p->LeftChild){
        if(!f)T=p->LeftChild;
        else if(p==f->RightChild)
            f->RightChild=p->LeftChild;
        else
            f->LeftChild=p->LeftChild;
        delete p;

    }

//    p只有右孩子
    else if(p->RightChild){
        if(!f)T=p->RightChild;
        else if(p==f->RightChild)
            f->RightChild=p->RightChild;
        else f->LeftChild=p->RightChild;
        delete p;
    }

//    情况4p没有孩子
    else {
        if (!f)
            T = NULL;
        else if (p == f->LeftChild)
            f->LeftChild = NULL;
        else
            f->RightChild = NULL;
        delete p;
    }
}

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
            DelTreeNode(Tree,num);
            PrintTree(Tree);
            cout<<endl;
        }
        delete [] p;
    }
    return 0;
}




