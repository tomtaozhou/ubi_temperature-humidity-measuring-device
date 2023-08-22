#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WEMOS_SHT3X.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#define WIFI_SSID "your_SSID"
#define WIFI_PASSWORD "your_PASSWORD"

#define MASTODON_HOST "https://your_domain.com"
#define MASTODON_TOKEN "your_token_here"

const char* serverName = "https://your_domain.com/wp-json/wp/v2/posts/";
String serverPath = "";

SHT3X sht30(0x45);

WiFiClientSecure wifiClient; // Use WiFiClientSecure for HTTPS

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  wifiClient.setInsecure(); // Disable SSL/TLS certificate validation

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  if(sht30.get() == 0){
    String message = "Temperature in Celsius: " + String(sht30.cTemp) +
                     ", Temperature in Fahrenheit: " + String(sht30.fTemp) +
                     ", Relative Humidity: " + String(sht30.humidity);
    postToWordPress(message);
  }
  else
  {
    Serial.println("Error!");
  }
  delay(10000);
}

void postToWordPress(String message) {
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    http.begin(wifiClient, String(serverName) + serverPath);
    http.addHeader("Content-Type", "application/json");
    http.setAuthorization("your_wordpress_username", MASTODON_TOKEN);
    
    StaticJsonDocument<200> doc;
    doc["title"] = "Environment data";
    doc["status"] = "publish";
    doc["slug"] = "environment-data";
    doc["categories"] = 5;
    doc["date"] = "2023-07-20T00:00:00";
    doc["content"] = message;
    String output;
    serializeJson(doc, output);
    
    int httpResponseCode = http.POST(output);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.print("Status code: ");
      Serial.println(httpResponseCode);
      Serial.print("Response: ");
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else{
    Serial.println("Error in WiFi connection");
  }
}
