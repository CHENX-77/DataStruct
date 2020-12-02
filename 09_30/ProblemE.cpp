//
// Created by CHENX on 2020/9/30.
//
#include "iostream"
#include <string>
#include <stack>
using namespace std;
int BoolPrior(char&C){
    if(C=='+'||C=='-')
        return 1;
    else if(C=='*'||C=='/')
        return 2;
    else if(C=='^')
        return 3;
}//判断优先级

void ChangetoBolan(string&L) {
    stack<char> s;
    stack<char> num;
    char cfre='a';
    char c;
    int len = L.length();//计算字符串长度
    for (int i = len - 1; i >= 0; i--) {
        c=L[i];
        if(i>=0)
            cfre=L[i-1];
        if(c>= '0' && c<= '9'){
            if(cfre>='0'&&cfre<='9')
            {
                num.push(c);
                num.push(L[i-1]);
                num.push('#');
                i--;//设置#进行区分多位数
            }
            else{
                num.push(c);
            }
            continue;
        }
        if(i==-1)
            break;
        c=L[i];
        if (s.empty() == true || s.top() == ')'|| c == ')') {
            s.push(c);
        }
         else if (c == '(') {
            while (num.top() != ')') {
                num.push(s.top());
                s.pop();
            }
            num.pop();
        }else if (BoolPrior(c) >= BoolPrior(s.top())) {
            s.push(c);
        }
            else {
                num.push(s.top());
                s.pop();
                s.push(c);
        }
    }
    while(s.empty()==false){
        num.push(s.top());
        s.pop();
}
    while(num.empty()==false){
        if(num.top()=='#'){
            num.pop();
            cout<<num.top();
            num.pop();
        } else{
            cout<<num.top()<<" ";
            num.pop();
        }
    }
    cout<<endl;
}
void ChangetoNiBolan(string&L){
    stack<char>s;
    stack<char>num;
    int len=L.length();
    char cfre='a';
    char c ;
    for (int i = 0; i <len;i++) {
        c=L[i];
        if(i>=0)
            cfre=L[i+1];
        if(c>= '0' && c<= '9'){
            if(cfre>='0'&&cfre<='9')
            {
                num.push('#');
                num.push(c);
                num.push(L[i+1]);
                i++;
            }
            else{
                num.push(c);
            }

            continue;
        }
        if(i>len)
            break;
        c=L[i];
        if (s.empty() == true || s.top() == '('|| c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (s.top() != '(') {
                num.push(s.top());
                s.pop();
            }
            s.pop();
        }else if (BoolPrior(c) > BoolPrior(s.top())) {
            s.push(c);
        }
        else if(BoolPrior(c) <= BoolPrior(s.top())){
            num.push(s.top());
            s.pop();
            while(BoolPrior(c) <= BoolPrior(s.top()))
            {
                num.push(s.top());
                s.pop();
                if(s.empty()==true)
                    break;
            }
            s.push(c);
        }
    }
    while(s.empty()==false){
        num.push(s.top());
        s.pop();
    }
    stack<char>answer;
    while(num.empty()==false){
        answer.push(num.top());
        num.pop();
    }
    while(answer.empty()==false){
        if(answer.top()!='#'){
            cout<<answer.top()<<" ";
            answer.pop();
        }
        else{
            answer.pop();
            cout<<answer.top();
            answer.pop();
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    string str;
    while(t--) {
        cin>>str;
        ChangetoBolan(str);
        ChangetoNiBolan(str);
        if(t!=0)
            cout<<endl;
    }
    return 0;
}


