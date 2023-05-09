// 숫자 정사각형 출력하기 -1 다른사람꺼 배껴옴
#include<iostream>
using namespace std;
int main(void){
    int t,vks,l;
    cin >> l;
    for(int ll=0;ll<l;ll++) {
        cin >> t;
        int map1[101][101] = {};
        if (t % 4 == 3) vks = 1;
        else vks = 0;
        for (int k = 1; k <= t / 2 + 1; k++) {
            for (int i = 0; i < t - ((k - 1) * 2); i++)
                map1[k][k + i] = map1[k + i][k] = map1[t - k + 1][t - k + 1 - i] = map1[t - k + 1 - i][t - k + 1] = vks;
            if (vks == 1) vks = 0;
            else vks = 1;
        }
        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= t; j++) cout << map1[i][j];
            cout << endl;
        }
    }
}