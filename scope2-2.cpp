#include <iostream>
using namespace std;

int garray[3]; // 전역변수 , 범위 : 전체
int i; // 전역변수, 범위 : 전체

extern int f1(int a, int b); // scope2-1.cpp의 함수 f1() 참조, 범위 : 전체

void f2(void) {
  extern int g1; //전역변수 g1 참조, 범위 : f2()
  cout << "f1(10,20) = " << f1(10, 20) << endl;
}
