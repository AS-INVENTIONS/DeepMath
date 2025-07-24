# DeepMath
DeepMath is a lightweight Arduino library by "Hfiz Amanudeen pallimukku"for performing high-precision decimal and large number arithmetic operations without using floating point types (float or double) or external libraries like sprintf, string, or stringstream.

This library is designed for use in memory-limited microcontrollers (such as ESP32-Wroom,ATmega328, ESP32-CAM, etc.) where standard math functions are not reliable for large or precise decimal operations.

📘 Usage
cpp

#include <DeepMath.h>

void setup() {
  Serial.begin(9600);

  long long num = 1234567890123456789LL;

  // Convert large number to string
  String re
---

## ✨ Features

- Pure logic-based implementation
- Works with very large integers (`long long`, `unsigned long long`)
- Supports:
  - Integer to String conversion (up to 20 digits)
  - Decimal point insertion without float
  - Manual power, division, and addition logic
- Minimal dependencies (`Arduino.h` and `math.h` only)
- No dynamic memory allocation (`malloc`, `new`, etc.)

---

## 🔧 Installation

### Method 1: Manually

1. Download or clone this repository:
2. Move the folder into your Arduino libraries directory:

### Method 2: Zip Import

1. Go to Arduino IDE → Sketch → Include Library → Add .ZIP Library.
2. Select the zipped DeepMath folder.

---

## 📘 Usage

```cpp
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
  Serial.println(math.CALC("36.56776878", '/', "12.234567",5)); // Division
  Serial.println(math.CALC("43.23849487", '+', "6.832734",0));  // Addition
  Serial.println(math.CALC("68.323327", '-', "43.2367237",0));  // Subtraction
}

void loop() {
  // Your code here
}




