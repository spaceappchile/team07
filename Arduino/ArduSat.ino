#include <Wire.h> 

int sensorPin = A0;
int sensorValue = 0;

void setup() 
{ 
  Wire.begin(0x2A);
  Wire.onReceive(receiveData);  
  Wire.onRequest(sendData);  
  Serial.begin(9600); 
} 

void loop() 
{ 
  delay(1);
} 

void receiveData(int sensorSelect) 
{
  
}

void sendData() 
{  
  sensorValue = analogRead(sensorPin);    
  Wire.write(sensorValue);
}
