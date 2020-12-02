//
// Created by CHEN on 2020/09/09.
//

#include <iostream>
using namespace std;
void change( int *p1){
    int Juzhen2[3][2];
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            *(*Juzhen2+(2-j)*2+i)=*(p1+i*3+j);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << *(*(Juzhen2 + i) + j)<<" ";
        cout << endl;
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int Juzhen[2][3];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                cin >> Juzhen[i][j];
        change(*Juzhen);
    }
    return 0;
}