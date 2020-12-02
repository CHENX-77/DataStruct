//
// Created by CHENX on 2020/9/30.
//
#include "iostream"
#include <string>
#include <stack>
using namespace std;

int main(){
    int t,len;
    cin>>t;
    string str;
    stack<char>s;
    stack<char>m;
    while(t--){
        cin>>str;
        len=str.length();
        for(int i=0;i<len;i++){
            s.push(str[i]);
        }
        while(s.empty()==false){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
}

