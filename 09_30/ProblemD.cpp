//
// Created by CHENX on 2020/9/30.
//
#include <iostream>
#include <stack>
using namespace std;

struct position {
    int xp;
    int yp;
};
class Maze {
public:
    int **maze;
    int length;
    stack<position> path;
public:
    Maze(int n);
    ~Maze();
    void Game();
};

Maze::Maze(int n) {
    length = n;
    maze=new int*[n];//行
    for (int i = 0; i < n; i++)
        maze[i] = new int[n];//列
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
}//进行输入迷宫

Maze::~Maze() {
    for (int i = 0; i < length; i++)
        delete[]maze[i];
    delete[]maze;
}//释放资源

void Maze::Game() {
    // 进入迷宫
    int i = 0, j = 0;
    path.push({0, 0});
    maze[0][0] = 1;//1就表示走过的路径
    // 迷宫按照右下左上走
    while (true) {
        if (j + 1 < length&& maze[i][j + 1] == 0)    //往右
        {
            maze[i][j + 1] = 1;   //标记右边的点
            path.push({i, j=j+1}); //走到 i,j+1位置，入栈,用++j也可以，下面的i也是同理
        } else if (i + 1 < length && maze[i + 1][j] == 0)    //往下
        {
            maze[i + 1][j] = 1;
            path.push({i=i+1, j});
        } else if (j - 1 >= 0 && maze[i][j - 1] == 0)  //往左
        {
            maze[i][j - 1] = 1;
            path.push({i, j=j-1});
        } else if (i - 1 >= 0 && maze[i - 1][j] == 0)  //往上
        {
            maze[i - 1][j] = 1;
            path.push({i=i-1, j});
        } else    //如果右下左上都走不通
        {
            //后退一格
            i = path.top().xp;
            j = path.top().yp;
            //判断后退的一格有没有路
            if(!((j + 1 < length && maze[i][j + 1] == 0) || (i + 1 < length && maze[i + 1][j] == 0) || (j - 1 >= 0 && maze[i][j - 1] == 0)  || (i - 1 >= 0 && maze[i - 1][j] == 0)))
                path.pop();  //出栈
        }
        if (path.empty() || (i == length- 1 && j == length- 1))  //回到终点或者起点跳出循环
            break;
    }
    //输出路径
    if (!path.empty())
    {
        stack<position> path1;
        while (!path.empty())
        {
            path1.push(path.top());
            path.pop();
        }//将path数据导入path1
        i = 0;
        while (!path1.empty()) {
            if ((++i) % 4 == 0)
                cout << '[' << path1.top().xp << ',' << path1.top().yp << ']' << "--" << endl;
            else
                cout << '[' << path1.top().xp << ',' << path1.top().yp << ']' << "--";
            path1.pop();
        }
        cout << "END" << endl;
    }
    else
        cout << "no path" << endl;//找不到路径输出
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Maze migong(n);
        migong.Game();
    }
    return 0;
}


