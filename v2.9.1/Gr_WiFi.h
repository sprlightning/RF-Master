#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPUpdateServer.h>
#include <DNSServer.h>


const char* host1 = "esp8266";
const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);
ESP8266WebServer webServer(810);
ESP8266HTTPUpdateServer httpUpdater;  //OTA更新
DNSServer dnsServer;
WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // 本地监听端口
char incomingPacket[255];  // 存储Udp客户端发过来的数据
const uint16_t port = 8234;

int Max = 1;
#include "Gr_html.h"


void Open_Wifi_NoJump(){
   if(menu.udp == true){
    menu.udp = false;
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);  //关闭ap模式
    delay(5000); 
    }

    
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  int id = ESP.getChipId();
  String wifissid = rc.GetSys_diyssid();
  String wifipassword = rc.GetSys_diypassword();
  DebugPrintln(wifissid);
  DebugPrintln(wifipassword);
  DebugPrintln(wifissid.length());
  if(wifissid.length() > 0){
    if(wifissid == "null"){wifissid = "射频管家_" + String(id);}
    }else{ wifissid = "射频管家_" + String(id);}
    
  if(wifipassword.length() > 7){
    WiFi.softAP(wifissid.c_str() ,wifipassword.c_str(),1,0,2);
    }else{
      WiFi.softAP(wifissid.c_str() ,NULL,1,0,2);
      }

  
  Max = 1;
  MDNS.begin(host1);
  webServer.on("/", homepage);
  webServer.on("/set", handleSet);    //请求打开设置网页
  webServer.on("/Restart", Restart);   
 
  httpUpdater.setup(&webServer);
  MDNS.addService("http", "tcp", 80);
  webServer.begin();

  menu.Wifi = true;
  
  }
void Open_Wifi_Jump(){
  if(menu.udp == true){
    
    menu.udp = false;
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);  //关闭ap模式
    delay(5000); 
    }
  
  
  
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  int id = ESP.getChipId();
  String wifissid = rc.GetSys_diyssid();
  String wifipassword = rc.GetSys_diypassword();
  DebugPrintln(wifissid);
  DebugPrintln(wifipassword);
  if(wifissid.length() > 0){
    if(wifissid == "null"){wifissid = "射频管家_" + String(id);}    
    }else{ wifissid = "射频管家_" + String(id);}
    
  if(wifipassword.length() > 7){
    WiFi.softAP(wifissid.c_str() ,wifipassword.c_str(),1,0,2);
    }else{
      WiFi.softAP(wifissid.c_str() ,NULL,1,0,2);
      }

  
  Max = 1;
  dnsServer.start(DNS_PORT, "*", apIP);
  webServer.onNotFound([]() {
  webServer.send(200, "text/html", HTML());
  });
//  webServer.on("/set", handleSet);    //请求打开设置网页
  webServer.on("/", homepage);
  webServer.on("/Restart", Restart); 
  webServer.begin();
  menu.Wifi = true;
  
  }
  
void Close_Wifi(){
  menu.Wifi = false;
  WiFi.mode(WIFI_OFF);
  //webServer.stop();
  }

bool autoConfig(){
  //首先自动联网
  WiFi.mode(WIFI_STA);
  String ssid = rc.GetSys_ssid();
  String password = rc.GetSys_password();
  Debugging("Auto ...","","" ,"");

  DebugPrintln(ssid.length());
  DebugPrintln(password.length());
  if(ssid.length() > 0 && password.length() > 7){ 
    DebugPrintln("执行！");
    WiFi.begin(ssid.c_str(), password.c_str());
    }else { 
      DebugPrintln("无保存WiFi执行！");
      WiFi.begin();}
      
  for (int i = 0; i < 20; i++){
    int wstatus = WiFi.status();
    if (wstatus == WL_CONNECTED){ 
       
       Debugging("Auto ...ok!","","" ,"");

       //连接成功返回真
       return true;
    }
    else
    {  

       
       Debugging("Auto ... " + String(i) + "s","","" ,"");

       delay(1000);
       }  
     }
  
  return false;//连接失败返回 假

  }
bool smartConfig(){
  WiFi.mode(WIFI_STA);
  Serial.println("\r\nWaiting for Smartconfig");
  delay(2000);
  WiFi.beginSmartConfig();        //等待配网
  String Smart = "Smart ";
  while (1){
    if(Smart == "Smart ......"){Smart = "Smart ";}else{ Smart = Smart +"." ;}
    
    Debugging("Auto ...",Smart,"" ,"");
    delay(500);    
    if (WiFi.smartConfigDone()){
      Debugging("Auto ...","Smart ...ok!","" ,"");
      WiFi.setAutoConnect(true);  //设置自动连接
      break;      
      }
    }

  Serial.println("等待连接"); 
  for (int i = 0; i < 20; i++){ 
    //20秒等待微信配网结果
   if (WiFi.status() == WL_CONNECTED){ 
    return true; //连接成功返回真
    }else{
      Serial.println("AutoConfig Waiting 3......");
      delay(1000); 
    } }
  return false;  //连接失败返回 假
}
  
void com_ota(){
  menu.Wifi = false;
  WiFi.mode(WIFI_OFF);  //关闭ap模式
  delay(500);
  if (!autoConfig())  { 
    //如果自动联网失败的话，就启动smartconfig           
    Serial.println("Start smartconfig");
    if (!smartConfig()){
      ESP.restart();
      }
  }
  
  rc.System(rc.GetSys_oled() ,rc.GetSys_ID() , rc.GetSys_cartoon() , rc.GetSys_Jump() , WiFi.SSID().c_str() , WiFi.psk().c_str() , rc.GetSys_diyssid() , rc.GetSys_diypassword() , rc.GetSys_Time());
  Serial.print("ssid:");
  Serial.println(rc.GetSys_ssid());
  Serial.print("password:");
  Serial.println(rc.GetSys_password());
  Serial.println(); 
  Serial.println("WiFi 连接成功");  
  Serial.println("IP 地址: ");
  Serial.println(WiFi.localIP());   //得到IP地址
  Debugging("Auto ...ok!","Smart ...ok!","WiFi 连接成功!" ,"IP: " + WiFi.localIP().toString());

 
  
/*------------------------------------------------------------------------------------------------------------------------*/ 
//开启udp监听
  Udp.begin(localUdpPort);
  menu.udp = true;
  
/*------------------------------------------------------------------------------------------------------------------------*/   
//开启pc端网页访问服务  
  MDNS.begin(host1);
  webServer.on("/", homepage);
  webServer.on("/set", handleSet);    //请求打开设置网页
  webServer.on("/Restart", Restart); 
  httpUpdater.setup(&webServer);
  
  MDNS.addService("http", "tcp", 80);
  webServer.begin();

  }
