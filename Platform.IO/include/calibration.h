#ifndef CALIBRATION_H
#define CALIBRATION_H 1

#include <Arduino.h>

extern bool OWnotconnected[7];
extern uint8_t sensorToCalibrate;
extern float offset[7];
extern float OWwO[7];  // Variables for DS18B20 Onewire Sensores with Offset (One Wire1 with Offset)
extern float OW[7];         // variables for DS18B20 Onewire sensors 
extern float temperatur;      // Variablen für den BLE280 am I2C
extern uint8_t eeAddrCalibrated;
extern uint8_t eeAddrCredentialsSaved;
extern uint8_t eeAddrOffset[7];  //EEPROM address to start reading from

void calibrationAverage();

void calibrationSensor(uint8_t sensor);

void calibrationValue(float value);

void calibrationBME();

void calibrationSet0();


#endif