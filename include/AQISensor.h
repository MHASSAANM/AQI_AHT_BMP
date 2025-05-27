
#ifndef __AQISENSOR_H__
#define __AQISENSOR_H__

#include <Arduino.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>

// Struct to hold AQI data
struct AQIData {
    float temperature;
    float humidity;
    float pressure;
};

// Functions for AQI sensor
class AQISensor {
public:
    AQISensor();
    bool init();            // Initialize all sensors
    AQIData getData();      // Read data from sensors
    bool aht20Initialized = false;
    bool bmp280Initialized = false;

private:
    Adafruit_AHTX0 aht;
    Adafruit_BMP280 bmp;
    
    uint32_t getAbsoluteHumidity(float temperature, float humidity);

    AQIData aqiData;
};

#endif


