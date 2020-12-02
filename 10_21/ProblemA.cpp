//
// Created by CHENX on 2020/10/21.
//
#include <iostream>
#include <string>
using namespace std;

class myString{
private:
    string mainstr;
    int size;
    void GetNext(string p,int next[]);
    int KMPFind(string p,int pos,int next[]);

public:
    myString();
    ~myString();
    void SetVal(string sp); //设定主串字符内容和长度
    int KMPFindSubstr(string p,int pos);
};

myString::myString() {
    size=0;
    mainstr=" ";
}
myString::~myString() {
    size=0;
    mainstr=" ";
}
void myString::SetVal(string sp) {
    mainstr=" ";
    mainstr.assign(sp);
    size=mainstr.length();
}
//主串从pos开始查找字串p，找到返回p在主串开始位置，否则返回-1
int myString::KMPFindSubstr(string p, int pos) {
    int i;
    int L=p.length();
    int *next=new int[L];
    GetNext(p,next);
    for(i=0;i<L;i++)
        cout<<next[i]<<' ';
    cout<<endl;
    int v=-1;
    v=KMPFind(p,pos,next);
    delete [] next;
    return v;
}

void myString::GetNext(string p, int *next) {
    int i=1;
    next[0]=-1;
    int j=0;
    while(i<p.length()){
        if(j==-1||p[i]==p[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

int myString::KMPFind(string p, int pos, int *next) {
    int i=pos;
    int j=0;
    int L=p.length();
    while(i<size&&j<L){
        if(j==-1||mainstr[i]==p[j]){
            ++i;
            ++j;
        } else
            j=next[j];
    }
    if(j==p.length())
        return i-j;
    else
        return -1;
}



int main(){
    int t;
    cin>>t;
    string strM,strS;
    while(t--){
        cin>>strM>>strS;
        myString S1;
        S1.SetVal(strM);
        cout<<S1.KMPFindSubstr(strS,0)+1<<endl;
    }
    return 0;
}










