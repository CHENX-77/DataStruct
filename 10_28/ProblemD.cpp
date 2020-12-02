#include<iostream>
using namespace std;

int count;//计数器

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
        if(T->lchild)
            if(!T->lchild->lchild &&!T->lchild->rchild)//如果左结点的左子树和右子树都不存在，则说明该结点是左子叶
                count++;
        leef(T->lchild);//遍历左子树
        leef(T->rchild);//遍历右子树
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











