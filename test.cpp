#include<iostream>
#include<string>

using namespace std;

int main() {
    int testCase;
    string str;

    cin >> testCase;
    for(int i=testCase; i>0; i--){
        cin >> str;
        int size = str.size();
        int arr[size];

        for(int i=0; i<size; i++){
            if(str.size()==1) break;
            
            int num = str.back() - '0';
            arr[i] = num;
            str.pop_back();

            if(str.size()==1){
                if( (str[0])-'0' == num ){
                    str = '0';
                    break;
                } else break;
            }

            if(str.size() == 2){
                int temp = stoi(str)-num;
                str = to_string(temp);
            }
            else{
                int temp = stoi(str.substr(str.size()-3)) - num;
                str.pop_back();str.pop_back();
                if(temp<=9){
                    str.push_back('0'); str.push_back((char)temp);
                } else{
                    str += to_string(temp);
                }
            }
        }

        if(str[0]-'0' !=0){
            cout << 0 << endl;
            continue;
        }

        for(int i=size-1; i>=0; i--){
            cout << arr[i];
        }
        cout << endl;
    }
}