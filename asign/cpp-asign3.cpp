// 시침과 분침 사이각 구하기
#include <iostream>
#include <math.h>
using namespace std;
int angleClock(int h, int m);
int main(void)
{
int t;
int h, m;
    cin >> t;
    for(int i=0; i<t; i++)
{
        cin >> h >> m;
        cout << angleClock( h, m ) << endl;
    }
    return 0;
}
int angleClock(int h, int m)
{
    //분침 1시간 360, 1분 6
    //시침 1시간 30 , 1분 0.5
    
    double  result=0, hour=0, min=0;

    hour = 30*h + 0.5*m;
    min = 6*m;

    if(hour == min) return 0;
    else if (hour > min) {
        result = (hour - min);
        if (result > 180) return abs((int)(360 - result));
        return abs((int) result);
    }
    else {
        result = min - hour;
        if (result > 180) return abs((int)(360 - result));
        return abs((int)result);
    }
}