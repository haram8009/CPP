// 정사각형 출력-3
#include<iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                if(j==0 | j==n-1){
                    if(k==0 | k==n/2 | k==n-1) cout << "+";
                    else cout << "-";
                } else if (j==n/2) {
                    if (k==0 | k==n-1) cout << "+";
                    else if (k==n/2) cout << "*";
                    else cout << "-";
                }else {
                    if (k==0 | k==n/2 | k==n-1) cout << "|";
                    else if (k==j) cout << "\\";
                    else if (k==n-1-j) cout << "/";
                    else cout << ".";
                }
            }
            cout << endl;
        }
    }
}