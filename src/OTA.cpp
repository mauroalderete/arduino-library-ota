#include "OTA.h"

OTAClass::OTAClass(){
    port = 8266;
    password = "";
    md5 = false;
    hostname = "esp8266";
    debug = false;
}

OTAClass::~OTAClass(){

}

void OTAClass::Begin(){
    ArduinoOTA.setPort(port);
    ArduinoOTA.setHostname( hostname.c_str() );
    if(md5){
        ArduinoOTA.setPassword( password.c_str() );
    } else {
        ArduinoOTA.setPasswordHash( password.c_str() );
    }

    ArduinoOTA.onStart([]() {
#ifdef _OTA_DEBUG_
    const String TAG = "ArduinoOTA.onStart::";
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println(TAG + "Start updating " + type);
#endif
    });

    ArduinoOTA.onEnd([]() {
#ifdef _OTA_DEBUG_
    const String TAG = "ArduinoOTA.onEnd::";
    Serial.println("");
    Serial.println(TAG + "End");
#endif
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
#ifdef _OTA_DEBUG_
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
#endif
  });

    ArduinoOTA.onError([](ota_error_t error) {
#ifdef _OTA_DEBUG_
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
#endif
    });

    ArduinoOTA.begin();
#ifdef _OTA_DEBUG_
  const String TAG = "OTAInitializate::";
  Serial.println("");
  Serial.println(TAG + "OTA started");
#endif
}

void OTAClass::Loop(){
    ArduinoOTA.handle();
}

OTAClass OTA;