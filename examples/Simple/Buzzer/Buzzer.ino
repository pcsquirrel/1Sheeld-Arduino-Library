/*

Buzzer Shield Example

This example shows an application on 1Sheeld's buzzer shield.

By using this example, you can buzz each time you press the
hardware push button placed on pin 12.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the button on pin 12. */
int buttonPin = 12;
/* A name for the LED on pin 13. */
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Always check the button state. */
  if(digitalRead(buttonPin) == HIGH)
  {
    /* Turn on the buzzer. */
    Buzzer.buzzOn();
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /* Turn off the buzzer. */
    Buzzer.buzzOff();
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }
}
