/*
Pomodoro timer. Have a rest for 5 minutes after 20 minutes of work.
Digital blink of built-in LED.
Show information on OLED display.
*/

#define pin_SW_SDA A4
#define pin_SW_SCL A5
#include <Wire.h>
#include <iarduino_OLED_txt.h>
iarduino_OLED_txt myOLED(0x3C);
extern uint8_t SmallFont[];

const int ledPin = 13; // Led on 13th pin
const byte delayTime = 100; // 1 second = 1000 Milliseconds, Time of blink

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.setCoding(TXT_UTF8);
  myOLED.clrScr();
  myOLED.print( "Hello", 0, 0);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  myOLED.clrScr();
  myOLED.print( "Work", 0, 0);
  digitalWrite(ledPin, LOW);
  long int finishWorkTime = 1200000; // 20 Minutes = 1200000 Milliseconds, Time of work
  for (long i = 0; i <= finishWorkTime; i = i + 1000) { // Work
    myOLED.print( "    ", 0, 1); // Clear the string from remaining characters
    myOLED.print( (finishWorkTime - i) / 1000, 0, 1);
    myOLED.print( "seconds remain", 0, 2);
    delay(1000);
  }
  
  myOLED.print( "Break", 0, 0);
  digitalWrite(ledPin, HIGH);
  long finishBreakTime = 300000; // 5 Minutes = 300000 Milliseconds, declare local variable, time of rest
  for (long i = 0; i <= finishBreakTime; i = i + (delayTime * 2)) { // Rest
    myOLED.print( "    ", 0, 1); // Clear the string from remaining characters
    myOLED.print( (finishBreakTime - i) / 1000, 0, 1);
    myOLED.print( "seconds remain", 0, 2);
    digitalWrite(ledPin, HIGH);
    delay(delayTime);
    digitalWrite(ledPin, LOW);
    delay(delayTime);
  }
}
