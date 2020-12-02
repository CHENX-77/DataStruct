//
// Created by CHEN on 2020/09/09.
//

#include <iostream>
#include<iomanip>
#include"math.h"

using namespace std;

class Point {
    double x, y;
public:
    Point() :x(0),y(0){};
    ~Point() { cout << "Distructor." << endl; };
    Point(double x_value, double y_value) { x = x_value; y = y_value; };
    double getX() { return x; };
    double getY() { return y; };
    void setXY(double x1, double y1) { x = x1; y = y1; }
    void setX(double x_value) { x = x_value; };
    void setY(double y_value) { y = y_value; };
    Point(const Point& S);//拷贝构造函数
    double getDisTo(const Point& X2);
};

Point:: Point(const Point& S) {
    x = S.x;
    y = S.y;

}
double Point::getDisTo(const Point& X2) {
    double Distence = sqrt(pow(x - X2.x, 2)+pow(y - X2.y, 2));
    return Distence;
}

int main()
{

    int t,num;
    int FM,SM;
    cin >> t;
    while (t--)
    {
        double Max=0;
        cin >> num;
        double X,Y;
        int i,j=0;

        Point *PP=new Point[num];
        for(i=0;i<num;i++)
        {
            cin>>X>>Y;
            PP[i].setXY(X,Y);
            cout<<"Constructor."<<endl;
        }
           for(i=0;i<num-1;i++)
               for(j=0;j<num;j++)
                   if (PP[i].getDisTo(PP[j])> Max) {
                       Max = PP[i].getDisTo(PP[j]);
                       FM = i,SM = j;
                   }

           cout<<"The longeset distance is "<<fixed<<setprecision(2)<<Max<<
        ",between p["<<FM<<"] and p["<<SM<<"]."<<endl;
                   delete[] PP;
    }
    return 0;
}





