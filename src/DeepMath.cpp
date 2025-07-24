#include<DeepMath.h>
#include<math.h>
 


String DeepMath::AddPoint(long long g, long  h) {
 
  char A[30];
  char sdot = '.';
  char s;
  String txt;
String v = LtoS(g);
  v.toCharArray(A,30);
  
  //ltoa(g, A, 10);
  
  unsigned int max = strlen(A);

  h = max - h;
  boolean p = false;
  for (int i = 0; i < max + 1; i++) {
    if (h == i) { p = true; }
    if (p == true) {
      s = A[i];
      A[i] = sdot;
      sdot = s;
    }

    txt = txt + A[i];
  }
  return txt;
}
String local(int n){
  String b;
  for(int i=0;i<n;i++){
     b = b+"0";
   }
 return b;}
  /////////////////////////////////////////////////////////////////////////////////////
  
String  DeepMath::LtoS(long long digit) {
  unsigned long hat;
  String TXT;
  
  bool isNegative = (digit < 0); // check sign

  // Inline absolute value without llabs()
  long long absDigit = (digit < 0) ? -digit : digit;

  int p = (absDigit == 0) ? 1 : (int)log10(absDigit) + 1;

  if (p <= 9) {
   
    hat = (unsigned long)absDigit;
    TXT = String(hat);
  } 
  else if (p > 9 && p <= 18) {
    
    long val = absDigit / 1000000000;
    TXT = TXT + String(val);

    long valnot = absDigit - (val * 1000000000);
    int vp = (valnot == 0) ? 1 : (int)log10(valnot) + 1;
    TXT = TXT + local(9 - vp) + String(valnot);
  } 
  else if (p > 18 && p <= 20) {
    
    long bal = absDigit / 1000000000000000000;
    TXT = TXT + String(bal);
    TXT = TXT + String(bal);  // kept as per your logic
    TXT = TXT + LtoS(absDigit - (bal * 1000000000000000000));
  } 
  else {
    return "error it's value too large, greater than 19 digits";
  }

  if (isNegative) {
    TXT = "-" + TXT;
  }

  return TXT;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


long long  DeepMath::AnalyseStr(String S, char P) {
  String result;long TOTTAL;long FP;
char z='*';
                       
  char snot = '.';
  int t = 1;
  result.remove(0);
  S = S + "*";
  char D[30];
  memset(D, '\0', sizeof(D));  //delete all val in D  array
  S.toCharArray(D, 20);
  

  for (int i = 0; i < i + t; i++) {
  
    if(P!='#'){
    if (D[i] == '.') {
      
     
      point = true;
      FP = i;}
    }else z = '.';
    if (point == true) {
      D[i] = D[i + 1];
    }

    if (D[i] != z) { result = result + D[i]; }
    
    

    if (D[i] == z) {
      TOTTAL = i;
      t = 0;
      point = false;
    }
  }

  if (P == '0' || P == '#') {

   
    return StoL(result);
    
  }
  if (P == 'T') {

    return TOTTAL;
  }




  if (P == 'F') {

    return TOTTAL - FP;
  } else return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////









long long  DeepMath::Power(long a, long b) {
  if (b == 0) {
    return 1;  // anything raised to the Power of 0 is 1
  }
  
  long long result = 1;
  
  for ( long i = 0; i < b; i++) {
    result *= a;  // multiply a, b times
  }

  return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

long long  DeepMath::StoL(String o) {
  char f[21];  // +1 for null terminator
  long long B = 0;
  int len = o.length();
  
  if (len > 20) return 0;  // avoid buffer overflow

  o.toCharArray(f, 21);

  for (int y = 0; y < len; y++) {
    if (isDigit(f[y])) {
      int digit = f[y] - '0';
      B += (long long)digit * Power(10, len - y - 1);
    } else {
      return 0; // invalid character
    }
  }

  return B;
}

/////////////////////////////////////////////////////////////////////////////////////////////////




String  DeepMath::CALC(String a, char b, String c,int dec) {
  long long greater=0;
    long long lesser=0;
    long long Olesser=0;
    long long Ogreater=0;
   long long a0=AnalyseStr(a,'0');
   long long c0=AnalyseStr(c,'0');
   long long af=AnalyseStr(a,'F');
  long long cf=AnalyseStr(c,'F');
  long fd;
  if (b == '*') {
    
    return AddPoint(a0 * c0, af + cf);//AddPoint,k );

  } else if (b == '+' || b == '-') {
    
    if (af < cf) {
      greater = cf;
      lesser = af;
      Olesser = a0;
      Ogreater = c0;
    } else if (af > cf) {
      greater = af;
      lesser = cf;
      Olesser = c0;
      Ogreater = a0;
    }
                   
    long fd /*float point differwnce*/ = greater - lesser;
   
    if (af == cf) {

      Ogreater = a0;
      Olesser =c0;
      greater = cf;
    }

   
    long POWER = Power(10, fd);
   if(Ogreater==a0){c0=c0*POWER;}
    else if (Ogreater==c0){a0=a0*POWER;}

    if (b == '+') {
     
     
      return AddPoint(a0 + c0 , greater);

    } else if (b == '-') {
 
      
 
      return AddPoint(a0-c0, greater);
    }
    return "0";
  }//end +/-
  if(b=='/'){
 
  //int greater=0;int lesser=0;long Olesser=0;long Ogreater=0;
    if (AnalyseStr(a, 'F') < AnalyseStr(c, 'F')) {
 
      greater = cf;
      lesser = af;
      Ogreater=cf;
      Olesser=a0;
                
    } else if (af > cf) {
      greater = af;
      lesser = cf;
     Ogreater=a0;
      Olesser=c0;
    }  else if (af == cf) {
      greater = af;
      lesser = AnalyseStr(c, 'F');
     Ogreater=AnalyseStr(a,'0');
      Olesser=AnalyseStr(c,'0');
    } 
  long long x=AnalyseStr(LtoS(Ogreater),'0') ;
  
 
     long long y =AnalyseStr(LtoS(Olesser),'0')*Power(10,greater-lesser) ;
  
  int p= dec;
  String STR =String(((1.0*x)/y)*Power(10,p));
  
  long val =AnalyseStr(STR,'#');
STR=AddPoint(val,p);

 
 
   return STR;

}else return "0";

}