/* #include <Arduino.h>
  #include "bluetooth.h"
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
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

NimBLEServer *pServer = nullptr;
NimBLECharacteristic *pTxCharacteristic;
bool deviceConnected = false;
uint32_t value = 60;

class ServerCallbacks : public NimBLEServerCallbacks {
    void onConnect(NimBLEServer* pServer) {
      deviceConnected = true;
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
        SERIAL_AT.print("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++) {
          SERIAL_AT.print(rxValue[i]);
        }
        //men.input(rxValue);
        SERIAL_AT.println();
      }
    }
};
void bt::connect(){
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
  SERIAL_AT.println("Waiting for a client connection to notify...");
  while(!deviceConnected){
    SERIAL_AT.println("WHILE");
  };
}

};
bool bt::write(const char* message) {
if(deviceConnected){

  //const char* str = "Hello, World!";  // You can replace this with any string

  for (int i = 0; message[i] != '\0'; ++i) {
    //delay(10);
    char character = message[i];

    // Check if the character is printable (optional)
    if (isprint(character)) {
      int ascii_value = static_cast<int>(character);
      pTxCharacteristic->setValue(ascii_value);
      pTxCharacteristic->notify(false);
      SERIAL_AT.println(ascii_value);
      ///.print(character);
     delay(10);
    }
    //pTxCharacteristic->notify();
  }
}
  //pTxCharacteristic->notify();
return true;

};*/ 
