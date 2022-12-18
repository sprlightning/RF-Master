#define DebugBegin(message) Serial.begin(message)
#define DebugPrint(message) Serial.print(message)
#define DebugPrintln(message) Serial.println(message)

#include "Gr_Define.h"  //该文件调用各种库 以及声明


unsigned long lastTime_1 = 0;
unsigned long timerDelay_1 = 30000;

void setup() {
  DebugBegin(115200);
  while (!Serial) continue;
  if (!DateBegin()) {
    u8g2begin();
    Startup_error();  //存储报错显示
    DebugPrintln("存储启动失败");
  } else {

    u8g2begin();    //初始化屏幕驱动
    keyBegin();     //初始化按键io
    SwitchBegin();  //初始化射频io
    Main_menu(menu.Main_menu_inde1);
    Enumerate_Events();  //初始化内部文件存储

    DebugPrintln(Read("System"));
    //Set_logo(true);













    DebugPrintln("存储启动成功");
  }
}

void loop() {
  if (menu.DebugBeginWifi == true) {
    menu.DebugBeginWifi = false;
    DebugBeginWifi();
  }
  if (menu.Wifi == true) {
    AsyncElegantOTA.loop();
    ws.cleanupClients();
    if ((millis() - lastTime_1) > timerDelay_1) {
      // Send Events to the client with the Sensor Readings Every 30 seconds
      events.send("ping", NULL, millis());
      events.send(getSensorReadings().c_str(), "new_readings", millis());
      lastTime_1 = millis();
    }
  }

  if (menu.JsRf == true) {
    DebugPrintln(menu.JsRf);
    menu.JsRf = false;
    for (int i = 0; i < myAnimalList.size(); i++) {

      if (retList(i) != "System" && retList(i) != "[返回上级]" && retList(i) != "[删除全部数据]") {
        String json = getJsRf(retList(i), i);

        events.send("ping", NULL, millis());
        events.send(json.c_str(), "data_rf", millis());
        delay(10);
      }

    }
  }
  keyloop();
  SwitchAvailable();

}

void Enumerate_Events() {
  Dir dir = LittleFS.openDir("/");
  List1("[返回上级]", "");
  String filename;
  while (dir.next()) {
    filename = dir.fileName();
    // DebugPrintln(filename);
    if (filename != "System" && filename != "web") {
      List1(filename, Base10_1(filename));

    }  //判断文件不是系统文件将添加到链表
  }
  List1("[删除全部数据]", "");

  // for (int i = 0; i < myAnimalList.size(); i++) {
  //   DebugPrintln(Get_ListBase10(i));
  // }
}