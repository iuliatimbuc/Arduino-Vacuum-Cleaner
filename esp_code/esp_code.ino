#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "htmlpage.h"

const char* ssid = "Aspirator Iulia";
const char* password = "12345678";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  WiFi.softAP(ssid, password);
  
  IPAddress IP = WiFi.softAPIP();
  Serial.print("IP address: ");
  Serial.println(IP);
  
  server.on("/", []() {
    server.send(200, "text/html", htmlPage);
  });
  
  server.on("/fata", []() {
    Serial.println("F");
    server.send(200, "text/plain", "OK");
  });
  
  server.on("/spate", []() {
    Serial.println("B");
    server.send(200, "text/plain", "OK");
  });
  
  server.on("/stanga", []() {
    Serial.println("L");
    server.send(200, "text/plain", "OK");
  });
  
  server.on("/dreapta", []() {
    Serial.println("R");
    server.send(200, "text/plain", "OK");
  });
  
  server.on("/stop", []() {
    Serial.println("S");
    server.send(200, "text/plain", "OK");
  });
  
  server.begin();
}

void loop() {
  server.handleClient();
}