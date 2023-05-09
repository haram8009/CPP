// 끝자리 숫자 계산하기
// 입력받은 숫자도, 계산한 값도 모두 %10 해주기 << 이거땜에 계속 틀림;
#include<iostream>

using namespace std;

int main() {
    int i, j, tmp=0, result=1;

    cin >> i;

    for(; i>0; i--){
        for(cin>>j; j>0; j--){
            cin >> tmp;
            result *= tmp%10;
            result %= 10;
        }
        cout << result << endl;
        tmp =0, result =1;
    }
}