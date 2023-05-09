#include <iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        
        int num = 0;
        int cnt = 0;
        int snail[n*n] = {0};
        int idx = 0;
        
            while(cnt < n){
                for(int i = 1; i <= n-cnt; i++){
                    num++;
                    snail[idx] = num;
                    idx++;
                    if(i == n-cnt){
                        cnt++;
                        break;
                    }
                }
                for(int i = 1; i <= n-cnt; i++){
                    num += n;
                    snail[idx] = num;
                    idx++;
                } 
                for(int i = 1; i <= n-cnt; i++){
                    num--;
                    snail[idx] = num;
                    idx++;
                    if(i == n-cnt){
                        cnt++;
                        break;
                    }
                } 
                for(int i = 1; i <= n-cnt; i++) {
                    num -= n;
                    snail[idx] = num;
                    idx++;
                }
            }
            for(int i = a-1; i < b; i++){
                cout << snail[i] << " ";
            }
            cout << endl;
    }
}