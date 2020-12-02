//
// Created by CHENX on 2020/09/23.
//
#include <iostream>
#include <string>
using namespace std;

class ListNode{
public:
    int num;//系数
    int index;//指数
    ListNode * next;
    ListNode(){next =NULL;}
};

class LinkList{
public:
    int len;
    ListNode * head;
    LinkList();
    void add(LinkList&L);
    void makeList(int);
    void display();
};
LinkList::LinkList()  {
    head=new ListNode();
    len=0;
}

void LinkList::display() {
    ListNode *p=head->next;
    int i=0;
    for(;i<len;i++){
        if(p->num==0)
        {
            p=p->next;
            continue;
        }
        else if(p->num<0){
            cout<<"("<<p->num<<")";
            if(p->index>0)
                cout<<"x^"<<p->index;
            else if(p->index<0)
                cout<<"x^("<<p->index<<")";
            p=p->next;
        }
        else if(p->num>0){
            cout<<p->num;
            if(p->index>0)
                cout<<"x^"<<p->index;
            else if(p->index<0)
                cout<<"x^("<<p->index<<")";
            p=p->next;
        }
        if(i!=len-1)
            cout<<" + ";
    }
    cout<<endl;
}

void LinkList::add(LinkList &L) {
    ListNode*p=head->next;//当前链表指针
    ListNode*q=L.head->next;//L链表指针
    ListNode*h1=head;
    //两条链的第一个开始比较
    while(p!=NULL&&q!=NULL) {
        if (p->index < q->index) {
            p = p->next;
            h1 = h1->next;
        } else if (p->index == q->index) {
            p->num = p->num + q->num;
            p = p->next;
            h1 = h1->next;
            q = q->next;
            L.len--;
        } else {
            ListNode *Temp;
            Temp=q->next;
            q->next=h1->next;
            h1->next=q;
            q=Temp;
            h1=h1->next;
            L.len--;
        }
    }
        if(q){
            h1->next=q;
            len=len+L.len;
        }
}

void LinkList::makeList(int n) {
    ListNode*p=head;
    int I,N;
    for(int i=0;i<n;i++){
        cin>>N>>I;
        ListNode*q=new ListNode();
        q->num=N;
        q->index=I;
        p->next=q;
        p=q;
    }
    len=n;
}//写入链表

int main() {
    int t,n,m;
    cin>>t;
    while(t--){
        LinkList L1;
        cin>>n;
        L1.makeList(n);
        LinkList L2;
        cin>>m;
        L2.makeList(m);
        L1.display();
        L2.display();
        L1.add(L2);
        L1.display();
    }
    return 0;
}