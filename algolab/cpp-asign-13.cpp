// 요일 계산하기
// 일요일 0 ~ 토요일 6
// 그레고리언 1582년 1월 1일 금요일
#include<iostream>

using namespace std;

int main() {
    int testCase, y, m, d;
    int yearDays[] = {365, 366}; //0 평년, 1 윤년
    int monthDays[] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //윤년2,1,평년2,3,4,5,6,7,8,9,10,11,12
    bool isLeapYear;
    long days;
    

    cin >> testCase;
    for(int i=testCase; i>0; i--){
        cin >> y >> m >> d;
        days=0;

        for(int j=1582; j<y; j++){
            if(j%4==0){
                if(j%100==0)
                    if(j%400==0) isLeapYear = true;
                    else isLeapYear = false;
                else isLeapYear = true;
            } else isLeapYear = false;

            days += yearDays[isLeapYear];
        }

        if(y%4==0){
                if(y%100==0)
                    if(y%400==0) isLeapYear = true;
                    else isLeapYear = false;
                else isLeapYear = true;
            } else isLeapYear = false;
        for(int k=1; k<m; k++){
            if(isLeapYear)
                if(k==2) days += monthDays[0];
                else days += monthDays[k];
            else days += monthDays[k];
        }
        
        days += d;

        cout << (days + 4)%7 << endl;
    }
}