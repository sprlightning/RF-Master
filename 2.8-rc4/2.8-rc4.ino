//以下三个定义为调试定义
#define DebugBegin(baud_rate)    Serial.begin(baud_rate)
#define DebugPrintln(message)    Serial.println(message)
#define DebugPrint(message)      Serial.print(message)

bool Debug;

#include <LinkedList.h>
class Animal {
  public:
    char *name;
    bool isMammal;
};
LinkedList<Animal*> myAnimalList = LinkedList<Animal*>();

#include "Gr_algorithm.h"   //算法 定义
#include "Gr_Storage.h"     //文件存储系统
#include "Gr_Switch.h"      //射频解码
#include "Gr_oled.h"        //oled显示
#include "Gr_WiFi.h"        //wifi
#include "Gr_Key.h"         //按键





void setup() {
  DebugBegin(9600);
  DebugPrintln("串口通信");
  pinMode(UP_KEY, INPUT_PULLUP);
  pinMode(M_KEY, INPUT_PULLUP);
  pinMode(DOWN_KEY, INPUT_PULLUP);  

  Switch_433.enableReceive(12);   // 接收器
  Switch_433.enableTransmit(16);  // 发送器                                             

  Switch_315.enableReceive(13);   // 接收器
  Switch_315.enableTransmit(15);  // 发送器

  
  instantiate();  //初始化存储
  if(RC_existence("设置")  == 1){}
  
  u8g2.begin();
  u8g2.enableUTF8Print();
  
 // u8g2.setDisplayRotation(U8G2_R2);//屏幕反转

  
  key_tick.attach_ms(1, flip);
  Boot_logo_animation();
  Main_menu(menu.Main_menu_inde1);
  Debug = true;

  

 
}

void loop() {
  if (menu.Wifi == true) {
    dnsServer.processNextRequest();
    webServer.handleClient();
  }

}
