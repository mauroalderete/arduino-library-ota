#ifndef _OTA_HPP_
#define _OTA_HPP_

#include <Arduino.h>
#include <ArduinoOTA.h>

class OTAClass{
private:
    int port;
    String password;
    String hostname;

    void setDefault();

public:
    OTAClass();
    OTAClass(String hostname);
    OTAClass(String hostname, String password);
    OTAClass(String hostname, String password, int port);
    OTAClass(String hostname, int port);
    OTAClass(int port);
    ~OTAClass();

    void setPort(int port);
    void setHostname(String hostname);
    void setPassword(String password);

    void Begin(bool debug);
    void Loop();
};

extern OTAClass OTA;

#endif