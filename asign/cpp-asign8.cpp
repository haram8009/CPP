// 숫자의 모든 자릿수 반복 곱하기
#include<iostream>
using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i=0; i<numTestCases; i++) {
        long long data;
        cin >> data;

        while(data>9){
            long long result = 1;
            while (data != 0) {
                result *= (data % 10 != 0) ? data % 10 : 1;
                data /= 10;
            }
            data = result;
        }
        cout << data << endl;
    }
}