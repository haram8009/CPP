// 숫자 정사각형 출력하기 -1
#include <iostream>
using namespace std;
#include <stdio.h>

int draw(int a) {
    if ((a/2)%2==1) {return 1;}
    else {return 0;}
}

int main() {
    int t;
    for (cin>>t; t>0; t++) {
        cin >> n;
        int startNum = (n%4==3) ? 1 : 0;
        int endNum = (startNum+1)%2;
        int center = n/2;
        for (int i=0; i<center; i++){
            for (int j=0; j<n; j++){
                if (startNum==1){
                    if ()
                }
            }
        }
        for (int i=0; i<n; i++) {
            int a = (i%2==0) ? startNum : endNum ;
            cout << a;
        }
        cout << endl;
        for (int i=0; i<center; i++) {
            for (int j=0; j<n; j++){}
        }
    }
}