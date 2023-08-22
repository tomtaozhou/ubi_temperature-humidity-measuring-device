# Ubi-house Temperature Humidity Measuring Device

This repository contains the Arduino code for the Ubi-House temperature and humidity measuring device. The device utilizes the ESP8266 microcontroller and the WEMOS SHT3X sensor to monitor environmental conditions. Once measured, the data is sent to a specified WordPress site.

## Features

- **ESP8266 Integration:** Uses the popular ESP8266 microcontroller for WiFi capabilities.
- **Temperature and Humidity Measurement:** Uses the WEMOS SHT3X sensor to measure both temperature (in Celsius and Fahrenheit) and relative humidity.
- **WordPress Integration:** Connects to a specified WordPress site to post temperature and humidity data.
- **Error Logging:** Provides comprehensive error logging for ease of debugging and monitoring.
  
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
4. Update the following in the code with your own credentials:
   - `WIFI_SSID`
   - `WIFI_PASSWORD`
   - `MASTODON_HOST`
   - `MASTODON_TOKEN`
   - `serverName` (if using a different domain for the WordPress site)
   - `your_wordpress_username` (when setting up the authorization for WordPress)
5. Flash the code to your ESP8266.

## Usage

1. Power on the device.
2. Once connected to WiFi, the device will start measuring temperature and humidity at regular intervals.
3. This data will then be sent to the configured WordPress site, creating a new post with the environmental data.

## Contribution

Feel free to submit issues or pull requests if you'd like to enhance the functionalities or fix any bugs.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

