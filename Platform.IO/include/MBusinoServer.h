#ifndef MBUSINO_SERVER_H
#define MBUSINO_SERVER_H 1

#include "html.h"
#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h> 

#define MBUSINO_VERSION "0.9.16"

extern AsyncWebServer server;
extern AsyncWebSocket ws; // access at ws://[esp ip]/ws
extern AsyncEventSource events; // event source (Server-Sent events)


typedef struct settings {
  char ssid[30];
  char password[30];
  char mbusinoName[11];
  char broker[20];
  uint16_t mqttPort;
  uint16_t extension;
  char mqttUser[30];
  char mqttPswrd[30]; 
  uint32_t sensorInterval;
  uint32_t mbusInterval; 
  uint8_t mbusSlaves;
  uint8_t mbusAddress1;
  uint8_t mbusAddress2;
  uint8_t mbusAddress3;
  bool haAutodisc;
} ;

extern settings userData;

extern bool credentialsReceived;
extern uint8_t newAddress;
extern bool newAddressReceived;
extern bool waitToSetAddress;


/// @brief 
void setupServerMbusino();

void onRequest(AsyncWebServerRequest *request);

class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request) const override {
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", html_buffer); 
  }
};

#endif  // MBUSINO_SERVER_H