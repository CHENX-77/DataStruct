#include<iostream>
#include <string>
using namespace std;
int flag,Index;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild,*father;//左孩子指针、右孩子指针、父指针
}BiTNode,*BiTree;
//先序建立二叉树
BiTNode* P[50];//保存叶子结点

BiTree CreateBiTree(BiTNode *p){
    BiTree T;
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        if(flag==1)
            T->father=p;
        else{
            T->father=NULL;//根结点没有父节点
            flag++;
        }
        T->lchild = CreateBiTree(T);
        T->rchild = CreateBiTree(T);
    }
    return T;//返回根节点
}

void  FindLeef(BiTNode* Root) {
    if (Root == NULL)
        return ;
    if(Root->lchild==NULL&&Root->rchild==NULL){
        P[Index]=Root;//找到叶子结点就将它放进P数组里面
        Index++;
    }
    //非空就一直找到空为止
    if(Root->lchild!=NULL)
        FindLeef(Root->lchild);
    if(Root->rchild!=NULL)
        FindLeef(Root->rchild);
}

void FindDistance(){
    string *str=new string[Index];//Index的值表明有几个叶子结点
    for(int i=0;i<Index;i++)
    {
        str[i]=P[i]->data;
        BiTNode *temp=P[i];
        while(temp->father!=NULL){//如果父节点非空，就往上遍历，然后把父节点的值放到str的后面
            temp=temp->father;
            str[i] +=temp->data;
        }
    }
    string check1,check2;
    int Max=0;
    int Lnum=0;
    int Rnum=0;
    //先算出叶子结点到根结点A的路程上所经历的所有结点，存在str数组里面
    //如AB#C##D##，生成的str[1]就是CBA,str[2]就是DA
    //循环比较路程数组元素的最后一个值，如果相同就删除，我这里设置的是通过k来控制删除的位数
    if(Index>1)
    {
        for(int i=0;i<Index-1;i++){
            for(int j=i+1;j<Index;j++){
                check1=str[i];
                check2=str[j];
                int len1=str[i].length();
                int len2=str[j].length();
                int k=1;
                while(check1[len1-k]==check2[len2-k])
                    k++;
                if(Max<len1+len2-2*(k-1)){
                    Max=len1+len2-2*(k-1);
                    Lnum=i;
                    Rnum=j;
                }
            }
        }
        cout<<Max<<":"<<str[Lnum][0]<<" "<<str[Rnum][0]<<endl;
    } else
        cout<<str[0].length()-1<<":"<<endl;
};
int main(){
    int t;
    cin>>t;
    while(t--){
        flag=0;
        Index=0;
        BiTree T;
        T = CreateBiTree(T);//建立二叉树
        FindLeef(T);
        FindDistance();
    }
    return 0;
}