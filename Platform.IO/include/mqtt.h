#ifndef MQTT_H
#define MQTT_H 1

#include <MbusinoNetwork.h>

extern uint8_t adMbusMessageCounter; // Counter for autodiscouver mbus message.
extern uint8_t adSensorMessageCounter; // Counter for autodiscouver mbus message.
extern uint8_t pollingAddress;
extern bool polling;


void reconnect();

void callback(char* topic, byte* payload, unsigned int length);


#endif  