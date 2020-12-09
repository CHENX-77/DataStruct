//
// Created by CHENX on 2020/12/9.
//

#include <iostream>
#define Initialize -9999
using namespace std;
int SumCount;
int Hash(int num){
    return num%11;
}
int findHash(int find,int Hash[],int length,int Hash_key){
    int i=Hash_key;
    int j=0;
    while(j<length){//最多找了一遍全部表
        SumCount++;
        if(Hash[i]==Initialize)//遇到空位的表值就跳出循环，说明找不到
            break;
        if(find==Hash[i])
            return i;
        i++;
        i=i%length;
        j++;
    }
        return -1;
}

void PrintTable(int Hash[],int length){
    for(int i=0;i<length;i++){
        if(Hash[i]!=Initialize)
            cout<<Hash[i];
        else
            cout<<"NULL";
        cout<<" ";
    }
    cout<<endl;
}
int main(){
    int t,length,n,i,index,count;
    int k,check;
    cin>>t;
    while(t--){
        cin>>length>>n;
        int *Num=new int [n];
        int *Table=new int[length];
//        检查代码
//        int Num[n];
//        int Table[length];
        for(i=0;i<length;i++)
            Table[i]=Initialize;//初始化哈希表
        for(i=0;i<n;i++){
            count=0;//记录冲突次数
            cin>>Num[i];
            index=Hash(Num[i]);
            if(Table[index]==Initialize)//相应的位置有空位
                Table[index]=Num[i];
            else{
                count++;
                index=index+count;
                while(Table[index]!=Initialize){
                    index++;
                    index=index%length;
                }
                if(index>=length)
                    Table[index]=Num[i];
                else
                    Table[index]=Num[i];
            }
        }
        PrintTable(Table,length);
        cin>>k;
        while(k--){
            cin>>check;
            SumCount=0;
            int Index=findHash(check,Table,length,Hash(check));
            if(Index==-1)
                cout<<"0"<<" "<<SumCount;
            else
                cout<<"1"<<" "<<SumCount<<" "<<Index+1;
            cout<<endl;
        }
        delete [] Num;
        delete [] Table;
    }
    return 0;
}