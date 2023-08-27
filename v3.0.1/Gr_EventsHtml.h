unsigned long lastTime = 0;
unsigned long timerDelay = 30000;
int Max = 1;
#include "webh/Gr_index_html.h"
#include "webh/Gr_RF_html.h"
#include "webh/Gr_Set_html.h"
#include "webh/Gr_bootstrap_min_css.h"
#include "webh/Gr_home_css.h"
#include "webh/Gr_rf_css.h"
#include "webh/Gr_set_css.h"
#include "webh/Gr_bootstrap_min_js.h"
#include "webh/Gr_home_js.h"
#include "webh/Gr_jquery_min_js.h"
#include "webh/Gr_Rf_js.h"
#include "webh/Gr_set_js.h"



const char *PARAM_INPUT_inputtohide = "inputtohide";
const char *PARAM_INPUT_wifipass = "wifipass";
const char *PARAM_INPUT_ipaddress = "ipaddress";
const char *PARAM_INPUT_ipaddhost = "ipaddhost";
const char *PARAM_INPUT_reverse = "reverse";
const char *PARAM_INPUT_logo = "logo";
const char *PARAM_INPUT_Jump = "Jump";
const char *PARAM_INPUT_ssid = "ssid";
const char *PARAM_INPUT_pswd = "pswd";
const char *PARAM_INPUT_wg0pin = "wg0pin";
const char *PARAM_INPUT_wg1pin = "wg1pin";
const char *PARAM_INPUT_wg2pin = "wg2pin";
const char *PARAM_INPUT_wg3pin = "wg3pin";
const char *PARAM_INPUT_Rolling = "Rolling";
String getJsRf(String filename, int i) {
  String data = Read(filename);
  String pattern = data.substring(0, 2);
  JSONVar readings;
  readings["rf"] = filename;
  readings["id"] = i;
  readings["frequency"] = pattern;
  String jsonString = JSON.stringify(readings);
  return jsonString;
}


//系统运行时间子函数
String millisToStringShort() {
  unsigned long start_time;
  unsigned long myTime;
  int Time_second;                            //秒钟
  int Time_minute;                            //分钟
  int Time_hour;                              //小时
  unsigned long Time_hour_setting = 3600000;  //1小时 = 3600000 毫秒
  unsigned long Time_minute_setting = 60000;  // 1分钟 = 60000 毫秒
  unsigned long Time_second_setting = 1000;   //1秒 = 1000 毫秒
  start_time = millis();

  Time_hour = start_time / Time_hour_setting;                                                  //小时 = millis 除以  进率3600000
  Time_minute = (start_time % Time_hour_setting) / Time_minute_setting;                        //分钟数 = millis的小时取余后，除以进率60000
  Time_second = (start_time % Time_hour_setting) % Time_minute_setting / Time_second_setting;  //
  return String(Time_hour) + "时" + String(Time_minute) + "分" + String(Time_second) + "秒";
}

//页面基础信息反馈函数
String getSensorReadings() {
  JSONVar readings;

  readings["instructions"] = "1";
  readings["version"] = "v3.0";
  readings["ChipId"] = String(ESP.getChipId());
  readings["CpuFreqMHz"] = String(ESP.getCpuFreqMHz()) + "Mhz";
  readings["SSID"] = String(WiFi.SSID().c_str());      //正式版这里要做改变
  readings["IP"] = String(WiFi.localIP().toString());  //正式版这里要做改变 WiFi.localIP().toString()  WiFi.softAPIP().toString();
  readings["gateway"] = String(WiFi.gatewayIP().toString().c_str());
  readings["DNS"] = String(WiFi.dnsIP().toString().c_str());
  readings["APMAC"] = String(WiFi.softAPmacAddress().c_str());
  readings["STAMAC"] = String(WiFi.macAddress().c_str());
  readings["Uptime"] = "已运行：" + millisToStringShort();

  readings["SketchSize"] = String(ESP.getSketchSize() / 1024) + "kb";
  readings["SketchSpace"] = String(ESP.getFreeSketchSpace() / 1024) + "kb";
  readings["usedBytes"] = String(fs_info.usedBytes / 1024) + "kb";
  readings["available"] = String((fs_info.totalBytes - fs_info.usedBytes) / 1024) + "kb";
  readings["totalBytes"] = String(fs_info.totalBytes / 1024) + "kb";
  String jsonString = JSON.stringify(readings);
  return jsonString;
}


