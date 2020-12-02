//
// Created by CHENX on 2020/09/16.
//

#include <iostream>
using namespace std;

#define ok 0
#define error -1

class SeqList{
private:
    int *list;
    int maxsize;
    int size;
    int Che;
public:
    SeqList(int n);
    ~SeqList();
    int list_size();
    int list_insert(int i,int item);
    int list_del(int i);
    int list_get(int i);
    void list_display();
    int getChe(){return Che;}
};

SeqList::SeqList(int n) {
    maxsize=1000;
    size=n;
    list=new int [maxsize];
    for(int i=0;i<n;i++)
        cin>>list[i];
}

SeqList::~SeqList() {
    delete []list;
}

void SeqList::list_display() {
    cout<<size<<" ";
    for(int i=0;i<size;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

int SeqList::list_insert(int i, int item) {
    if(i<1||i>size+1)
        return error;
    else{
        for(int j=size;j>=(i-1);j--)
        {
            list[j+1]=list[j];
        }
        list[i-1]=item;
        size+=1;
        return ok;
    }
}

int SeqList::list_del(int i) {
    if(i<1||i>size)
        return error;
    else{
        for(int j=i-1;j<size-i;j++)
        {
            list[j]=list[j+1];
        }
        size-=1;
        return ok;
    }
}
int SeqList::list_get(int i) {
    if(i<1||i>size)
        return error;
    else{
        Che=list[i-1];
        return ok;
    }
}

int main() {
    int n,x,data,d,check;
    cin>>n;
    SeqList S1(n);
    S1.list_display();
    cin>>x>>data;
//添加
    if(S1.list_insert(x,data)==0)
        S1.list_display();
    else
        cout<<"error"<<endl;

    cin>>x>>data;
    if(S1.list_insert(x,data)==0)
        S1.list_display();
    else
        cout<<"error"<<endl;
//删除
    cin>>d;
    if(S1.list_del(d)==0)
        S1.list_display();
    else
        cout<<"error"<<endl;

    cin>>d;
    if(S1.list_del(d)==0)
        S1.list_display();
    else
        cout<<"error"<<endl;
//查找
    cin>>check;
    if(S1.list_get(check)==0)
        cout<<S1.getChe()<<endl;
    else
        cout<<"error"<<endl;
    cin>>check;
    if(S1.list_get(check)==0)
        cout<<S1.getChe()<<endl;
    else
        cout<<"error"<<endl;
    return 0;
}