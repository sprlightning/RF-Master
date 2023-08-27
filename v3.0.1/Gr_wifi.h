#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <ESP8266mDNS.h>

// #include <ESPConnect.h>
// #include <ESPAsyncWebServer.h>
// #include <AsyncElegantOTA.h>
#include <Arduino_JSON.h>


const byte DNS_PORT = 53;


AsyncWebServer server(80);
AsyncEventSource events("/events");
AsyncWebSocket ws("/ws");

String EspDhcp;

#include "Gr_EventsHtml.h"
const char* host1 = "射频管家";
unsigned int localUdpPort = 4210;  // 本地监听端口

String diyssid;
String diypassword;
String espid;
String ip;










//根据配置文件自动联网
bool AutoWifi() {
  WiFi.mode(WIFI_STA);  //首先开启sta模式
  String ssid = Get_ssid();
  String password = Get_password();
  Debugging("Auto ...", "", "", "");  //屏幕显示
  if (ssid.length() > 0) {
    WiFi.begin(ssid.c_str(), password.c_str());

    for (int i = 0; i < 20; i++) {
      int wstatus = WiFi.status();
      if (wstatus == WL_CONNECTED) {
        Debugging("Auto ...ok!", "", "", "");
        //连接成功返回真
        return true;
      } else {
        Debugging("Auto ... " + String(i) + "s", "", "", "");
        delay(1000);
      }
    }

    return false;  //连接失败返回 假
  } else {
    return false;
  }
}
//自动配网  微信配网默认2分钟等待
bool smartConfig() {
  int times = 2 * 60 * 1000;
  int times1;
  bool smart;
  WiFi.beginSmartConfig();
  String Smart = "Smart ";
  while (1) {
    ++times1;
    if (Smart == "Smart ......") {
      Smart = "Smart ";
    } else {
      Smart = Smart + ".";
    }

    if (times1 > times) {
      Debugging("配置失败", Smart, "", "");
      smart = false;
      break;
    }

    Debugging("Auto ...", Smart, "", "");
    delay(1000);
    if (WiFi.smartConfigDone()) {
      WiFi.setAutoConnect(true);  //设置自动连接
      Serial.print("ssid:");
      Serial.print(WiFi.SSID().c_str());
      Serial.print(" password:");
      Serial.println(WiFi.psk().c_str());
      
      break;
    }
  }
  for (int i = 0; i < 20; i++) {
    //20秒等待微信配网结果
    int wstatus = WiFi.status();
    if (wstatus == WL_CONNECTED) {
      smart = true;  //连接成功返回真
      Serial.println("连接成功！");
      Debugging("Auto ...", "Smart ...ok!", "", "");
      break;
    } else {
      Serial.println("等待连接......");
      delay(1000);
      smart = false;
    }
  }

  return smart;  //连接失败返回 假
}



//设置自定义ap-wifi
void get_diywifi() {
  espid = String(ESP.getChipId());
  diyssid = Get_diyssid();
  diypassword = Get_diypassword();
  if (diyssid.length() > 0) {
    if (diypassword.length() > 7) {

    } else {
      diypassword = "";
    }

  } else {
    diyssid = "射频管家_" + espid;
  }
}
//关闭wifi
void Close_Wifi() {
  menu.Wifi = false;
  WiFi.mode(WIFI_OFF);
  //webServer.stop();
}
//打开ap-WiFi 不跳转
void Open_Wifi_NoJump() {
  get_diywifi();  //获取设置ap-wifi的基本配置
  WiFi.mode(WIFI_AP);
  ip = Get_ip();
  String ip1 = fenge(ip, ".", 0);
  String ip2 = fenge(ip, ".", 1);
  String ip3 = fenge(ip, ".", 2);
  String ip4 = fenge(ip, ".", 3);
  IPAddress apIP(ip1.toInt(), ip2.toInt(), ip3.toInt(), ip4.toInt());

  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

  if (diypassword.length() == 0) {
    WiFi.softAP(diyssid.c_str(), NULL, 1, 0, 2);
  } else {
    WiFi.softAP(diyssid.c_str(), diypassword.c_str(), 1, 0, 2);
  }

  HttpServer();
  menu.Wifi = true;
}



//打开调试模式
void DebugBeginWifi() {
  if (menu.autoWifi == false && WiFi.isConnected() == false) {
    if (!AutoWifi()) {
      if (!smartConfig()) {
        ESP.restart();  //配置网络失败 设备重启
      }
    }
    menu.autoWifi = true;
    menu.Wifi = true;
  
    WiFi.hostname(EspDhcp.c_str());
  }
  HttpServer();

  Set_wifi(WiFi.SSID().c_str(), WiFi.psk().c_str());
  Serial.print("ssid:");
  Serial.println(Get_ssid());
  Serial.print("password:");
  Serial.println(Get_password());
  Serial.println();
  Serial.println("WiFi 连接成功");
  Serial.println("IP 地址: ");
  Serial.println(WiFi.localIP());                                                                  //得到IP地址
  Debugging("Auto ...ok!", "Smart ...ok!", "WiFi 连接成功!", "IP: " + WiFi.localIP().toString());  //显示连接成功
}
