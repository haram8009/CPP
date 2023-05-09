// 주가분석-1
#include<iostream>
using namespace std;

int main() {
    int t, n, prev, curr, next, cnt=0;
    bool isMax = false;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cin >> prev;
        if (n==3) {
            cin >> curr >> next;
            cout << (curr > prev && curr > next) ? 1 : 0;
            cout << endl;
            continue;
        }
        for (int j=1; j<n; j++){
            cin >> curr;
            if (prev > curr){
                if (isMax){
                    cnt++;
                    prev = curr;
                    isMax = false;
                } else {
                    prev = curr;
                }
            } else if (prev == curr) {
                prev = curr;
            } else {
                if (isMax) {
                    prev = curr;
                } else {
                    isMax = true;
                    prev = curr;
                }
            }
        }
        cout << cnt << endl;
        cnt = 0;
        isMax = false;
    }
}