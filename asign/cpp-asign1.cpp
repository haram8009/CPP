// 주어진 정수의 합 구하기
#include<iostream>

using namespace std;

int main() {
    int i, j, tmp=0, sum=0;

    cin >> i;
    for(; i>0; i--){
        
        for(cin >> j; j>0; j--){
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << endl;
        tmp=0, sum=0;
    }
}

/* 왜 이렇게 나올까..?
tmp=0, sum=0 먼저 해줘야지!!!
2
3
1 3 5
4201140
2
1 3 6
4201144 <- 이거 뭐냐고...

*/