#include "menu.h"
#include <esp_uno_r4.h>
#include "shared_virables.hpp"
#include "becon.h"
//this virable is info witch setting user pick
int pick_sett = 0;
//the function below runs once when user input
void menu::input(std::__cxx11::string input){
    //bt ble;
    becon bc;
    if(input[0]=='1'){
        //SERIAL_AT.println("TRUE");
        br = true;
        nazwa = "help - 1, becon - 2, HiD - 3\r";
        pick_sett = 1;
        writing = 1;
    }
        if(input[0]=='2'){
            br = true;
        nazwa = "Starting WiFi becon attack. To leave type 1\r";
        pick_sett = 2;
        bc.sett_bec();

    }
            if(input[0]=='3'){
            br = true;
        nazwa = "Starting HID device. Now everything you type will be send as hid data. To leave this mode type 1\r";
        pick_sett = 3;
        SERIAL_AT.print(3);
        writing = 2;
    }    

};
//this function runs in loop
void menu::sett_append(){
    becon bc;
switch(pick_sett){
    case 2: bc.att();
}
};