#include <esp_uno_r4.h>
#include "bluetooth.h"
bt ble;
void setup() {
  esp_uno_r4_setup();
  SERIAL_AT.begin(115200);
  ble.connect();
}

void loop() {
//ble.write("DZIALA");
//ble.connect();
}
