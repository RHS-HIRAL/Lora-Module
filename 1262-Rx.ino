//Code for Reciever Circuit for SX1262

#include <LoraSx1262.h>

LoraSx1262 radio;
byte receiveBuff[255];

void setup() {
  Serial.begin(9600);
  Serial.println("Booted");

  if (!radio.begin()) { //Initialize the radio
    Serial.println("Failed to initialize radio");
  }
}

void loop() {
  //Receive a packet over radio
  int bytesRead = radio.lora_receive_async(receiveBuff, sizeof(receiveBuff));

  if (bytesRead > -1) {
    //Print the payload out over serial
    Serial.print("Received: ");
    Serial.write(receiveBuff,bytesRead);
    Serial.println(); //Add a newline after printing
  }
}
