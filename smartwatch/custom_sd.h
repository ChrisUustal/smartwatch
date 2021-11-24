//custom_sd.h
#ifndef CUSTOM_SD_H
#define CUSTOM_SD_H

#define DATA_FILE "/test.txt"
#define DEFAULT_BUF_SIZE 64
#define LOG_ON_STARTUP false
#define CHIP_DETECT_PIN 21

File log_file;
char log_buf[DEFAULT_BUF_SIZE];
bool log_enable;
bool sd_installed; //is the card actually installed
bool sd_installed_prev;

void writeFile(fs::FS &fs, const char * path, const char * message);
void appendFile(fs::FS &fs, const char * path, const char * message);

void sd_init(bool on_restart);
void sd_setup();
void sd_loop();
void sd_event();
void sd_card_info();
void sd_check_file(bool on_restart);
void sd_periodic_save();

#endif
