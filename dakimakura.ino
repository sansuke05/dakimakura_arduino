#include <SoftwareSerial.h>
#define buttonPin A0

int buttonState = 0;
SoftwareSerial android(12,13);

void setup() {
  android.begin(115200);
  Serial.begin(19200);

  Serial.write("init");

  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH || Serial.available()) {
    Serial.write("Pushed!\n");
    android.write("1");
    delay(1000);
  }

}
