#include "WebServer.h"
#include "Motor.h"



AsyncWebServer server(80);

Motor motor;

String processor(const String &var) {
    if (var == "MOTOR_VALUE")
       return String(motor.getMotorValue());
    return String();
}

void WebServer::startServices() {

    connectNetwork();

    server.begin();

    while(!SPIFFS.begin());

    webServerSetup();

    server.begin();
}

void WebServer::connectNetwork(){
    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid, password);

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}

void WebServer::webServerSetup() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    server.on("/bootstrap.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/bootstrap.css"); 
    });

    server.on("/", HTTP_POST, [](AsyncWebServerRequest *request) {
        if(request->hasArg("motorValue")){
            motor.setMotorValue(request->arg("motorValue").toInt());
        }

        request->redirect("/");
    });

    server.on("/motorValue", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/plain", String(motor.getMotorValue()).c_str());
    });
}
