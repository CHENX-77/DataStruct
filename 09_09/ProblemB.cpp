#include <iostream>
#include "string"
using namespace std;


int main()
{
    int t,n;
    cin >> t;
    int I,mid,Mid,position;
    I = Mid = mid = position = 0;

    while (t--)
    {
        cin >> n;
        int* p = new int [n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        mid = n / 2;
        cout << *(p + --mid) << " ";
        mid=mid+1;
        cout << *(p + ++mid) << endl;

        cin >> I;
        if (I > Mid)
        {
            position = I - Mid;
            cout << *(p +Mid+position-1) << endl;
        }
        else
        {
            position =  Mid- I;
            cout << *(p + Mid-position-1) << endl;
        }

    }

    return 0;
}

