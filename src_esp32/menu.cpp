#include "menu.h"
#include <esp_uno_r4.h>
#include "shared_virables.hpp"
#include "becon.h"
#include "scan.h"
//this virable is info witch setting user pick
int pick_sett = 0;
const char* main1 = "help - 1, becon - 2, HiD - 3 ";
const char* main2 = "Starting WiFi becon attack. To leave type 1 ";
const char* main3 = "Starting HID device. Now everything you type will be send as hid data. To leave this mode type 1 ";
const char* main4 = "Start WiFi scanning. To leave this type 1";
//bool start = true;
//the function below runs once when user input
void menu::input(std::__cxx11::string input){
    //static_storage_main.begin("settings",false);
    //bt ble;
    becon bc;
    scan scan;
    
    switch (input[0]){
        case '1':
        br = true;
        
        strcpy(nazwa, main1);
        pick_sett = 1;
        writing = 1;
        break;
        case '2':
        bc.sett_bec();
        br = true;
        
        strcpy(nazwa, main2);
        pick_sett = 2;

        break;
        case '3':
        br = true;
        strcpy(nazwa, main3);
        pick_sett = 3;
        SERIAL_AT.print(3);
        writing = 2;
        break;
        case '5':
        scan.set_scan();
         br = true;
        strcpy(nazwa, main4);
        pick_sett = 4;
        break;

    }
    /*if(input[0]=='1'){
        //SERIAL_AT.println("TRUE");
        br = true;
        nazwa = "help - 1, becon - 2, HiD - 3 ";
        pick_sett = 1;
        writing = 1;
        //static_storage_main.putUInt("writing2", 1);
        //static_storage_main.end();
    }
        if(input[0]=='2'){
            bc.sett_bec();
            br = true;
        nazwa = "Starting WiFi becon attack. To leave type 1 ";
        pick_sett = 2;


    }
            if(input[0]=='3'){
            br = true;
        nazwa = "Starting HID device. Now everything you type will be send as hid data. To leave this mode type 1 \n";
        pick_sett = 3;
        SERIAL_AT.print(3);
        writing = 2;
    }          if(input[0]=='4'){
            br = true;
        nazwa = "Starting HID device. Now everything you type will be send as hid data. To leave this mode type 1 this mode will survive restarting";
        pick_sett = 3;
        SERIAL_AT.print(3);
        writing = 2;
        static_storage_main.putUInt("writing2", 2);
        static_storage_main.end();
    }       
    if(input[0]=='5'){
        scan.set_scan();
         br = true;
        nazwa = "Start WiFi scanning. To leave this type 1";
        pick_sett = 4;
        
    }*/ 

};
//this function runs in loop
/*
settings:
2: becon attack loop
4: scanning loop



*/
void menu::sett_append(){
    becon bc;
    scan scan;
switch(pick_sett){
    case 2: bc.att(); break;
    case 4: scan.scanning(); break;
}
/*if(start){
  int writing2 = static_storage_main.getUInt("writing2");
if(writing2==2){
  SERIAL_AT.print(3);
  writing=2;
}start = false;static_storage_main.end();}*/
};