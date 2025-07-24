
/**
 * DeepMath - Arduino Library for Large Number & Decimal Math
 * -----------------------------------------------------------
 * Author: Hafiz Amanudeen Pallimukku
 * Version: 1.0
 * License: MIT
 *
 * Description:
 * This library allows operations on large numbers and precise decimal math 
 * without relying on Arduino's limited floating point.
 * 
 * Features:
 * - Convert between String and unsigned long long
 * - Analyze decimal strings (length, integer part, no decimal, etc.)
 * - Perform manual arithmetic (+, -, *, /) on large decimal numbers
 *
 * Usage Example:
 *   #include <DeepMath.h>
 *   DeepMath math;
 *   Serial.println(math.CALC("45.50", '+', "54.25")); // 99.75
 *  For more information, refer to the README.md file in the DeepMath library folder.

*/ 



#include <DeepMath.h>
DeepMath math;
void setup() {
  Serial.begin(9600);

  long long num = 1234567890123456789LL;

  // Convert large number to string
  String result = math.LtoS(num);
  Serial.println(result);

  // Convert string to large number
  Serial.println(math.StoL(result));

  // Get total number of digits (including decimals)
  Serial.println(math.AnalyseStr("34.567", 'T')); // Output: 6

  // Remove decimal point and return pure number
  Serial.println(math.AnalyseStr("123.4567", '0')); // Output: 1234567

  // Get number of digits before the decimal point
  Serial.println(math.AnalyseStr("123.4567", 'F')); // Output: 3

  // Get only the integer part (truncate decimal)
  Serial.print("Integer part of 1234.567: ");
  Serial.println(math.AnalyseStr("1234.567", '#')); // Output: 1234

  // Arithmetic operations on large decimal values
  Serial.println(math.CALC("35.74537", '*', "1.223538",0));    // Multiplication
  Serial.println(math.CALC("36.56776878", '/', "12.234567",6)); // Division
  Serial.println(math.CALC("43.23849487", '+', "6.832734",0));  // Addition
  Serial.println(math.CALC("68.323327", '-', "43.2367237",0));  // Subtraction
}

void loop() {
  // Your code here
}



