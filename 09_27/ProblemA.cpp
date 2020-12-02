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
    int len;
    LinkList();
    ~LinkList();
    void makeList(int n);
    int delSimple();
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

int LinkList::delSimple() {
    ListNode *p=head;
    ListNode *q;
    while(p!=NULL){
        q=p;
        while(q->next!=NULL){
            if(p->data==q->next->data){
                q->next=q->next->next;
                len--;
            } else
                q=q->next;
        }
        p=p->next;
    }
}

void LinkList::makeList(int n) {
    int S;
    len=0;
    ListNode*p,*r;
    head=NULL;
    r=NULL;
    for(int i=0;i<n;i++) {
        p = new ListNode();//创建新结点
        cin >> S;
        p->data = S;
        if (head ==NULL)
            head = p;
        else
            r->next = p;
        r = p;
        len++;
    }
    if(r!=NULL)
        r->next=NULL;

    //尾插法插入链表
}
void LinkList::LL_display() {
    ListNode *p;
    p=head;
    cout<<len<<": ";
    if(p!=NULL){
        while(p){
            cout<<p->data<<' ';
            p=p->next;
        }

    }
    cout<<endl;
}
int main() {
    int t,n;
    cin>>t;
    LinkList L1;
    while(t--){
        cin>>n;
        L1.makeList(n);
        L1.delSimple();
        L1.LL_display();
    }
    return 0;
}
