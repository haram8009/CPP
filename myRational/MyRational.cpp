#include "MyRational.h"

myRational::myRational(long num, long den)
{
    _num = num;
    _den = den;
    (*this).reduce();
}
myRational::myRational(const myRational& rat)
{   
    (*this).reduce();
}
long myRational::getNumerator() const
{
    return _num;
}
long myRational::getDenominator() const
{
    return _den;
}
myRational myRational::reciprocal() const
{
    if( _num == 0 ){
        return myRational(0,1);
    }
    return myRational( _den, _num);
}
// operator + - * /
myRational myRational::operator +(const myRational& rat) const
{
    long new_den = (_den * rat.getDenominator());
    long new_num = _num * (new_den/_den) + rat._num * (new_den/rat.getDenominator());
    myRational new_rat(new_num, new_den);
    return new_rat;
}
myRational myRational::operator +(int value) const
{
    long new_num = _num + (value * _den);
    myRational new_rat(new_num, _den);
    return new_rat;
}
myRational operator +(int value, const myRational& rat)
{
    return rat + value;
}
myRational myRational::operator -(const myRational& rat) const
{
    long new_den = (_den * rat._den);
    long new_num = _num * (new_den/_den) - rat._num * (new_den/rat._den);
    myRational new_rat(new_num, new_den);
    return new_rat;
}
myRational myRational::operator -(int value) const
{
    long new_num = _num - (value * _den);
    myRational new_rat(new_num, _den);
    return new_rat;
}
myRational operator -(int value, const myRational& rat)
{
    myRational new_rat(value);
    myRational answer = new_rat-rat;
    return answer;
}
myRational myRational::operator *(const myRational& rat) const
{
    myRational new_rat = myRational(_num * rat.getNumerator(), _den * rat.getDenominator());
    return new_rat;
}
myRational myRational::operator *(int value) const
{
    myRational new_rat(value);
    return new_rat*(*this);
}
myRational operator *(int value, const myRational& rat)
{
    myRational new_rat = myRational(value * rat.getNumerator(), rat.getDenominator());
    return new_rat;
}
myRational myRational::operator /(const myRational& rat) const
{
    myRational new_rat = myRational(_num * rat.getDenominator(), _den * rat.getNumerator());
    return new_rat;
}
myRational myRational::operator /(int value) const
{
    myRational new_rat(value);
    return (*this)/new_rat;
}
myRational operator /(int value, const myRational& rat)
{
    myRational new_rat(value);
    myRational answer = new_rat / rat;
    return answer;
}

// operator ++ --
myRational& myRational::operator ++() //prefix++
{
    _num += _den;
    (*this).reduce();
    return (*this);
}
myRational myRational::operator ++(int)
{
    myRational tmp(_num, _den);
    _num += _den;
    (*this).reduce();
    return tmp;
}
myRational& myRational::operator --()
{
    _num -= _den;
    (*this).reduce();
    return(*this);
}
myRational myRational::operator --(int)
{
    myRational tmp(_num, _den);
    _num -= _den;
    (*this).reduce();
    return tmp;
}

// unary operator -
myRational myRational::operator -()
{
    return myRational(-_num, _den);
}

// comparison < <= > >= == !=
bool myRational::operator ==(const myRational& rat) const
{
    return (_num==rat.getNumerator()) && (_den==rat.getDenominator());
}
bool myRational::operator !=(const myRational& rat) const
{
    return !((*this)==rat);
}
bool myRational::operator >(const myRational& rat) const
{
    long new_den = (_den * rat.getDenominator());
    long this_num = _num*(new_den/_den);
    long rat_num = rat.getNumerator() * (new_den/rat.getDenominator());
    return this_num > rat_num;
}
bool myRational::operator >=(const myRational& rat) const
{
    long new_den = (_den * rat.getDenominator());
    long this_num = _num*(new_den/_den);
    long rat_num = rat.getNumerator() * (new_den/rat.getDenominator());
    return (this_num > rat_num) || (this_num==rat_num);
}
bool myRational::operator <(const myRational& rat) const
{
    long new_den = (_den * rat.getDenominator());
    long this_num = _num*(new_den/_den);
    long rat_num = rat.getNumerator() * (new_den/rat.getDenominator());
    return (this_num < rat_num);
}
bool myRational::operator <=(const myRational& rat) const
{
    long new_den = (_den * rat.getDenominator());
    long this_num = _num*(new_den/_den);
    long rat_num = rat.getNumerator() * (new_den/rat.getDenominator());
    return (this_num < rat_num) || (this_num==rat_num);
}
bool myRational::operator ==(int value) const
{
    return _num == value * _den;
}
bool myRational::operator !=(int value) const
{
    return _num != value * _den;
}
bool myRational::operator >(int value) const
{
    return _num > value * _den;
}
bool myRational::operator >=(int value) const
{
    return _num >= value * _den;
}
bool myRational::operator <(int value) const
{
    return _num < value * _den;
}
bool myRational::operator <=(int value) const
{
    return _num <= value * _den;
}

// Assignment operator = += -= *= /=
myRational& myRational::operator =(const myRational& rat)
{
    _num = rat.getNumerator();
    _den = rat.getDenominator();
    return (*this);
}
myRational& myRational::operator =(int value)
{
    _num = value;
    _den = 1;
    return (*this);
}
myRational& myRational::operator +=(const myRational& rat)
{
    long new_den = (_den * rat.getDenominator());
    _num = _num * (new_den/_den) + rat.getNumerator()*(new_den/rat.getDenominator());
    _den = new_den;
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator +=(int value)
{
    _num += value * _den;
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator -=(const myRational& rat)
{
    long new_den = (_den * rat.getDenominator());
    _num = _num * (new_den/_den) - rat.getNumerator()*(new_den/rat.getDenominator());
    _den = new_den;
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator -=(int value)
{
    _num -= value * _den;
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator *=(const myRational& rat)
{
    _num *= rat.getNumerator();
    _den *= rat.getDenominator();
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator *=(int value)
{
    _num *= value;
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator /=(const myRational& rat)
{
    _num *= rat.getDenominator();
    _den *= rat.getNumerator();
    (*this).reduce();
    return (*this);
}
myRational& myRational::operator /=(int value)
{
    _den *= value;
    (*this).reduce();
    return (*this);
}

ostream& operator <<(ostream& outStream, const myRational& r)
{
    if (r._num == 0)
    outStream << 0;
    else if (r._den == 1)
    outStream << r._num;
    else
    outStream << r._num << "/" << r._den;
    return outStream;
}
istream& operator >>(istream& inStream, myRational& r)
{
 inStream >> r._num >> r._den;
 if (r._den == 0)
 {
 r._num = 0;

 r._den = 1;
 }
 r.reduce();
 return inStream;
}
long myRational::gcd(long m, long n) const
{
    if (m == n)
    return n;
    else if (m < n)
    return gcd(m, n-m);
    else
    return gcd(m-n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0){
    _num = 0;
    _den = 1;
    return;
    }
    
    if (_den < 0){
    _den *= -1;
    _num *= -1;
    }
    
    if (_num == 1)
        return;
    
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
} 