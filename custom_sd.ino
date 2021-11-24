//custom_sd.ino
/* ~~~~~~~~~~ Reference Libraries ~~~~~~~~~~ */
//SD libraries
#include "FS.h"
#include "SD.h"
#include "SPI.h"

/* ~~~~~~~~~~ Custom Libraries ~~~~~~~~~~ */
#include "custom_sd.h"

//SD SETUP
void sd_setup(){
  log_enable = LOG_ON_STARTUP;

  pinMode(CHIP_DETECT_PIN, INPUT_PULLUP);
  //low = card installed 
  sd_installed = digitalRead(CHIP_DETECT_PIN);
  sd_installed_prev = sd_installed;

  if(sd_installed) {
    sd_init(true);
  } else {
    log_enable = false;
  }
}

void sd_init(bool on_restart){
  
  if(!SD.begin()){
    #ifdef SERIAL_DEBUG
        Serial.println("Card Mount Failed");
    #endif
        return;
  } else {

    #ifdef SERIAL_DEBUG
    sd_card_info();
    #endif

    sd_check_file(on_restart);

    //Open the file to save time 
    if(log_enable) {
      log_file = SD.open(DATA_FILE, FILE_APPEND);
    }
  }
  
}

void sd_check_file(bool on_restart){
  //if the output file doesn't exist, create it 
    if(!SD.open(DATA_FILE)){
      writeFile(SD, DATA_FILE, "Accel, Temp: \n");
    } else {
      //if the file did exist, note there was a restart 
      if(on_restart) {
        appendFile(SD, DATA_FILE, "\nRestart: \n");
      } else {
        //this has a weird bug where it only reports this after every other eject but logging still occurs properly 
        appendFile(SD, DATA_FILE, "\nCard Re-Installed: \n");
      }
      
    }
}

void sd_card_info(){
      //What type of card is it? 
      uint8_t cardType = SD.cardType();
  
      if(cardType == CARD_NONE){
          Serial.println("No SD card attached");
          return;
      }

      //Print card type to Serial
      Serial.print("SD Card Type: ");
      if(cardType == CARD_MMC){
          Serial.println("MMC");
      } else if(cardType == CARD_SD){
          Serial.println("SDSC");
      } else if(cardType == CARD_SDHC){
          Serial.println("SDHC");
      } else {
          Serial.println("UNKNOWN");
      }

      //Print card capacity
      uint64_t cardSize = SD.cardSize() / (1024 * 1024);
      Serial.printf("SD Card Size: %lluMB\n", cardSize);
}

//SD LOOP
void sd_loop(){
  sd_installed = digitalRead(CHIP_DETECT_PIN);

  if(sd_installed && (sd_installed != sd_installed_prev)) {
    sd_init(false);
  }

  sd_installed_prev = sd_installed;
  
  if(log_enable && sd_installed) {
    sprintf(log_buf, "%4.1f, %4.1f\n", acc, temp_c);
    //appendFile(SD, DATA_FILE, acc_buf);
    log_file.print(log_buf);
  }

 
}

void sd_event(){
  if(sd_installed) {
    if(log_enable){
      log_enable = false;
  
      sprintf(log_buf, "Logging Paused\r\n");
      log_file.print(log_buf);
      log_file.close(); //this takes a few ms
    } else {
      log_enable = true;
  
      log_file = SD.open(DATA_FILE, FILE_APPEND);
      sprintf(log_buf, "Logging Resumed\r\n");
      log_file.print(log_buf);
    }
  } else {
    log_enable = false;
  }
}

//SOME FUNCTIONS WE NEED FOR THE SD CARD
void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message){
    #ifdef SERIAL_DEBUG
      Serial.printf("Appending to file: %s\n", path);
    #endif

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        #ifdef SERIAL_DEBUG
          Serial.println("Message appended");
        #endif
    } else {
        #ifdef SERIAL_DEBUG
        Serial.println("Append failed");
        #endif
    }
    file.close();
}
