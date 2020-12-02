//
// Created by CHENX on 2020/11/11.
//
#include <iostream>
#include <stack>
using namespace std;
const int Maxlen=100;

struct position {
    int xp;
    int yp;
};

class Maze {
public:
    int **temp;
    int Count;
    int T_height,T_width;
    stack<position> path;
public:
    Maze(int H,int W);
    void Game();
};

Maze::Maze(int H,int W) {
    int i,j;
    //给原来的矩阵围一圈0
    T_height=H+2;
    T_width=W+2;

    temp=new int*[T_height];//行
    for (i = 0; i < T_height; i++)
        temp[i] = new int[T_width];//列

    //给四个顶点赋值为0
    for(i=0;i<T_width;i++) {
        temp[0][i] = 0;
        temp[T_height - 1][i] = 0;
    }
    for(i=0;i<T_height;i++){
        temp[i][0]=0;
        temp[i][T_width-1]=0;
    }
    for (i = 1; i < H+1; i++)
        for (j = 1; j < W+1; j++)
            cin >> temp[i][j];
}
//进行输入矩阵

void Maze::Game() {
    // 用迷宫的思想
    int i = 0, j = 0;
    path.push({0, 0});
    temp[0][0] = 2;//2就表示走过的路径
    // 方向按照右下左上走
    while (true) {

        if (j + 1 < T_width&& temp[i][j + 1] == 0)    //往右
        {
            temp[i][j + 1] = 2;   //标记右边的点
            path.push({i, j=j+1}); //走到 i,j+1位置，入栈,用++j也可以，下面的i也是同理
        } else if (i + 1 < T_height && temp[i + 1][j] == 0)    //往下
        {
            temp[i + 1][j] = 2;
            path.push({i=i+1, j});
        } else if (j - 1 >= 0 && temp[i][j - 1] == 0)  //往左
        {
            temp[i][j - 1] = 2;
            path.push({i, j=j-1});
        } else if (i - 1 >= 0 && temp[i - 1][j] == 0)  //往上
        {
            temp[i - 1][j] = 2;
            path.push({i=i-1, j});
        } else    //如果右下左上都走不通
        {
            //后退一格
            i = path.top().xp;
            j = path.top().yp;
            //判断后退的一格有没有路
            if(!(
                    (j + 1 < T_width&& temp[i][j + 1] == 0)
                    || (i + 1 < T_height && temp[i + 1][j] == 0)
                    || (j - 1 >= 0 && temp[i][j - 1] == 0)
                    || (i - 1 >= 0 && temp[i - 1][j] == 0)
                    ))
                path.pop();  //出栈
        }
        if (path.empty()||i==0&&j==0)  //回到终点
            break;
    }

    //计算围住的个数
    int Count_one=0;
    int Count_two=0;
    int sum=T_width*T_height;
    for(i=0;i<T_height;i++)
        for(j=0;j<T_width;j++){
            if(temp[i][j]==1)
                Count_one++;
            else if(temp[i][j]==2)
                Count_two++;
        }
    cout<<sum-Count_one-Count_two<<endl;
}

int main(){
    int t,H,W;
    cin>>t;
    while(t--){
        cin>>H>>W;
        Maze M1(H,W);
        M1.Game();
    }
    return 0;
}