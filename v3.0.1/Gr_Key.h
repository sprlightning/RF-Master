//#include <Ticker.h>

//Ticker key_tick;
#include "OneButton.h"

uint32_t keyTime;
uint32_t keyTime1;

#define UP_KEY 0
#define M_KEY 2
#define DOWN_KEY 14

OneButton button1(UP_KEY, true);
OneButton button2(M_KEY, true);
OneButton button3(DOWN_KEY, true);
void click1();
void click2();
void click3();
void longPressStart1();
void longPressStart2();
void longPressStart3();
void longPressStop1();
void longPressStop2();
void longPressStop3();
void longPress1();
void longPress2();
void longPress3();



//按键初始化函数
void keyBegin() {
  menu.Rolling = Get_Rolling();
  button1.attachClick(click1);                    //上翻单击事件
  button1.attachLongPressStart(longPressStart1);  //上翻长按开始
  button1.attachLongPressStop(longPressStop1);    //上翻长按结束
  button1.attachDuringLongPress(longPress1);      //上翻长按期间
  button1.setDebounceTicks(60);                   //按键消抖时间

  button2.attachClick(click2);
  button2.attachLongPressStart(longPressStart2);
  button2.attachLongPressStop(longPressStop2);
  button2.attachDuringLongPress(longPress2);
  button2.setDebounceTicks(60);

  button3.attachClick(click3);
  button3.attachLongPressStart(longPressStart3);
  button3.attachLongPressStop(longPressStop3);
  button3.attachDuringLongPress(longPress3);
  button3.setDebounceTicks(60);
}

//按键循环检测函数
void keyloop() {
  uint32_t keyloop;
  keyloop = millis();
  if (keyloop > keyTime & keyloop - keyTime > 1) {
    keyTime = keyloop;
    button1.tick();
    button2.tick();
    button3.tick();
  }
}

//上翻单击事件
void click1() {
  DebugPrintln("上翻单击事件");
  if (menu.Menu_page == 1) {
    if (--menu.Main_menu_inde1 < 1) { menu.Main_menu_inde1 = 6; }
    Main_menu(menu.Main_menu_inde1);
  }
  if (menu.Menu_page == 4) {
    if (--menu.Main_menu_inde3 < 0) { menu.Main_menu_inde3 = 1; }
    AP_Menu(menu.Main_menu_inde3);
  }
  if (menu.Menu_page == 6 or menu.Menu_page == 8) {
    if (--menu.Main_menu_inde4 < 0) { menu.Main_menu_inde4 = 1; }
    Delete_all(menu.Main_menu_inde4);
  }
  if (menu.Menu_page == 7) {
    if (--menu.Main_menu_inde5 < 1) { menu.Main_menu_inde5 = 5; }
    SysOled(menu.Main_menu_inde5);
  }

  if (menu.Menu_page == 3 or menu.Menu_page == 5) {
    --menu.Main_menu_inde2;
    if (menu.Menu_page == 3) {
      if (menu.Main_menu_inde2 < 0) { menu.Main_menu_inde2 = myAnimalList.size() - 2; }
    }
    if (menu.Menu_page == 5) {
      if (menu.Main_menu_inde2 < 0) {
        if (myAnimalList.size() - 2 == 0) {
          menu.Main_menu_inde2 = myAnimalList.size() - 2;
        } else {
          menu.Main_menu_inde2 = myAnimalList.size() - 1;
        }
      }
    }
    Launch_Menu(menu.Main_menu_inde2);  //菜单显示
  }
}

