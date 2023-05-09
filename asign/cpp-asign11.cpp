// 두 사각형 면적 둘레 구하기
#include<iostream>
using namespace std;

int function(char side, int S11, int S12, int S21, int S22);

int x_o, x_c, y_o, y_c;
int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
        char side;
        cin >> ax1 >> ay1 >> ax2 >> ay2;
        cin >> bx1 >> by1 >> bx2 >> by2;

        side = 'x';
        function(side, ax1, ax2, bx1, bx2);
        side = 'y';
        function(side, ay1, ay2, by1, by2);
        
        int area=0, perimeter=0;
        if (x_o!=0 && y_o!=0) {
            area =((ax2-ax1)*(ay2-ay1)) + ((bx2-bx1)*(by2-by1)) - x_o*y_o;
            perimeter = 2*(x_c+y_c);
       } else {
            area = ((ax2-ax1)*(ay2-ay1)) + ((bx2-bx1)*(by2-by1));
            perimeter = 2*((ax2-ax1)+(ay2-ay1)) + 2*((bx2-bx1)+(by2-by1));
       }
        cout << area << " " << perimeter << endl;
    }
}

int function(char side, int S11, int S12, int S21, int S22) {
    int overlab, combine;
    if (S11 < S21) {
        if (S12 < S22) {
            if (S12 < S21) {
                overlab = 0;
                combine = (S12-S11)+(S22-S21);
            } else {
                overlab = S12-S21;
                combine = S22-S11;
            }
        } else {
            overlab = S22-S21;
            combine = S12-S11;
        }
    } else {
        if (S12>S22){
            if(S22<S11) {
                overlab = 0;
                combine = (S12-S11)+(S22-S21);
            } else {
                overlab = S22-S11;
                combine = S12-S21;
            }
        } else {
            overlab = S12-S11;
            combine = S22-S21;
        }
    }

    if (side == 'x'){
        x_o = overlab;
        x_c = combine;
    } else if (side == 'y') {
        y_o = overlab;
        y_c = combine;
    }
    return 0;
}