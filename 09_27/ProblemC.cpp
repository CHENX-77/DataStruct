//
// Created by CHENX on 2020/9/27.
//
#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode * next;
    ListNode(){next =NULL;}
};

class LinkList{
public:
    ListNode * head;
    ListNode *cyclic;
    int len;
    LinkList();
    void makeList(int n);
    void LL_display();
    void Game(int,int);
};

LinkList::LinkList() {
    head=new ListNode();
    len=0;
}

void LinkList::Game(int K, int S) {
    ListNode *p=cyclic;
    while(p!=NULL){
        if(p->next->data==S)
            break;
        p=p->next;
    }
    ListNode *Q=p->next;
    ListNode *Qpre=p;
    int i=0;
    int flag=0;
    while(len>=1){
        if(i==(K-1)%len){//将i=1改为0，K%len改为(K-1)%len，因为取余的话可能会有等于0的情况，之前的i不可能等于0
            ListNode *T=Q;
            cout<<T->data<<" ";
            Q=Q->next;
            Qpre->next=T->next;//Qpre保持不动，Q要移动到下一个
            len--;
            i=0;
            flag=1;
        }if(flag==0)//flag是防止Q移动增加两次
        {
            Q=Q->next;
            Qpre=Qpre->next;
            i++;
        }
        flag=0;
    }
    cout<<endl;
}

void LinkList::makeList(int n) {
    len=0;
    head->data=1;
    cyclic=head;
    len++;
    for(int i=2;i<=n;i++) {
        ListNode *p = new ListNode();//创建新结点
        p->data = i;
        cyclic->next=p;
        cyclic=cyclic->next;
        len++;
    }
    cyclic->next=head;
    //生成循环链表
}
int main() {
    int t,N,K,S;
    cin>>t;
    LinkList L1;
    while(t--){
        cin>>N>>K>>S;
        L1.makeList(N);
        L1.Game(K,S);
    }
    return 0;
}
