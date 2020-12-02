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
    int swap(int pa,int pb);
    void LL_display();
};

LinkList::LinkList() {
    head=new ListNode();
    len=0;
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

ListNode* LinkList::LL_index(int i) {
    if(i<0||i>len)
        return NULL;
    ListNode *p=head;
    int j=0;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    return p;

}//返回i结点的指针

void LinkList::LL_display() {
    ListNode *p;
    p=head->next;
    while(p){
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

int LinkList::swap(int pa, int pb) {
    ListNode *p,*q;
    ListNode *Temp=new ListNode;
    if(pa<1||pb<1||pa>len||pb>len)
        return error;
    p=LL_index(pa-1);
    q=LL_index(pb-1);//获取两个的前驱结点

    if(p->next==q){
        p->next=q->next;
        q->next=p->next->next->next;
        p->next->next=q;
        return ok;
    }//如果p在q前面

    if(q->next==p){
        q->next=p->next;
        p->next=q->next->next->next;
        q->next->next=p;
        return ok;
    }//如果q在p前面

    Temp=p->next;
    p->next=q->next;
    q->next=Temp;

    Temp=p->next->next;
    p->next->next=q->next->next;
    q->next->next=Temp;
    return ok;
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
    int X,Y;
    cin>>X>>Y;
    if(L1.swap(X,Y)==-1)
        cout<<"error"<<endl;
    else
        L1.LL_display();
    cin>>X>>Y;
    if(L1.swap(X,Y)==-1)
        cout<<"error"<<endl;
    else
        L1.LL_display();
    return 0;
}