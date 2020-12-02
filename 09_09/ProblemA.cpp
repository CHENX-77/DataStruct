#include <iostream>
using namespace std;
char *Month[] = { "January","February","March","April","May","June",
                     "July","Aguest","September","October","November","December" };
int main()
{
    int t;
    cin >> t;
    int N;
    while (t--)
    {
        cin >> N;
        if (N > 12 || N <= 0)
            cout << "error" << endl;
        else
            cout <<*(Month+N-1) << endl;
    }
    return 0;
}

