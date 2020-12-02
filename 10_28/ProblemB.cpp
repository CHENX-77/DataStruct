#include<iostream>
#include <queue>
using namespace std;

queue<char>child;
queue<char>father;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;//左孩子指针、右孩子指针
}BiTNode,*BiTree;
//先序建立二叉树

BiTree CreateBiTree(){
    BiTree T;
        char ch;
        cin>>ch;
        if(ch=='0')
            T=NULL;
        else{
            T = (BiTree)malloc(sizeof(BiTNode));
            T->data = ch;
            T->lchild = CreateBiTree();
            T->rchild = CreateBiTree();
        }
    return T;//返回根节点
}

void leef(BiTree T,char father_data){
    if(T){
            if(T->lchild==NULL&&T->rchild==NULL){
                child.push(T->data);
                father.push(father_data);
            }
        leef(T->lchild,T->data);
        leef(T->rchild,T->data);
    }
}
//主函数

int main(){
    int t;
    cin>>t;
    while(t--){
        BiTree T;
        T = CreateBiTree();//建立二叉树
        leef(T,T->data);
        while(!child.empty()){
            cout<<child.front()<<" ";
            child.pop();
        }
        cout<<endl;
        while(!father.empty()){
            cout<<father.front()<<" ";
            father.pop();
        }
        cout<<endl;
    }
    return 0;
}

















