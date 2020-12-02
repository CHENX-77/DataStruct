//
// Created by CHENX on 2020/09/23.
//

#include <iostream>
using namespace std;
#define ok 0
#define error -1

class ListNode{
public:
    int data;
    ListNode * next;
    ListNode(){next =NULL;}
};

class LinkList{
public:
    ListNode * head;
    int len;
    LinkList();
    ~LinkList();
    ListNode *LL_index(int i);
    int LL_get(int i);
    int LL_insert(int i,int item);
    int LL_del(int i);
    void LL_display();
};

LinkList::LinkList() {
    head=new ListNode();
    len=0;
}

int LinkList::LL_insert(int i, int item) {
    ListNode *p;
    p=head;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return error;
    ListNode *S=new ListNode();//生成新的结点
    S->data=item;
    S->next=p->next;
    p->next=S;
    return ok;
}//把数值item插入到第i个位置

int LinkList::LL_del(int i) {
    ListNode *p;
    p=head;
    int j=0;
    while(p->next&&j<i-1){
        p=p->next;
        ++j;

    }
    if(!(p->next)||j>i-1)
        return error;
    ListNode *q=new ListNode();
    q=p->next;
    p->next=q->next;
    return ok;
}

int LinkList::LL_get(int i) {
    int j = 0;
    ListNode *p;
    p = head;
    if (i > len || i <= 0)
    {
        cout<<"error"<<endl;
        return 0; //不加return0会输出错误的值
    }

    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (p){
        cout<<p->data<<endl;
        return p->data;
    }

}

LinkList::~LinkList() {
    ListNode*p,*q;
    p=head;
    while(p!=NULL){
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head=NULL;

}

void LinkList::LL_display() {
    ListNode *p;
    p=head->next;
    while(p){
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}



int main() {
    int n,S;
    cin>>n;
    LinkList L1;
    L1.len=0;
    for(int i=0;i<n;i++){
        cin>>S;
        int j=0;
        ListNode *P;
        P=L1.head;
        while(P&&j<i)
        {
            P=P->next;
            j++;
        }
        ListNode *N=new ListNode();
        N->data=S;
        P->next=N;
        L1.len++;
    }
    L1.LL_display();
    int X,item;
    cin>>X>>item;
    if(L1.LL_insert(X,item)==-1)
        cout<<"error"<<endl;
    else
        L1.LL_display();
    cin>>X>>item;
    if(L1.LL_insert(X,item)==-1)
        cout<<"error"<<endl;
    else
        L1.LL_display();
    cin>>X;
    if(L1.LL_del(X)==-1)
        cout<<"error"<<endl;
    else
        L1.LL_display();
    cin>>X;
    if(L1.LL_del(X)==-1)
        cout<<"error"<<endl;
    else
        L1.LL_display();
    cin>>X;
    L1.LL_get(X);
    cin>>X;
    L1.LL_get(X);
    return 0;
}