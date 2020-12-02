#include <iostream>
#include<iomanip>
using namespace std;

class Date {
    int year, month, day;
public:
    Date();
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addOneDay();
    /*  bool Check()
      {
          if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
              return true;
          else
              return false;
      };*/
};

Date::Date() { year = 1900; month = 1; day = 1; }

Date::Date(int y, int m, int d) :year(y),month(m),day(d){}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::setDate(int y, int m, int d) { year = y; month = m; day = d; }

void Date::print() {

    cout << year << "/" <<setfill('0')<<setw(2)<< month << "/" << setfill('0') << setw(2) << day << endl;
}

void Date::addOneDay() {
    int C=0;
    int Day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        C = 1;
        Day[1] = 29;
    }
    int Dmax=0;
    Dmax = Day[month-1];
    if(day<Dmax)
        day++;
    else
    {
        day = 1;
        if (month < 12)
            month++;
        else
        {
            month = 1;
            year++;
        }
    }

}

int main()
{
    int t;
    cin >> t;
    int Y, M, D;
    for(int i=1;i<=t;i++)
    {
        cin >> Y>>M>>D;
        if (i % 2 != 0)
        {
            Date D1(Y, M, D);
            cout << "Today is ";
            D1.print();
            D1.addOneDay();
            cout << "Tomorrow is ";
            D1.print();
        }
        else
        {
            Date D2;
            D2.setDate(Y, M, D);
            cout << "Today is ";
            D2.print();
            D2.addOneDay();
            cout << "Tomorrow is ";
            D2.print();

        }

    }

    return 0;

}
