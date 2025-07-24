#ifndef DEEPMATH_H
#define DEEPMATH_H
#include<Arduino.h>
class DeepMath{
private:
boolean  point;
String AddPoint(long long g, long  h);

public:
String LtoS(long long digit);
long long AnalyseStr(String S, char P);
long long Power(long a, long b);
long long StoL(String o);
String CALC(String a, char b, String c,int dec);
};


#endif