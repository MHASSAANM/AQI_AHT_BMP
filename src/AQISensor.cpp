#include "AQISensor.h"

// Constructor
AQISensor::AQISensor() : aqiData { 0.0,
                                   0.0,
                                   0.0 } {}

// Initialize sensors
bool AQISensor::init() {

    /*if (!aht.begin()) {
        log_e("Could not find AHT20 sensor! Check wiring.");
        return false;
    }
    log_d("AHT20 initialized");

    if (!bmp.begin(0x76)) {
        log_e("Could not find BMP280 sensor! Check wiring.");
        return false;
    }
    log_d("BMP280 initialized");

    Serial2.begin(9600, SERIAL_8N1, PMS_RX_PIN, PMS_TX_PIN);
    Serial2.write(setPassiveCommand, sizeof(setPassiveCommand));
    vTaskDelay(1000);
    log_d("PM5007 initialized");*/

    aht20Initialized = aht.begin();
    if (!aht20Initialized) {
        log_e("Could not find AHT20 sensor! Check wiring.");
    } else {
        log_d("AHT20 initialized");
    }
    
    bmp280Initialized = bmp.begin(0x76);
    if (!bmp280Initialized) {
        log_e("Could not find BMP280 sensor! Check wiring.");
    } else {
        log_d("BMP280 initialized");
    }

    return true;
}

// Get AQI data
AQIData AQISensor::getData() {
    sensors_event_t tempEvent, humidityEvent;
    aht.getEvent(&humidityEvent, &tempEvent);
    aqiData.temperature = tempEvent.temperature;
    aqiData.humidity = humidityEvent.relative_humidity;
    aqiData.pressure = bmp.readPressure() / 100.0;
    return aqiData;
}


