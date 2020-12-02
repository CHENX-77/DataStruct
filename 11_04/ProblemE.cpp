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

int Caculateleef(BiTree T){
    if(T){
        int lheight=Caculateleef(T->lchild);
        int rheight=Caculateleef(T->rchild);
        return lheight>rheight?lheight+1:rheight+1;
    } else
        return 0;
}
//主函数

int main(){
    int t;
    cin>>t;
    while(t--){
        count=0;
        BiTree T;
        T = CreateBiTree();//建立二叉树
        cout<<Caculateleef(T)<<endl;
    }
    return 0;
}