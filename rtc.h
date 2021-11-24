//rtc.h
#ifndef RTC_H
#define RTC_H

//only use NU_WIFI or PERSONAL_WIFI
//#define PERSONAL_WIFI
#define NU_WIFI
//RTC
#define ALLOWED_RTC_FAILS 1

#ifdef PERSONAL_WIFI
const char* ssid       = "Not Skynet";
const char* password   = "arnold198";
#endif

#ifdef NU_WIFI
const char* ssid       = "Device-Northwestern";
const char* password   = "";
#endif  

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -6*3600;
const int   daylightOffset_sec = 3600;

int my_hour;
int my_minute;
int my_second;

int rtc_fails;
bool wifi_connected;

void rtc_setup();
void rtc_loop();

#endif
