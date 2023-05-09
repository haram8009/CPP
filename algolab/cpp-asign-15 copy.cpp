#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        string num;
        cin >> num;

        string answer = "";

        while (num.size() > 1) {
            string slice_num = num.substr(0, num.size()-1);
            string last_num = num.substr(num.size()-1, 1);
            answer += last_num;
            
            string slice_num_last_one = slice_num.substr(slice_num.size()-1, 1);
            int diff = stoi(slice_num_last_one) - stoi(last_num);

            if (slice_num.size() > 1) {
                string remain = slice_num.substr(0, slice_num.size()-1);

                if (diff < 0) {
                    diff += 10;

                    for (int i=remain.size()-1; i>=0; i--) {
                        if (remain[i] != '0') {
                            remain[i] = char((remain[i] - '0') - 1 + 48);
                            break;
                        }
                        remain[i] = '9';
                    }
                }
                num = remain + to_string(diff);
            }
            else {
                if (diff >= 0) num = to_string(diff);
                else break;
            }
        }

        if (stoi(num) == 0) {
            if (answer[answer.size()-1] != '0') {
                for (int i=answer.size(); i>0; i--) {
                    cout << answer[i-1];
                }
                cout << endl;
            }
            else {
                for (int i=answer.size(); i>1; i--) {
                    cout << answer[i-2];
                }
                cout << endl;
            }
        }
        else cout << "0" << endl;
    }

    return 0;
}