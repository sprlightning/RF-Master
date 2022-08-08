#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>


const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);
ESP8266WebServer webServer(80);
DNSServer dnsServer;

#include "Gr_html.h"


void Open_Wifi(){
  
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  int id=ESP.getChipId();
  String a1 = "射频管家_" + String(id);
  WiFi.softAP(a1.c_str() ,NULL,1,0,2);
  

  dnsServer.start(DNS_PORT, "*", apIP);
  webServer.onNotFound([]() {
  webServer.send(200, "text/html", HTML);
  });
  webServer.on("/", homepage);
  webServer.begin();
  menu.Wifi = true;
  
  }
void Close_Wifi(){
  menu.Wifi = false;
  WiFi.mode(WIFI_OFF);
  }
