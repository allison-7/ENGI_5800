// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(7,8,9,10,11,12);

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
lcd.clear();
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
int i = 0;
float CurrentTotal = 0;
float VoltageTotal = 0;
  while (i<400)
  {
  // read the input on analog pin 0:
  float Current = analogRead(A0);
  float CurrentValue = (Current-390)/100;
  float Voltage = analogRead(A1);
  float VoltageValue = 31 *Voltage * (5.0 / 1023.0);

  CurrentTotal +=CurrentValue;
  VoltageTotal +=VoltageValue;
    i += 1;
  }
  CurrentTotal=CurrentTotal/400;
  VoltageTotal=VoltageTotal/400;
  int PhotoResistor = A3;
  float power = CurrentTotal*VoltageTotal;
  int light=analogRead(PhotoResistor);
 
  String out = String(power) + ',' + String(light);
  Serial.println(out);
  
  lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
  lcd.print("Power: "); // Prints Sensor Val: to LCD
  lcd.print(CurrentTotal*VoltageTotal); // Prints value on Potpin1 to LCD
  lcd.setCursor(0,1); // Sets the cursor to col 1 and row 0
  lcd.print("Light: "); // Prints Sensor Val: to LCD
  lcd.print(analogRead(PhotoResistor)); // Prints value on Potpin1 to LCD
  delay(500);               

}
