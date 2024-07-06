#include <esp_uno_r4.h>
//#include "bluetooth.h"
#include <NimBLEDevice.h>
#include <NimBLEUtils.h>
#include <NimBLEServer.h>
#include <NimBLECharacteristic.h>
#include <NimBLEHIDDevice.h>
#include <NimBLE2904.h>
#include <esp_uno_r4.h>
#include <iostream>
#include <string>
#include "menu.h"
#include "shared_virables.hpp"
//#include "menu.cpp"
bool br = false;
char* nazwa;
int writing = 1;
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"
//bt ble;
NimBLEServer *pServer = nullptr;
NimBLECharacteristic *pTxCharacteristic;
bool deviceConnected = false;
uint32_t value = 60;
menu men;
class ServerCallbacks : public NimBLEServerCallbacks {
    void onConnect(NimBLEServer* pServer) {
      deviceConnected = true;
      br = true;
      nazwa = "Welcome!!! type 1 for help or another number for attack number\r";
    };

    void onDisconnect(NimBLEServer* pServer) {
      deviceConnected = false;
    }
};

class CharacteristicCallbacks : public NimBLECharacteristicCallbacks {
  menu men;
    void onWrite(NimBLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();
      if (rxValue.length() > 0) {
        //SERIAL_AT.print("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++) {
          if(writing==2){SERIAL_AT.print(rxValue[i]);
          if(rxValue[i]=='1'){
            writing=1;          }}
        }
        switch(writing){
          case 1:men.input(rxValue);
        }
        
        //SERIAL_AT.println();
      }
    }
};
//
void setup() {
  esp_uno_r4_setup();
  //SERIAL_AT.begin(115200);
  if(!deviceConnected){
      // Create the BLE Device
  NimBLEDevice::init("ESP32_S3_BLE_Serial");

  // Create the BLE Server
  pServer = NimBLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  // Create the BLE Service
  NimBLEService *pService = pServer->createService(SERVICE_UUID);

  // Create the BLE Characteristic
  pTxCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      NIMBLE_PROPERTY::NOTIFY
                    );

  NimBLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
                                           CHARACTERISTIC_UUID_RX,
                                           NIMBLE_PROPERTY::WRITE
                                         );

  pRxCharacteristic->setCallbacks(new CharacteristicCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  //SERIAL_AT.println("Waiting for a client connection to notify...");
  //ble.connect();
}}

void loop() {
  //SERIAL_AT.println(ble.transmission);
  if(deviceConnected&&br){
    //SERIAL_AT.println("LOOP DZIALA");
  //const char* str = "Hello, World!";  // You can replace this with any string
  //SERIAL_AT.print(nazwa);
  for (int i = 0; nazwa[i] != '\0'; ++i) {
    //delay(10);
    char character = nazwa[i];

    // Check if the character is printable (optional)
    if (isprint(character)) {
      int ascii_value = static_cast<int>(character);
      pTxCharacteristic->setValue(ascii_value);
      pTxCharacteristic->notify(false);
      //SERIAL_AT.println(ascii_value);
      ///.print(character);
     delay(10);
    }
    //pTxCharacteristic->notify();
  }
  br=false;
}
  men.sett_append();
  //pTxCharacteristic->notify();
//return true;
//ble.write("DZIALA");
}