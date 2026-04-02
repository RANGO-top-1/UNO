
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C LCD(0x27, 16, 2);

#define LED 10
#define BUZ 12
#define B1 2
#define B2 3
#define B3 4
#define B4 5

boolean button1WasUp = true;
boolean button2WasUp = true;
boolean button3WasUp = true;
boolean button4WasUp = true;

byte w = 0;
int SEC = 0;
int MIN = 0;
unsigned long timer;

void setup() {
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  pinMode(BUZ, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  LCD.begin();
  LCD.backlight(); 

  LCD.setCursor(2, 0);
  LCD.print("TIMER  STOP");
  LCD.setCursor(5, 1);
  LCD.print(MIN);
  LCD.print(" : ");
  LCD.print(SEC);
}

void loop() {
  boolean button1IsUp = digitalRead(B1);
  boolean button2IsUp = digitalRead(B2);
  boolean button3IsUp = digitalRead(B3);
  boolean button4IsUp = digitalRead(B4);

  if (button1WasUp && !button1IsUp) {
     delay(10);
     button1IsUp = digitalRead(B1);
     if (!button1IsUp) {
        MIN = MIN - 1; SEC = 0;
        if (MIN < 0) { MIN = 0; }
        LCD.clear(); 
        LCD.setCursor(2, 0); 
        LCD.print("TIMER STOP"); 
        LCD.setCursor(5, 1); 
        LCD.print(MIN); 
        LCD.print(" : "); 
        LCD.print(SEC);
     }
  } 
  button1WasUp = button1IsUp;
   
  if (button2WasUp && !button2IsUp) {
     delay(10); 
     button2IsUp = digitalRead(B2); 
     if (!button2IsUp) { 
        MIN = MIN + 1; SEC = 0; 
        LCD.clear(); 
        LCD.setCursor(2, 0); 
        LCD.print("TIMER STOP"); 
        LCD.setCursor(5, 1); 
        LCD.print(MIN); 
        LCD.print(" : "); 
        LCD.print(SEC);
     }
  } 
  button2WasUp = button2IsUp;

  if (button3WasUp && !button3IsUp && MIN > 0) {
     delay(10);
     button3IsUp = digitalRead(B3);
     if (!button3IsUp) {
        if (SEC == 0) { SEC = 60; MIN = MIN - 1; }
        if (MIN < 0 ) { MIN = 0; }
        digitalWrite(LED, LOW);
        w = 1;
     }
  }
  button3WasUp = button3IsUp;

  if (button4WasUp && !button4IsUp) {
     delay(10);
     button4IsUp = digitalRead(B4);
     if (!button4IsUp) {
        MIN = 0; SEC = 0;
        digitalWrite(10, HIGH);
        LCD.clear();
        LCD.setCursor(2, 0);
        LCD.print("TIMER STOP");
        LCD.setCursor(5, 1);
        LCD.print(MIN);
        LCD.print(" : ");
        LCD.print(SEC);
     }
  }
  button4WasUp = button4IsUp;

  while (w == 1 ) {
     if (millis() - timer > 995) {
        timer = millis();
        SEC = SEC - 1;

        if (SEC == 0 && MIN == 0) {
           LCD.clear();
           LCD.setCursor(2, 0);
           LCD.print("TIMER  STOP");
           LCD.setCursor(5, 1);
           LCD.print(MIN);
           LCD.print(" : ");
           LCD.print(SEC);
           digitalWrite(LED, HIGH);
           tone(BUZ, 100);
           delay(500);
           noTone(BUZ);
           w = 0;
        }

        if (SEC == 0) {
           SEC = 59; MIN = MIN - 1;
           if (MIN < 0 ) { MIN = 0; }
        }

        if (w == 1) {
           LCD.clear();
           LCD.setCursor(2, 0);
           LCD.print("TIMER START");
           LCD.setCursor(5, 1);
           LCD.print(MIN);
           LCD.print(" : ");
           LCD.print(SEC);
        }
    }
 
    boolean button3IsUp = digitalRead(B3);
 
    if (button3WasUp && !button3IsUp) {
       delay(10);
       button3IsUp = digitalRead(B3);
       if (!button3IsUp) {
          LCD.setCursor(2, 0);
          LCD.print("TIMER  STOP");
          w = 0;
       }
    }
    button3WasUp = button3IsUp; 
  }
}
