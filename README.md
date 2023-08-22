# ubi-house_temperature_humidity_measuring_device

This repository contains the Arduino code for the Ubi-House temperature and humidity measuring device. This device is designed to monitor and report environmental conditions and integrates with WordPress to post updates.

## Features

- Uses the ESP8266 microcontroller.
- Connects to WiFi to post data to a WordPress site.
- Measures temperature in Celsius and Fahrenheit.
- Measures relative humidity.
- Provides error logging for ease of debugging.

## Hardware Requirements

- ESP8266 WiFi Microcontroller
- WEMOS SHT3X Sensor

## Software Dependencies

- [ESP8266WiFi.h](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
- [ESP8266HTTPClient.h](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient)
- [WEMOS_SHT3X.h](https://github.com/wemos/WEMOS_SHT3x_Arduino_Library)
- [WiFiClientSecure.h](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi/src)
- [ArduinoJson.h](https://arduinojson.org/)

## Setup and Installation

1. Clone this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Install the required libraries via the Library Manager in the Arduino IDE.
4. Update the WiFi SSID and PASSWORD in the code with your own credentials.
5. Flash the code to your ESP8266.

## Usage

Once the device is powered on and connected to the WiFi, it will start measuring temperature and humidity at regular intervals. It will then post this data to the configured WordPress site.

## Contribution

Feel free to submit issues or pull requests if you'd like to enhance the functionalities or fix any bugs.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
