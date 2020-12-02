//
// Created by CHENX on 2020/11/4.
//
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class BiTreeNode{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode();

};

class BiTree{
private:
    BiTreeNode *Root;//根节点
    int pos;
    string strTree;
    BiTreeNode *CreateBiTree();
    void PreOrder(BiTreeNode *t);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);
    void DeepOrder(BiTreeNode *t);
public:
    BiTree(){};
    ~BiTree(){};
    BiTreeNode * getRoot(){return Root;}
    void change(BiTreeNode *T);
    void CreateTree(string TreeArray);
    void PreOrder();//先序遍历
    void InOrder();//中序遍历
    void PostOrder();//后序遍历
    void DeepOrder();//层次遍历
};
//构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray) {
    pos=0;
    strTree.assign(TreeArray);
    Root=CreateBiTree();
}
void BiTree::change(BiTreeNode *T) {
    if(T!=NULL)
    {
        change(T->LeftChild);
        change(T->RightChild);
        BiTreeNode *temp;
        temp = T->LeftChild;
        T->LeftChild = T->RightChild;
        T->RightChild = temp;
    }

}

void BiTree::PreOrder() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode *t) {
    if(t!=NULL){
        cout<<t->data<<" ";
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}


void BiTree::InOrder() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        InOrder(Root);
}
void BiTree::InOrder(BiTreeNode *t) {
    if(t!=NULL){
        InOrder(t->LeftChild);
        cout<<t->data<<" ";
        InOrder(t->RightChild);
    }
}


void BiTree::PostOrder() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode *t) {
    if(t!=NULL){
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data<<" ";
    }
}

void BiTree::DeepOrder() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        DeepOrder(Root);
}

void BiTree::DeepOrder(BiTreeNode *t) {
        if(t!=NULL)
        {
            queue<BiTreeNode*> qt;
            BiTreeNode *p=t;
            qt.push(p);
            while(true)
            {
                p=qt.front();
                qt.pop();
                cout<<p->data<<' ';
                if(p->LeftChild)
                    qt.push(p->LeftChild);
                if(p->RightChild)
                    qt.push(p->RightChild);
                if(qt.empty())
                    break;
            }
        }
    }
BiTreeNode* BiTree::CreateBiTree() {//递归建树
    BiTreeNode *T;
    char ch;
    ch=strTree[pos++];
    if(ch=='#')
        T=NULL;
    else{
        T=new BiTreeNode();
        T->data=ch;
        T->LeftChild=CreateBiTree();
        T->RightChild=CreateBiTree();
    }
    return  T;
}



int main(){
    int t;
    string str;
    cin>>t;
    BiTree Tree;
    while(t--){
        cin>>str;
        Tree.CreateTree(str);
        Tree.change(Tree.getRoot());
        Tree.PreOrder();
        cout<<endl;
        Tree.InOrder();
        cout<<endl;
        Tree.PostOrder();
        cout<<endl;
        Tree.DeepOrder();
        cout<<endl;
    }
    return 0;
}


