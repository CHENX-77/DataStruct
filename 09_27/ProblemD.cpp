//
// Created by CHENX on 2020/09/23.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int t;
    string str;
    cin>>t;
    while(t--){
        stack<char>s;
        stack<char>m;
        char ct;
        cin>>str;
        int len=str.length();
        for(int i=0;i<len;i++) {
            ct=str[i];
            s.push(ct);
            if (s.top() == '#') {
                s.pop();
                if (s.empty() == false){
                    if (s.top() != '@') {
                        s.pop();
                        s.push('@');
                    }
                    else if(s.top()=='@')
                        s.pop();
                }
                //如果存在至少两个字符
            }
        }
        while(s.empty()==false){
            if(s.top()=='#')
                s.pop();
            m.push(s.top());
            s.pop();
        }
        while(m.empty()==false){
            cout<<m.top();
            m.pop();
        }
        cout<<endl;
    }
    return 0;
}
