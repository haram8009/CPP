// 두 구간이 차지하는 길이 구하기
#include<iostream>
using namespace std;

int main() {
    int t, S11, S12, S21, S22, overlab, combine;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> S11 >> S12 >> S21 >> S22;
        if (S11 < S21) {
            if (S12 < S22) {
                if (S12 < S21) {
                    overlab = 0;
                    combine = (S12-S11)+(S22-S21);
                    cout << overlab << " " << combine << endl;
                    continue;
                }
                overlab = S12-S21;
                combine = S22-S11;
            } else {
                overlab = S22-S21;
                combine = S12-S11;
            }
        } else {
            if (S12>S22){
                if(S22<S11) {
                    overlab = 0;
                    combine = (S12-S11)+(S22-S21);
                    cout << overlab << " " << combine << endl;
                    continue;
                }
                overlab = S22-S11;
                combine = S12-S21;
            } else {
                overlab = S12-S11;
                combine = S22-S21;
            }

        }
        cout << overlab << " " << combine << endl;
    }
}