//实验D的例子代码
#include<iostream>
#include <iomanip>
#include<queue>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int* wait = new int[N];//用于存放每个顾客的等待时间
    int T, P;
    queue<int>a, b;//两条队列，一个存放到达时间T，一个存放处理时间P
    for(int i=0;i<N;i++)
    {
        cin >> T >> P;
        a.push(T);
        b.push(P);
    }
    int K;
    cin >> K;
    if (K > 10)
        cout << "error" << endl;
    else
    {
        int* num = new int[K];//用于判断窗口是否空闲
        int q = 0;
        for(int i=0;i<K;i++)//刚开始窗口都空闲，值为0
        {
            num[i] = 0;
        }
        int time = 0;       //当前时间
        while (!a.empty())
        {
            for (int i = 0; i < K; i++)//从编号小的窗口开始循环
            {
                if (a.front() <= time && !num[i])//如果到达时间小于或等于当前时间且有窗口空闲
                {
                    wait[q] = time - a.front();             //等待时间=当前时间-到达时间
                    a.pop();
                    num[i] = b.front();             //将处理时间赋给窗口
                    b.pop();
                    q++;
                    if (a.empty())          //如果队列为空，则退出循环
                        break;
                }
            }
            time++;     //当前时间+1
            for (int i = 0; i < K; i++)//循环让每个有人的窗口处理时间-1
            {
                if (num[i])
                    num[i]--;           //减到为0，就是窗口空闲
            }
        }
        int flag = 3;           //设置所有顾客都处理完成的标志
        while (flag)//时间继续流逝，直到所有处理完成，那时time就是最后完成时间
        {
            time++;
            flag = 3;
            for (int i = 0; i < K; i++)
            {
                if (num[i])
                    num[i]--;
                if (!num[i])
                    flag--;         //当所有的窗口都为0时，flag也为0，退出循环
            }
        }
        double sum = 0;
        int max = 0;
        for (int i = 0; i < N; i++)
        {
            sum = wait[i] + sum;        //每个顾客的等待时间加起来，即总的等待时间
            if (wait[i] > max)
                max = wait[i];          //得到最长等待时间
        }
        cout << fixed << setprecision(1) << sum / N << " " << max << " " << time << endl;
    }
    return 0;
}
