#include<iostream>
using namespace std;

int main() {
    int t, n, prev, curr, next, cnt=0;
    int currmax=0;
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
        for (int j=0; j<n-2; j++){
            cin >> curr;
            if (prev < curr) {
                prev = curr; curr = next;
            } else {
                if (currmax !=0) {
                    if (currmax <= curr) {
                        currmax = curr;
                        prev = curr; curr = next;
                    } else {
                        cnt++;
                        currmax = 0;
                        prev = curr; curr = next;
                    }
                } else {
                    currmax = curr;
                    prev = curr; curr = next;
                }
            }
        }
        if (curr > next) {
            if (currmax == curr) {
                cnt++;
            }
        }
        cout << cnt << endl;
        cnt = 0;
}