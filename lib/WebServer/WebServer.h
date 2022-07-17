#ifndef WebServer_H
#define WebServer_H

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>

class WebServer
{
    private:
        

    public:
        void connectNetwork();
        void webServerSetup();
        void startServices();
};

#endif