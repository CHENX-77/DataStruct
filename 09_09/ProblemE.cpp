//
// Created by CHEN on 2020/09/09.
//
#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        char Type;
        int n;
        cin>>Type;
        switch (Type) {
            case 'I': {
                cin >> n;
                int X, SUM = 0;
                int *p = new int[n];
                for (int i = 0; i < n; i++) {
                    cin >> *(p + i);
                    SUM = SUM + *(p + i);
                }
                cout << SUM / n << endl;
                break;
            }

            case 'C': {
                cin >> n;
                char Y, Max;
                int i,j;
                char *pp = new char[n];
                for (i = 0; i < n; i++) {
                    cin >> *(pp + i);
                }
                   for(i=0;i<n;i++)
                       for(j=0;j<n-i-1;j++)
                           if(*(pp+j)>*(pp+j+1))
                           {
                               int change=*(pp+j);
                               *(pp+j)=*(pp+j+1);
                               *(pp+j+1)=change;
                           }

                cout << *(pp+n-1)<< endl;
                break;
            }

            case 'F': {
                cin >> n;
                int i,j;
                float *ppp = new float[n];
                for (int i = 0; i < n; i++) {
                    cin >> *(ppp + i);
                }
                for(i=0;i<n;i++)
                    for(j=0;j<n-i-1;j++)
                        if(*(ppp+j)>*(ppp+j+1))
                        {
                            float change=*(ppp+j);
                            *(ppp+j)=*(ppp+j+1);
                            *(ppp+j+1)=change;
                        }
                cout << *(ppp)<< endl;
                break;
            }

        }
    }
    return 0;
}