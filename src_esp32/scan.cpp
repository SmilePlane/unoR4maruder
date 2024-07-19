#include "WiFi.h"
#include "scan.h"
#include "shared_virables.hpp"
int i=0;
int n;
char* temp2;
String build;
void scan::set_scan() {
  // Set WiFi to station mode and disconnect from an AP if it was previously connected.
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  i=0;
  build.reserve(400);
}

void scan::scanning() {
  // WiFi.scanNetworks will return the number of networks found.
  int n = WiFi.scanNetworks();
  if (n == 0) {//if no networks found
    br = true;
    nazwa = (char*)"no networks found";
  } else {
    br = true;
    //it must to be one string
    build = "name:"+ WiFi.SSID(i)+" RSSI:"+WiFi.RSSI(i)+" chanel:"+WiFi.channel(i);
    strcpy(nazwa, build.c_str());

      /*switch (WiFi.encryptionType(i)) {
        case WIFI_AUTH_OPEN:            Serial.print("open"); break;
        case WIFI_AUTH_WEP:             Serial.print("WEP"); break;
        case WIFI_AUTH_WPA_PSK:         Serial.print("WPA"); break;
        case WIFI_AUTH_WPA2_PSK:        Serial.print("WPA2"); break;
        case WIFI_AUTH_WPA_WPA2_PSK:    Serial.print("WPA+WPA2"); break;
        case WIFI_AUTH_WPA2_ENTERPRISE: Serial.print("WPA2-EAP"); break;
        case WIFI_AUTH_WPA3_PSK:        Serial.print("WPA3"); break;
        case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.print("WPA2+WPA3"); break;
        case WIFI_AUTH_WAPI_PSK:        Serial.print("WAPI"); break;
        default:                        Serial.print("unknown"); 
      }*/
      //delay(10);
      if(i>=n){
        i=0;
      
      }else{i = i+1;}
      
    }
  //Serial.println("");

  // Delete the scan result to free memory for code below.
  WiFi.scanDelete();

  // Wait a bit before scanning again.
  //delay(5000);
}