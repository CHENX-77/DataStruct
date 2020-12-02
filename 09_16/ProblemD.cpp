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
    void Change(int C,int N);
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
    for(int i=0;i<size;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void Seqlist::Change(int C,int N) {
    int temp;
    if(C==0)
    {
        for(int i=0;i<N;i++)
        {
            temp=list[0];
            for(int j=1;j<size;j++) {
                list[j-1]=list[j];
            }
            list[size-1]=temp;
        }
    }//左移
    if(C==1)
    {
        for(int i=0;i<N;i++)
        {
            temp=list[size-1];
            for(int j=size-2;j>=0;j--) {
                list[j+1]=list[j];
            }
            list[0]=temp;
        }
    }//右移

}

int main() {
    int n;
    cin>>n;
    Seqlist S1(n);
    S1.display();
    int changeXY,num;
    cin>>changeXY>>num;
    S1.Change(changeXY,num);
    S1.display();
    cin>>changeXY>>num;
    S1.Change(changeXY,num);
    S1.display();
    return 0;
}