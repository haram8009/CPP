// 11의 배수
// str.substr(n) str의 n번째 index부터 끝까지의 문자를 부분문자열로 반환
//erase(index: int, n: int): string	문자열의 index 위치에서 시작해서 n개의 문자 제거

// str.append(str2) str 뒤에 str2 문자열을 이어 붙여줌 ('+' 와 같은 역할)
//str.push_back(c) str의 맨 뒤에 c 문자를 붙여줌

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

string find_diff(string str, int num){
    cout << "str=" << str << endl;
    string answer = "";
    int size = str.size();
    reverse(str.begin(), str.end());
    int carry = 0;

    int sub = (str[0]-'0') - num - carry;

    if(sub < 0){
        sub += 10;
        carry = 1;
    } else{
        carry = 0;
    }
    answer.push_back(sub + '0');

    for(int i=1; i<str.size(); i++){
        sub = (str[i]-'0') - carry;
        if(sub < 0){
            sub += 10;
            carry = 1;
        } else{
            carry = 0;
        }
        answer.push_back(sub + '0');
    }

    
    while(answer.back() == '0'){
        answer.pop_back();
    }
    if(answer.size()==0) answer.push_back('0');
    reverse(answer.begin(), answer.end());
    cout << "answer" << answer << endl;
    return answer;
}


int main() {
    int testCase;

    cin >> testCase;
    for(int i=testCase; i>0; i--){
        string str;
        cin >> str;
        int size = str.size();
        int arr[101];

        int idx=100;
        while(str.size() != 1){
            
            int num = str.back() - '0';
            cout << "num=" << num << endl;
            arr[idx] = num;
            str.pop_back();

            str = find_diff(str, num);
            idx--;
        }


        if(str[0] != '0'){
            cout << 0 << endl;
            continue;
        }

        for(idx==100; idx > 101-size; idx--){
            cout << arr[idx];
        }
        cout << endl;
    }
}