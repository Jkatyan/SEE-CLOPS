#include <SPI.h>  
#include "RF24.h"

#define buttonPin 2
RF24 myRadio (7, 8);
byte addresses[][6] = {"0"};

struct package
{
  int id=1;
  bool button;
  float temperature = 18.3;
  char  text[100] = "Text to be transmitted";
};


package data;


void setup()
{
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  delay(1000);
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe( addresses[0]);
  delay(1000);
}

void loop()
{
  myRadio.write(&data, sizeof(data)); 

  Serial.print("\nPackage:");
  Serial.print(data.id);
  Serial.print("\n");
  Serial.println(data.temperature);
  Serial.println(data.text);
  Serial.println(data.button);
  data.id = data.id + 1;
  data.button = digitalRead(buttonPin);
  data.temperature = data.temperature+0.1;
  delay(100);

}
