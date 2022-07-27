#include <Arduino.h>

#include "BluetoothSerial.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define ONE_WIRE_BUS 15


BluetoothSerial SerialBT;
int received;// received value will be stored in this variable
char receivedChar;// received value will be stored as CHAR in this variable

const int LEDpin = 23;
const char temp ='t';

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Temperature"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LEDpin, OUTPUT);
  sensors.begin();
}

void loop() {
  receivedChar =(char)SerialBT.read(); //Read iput command from BT terminal

  if (Serial.available()) {
      SerialBT.write(Serial.read());
  }
  
  if (SerialBT.available()) {
      SerialBT.print("Type '/t' to recieve data");
      SerialBT.print("Received:");// write on BT app
      SerialBT.println(receivedChar);// write on BT app 
      if(receivedChar == temp)
      {
        sensors.requestTemperatures();
        float tempC = sensors.getTempCByIndex(0);
          if(tempC != DEVICE_DISCONNECTED_C) 
          {
              SerialBT.print("Temperature is: ");
              SerialBT.println(tempC);
          } 
          else
          {
          SerialBT.println("Error: Could not read temperature data");
          }
      }
  }
  

}