#include "OTA.h"

OTAClass::OTAClass() {
    setDefault();
}

OTAClass::OTAClass(String hostname) {
    setDefault();
    setHostname(hostname);
}
OTAClass::OTAClass(String hostname, String password) {
    setDefault();
    setHostname(hostname);
    setPassword(password);
}
OTAClass::OTAClass(String hostname, String password, int port) {
    setDefault();
    setHostname(hostname);
    setPassword(password);
    setPort(port);
}
OTAClass::OTAClass(String hostname, int port) {
    setDefault();
    setHostname(hostname);
    setPort(port);
}
OTAClass::OTAClass(int port) {
    setDefault();
    setPort(port);
}

OTAClass:: ~ OTAClass() {}

void OTAClass::setDefault() {
    setPort(8266);
    setPassword("");
    setHostname("esp8266");
    setDebug(false);
}

void OTAClass::setPort(int port) {
    this -> port = port;
}

void OTAClass::setPassword(String password) {
    this -> password = password;
}

void OTAClass::setHostname(String hostname) {
    this -> hostname = hostname;
}

void OTAClass::setDebug(bool debug) {
    this->debug = debug;
}

void OTAClass::Begin() {
    ArduinoOTA.setPort(port);
    ArduinoOTA.setHostname(hostname.c_str());

    if (password != "") {
        ArduinoOTA.setPasswordHash(password.c_str());
    }

    if (debug) {
        ArduinoOTA.onStart(
            []() {
                const String TAG = "ArduinoOTA.onStart::";
                String type;
                if (ArduinoOTA.getCommand() == U_FLASH) {
                    type = "sketch";
                } else {
                    type = "filesystem";
                }
                Serial.println(TAG + "Start updating " + type);
            }
        );

        ArduinoOTA.onEnd(
            []() {
                const String TAG = "ArduinoOTA.onEnd::";
                Serial.println("");
                Serial.println(TAG + "End");
            }
        );

        ArduinoOTA.onProgress(
            [](unsigned int progress, unsigned int total) {
                Serial.printf("Progress: %u%%\r", (progress / (total / 100)));

            }
        );

        ArduinoOTA.onError(
            [](ota_error_t error) {

                const String TAG = "ArduinoOTA.onError::";
                Serial.printf("Error[%u]: ", error);
                if (error == OTA_AUTH_ERROR) {
                    Serial.println(TAG + "Auth Failed");
                } else if (error == OTA_BEGIN_ERROR) {
                    Serial.println(TAG + "Begin Failed");
                } else if (error == OTA_CONNECT_ERROR) {
                    Serial.println(TAG + "Connect Failed");
                } else if (error == OTA_RECEIVE_ERROR) {
                    Serial.println(TAG + "Receive Failed");
                } else if (error == OTA_END_ERROR) {
                    Serial.println(TAG + "End Failed");
                }
            }
        );
    }
    
    ArduinoOTA.begin();

}

void OTAClass::Loop() {
    ArduinoOTA.handle();
}

OTAClass OTA;