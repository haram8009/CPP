#include <fstream>
#include <cstdlib>
#include "MyRational.h"
using namespace std;
void testSimpleCase();
void testDataFromFile();
int main()
{
 testSimpleCase();
 testDataFromFile();
}
void testSimpleCase()
{
 myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
 cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
 cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
 // Check arithmetic operators
 cout << frac1 * frac2 << " "
 << frac1 + frac3 << " "
 << frac2 - frac1 << " "
 << frac3 / frac2 << endl;
 // Check comparison operators

 cout << ((frac1 < frac2) ? 1 : 0) << " "
 << ((frac1 <= frac2) ? 1 : 0) << " "
 << ((frac1 > frac2) ? 1 : 0) << " "
 << ((frac1 >= frac2) ? 1 : 0) << " "
 << ((frac1 == frac2) ? 1 : 0) << " "
 << ((frac1 != frac2) ? 1 : 0) << " "
 << ((frac2 < frac3) ? 1 : 0) << " "
 << ((frac2 <= frac3) ? 1 : 0) << " "
 << ((frac2 > frac3) ? 1 : 0) << " "
 << ((frac2 >= frac3) ? 1 : 0) << " "
 << ((frac2 == frac3) ? 1 : 0) << " "
 << ((frac2 != frac3) ? 1 : 0) << endl;
 cout << (frac6 = frac3) << " ";
 cout << (frac6 += frac3) << " ";
 cout << (frac6 -= frac3) << " ";
 cout << (frac6 *= frac3) << " ";
 cout << (frac6 /= frac3) << endl;
 cout << -frac6 << endl;
 // why?????????????????
 frac6 = (++frac4) + 2;
 frac7 = 2 + (frac4++);
 cout << frac4 << " " << frac6 << " " << frac7 << endl;
 frac6 = (--frac4) - 2;
 frac7 = 2 - (frac4--);
 cout << frac4 << " " << frac6 << " " << frac7 << endl;
 cout << 2 * frac3 << " " << frac3 * 2 << " "
 << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
    ifstream inStream;

    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    int testCase, n;
    cin >> testCase;
    for (int i=0; i<testCase; i++){
        cin >> n;
        myRational arr[n];
        for (int j=0; j<n; j++){
            long num, den;
            cin >> num >> den;
            arr[j] = myRational(num, den);
        }
        // sort
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[j]>arr[k]){
                    myRational temp;
                    temp = arr[j];
                    arr[j]=arr[k];
                    arr[k]=temp;
                }
            }
        }
        // cout
        for (int j=0; j<n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    inStream.close();
}