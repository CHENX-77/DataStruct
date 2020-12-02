#include<iostream>
int count;
using namespace std;
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

void leef(BiTree T){
    if(T){
        if(!T->lchild&&!T->rchild)//如果孩子都是空就算父亲是叶子
            count++;
        leef(T->lchild);
        leef(T->rchild);
    }
}
//主函数

int main(){
    int t;
    cin>>t;
    while(t--){
        count=0;
        BiTree T;
        T = CreateBiTree();//建立二叉树
        leef(T);
        cout<<count<<endl;//计算叶子节点数
    }
    return 0;
}