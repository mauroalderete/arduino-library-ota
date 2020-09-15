#ifndef _OTA_HPP_
#define _OTA_HPP_

#include <Arduino.h>
#include <ArduinoOTA.h>

class OTAClass{
private:
    int port;
    String password;
    bool md5;
    String hostname;
    bool debug;

public:
    OTAClass();
    ~OTAClass();
    void Begin();
    void Loop();
};

extern OTAClass OTA;

#endif