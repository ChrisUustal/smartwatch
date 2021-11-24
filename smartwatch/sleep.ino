//sleep.ino
/* ~~~~~~~~~~ Reference Libraries ~~~~~~~~~~ */
//SD libraries
#include "FS.h"
#include "SD.h"
#include "SPI.h"

/* ~~~~~~~~~~ Custom Libraries ~~~~~~~~~~ */
#include "custom_sd.h"
#include "sleep.h"
#include "display.h"

//Configure interrupt to wake from sleep 
void sleep_setup(){
  //esp_sleep_enable_timer_wakeup(sleep_secs * uS_TO_S_FACTOR);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_15, 0); //button a
}

void sleep_event() {
  
    #ifdef SERIAL_DEBUG
    Serial.println("Sleeping...");
    #endif
    
    display0.clearDisplay();
    display0.setCursor(0, 0);
    display0.print("Sleeping..");
    display0.display();

    //close the SD card file to avoid corruption 
    log_file.close();
    appendFile(SD, DATA_FILE, "Sleeping...\n");

    delay(500);

    display0.clearDisplay();
    display0.setCursor(0, 0);
    display0.display();

    delay(100);

    //Enter light sleep 
    esp_light_sleep_start();

    //wait until they stop pressing the button
    while(!digitalRead(button_a.pin)){
      delay(1);
    }

    #ifdef SERIAL_DEBUG
      Serial.println("Waking up...");
    #endif

    display0.clearDisplay();
    display0.setCursor(0, 0);
    display0.print("Waking up...");
    display0.display();

    //reopen the SD card, ready to append
    appendFile(SD, DATA_FILE, "Waking...\n");
    log_file = SD.open(DATA_FILE, FILE_APPEND);

    //reset our timers so they don't rapid fire 
    for(int i = 0; i < num_timers; i++){
      timer_arr[i].timer_ref = millis();
    }

    delay(500);
    
}
