
#include <SPI.h>
#include <LoRa.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define ss 15
#define rst 16
#define dio0 4

String counter;

String msg1;
String msg2;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");
  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa Reciever failed!");
    while (1);
  }
}

void loop() {
 
  // try to parse packet
  int  pos2, pos3;
  int packetSize = LoRa.parsePacket();
  if (packetSize)
  {
    // received a packet
    Serial.print("Received packet:  ");
    String LoRaData = LoRa.readString();
    Serial.print(LoRaData);

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());

    pos2 = LoRaData.indexOf('@');
    pos3 = LoRaData.indexOf('$');

    //Parsing strings
    counter = LoRaData.substring(0, pos2);
    msg1 = LoRaData.substring(pos2 + 1, pos3);
    msg2 = LoRaData.substring(pos3 + 1, LoRaData.length());

    //Printing messages seperately
    Serial.print(F("Packet No = "));
    Serial.println(counter);
    Serial.print(F("First message: "));
    Serial.println(msg1);
    Serial.print(F("Second message = "));
    Serial.println(msg2);
    Serial.println();
  }
}

    
   