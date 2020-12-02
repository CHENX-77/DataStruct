//
// Created by CHENX on 2020/9/30.
//
#include "iostream"
#include <string>
#include <stack>
using namespace std;

int main(){
    int t,len,flag=0;
    cin>>t;
    string str;
    stack<char>s;
    stack<char>m;
    while(t--){
        cin>>str;
        len=str.length();
        for(int i=0;i<len;i++){
            s.push(str[i]);
            if(s.top()=='#'){
                s.pop();
                if(s.empty()==false){
                    if(s.top()=='#'){
                        while(s.top()=='#'){
                            flag++;
                            s.pop();
                        }
                        while(flag) {
                            s.pop();
                            flag--;
                        }
                    }
                    else
                        s.pop();
                }
            }
        }
        if(s.empty()==true)
            cout<<"NULL"<<endl;
        else{
            while(s.empty()==false){
                m.push(s.top());
                s.pop();
            }
            while(m.empty()==false){
                cout<<m.top();
                m.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}

