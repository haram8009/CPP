// 자리수 거듭제곱수
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main() {
    int i, n, tmp, size_n=0, sum=0;
    for(cin >> i; i>0; i--){
        cin >> n;
        size_n = to_string(n).size();
        tmp = n;
        for(int j=0; j<size_n; j++) {
            sum += pow(tmp%10, size_n);
            tmp /= 10;
        }
        if (n == sum) cout << 1 << endl;
        else cout << 0 << endl;
        sum=0;
    }
}