// 변수 이름
// 95 _, 48~57 숫자, 97~122 소문자, 65~90 대문자 
#include<iostream>
#include<string>

using namespace std;

int answer(string str){
    if (str[0]>=48 && str[0]<=57) return false; // first char != number
    for (int j=0; j<str.size(); j++){
        if ( !(str[j]==95 || (str[j]>=48 && str[j]<=57) || (str[j] >= 97 && str[j] <= 122) || (str[j] >= 65 && str[j] <= 90)) )
            return false;
    }
    return true;
}


int main() {
    int testCase;

    cin >> testCase;
    for(int i=testCase; i>0; i--){
        string str;
        cin >> str;

        cout << answer(str) << endl;
    }
}
