#ifndef MBUSINO_NETWORK_H
#define MBUSINO_NETWORK_H 1

#include <Arduino.h>

#include <PubSubClient.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <AsyncTCP.h>
#endif

extern WiFiClient espClient;
extern PubSubClient client;

extern uint16_t conCounter;


#endif