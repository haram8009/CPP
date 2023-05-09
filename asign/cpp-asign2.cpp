// 주어진 정수의 최대 최소 구하기
#include<iostream>

using namespace std;

int main() {
    int i, j, tmp=0, min=0, max=0;

    cin >> i;
    for(; i>0; i--){
        cin >> j;
        cin >> min; max = min;
        for(; j-1>0; j--){
            cin >> tmp;
            if (tmp > max) {
                max = tmp;
            }
            else if (tmp < min) {
                min = tmp;
            }
        }
        cout << max << " " << min << endl;
        tmp=0, max=0, min=0;
    }
}