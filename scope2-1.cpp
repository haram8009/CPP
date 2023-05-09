#include <iostream>
using namespace std;

void f2(void); // scope2-2.cpp의 전역함수 f2() 참조, 범위 : 전체

int f1(int a, int b=1); //
int g1 = 3; // 전역변수, 범위 : 전체
extern int garray[3]; // 전역변수, 범위 : 전체  // = {4, 5, 6};

int main() {
  extern int i; // i 참조, 범위 : main() 블럭 내
  for (int j=0; j<2; j++) {
    static int i = 1; // 지역변수, 범위 : for loop 블럭 내
    i++;
    cout << "inside loop, i = " << i << endl;
  }
  cout << "outside loop, i = " << i << endl;

  cout << "f1(i)= " << f1(i) << endl;
  cout << "f1(i)= " << f1(1000, 50) << endl;
  f2();
  return 0;
}

int f1(int a, int b){ // int a, int b >> 지역변수, 범위 : f1() 블럭
  static int c = 100; // 지역변수, 범위 : f1() 블럭
  c = a+b+c+g1;
  return c;
}
