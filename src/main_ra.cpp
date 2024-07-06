#include <Arduino.h>
#include <Keyboard.h>
bool hid = false;
void setup()
{
  Serial.begin(115200);
    
  SERIAL_AT.begin(115200);
}

void loop()
{
  delay(10);

  // Read messages from ESP32
  if (SERIAL_AT.available()) {
    char inChar = SERIAL_AT.read();
    //Serial.print("ESP32 says: ");
   /* while (SERIAL_AT.available()) {
      Serial.write(SERIAL_AT.read());
    }*/
    //Serial.write("HIIII");
   //Serial.write(SERIAL_AT.read());
   if(inChar=='3'&&!hid){
Keyboard.begin();
   hid = true;
  }
   if(hid){
      if(inChar=='1'){
      Keyboard.end();
      hid = false;
    }
    Keyboard.print(inChar);
    //delay(1000);

   }
  }
}