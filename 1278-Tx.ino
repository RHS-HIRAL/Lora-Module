//Code for the Transmitter Citcuit

#include <SPI.h>
#include <LoRa.h>

#define ss 10
#define rst 9
#define dio0 2

String LoRaMessage = "";
int counter = 0;
String Message1 = "Hello";
String Message2 = "World";

void setup() 
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");
  LoRa.setPins(ss, rst, dio0);
    if (!LoRa.begin(868E6)) {
      Serial.println("Starting LoRa Transmitter failed!");
      delay(100);
      while (1);
  }
}
 
void loop() 
{
  Serial.print("Sending packet: ");
  Serial.println(counter);
  
  LoRaMessage = String(counter) + "@" + String(Message1) + "$" + String(Message2);
  // send packet
  LoRa.beginPacket();
  LoRa.print(LoRaMessage);
  LoRa.endPacket();
  counter++;
  delay(500);
}