//确认单击事件
void click2() {
  DebugPrintln("确认单击事件");
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=主菜单 并且 主菜单索引=1（接收菜单）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 1) {
    Switch_433.resetAvailable();  //进入接收菜单前清除数据
    Switch_315.resetAvailable();  //进入接收菜单前清除数据
    menu.Menu_page = 2;           //进入接收菜单
    Receiving_mode("", "");       //菜单显示
    menu.Switch = true;
    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=主菜单 并且 主菜单索引=2（发射菜单）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 2) {
    menu.Menu_page = 3;  //进入发射菜单

    Launch_Menu(menu.Main_menu_inde2);  //菜单显示
    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=主菜单 并且 主菜单索引=3（AP模式）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 3) {
    menu.Menu_page = 4;  //进入AP模式
    AP_Menu(menu.Main_menu_inde3);
    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=主菜单 并且 主菜单索引=4（删除模式）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 4) {
    menu.Menu_page = 5;  //进入删除菜单

    Launch_Menu(menu.Main_menu_inde2);

    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=主菜单 并且 主菜单索引=5（系统设置）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 5) {
    menu.Menu_page = 7;  //进入系统设置
    menu.Main_menu_inde5 = 1;
    SysOled(menu.Main_menu_inde5);


    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=接收菜单 并且 主菜单索引=1（接收菜单）
  if (menu.Menu_page == 2 & menu.Main_menu_inde1 == 1) {
    menu.Switch = false;
    menu.Menu_page = 1;               //页面=主菜单
    Main_menu(menu.Main_menu_inde1);  //返回主菜单
    return;
  }

  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=AP模式 并且 主菜单索引=3（AP模式） 并且2级菜单=1（返回上级）
  if (menu.Menu_page == 4 & menu.Main_menu_inde1 == 3 & menu.Main_menu_inde3 == 1) {
    menu.Menu_page = 1;  //返回主菜单
    menu.Main_menu_inde3 = 0;
    Main_menu(menu.Main_menu_inde1);
    return;
  }

  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=AP模式 并且 主菜单索引=3（AP模式） 并且2级菜单=0（开启WiFi）
  if (menu.Menu_page == 4 & menu.Main_menu_inde1 == 3 & menu.Main_menu_inde3 == 0) {
    if (menu.Wifi == false) {
      if (Get_Jump()) {
        //开启跳转模式

      } else {
        Open_Wifi_NoJump();  //不开启跳转模式
      }
    } else {
      if (menu.Wifi == true) { Close_Wifi(); }  //关闭 WiFi-ap
    }


    AP_Menu(menu.Main_menu_inde3);

    return;
  }

  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=发射模式 并且 主菜单索引=2（发送模式）
  if (menu.Menu_page == 3 & menu.Main_menu_inde1 == 2) {
    if (menu.Main_menu_inde2 == 0) {
      menu.Menu_page = 1;
      Main_menu(menu.Main_menu_inde1);
    }
    if (menu.Main_menu_inde2 > 0 & menu.Main_menu_inde2 < myAnimalList.size() - 1) {
      SwitchSend(retList(menu.Main_menu_inde2));
    }


    return;
  }

  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=删除模式 并且 主菜单索引=（删除模式）
  if (menu.Menu_page == 5 & menu.Main_menu_inde1 == 4) {

    if (menu.Main_menu_inde2 == 0) {
      menu.Menu_page = 1;
      Main_menu(menu.Main_menu_inde1);
      return;
    }
    if (menu.Main_menu_inde2 > 0 & menu.Main_menu_inde2 < myAnimalList.size() - 1) {
      String Read_RF = retList(menu.Main_menu_inde2);

      Deledata(Read_RF);
      DeleList(menu.Main_menu_inde2);
      if (menu.Main_menu_inde2 == myAnimalList.size() - 1) { --menu.Main_menu_inde2; }
    }
    if (menu.Main_menu_inde2 == myAnimalList.size() - 1) {
      menu.Menu_page = 6;
      Delete_all(menu.Main_menu_inde4);
    }
    if (menu.Menu_page != 6) { Launch_Menu(menu.Main_menu_inde2); }


    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=删除页面菜单
  if (menu.Menu_page == 6) {
    if (menu.Main_menu_inde4 == 0) {
      String Json = Read("System");
      DynamicJsonDocument jsonBuffer(400);
      deserializeJson(jsonBuffer, Json);
      JsonObject obj = jsonBuffer.as<JsonObject>();
      String output;
      serializeJson(jsonBuffer, output);


      LittleFS.format();
      u8g2.clear();
      myAnimalList.clear();
      List1("[返回上级]", "");
      List1("[删除全部数据]", "");
      File file = LittleFS.open("/System", "w");
      file.print(output);
      file.close();


      menu.Menu_page = 1;
      Main_menu(menu.Main_menu_inde1);
      menu.Main_menu_inde2 = 0;
      menu.Main_menu_inde4 = 1;
    }

    if (menu.Main_menu_inde4 == 1) {
      menu.Menu_page = 1;  //返回主菜单
      menu.Main_menu_inde4 = 1;
      menu.Main_menu_inde2 = 0;
      Main_menu(menu.Main_menu_inde1);  //刷新屏幕显示
    }
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=系统设置菜单
  if (menu.Menu_page == 7 & menu.Main_menu_inde5 == 1) {
    menu.Menu_page = 1;  //返回主菜单
    menu.Main_menu_inde5 = 1;
    Main_menu(menu.Main_menu_inde1);  //刷新屏幕显示
    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=系统设置菜单 Main_menu_inde5=2 屏幕反转
  if (menu.Menu_page == 7 & menu.Main_menu_inde5 == 2) {
    if (Get_reverse()) {
      Set_reverse(false);
    } else {
      Set_reverse(true);
    }
    SysOled(menu.Main_menu_inde5);  //刷新屏幕显示

    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=系统设置菜单 Main_menu_inde5=3 开机动画
  if (menu.Menu_page == 7 & menu.Main_menu_inde5 == 3) {
    if (Get_logo()) {
      Set_logo(false);
    } else {
      Set_logo(true);
    }
    SysOled(menu.Main_menu_inde5);  //刷新屏幕显示
    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=系统设置菜单 Main_menu_inde5=4 web跳转
  if (menu.Menu_page == 7 & menu.Main_menu_inde5 == 4) {
    if (Get_Jump()) {
      Set_Jump(false);
    } else {
      Set_Jump(true);
    }
    SysOled(menu.Main_menu_inde5);  //刷新屏幕显示
    return;
  }
  /*------------------------------------------------------------------------------------------------------------------------*/
  //如果页面=系统设置菜单 Main_menu_inde5=5 设备初始化
  if (menu.Menu_page == 7 & menu.Main_menu_inde5 == 5) {
    menu.Menu_page = 8;
    Delete_all2(menu.Main_menu_inde4);
    return;
  }
  //设备初始化页面
  if (menu.Menu_page == 8) {
    if (menu.Main_menu_inde4 == 0) {
      LittleFS.format();  //删除所有已保存的数据
      ESP.restart();      //设备重启
    }
    if (menu.Main_menu_inde4 == 1) {
      menu.Menu_page = 1;  //返回主菜单
      menu.Main_menu_inde4 = 1;
      menu.Main_menu_inde2 = 0;
      Main_menu(menu.Main_menu_inde1);  //刷新屏幕显示
    }


    return;
  }
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 6) {
    menu.DebugBeginWifi = true;
    return;
  }
}

//下翻单击事件
void click3() {
  DebugPrintln("下翻单击事件");
  if (menu.Menu_page == 1) {
    if (++menu.Main_menu_inde1 > 6) { menu.Main_menu_inde1 = 1; }
    Main_menu(menu.Main_menu_inde1);
  }
  if (menu.Menu_page == 4) {
    if (++menu.Main_menu_inde3 > 1) { menu.Main_menu_inde3 = 0; }
    AP_Menu(menu.Main_menu_inde3);
  }
  if (menu.Menu_page == 6 or menu.Menu_page == 8) {
    if (++menu.Main_menu_inde4 > 1) { menu.Main_menu_inde4 = 0; }
    Delete_all(menu.Main_menu_inde4);
  }
  if (menu.Menu_page == 7) {
    if (++menu.Main_menu_inde5 > 5) { menu.Main_menu_inde5 = 1; }
    SysOled(menu.Main_menu_inde5);
  }
  if (menu.Menu_page == 3 or menu.Menu_page == 5) {
    ++menu.Main_menu_inde2;
    if (menu.Menu_page == 3) {
      if (menu.Main_menu_inde2 == myAnimalList.size() - 1) { menu.Main_menu_inde2 = 0; }
    }
    if (menu.Menu_page == 5) {
      if (myAnimalList.size() - 2 == 0) {
        menu.Main_menu_inde2 = 0;
      }

      if (menu.Main_menu_inde2 == myAnimalList.size()) { menu.Main_menu_inde2 = 0; }
    }
    Launch_Menu(menu.Main_menu_inde2);  //菜单显示
  }
}

//上翻长按开始
void longPressStart1() {
  DebugPrintln("上翻长按开始");
}

//上翻长按停止
void longPressStop1() {
  DebugPrintln("上翻长按停止");
}

//确认长按开始
void longPressStart2() {
  DebugPrintln("确认长按开始");
}

//确认长按停止
void longPressStop2() {
  DebugPrintln("确认长按停止");
}

//下翻长按开始
void longPressStart3() {
  DebugPrintln("下翻长按开始");
}

//下翻长按停止
void longPressStop3() {
  DebugPrintln("下翻长按停止");
}

//上翻长按期间
void longPress1() {
  DebugPrintln("上翻长按期间");

  uint32_t keyPress1;
  keyPress1 = millis();
  if (keyPress1 > keyTime1 & keyPress1 - keyTime1 > menu.Rolling) {
    keyTime1 = keyPress1;
    if (menu.Menu_page == 1) {
      if (--menu.Main_menu_inde1 < 1) { menu.Main_menu_inde1 = 6; }
      Main_menu(menu.Main_menu_inde1);
    }
    if (menu.Menu_page == 4) {
      if (--menu.Main_menu_inde3 < 0) { menu.Main_menu_inde3 = 1; }
      AP_Menu(menu.Main_menu_inde3);
    }
    if (menu.Menu_page == 6 or menu.Menu_page == 8) {
      if (--menu.Main_menu_inde4 < 0) { menu.Main_menu_inde4 = 1; }
      Delete_all(menu.Main_menu_inde4);
    }
    if (menu.Menu_page == 7) {
      if (--menu.Main_menu_inde5 < 1) { menu.Main_menu_inde5 = 5; }
      SysOled(menu.Main_menu_inde5);
    }
    if (menu.Menu_page == 3 or menu.Menu_page == 5) {
      --menu.Main_menu_inde2;
      if (menu.Menu_page == 3) {
        if (menu.Main_menu_inde2 < 0) { menu.Main_menu_inde2 = myAnimalList.size() - 2; }
      }
      if (menu.Menu_page == 5) {
        if (menu.Main_menu_inde2 < 0) {
          if (myAnimalList.size() - 2 == 0) {
            menu.Main_menu_inde2 = myAnimalList.size() - 2;
          } else {
            menu.Main_menu_inde2 = myAnimalList.size() - 1;
          }
        }
      }
      Launch_Menu(menu.Main_menu_inde2);  //菜单显示
    }
  }
}

//确认长按期间
void longPress2() {
  DebugPrintln("确认长按期间");
  if (menu.Menu_page == 3 & menu.Main_menu_inde1 == 2) {
    if (menu.Main_menu_inde2 > 0 & menu.Main_menu_inde2 < myAnimalList.size() - 1) {
      SwitchSend(retList(menu.Main_menu_inde2));
    }
  }
}
//下翻长按期间
void longPress3() {
  DebugPrintln("下翻长按期间");
  uint32_t keyPress3;
  keyPress3 = millis();
  if (keyPress3 > keyTime1 & keyPress3 - keyTime1 > menu.Rolling) {
    keyTime1 = keyPress3;
    if (menu.Menu_page == 1) {
      if (++menu.Main_menu_inde1 > 6) { menu.Main_menu_inde1 = 1; }
      Main_menu(menu.Main_menu_inde1);
    }
    if (menu.Menu_page == 4) {
      if (++menu.Main_menu_inde3 > 1) { menu.Main_menu_inde3 = 0; }
      AP_Menu(menu.Main_menu_inde3);
    }
    if (menu.Menu_page == 6 or menu.Menu_page == 8) {
      if (++menu.Main_menu_inde4 > 1) { menu.Main_menu_inde4 = 0; }
      Delete_all(menu.Main_menu_inde4);
    }
    if (menu.Menu_page == 7) {
      if (++menu.Main_menu_inde5 > 5) { menu.Main_menu_inde5 = 1; }
      SysOled(menu.Main_menu_inde5);
    }
    if (menu.Menu_page == 3 or menu.Menu_page == 5) {
      ++menu.Main_menu_inde2;
      if (menu.Menu_page == 3) {
        if (menu.Main_menu_inde2 == myAnimalList.size() - 1) { menu.Main_menu_inde2 = 0; }
      }
      if (menu.Menu_page == 5) {
        if (myAnimalList.size() - 2 == 0) {
          menu.Main_menu_inde2 = 0;
        }
        if (menu.Main_menu_inde2 == myAnimalList.size()) { menu.Main_menu_inde2 = 0; }
      }
      Launch_Menu(menu.Main_menu_inde2);  //菜单显示
    }
  }
}