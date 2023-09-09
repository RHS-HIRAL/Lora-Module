#include <LoraSx1262.h>

byte* msg = "Hello world.  This a pretty long payload. We can transmit up to 255 bytes at once, which is pretty neat if you ask me";
LoraSx1262 radio;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Booted");
  if (!radio.begin()) { //Initialize radio
    Serial.println("Failed to initialize radio.");
  }
}

void loop() {
  Serial.print("Transmitting... ");
  radio.transmit(msg,strlen(msg));
  Serial.println("Done!");
  delay(1000);
}
