#ifndef AUTODISCOVER_H
#define AUTODISCOVER_H 1
struct autodiscover {
  char bufferValue[500] = {0};
  char bufferTopic[100] = {0};
  char haName[20] = {0};
  char haUnits[20] = {0};
  char stateClass[30] = {0};
  char deviceClass[30] = {0};
  char deviceClassString[50] = {0};
};

extern autodiscover adVariables; // home assistand auto discover

extern const char bmeValue[4][12];
extern const char bmeDeviceClass[4][12];
extern const char bmeUnits[4][5];

//const char vs[4] = "_vs"; //placeholder for insert "_vs" for valuestring is used instead of value
//const char[4] noVs = {0}; //empty, no Valuestring

extern const char adValueMbus[] PROGMEM ;
extern const char adTopicMbus[] PROGMEM ;

extern const char adValueSensor[] PROGMEM ;
extern const char adTopicSensor[] PROGMEM ;

extern const char adValueBME[] PROGMEM ;
extern const char adTopicBME[] PROGMEM;

void haHandoverMbus(uint8_t haCounter, bool engelmann, uint8_t address);

void haHandoverOw(uint8_t haCounter);

void haHandoverBME();



/*
char* getStateClass(const char* unit) {
  if (this->unit == "C") {
      return "measurement";
  }else if (this->unit == "K") {
      return "measurement";
  }else if (this->unit == "W") {
      return "measurement";
  }else if(this->unit =="Wh") {
      return "total";
  }else if(this->unit=="kWh"){
      return "total";
  }else if(this->unit=="m3") {
      return "total";
  }else if(this->unit =="m3/h"){
      return "measurement";
  } else {
      return String("");
  }
}

String getDeviceClass() {
    if (this->unit == "C") {
        return "temperature";
    }else if (this->unit == "K") {
        return "temperature";
    }else if (this->unit == "W") {
        return "power";
    }else if(this->unit =="Wh") {
        return "energy";
    }else if(this->unit=="kWh"){
        return "energy";
    }else if(this->unit=="m3") {
        return "water";
    }else if(this->unit =="m3/h"){
        return String("");
    } else {
        return String("");
    }
}


///######## Device.h #####################################
#include <vector>
class Device {
public:

    Device() = default;
    String toJsonString(String mbusinoName) const {
        String oss;
        oss +=  "{";
        oss +=   "\"ids\":  [";
        oss +=    "\""+mbusinoName+"\"";
        oss +=    "],";
        oss +=    "\"name\": \""+mbusinoName+"\",";
        oss +=    "\"mdl\": \"MBusino v.070\"";
        oss += "}";
        return oss;
    }
};

///######## MBusTopic.h #####################################
#include "SensorData.h"

class MBusTopic {
public:
    String topic;
    String value;
    String unit;
    String name;

    MBusTopic(String t) : topic(t), value(""), unit("") {
        name = getLastTopicPart(t);
    }

    void setValue(String v) {
        value = v;
    }

    void setUnit(String u) {
        unit = u;
    }

private:
    const char *getLastTopicPart(String curTopic) {
        const char *lastSlash = strrchr(curTopic.c_str(), '/'); // Suche den letzten Slash

        if (lastSlash != nullptr) {
            // Rückgabe des Zeigers auf den Anfang des letzten Teils des Topics
            return lastSlash + 1;
        } else {
            // Wenn kein Slash gefunden wurde, bedeutet das, dass der ganze String das Topic ist
            return curTopic.c_str();
        }
    }

    bool isValid() {
        if (this->value != nullptr && this->unit != nullptr) {
            return true;
        } else {
            return false;
        }
    }

private:
    String getUnitOfMeassuremetn() {
        if (this->unit == "C") {
            return "°C";
        }else if (this->unit == "K") {
            return "K";
        }else if (this->unit == "W") {
            return "W";
        }else if(this->unit =="Wh") {
            return "Wh";
        }else if(this->unit=="kWh"){
            return "kWh";
        }else if(this->unit=="m3") {
            return "m³";
        }else if(this->unit =="m3/h"){
            return "m³/h";
        } else {
            return String("");
        }
    }
private:
    String getStateClass() {
        if (this->unit == "C") {
            return "measurement";
        }else if (this->unit == "K") {
            return "measurement";
        }else if (this->unit == "W") {
            return "measurement";
        }else if(this->unit =="Wh") {
            return "total";
        }else if(this->unit=="kWh"){
            return "total";
        }else if(this->unit=="m3") {
            return "total";
        }else if(this->unit =="m3/h"){
            return "measurement";
        } else {
            return String("");
        }
    }
private:
    String getDeviceClass() {
        if (this->unit == "C") {
            return "temperature";
        }else if (this->unit == "K") {
            return "temperature";
        }else if (this->unit == "W") {
            return "power";
        }else if(this->unit =="Wh") {
            return "energy";
        }else if(this->unit=="kWh"){
            return "energy";
        }else if(this->unit=="m3") {
            return "water";
        }else if(this->unit =="m3/h"){
            return String("");
        } else {
            return String("");
        }
    }


public:
    SensorData toSensorData(String basic) {
        SensorData sensorData;
        sensorData.unique_id = basic + "_" + this->name;
        sensorData.object_id = basic + "_" + this->name;
        sensorData.state_topic = this->topic;
        sensorData.name = this->name;
        sensorData.value_template = "{{value_json if value_json is defined else 0}}";
        sensorData.unit_of_meas = getUnitOfMeassuremetn();
        sensorData.state_class = getStateClass();
        sensorData.device_class = getDeviceClass();
        sensorData.availability_mode = "all";
        return sensorData;
    }
};

///######## MBusTopicService.h #####################################
#include "SensorData.h"

class MBusTopic {
public:
    String topic;
    String value;
    String unit;
    String name;

    MBusTopic(String t) : topic(t), value(""), unit("") {
        name = getLastTopicPart(t);
    }

    void setValue(String v) {
        value = v;
    }

    void setUnit(String u) {
        unit = u;
    }

private:
    const char *getLastTopicPart(String curTopic) {
        const char *lastSlash = strrchr(curTopic.c_str(), '/'); // Suche den letzten Slash

        if (lastSlash != nullptr) {
            // Rückgabe des Zeigers auf den Anfang des letzten Teils des Topics
            return lastSlash + 1;
        } else {
            // Wenn kein Slash gefunden wurde, bedeutet das, dass der ganze String das Topic ist
            return curTopic.c_str();
        }
    }

    bool isValid() {
        if (this->value != nullptr && this->unit != nullptr) {
            return true;
        } else {
            return false;
        }
    }

private:
    String getUnitOfMeassuremetn() {
        if (this->unit == "C") {
            return "°C";
        }else if (this->unit == "K") {
            return "K";
        }else if (this->unit == "W") {
            return "W";
        }else if(this->unit =="Wh") {
            return "Wh";
        }else if(this->unit=="kWh"){
            return "kWh";
        }else if(this->unit=="m3") {
            return "m³";
        }else if(this->unit =="m3/h"){
            return "m³/h";
        } else {
            return String("");
        }
    }
private:
    String getStateClass() {
        if (this->unit == "C") {
            return "measurement";
        }else if (this->unit == "K") {
            return "measurement";
        }else if (this->unit == "W") {
            return "measurement";
        }else if(this->unit =="Wh") {
            return "total";
        }else if(this->unit=="kWh"){
            return "total";
        }else if(this->unit=="m3") {
            return "total";
        }else if(this->unit =="m3/h"){
            return "measurement";
        } else {
            return String("");
        }
    }
private:
    String getDeviceClass() {
        if (this->unit == "C") {
            return "temperature";
        }else if (this->unit == "K") {
            return "temperature";
        }else if (this->unit == "W") {
            return "power";
        }else if(this->unit =="Wh") {
            return "energy";
        }else if(this->unit=="kWh"){
            return "energy";
        }else if(this->unit=="m3") {
            return "water";
        }else if(this->unit =="m3/h"){
            return String("");
        } else {
            return String("");
        }
    }


public:
    SensorData toSensorData(String basic) {
        SensorData sensorData;
        sensorData.unique_id = basic + "_" + this->name;
        sensorData.object_id = basic + "_" + this->name;
        sensorData.state_topic = this->topic;
        sensorData.name = this->name;
        sensorData.value_template = "{{value_json if value_json is defined else 0}}";
        sensorData.unit_of_meas = getUnitOfMeassuremetn();
        sensorData.state_class = getStateClass();
        sensorData.device_class = getDeviceClass();
        sensorData.availability_mode = "all";
        return sensorData;
    }
};
//######################### SensorData.h ###############################################################
#include <vector>
#include "Device.h"

class SensorData {
public:
    String unique_id;
    String object_id;
    String state_topic;
    String name;
    String value_template;
    String unit_of_meas;
    String state_class;
    Device device;
    String availability_mode;
    String device_class;

    SensorData() = default;

public:
    String toJsonString(String mbusinoName) const {
        String oss;
        oss += "{";
        oss += "\"unique_id\":\"" + unique_id + "\",";
        oss += "\"object_id\":\"" + object_id + "\",";
        oss += "\"state_topic\":\"" + state_topic + "\",";
        oss += "\"name\":\"" + name + "\",";
        oss += "\"value_template\":\"" + value_template + "\",";
        if (!unit_of_meas.isEmpty()) {
            oss += "\"unit_of_meas\":\"" + unit_of_meas + "\",";
        }
        // checking state_class for null and empty, if nothing is present then no entry is made in JSON
        if (!state_class.isEmpty()) {
            oss += "\"state_class\":\"" + state_class + "\",";
        }
        oss += "\"device\":" + device.toJsonString(mbusinoName) + ",";
        if (!device_class.isEmpty()) {
            oss += "\"device_class\":\"" + device_class+ "\",";
        }
        oss += "\"availability_mode\":\"" + availability_mode + "\"";

        oss += "}";
        return oss;
    }

};
*/


#endif // AUTODISCOVER_H