//
// Created by CHENX on 2020/09/23.
//
#include <iostream>
#include <string>
using namespace std;
#define ok 0
#define error -1

class Student{
public:
    int num;
    string name="0";
    Student * next;
    Student(){next =NULL;}
};

class Dormitory{
public:
    int len;
    Student * head;
    Dormitory();
    ~Dormitory();
    void makeList(int n);
    int ass_already(int ,string );//分配房间
    void ass(Dormitory &Home);
    int ret(Dormitory &Homeless);//释放房间
    void display_free();//打印空闲房间
    void display_used();//打印已用房间
    void Sort();

};

Dormitory::Dormitory()  {
    head=new Student();
    len=0;
}

Dormitory::~Dormitory() {
    Student*p,*q;
    p=head;
    while(p!=NULL){
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head=NULL;
}

int Dormitory::ass_already(int NUM,string Name) {
    Student *p=head;
    while(p&&(NUM!=p->num)){
        p=p->next;
    }
    if(!p)
        return error;
    else
        p->name=Name;
    return ok;
}

void Dormitory::Sort() {
    Student* q;
    q = head;
    int count = 0;
    while (q->next != NULL)
    {
        count++;
        q = q->next;
        }
    for (int j = 0; j < count - 1; j++)
    {
        q = head->next;
        for (int k = 0; k < count-j-1; k++)
        {
            if (q->num > q->next->num)
            {
              int t;
              string N;
              t = q->num;
              N = q->name;
              q->num = q->next->num;
              q->name = q->next->name;
              q->next->num = t;
              q->next->name = N;
            }
            q = q->next;
        }
    }
}

void Dormitory::ass(Dormitory &Home) {
    string studentname;
    cin>>studentname;
    Student *p=head;
    Student *q=Home.head;
    Student *Temp=p->next->next;
    p->next->name=studentname;

    p->next->next=q->next;
    q->next=p->next;
    p->next=Temp;
//    cout<<Home.head->next->name<<endl;
//    cout<<q->next->name<<endl;
}

int Dormitory::ret(Dormitory &Homeless) {

    int RoomNum;
    cin>>RoomNum;
    Student *p=head;
    Student *q=Homeless.head;
    while(p->next&&RoomNum!=p->next->num){
        p=p->next;
    }
    if(p==NULL)
        return error;
    else
        {
        while(q->next!=NULL)
            q=q->next;
        q->next=p->next;
        p->next=p->next->next;
        q->next->next=NULL;
        len++;
        }
    return ok;
}

void Dormitory::display_free() {
    Student *p;
    p=head->next;
    while(p->next){
        cout<<p->num<<"-";
        p=p->next;
    }
    if(p)
        cout<<p->num<<endl;
}

void Dormitory::display_used() {
    Student *p;
    p=head->next;
    if(p!=NULL){
        while(p->next){;
            cout<<p->name<<"("<<p->num<<")-";
            p=p->next;
        }
        cout<<p->name<<"("<<p->num<<")"<<endl;
    }
}

void Dormitory::makeList(int n) {
    int S=101;
    len=n;
    for(int i=0;i<n;i++){
        int j=0;
        Student *P;
        P=head;
        while(P&&j<i)
        {
            P=P->next;
            j++;
        }
        Student *N=new Student();
        N->num=S;
        S++;
        P->next=N;
        len++;
    }
}//写入链表

int main() {
    int m,t,NUM;
    string Name;
    Dormitory UsedRoom,FreeRoom;
    FreeRoom.makeList(20);
    cin>>t;
    while(t--){
        cin>>Name>>NUM;
        FreeRoom.ass_already(NUM,Name);
        FreeRoom.len--;
    }

    Student *q=UsedRoom.head;
    Student *p=FreeRoom.head;
    //准备将20个宿舍中的已分配宿舍提取出来
    int j=0;
    while(p->next&&j<20) {
        if (p->next->name != "0") {
            q->next=p->next;
            p->next=p->next->next;
            q->next->next=NULL;
            q=q->next;
        }
        else
        p=p->next;
        ++j;
    }//生成已经分配的宿舍和未分配的宿舍两个列表
// 测试前面的分宿舍的代码有无错误   UsedRoom.display_free();
//测试代码    UsedRoom.display_used();
    cin>>m;
    string option="0";
    while(m--){
        cin>>option;
        if(option=="assign")
            FreeRoom.ass(UsedRoom);

        else if(option=="return")
            UsedRoom.ret(FreeRoom);

        else if(option=="display_free")
            FreeRoom.display_free();

        else if(option=="display_used")
        {
            UsedRoom.Sort();
            UsedRoom.display_used();
        }

    }
    return 0;
}