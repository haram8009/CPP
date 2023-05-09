// 행렬 곱셈
#include<iostream>

using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    for(int i=0; i<testCase; i++){
        int r, s, t;
        cin >> r >> s >> t;
        int arr1[r][s], arr2[s][t];
        int tmp=0;
        for(int j=0; j<r; j++){
            for(int k=0; k<s; k++){
                cin >> tmp;
                arr1[j][k] = tmp;
            }
        }
        for(int j=0; j<s; j++){
            for(int k=0; k<t; k++){
                cin >> tmp;
                arr2[j][k] = tmp;
            }
        }
        int resultArray[r][t] = {0};
        for(int j=0; j<r; j++){
            for(int k=0; k<t; k++){
                int tmp=0;
                for(int p=0; p<s; p++){
                     tmp += (arr1[j][p]) * (arr2[p][k]);
                }
                resultArray[j][k] = tmp;
            }
        }
        for(int j=0; j<r; j++){
            for(int k=0; k<t; k++){
                cout << resultArray[j][k] << " ";
            }
            cout << endl;
        }
    }
}