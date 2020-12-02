//
// Created by CHENX on 2020/09/16.
//

#include <iostream>
using namespace std;
class Seqlist{
private:
    int *list;
    int maxsize;
    int size;
public:
    Seqlist(){};
    Seqlist(int n);
    ~Seqlist(){delete []list;};
    void ADDSeqlist(Seqlist &a,Seqlist &b);
    void display();

};

Seqlist::Seqlist(int n) {
    maxsize=1000;
    size=n;
    list=new int [maxsize];
    for(int i=0;i<n;i++)
        cin>>list[i];
}

void Seqlist::display() {
    cout<<size<<" ";
    for(int i=0;i<size;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void Seqlist::ADDSeqlist(Seqlist &a, Seqlist &b) {
    list=new int[maxsize];
    for(int i=0;i<a.size;i++) {
        list[i] = a.list[i];
        size=a.size;
    }

    for(int i=0;i<b.size;i++){
        list[a.size+i]=b.list[i];
    }
        size+=b.size;
    for(int i=0;i<size-1;i++)
        for(int j=0;j<size-1-i;j++)
            if(list[j]>list[j+1])
            {
                int temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
}

int main() {
    int n,m;
    cin>>n;
    Seqlist S1(n);
    cin>>m;
    Seqlist S2(m);
    Seqlist S3;
    S3.ADDSeqlist(S1,S2);
    S3.display();
    return 0;
}