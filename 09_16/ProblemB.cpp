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
    Seqlist(int n);
    ~Seqlist(){delete []list;};
    int multiinsert(int i,int n,int item[]);
    int multidel(int i,int n);
    void display();

};

Seqlist::Seqlist(int n) {
    maxsize=1000;
    size=n;
    list=new int [maxsize];
    for(int i=0;i<n;i++)
        cin>>list[i];
}
int Seqlist::multiinsert(int i, int n, int *item) {
    if(size+n>maxsize||i<=0||i>size+1)
        return 0;
    else
    {
        for (int j = size - 1; j >= (i - 1); j--)
            list[j + n] = list[j];
        for(int j=i-1;j<n+i-1;j++)
            list[j]=item[j-i+1];
        size+=n;
        return 1;
    }
}

int Seqlist::multidel(int i, int n) {
    if(i+n-1>size||i<=0||i>size+1)
        return 0;
    else{
        for(int j=i-1;j<i+n-1;j++)
            list[j]=list[j+n];
        size-=n;
        return 1;
    }

}

void Seqlist::display() {
    cout<<size<<" ";
    for(int i=0;i<size;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

int main() {
    int n,k,i;
    cin>>n;
    Seqlist S1(n);
    S1.display();
    cin>>i>>k;
    int *ADD=new int [k];
    for(int j=0;j<k;j++)
        cin>>ADD[j];
    if(S1.multiinsert(i,k,ADD))
        S1.display();
    else
        cout<<"error"<<endl;
    cin>>i>>k;
    if(S1.multidel(i,k))
        S1.display();
    else
        cout<<"error"<<endl;
}