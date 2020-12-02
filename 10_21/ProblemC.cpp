//
// Created by CHENX on 2020/10/21.
//
#include <iostream>
#include <string>
using namespace std;

string matched_Prefix_Postfix(string str) {
    int Max_len=0;
    string strTop,strBottom;
    strTop=str.substr(0,str.length()-1);
    strBottom=str.substr(1,str.length()-1);
    int i,j,Max_index=-1;
    int len=0;
    string Top[str.length()-1];
    string Bottom[str.length()-1];
    //生成前缀的集合
    for(i=0;i<str.length()-1;i++)
        Top[i]=strTop.substr(0,i+1);
    //生成后缀的集合
    for(i=0;i<str.length()-1;i++)
        Bottom[i]=strBottom.substr(strBottom.length()-i-1,i+1);

    //寻找两个集合之间相同的元素
    for(i=0;i<str.length()-1;i++)
        for(j=0;j<str.length()-1;j++){
            if(Top[i]==Bottom[j]){
                len=Bottom[i].length();//如果找到相同的字符串元素，就计算它的长度
                if(len>Max_len){//如果字符串的长度大于最大长度
                    Max_index=i;//找出匹配的最大值的指数i,i是属于前缀集合的
                    Max_len=len;
                }
            }
        }
    if(Max_len==0)
        return "empty";
    else
        return Top[Max_index];
}

int main(){
    int t;
    cin>>t;
    string strtest;
    while(t--){
        cin>>strtest;
        cout<<matched_Prefix_Postfix(strtest)<<endl;
        }
    return 0;
}










