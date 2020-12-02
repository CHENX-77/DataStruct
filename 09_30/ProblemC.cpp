//
// Created by CHENX on 2020/9/30.
//
#include "iostream"
#include <string>
#include <stack>
using namespace std;

int check(char A,char B){
    if(A==B)
        return 1;
    else
        return 0;
}

int main(){
    int t,len,flag;
    cin>>t;
    string str;
    char c;
    stack<char>s;
    stack<char>m;
    while(t--){
        flag=0;
        cin>>str;
        len=str.length();
        for(int i=0;i<len;i++) {
            c=str[i];
            switch (c) {
                case '[':
                    s.push(str[i]);
                    flag++;
                    break;
                case '(':
                    s.push(str[i]);
                    flag++;
                    break;
                case '{':
                    s.push(str[i]);
                    flag++;
                    break;
                case ']':
                    if (check(s.top(), '[')) {
                        s.pop();
                        flag--;
                    }
                    break;
                case ')':
                    if (check(s.top(), '(')) {
                        s.pop();
                        flag--;
                    }
                    break;
                case '}':
                    if (check(s.top(), '{')) {
                        s.pop();
                        flag--;
                    }
            }
        }
        if(flag!=0)
            cout<<"error"<<endl;
        else
            cout<<"ok"<<endl;
    }
    return 0;
}

