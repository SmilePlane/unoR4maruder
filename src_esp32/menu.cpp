#include "menu.h"
#include <esp_uno_r4.h>
#include "shared_virables.hpp"
#include "becon.h"
//this virable is info witch setting user pick
int pick_sett = 0;
//the function below runs once when user input
void menu::input(std::__cxx11::string input){
    //bt ble;
    if(input[0]=='1'){
        SERIAL_AT.println("TRUE");
        br = true;
        nazwa = "Welcome!!! becon attack- 2, help - 1,\n";
        pick_sett = 1;
    }
        if(input[0]=='2'){
            becon bc;
            br = true;
        nazwa = "Starting WiFi becon attack. To leave type 1\n";
        pick_sett = 2;

    }

};
//this function runs in loop
void menu::sett_append(){
    becon bc;
switch(pick_sett){
    case 2: bc.sett_bec(); bc.att();
}
};