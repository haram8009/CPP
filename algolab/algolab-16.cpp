// 홀수 마방진
#include<iostream>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    for(int i=0; i<testCase; i++){
        int n;
        cin >> n;

        int arr[n][n] ={0};
        int r, c;
        r = 0; c = n/2;
        arr[r][c] = 1;
        r--; c++;
        for(int j=2; j <= n*n; j++){
            if(r<0) r+=n;
            if(c>=n) c-=n;
            arr[r][c]=j;
            if(j%n==0){
                r++;
                continue;
            }
            r--; c++;
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
    }
}