String Scan() {
  String json = "[";
  int n = WiFi.scanComplete();
  if (n == -2) {
    WiFi.scanNetworks(true);
  } else if (n) {
    for (int i = 0; i < n; ++i) {
      if (i) json += ",";
      json += "{";
      json += "\"rssi\":" + String(WiFi.RSSI(i));
      json += ",\"ssid\":\"" + WiFi.SSID(i) + "\"";
      json += ",\"bssid\":\"" + WiFi.BSSIDstr(i) + "\"";
      json += ",\"channel\":" + String(WiFi.channel(i));
      json += ",\"secure\":" + String(WiFi.encryptionType(i));
      json += ",\"hidden\":" + String(WiFi.isHidden(i) ? "true" : "false");
      json += "}";
    }
    WiFi.scanDelete();
    if (WiFi.scanComplete() == -2) {
      WiFi.scanNetworks(true);
    }
  }
  json += "]";
  return json;
}


String getJsSet() {
  JSONVar readings;
  String Dssid = Get_diyssid();
  Scan();
  if (Dssid.length() == 0) {
    Dssid = "射频管家_" + String(ESP.getChipId());
  }

  readings["diyssid"] = Dssid;
  readings["diypassword"] = Get_diypassword();
  readings["logo"] = Get_logo();
  readings["reverse"] = Get_reverse();
  readings["Jump"] = Get_Jump();
  readings["espdhcp"] = Get_espdhcp();
  readings["ip"] = Get_ip();
  readings["wg0pin"] = Get_wg0pin();
  readings["wg1pin"] = Get_wg1pin();
  readings["wg2pin"] = Get_wg2pin();
  readings["wg3pin"] = Get_wg3pin();
  readings["Rolling"] = Get_Rolling();
  String jsonString = JSON.stringify(readings);
  return jsonString;
}
void HttpServer() {
  //== html =====================================================================================================================================================
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", index_html_gz, index_html_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/Set", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", Set_html_gz, Set_html_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/RF", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", RF_html_gz, RF_html_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });

  //== css =====================================================================================================================================================
  server.on("/css/home.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/css", home_css_gz, home_css_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/css/bootstrap.min.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/css", bootstrap_min_css_gz, bootstrap_min_css_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/css/set.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/css", set_css_gz, set_css_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/css/rf.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/css", rf_css_gz, rf_css_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });


  //== js =====================================================================================================================================================

  server.on("/js/home.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", home_js_gz, home_js_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/js/set.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", set_js_gz, set_js_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/js/jquery.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", jquery_min_js_gz, jquery_min_js_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/js/bootstrap.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", bootstrap_min_js_gz, bootstrap_min_js_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/js/Rf.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", Rf_js_gz, Rf_js_gz_size);
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });


  //== 处理请求 =====================================================================================================================================================


  server.on("/wifi", HTTP_GET, [](AsyncWebServerRequest *request) {
    String ssid;
    String pswd;
    if (request->hasParam(PARAM_INPUT_ssid) && request->hasParam(PARAM_INPUT_pswd)) {
      ssid = request->getParam(PARAM_INPUT_ssid)->value();
      pswd = request->getParam(PARAM_INPUT_pswd)->value();
      Set_wifi(ssid, pswd);
    } else {
      ssid = "No message sent";
      pswd = "No message sent";
    }
    request->send(200, "text/plain", "OK");
  });
  server.on("/readings", HTTP_GET, [](AsyncWebServerRequest *request) {
    String json = getSensorReadings();
    request->send(200, "application/json", json);
    json = String();
  });
  server.on("/JsSet", HTTP_GET, [](AsyncWebServerRequest *request) {
    String json = getJsSet();
    request->send(200, "application/json", json);
    json = String();
  });
  server.on("/Scan", HTTP_GET, [](AsyncWebServerRequest *request) {
    String json;
    json = Scan();
    request->send(200, "application/json", json);
    json = String();
  });
  server.on("/deletewifi", HTTP_GET, [](AsyncWebServerRequest *request) {
    Set_wifi("", "");
    request->send(200, "text/plain", "OK");
  });
  server.on("/deleteapwifi", HTTP_GET, [](AsyncWebServerRequest *request) {
    Set_diywifi("射频管家_" + String(ESP.getChipId()), "");
    Set_ip("192.168.4.1");
    Set_espdhcp("esp-spgj");
    request->send(200, "text/plain", "OK");
  });
  server.on("/delete", HTTP_GET, [](AsyncWebServerRequest *request) {
    LittleFS.format();
    Set_System(false, true, false, "", "", "", "", "esp-spgj", "192.168.4.1", 12, 16, 13, 15, 10);

    ESP.restart();
    request->send(200, "text/plain", "OK");
  });
  server.on("/restart", HTTP_GET, [](AsyncWebServerRequest *request) {
    ESP.restart();
    request->send(200, "text/plain", "OK");
  });
  server.on("/SysSet", HTTP_GET, [](AsyncWebServerRequest *request) {
    String ipaddress;
    String ipaddhost;
    String reverse;
    String logo;
    String Jump;
    String wg0pin;
    String wg1pin;
    String wg2pin;
    String wg3pin;
    String Rolling;
    if (request->hasParam(PARAM_INPUT_ipaddress) && request->hasParam(PARAM_INPUT_ipaddhost) && request->hasParam(PARAM_INPUT_reverse) && request->hasParam(PARAM_INPUT_logo) && request->hasParam(PARAM_INPUT_Jump) && request->hasParam(PARAM_INPUT_wg0pin) && request->hasParam(PARAM_INPUT_wg1pin) && request->hasParam(PARAM_INPUT_wg2pin) && request->hasParam(PARAM_INPUT_wg3pin) && request->hasParam(PARAM_INPUT_Rolling)) {
      ipaddress = request->getParam(PARAM_INPUT_ipaddress)->value();
      ipaddhost = request->getParam(PARAM_INPUT_ipaddhost)->value();
      reverse = request->getParam(PARAM_INPUT_reverse)->value();
      logo = request->getParam(PARAM_INPUT_logo)->value();
      Jump = request->getParam(PARAM_INPUT_Jump)->value();
      wg0pin = request->getParam(PARAM_INPUT_wg0pin)->value();
      wg1pin = request->getParam(PARAM_INPUT_wg1pin)->value();
      wg2pin = request->getParam(PARAM_INPUT_wg2pin)->value();
      wg3pin = request->getParam(PARAM_INPUT_wg3pin)->value();
      Rolling = request->getParam(PARAM_INPUT_Rolling)->value();

      Set_reverse(reverse.toInt());
      Set_logo(logo.toInt());
      Set_Jump(Jump.toInt());
      Set_espdhcp(ipaddhost);
      Set_ip(ipaddress);
      Set_wg0pin(wg0pin.toInt());
      Set_wg1pin(wg1pin.toInt());
      Set_wg2pin(wg2pin.toInt());
      Set_wg3pin(wg3pin.toInt());
      Set_Rolling(Rolling.toInt());
    } else {
      ipaddress = "No message sent";
      ipaddhost = "No message sent";
    }

    request->send(200, "text/plain", "OK");
  });

  server.on("/Diywifi", HTTP_GET, [](AsyncWebServerRequest *request) {
    String inputtohide;
    String wifipass;
    String message;
    if (request->hasParam(PARAM_INPUT_inputtohide) && request->hasParam(PARAM_INPUT_wifipass)) {
      inputtohide = request->getParam(PARAM_INPUT_inputtohide)->value();
      wifipass = request->getParam(PARAM_INPUT_wifipass)->value();
      if (wifipass.length() > 7) {

      } else {
        wifipass = "";
      }
      message = "OK";

      Set_diywifi(inputtohide, wifipass);
    } else {
      message = "No";
    }
    request->send(200, "text/plain", "message:" + message);
  });

  server.on("/JsRf", HTTP_GET, [](AsyncWebServerRequest *request) {
    // DebugPrintln("===================================");
    // String FileName;
    // String json;
    // FileName = "[";
    // int i  = Max;
    // int a ;
    // for (i; i < myAnimalList.size(); i++) {
    //   if(i > Max + 15){break;}

    //   if (retList(i) != "System" && retList(i) != "[返回上级]" && retList(i) != "[删除全部数据]") {
    //     FileName = FileName + getJsRf(retList(i), i) + ",";
    //     a++;


    //   }

    // }
    // i++;a++;
    // FileName = FileName + getJsRf(retList(i), i);
    // json =Complement(String(a),2) + FileName + "]";

    // request->send(200, "application/json", json);
    // json = String();
    menu.JsRf = true;
    request->send(200, "text/plain", "OK");
  });

  events.onConnect([](AsyncEventSourceClient *client) {
    if (client->lastId()) {
      Serial.printf("客户端已重新连接！它得到的最后一个消息ID是: %u\n", client->lastId());
    }

    //发送带有消息“hello！”的事件，现在时间毫秒数
    //并将重新连接延迟设置为1秒
    client->send("hello!", NULL, millis(), 10000);
  });
  //=======================================================================================================
  server.on("/De", HTTP_GET, [](AsyncWebServerRequest *request) {
    int headers = request->headers();
    int i;
    for (i = 0; i < headers; i++) {
      AsyncWebHeader *h = request->getHeader(i);
      Serial.printf("HEADER[%s]: %s\n", h->name().c_str(), h->value().c_str());
      // 下面行功能同上面两行
      //Serial.printf("HEADER[%s]: %s\n", request->headerName(i).c_str(), request->header(i).c_str());
    }

    request->send(200, "text/plain", "OK");
  });




  server.addHandler(&events);
  AsyncElegantOTA.begin(&server);
  server.begin();
}