#include <Ticker.h>
Ticker key_tick;
#include "Gr_KeyFunction.h"

#define UP_KEY    0
#define M_KEY     2
#define DOWN_KEY  14

#define KEYU      digitalRead(UP_KEY)
#define KEYM      digitalRead(M_KEY)
#define KEYD      digitalRead(DOWN_KEY)

#define delay_time 300
#define short_press_time 10     //短按时间
#define long_press_time 1000    //长按时间

#define NO_KEY_PRES     0   //无按键按下

#define UP_KEY_PRES     1
#define M_KEY_PRES      2
#define DOWN_KEY_PRES   3

#define UP_KEY_LONG_PRES     11
#define M_KEY_LONG_PRES      22
#define DOWN_KEY_LONG_PRES   33
uint16_t KEYU_PRESS_COUNT = 0;//按KEYU时间计数
uint16_t KEYM_PRESS_COUNT = 0;//按KEYM时间计数
uint16_t KEYD_PRESS_COUNT = 0;//按KEYD时间计数

bool KEYU_UP = 0;//按键状态，0为弹起，1为按下
bool KEYM_UP = 0;//按键状态，0为弹起，1为按下
bool KEYD_UP = 0;//按键状态，0为弹起，1为按下

uint8_t KEYU_KEY_READ = NO_KEY_PRES;//KEYU按键状态
uint8_t KEYM_KEY_READ = NO_KEY_PRES;//KEYM按键状态
uint8_t KEYD_KEY_READ = NO_KEY_PRES;//KEYD按键状态

void flip() {
  //UP_KEY
  if (KEYU == 0) {
    KEYU_PRESS_COUNT++;
    KEYU_UP = 1;
    if (KEYU_PRESS_COUNT <= short_press_time)
      KEYU_KEY_READ = NO_KEY_PRES;
    if (KEYU_PRESS_COUNT >= short_press_time && KEYU_PRESS_COUNT <= long_press_time)
      KEYU_KEY_READ = UP_KEY_PRES;
    if (KEYU_PRESS_COUNT >= long_press_time)
      KEYU_KEY_READ = UP_KEY_LONG_PRES;
  }
  if (KEYU) {
    KEYU_PRESS_COUNT = 0;
    KEYU_UP = 0;//按键状态，0为弹起，1为按下
  }
  //M_KEY
  if (KEYM == 0) {
    KEYM_PRESS_COUNT++;
    KEYM_UP = 1;
    if (KEYM_PRESS_COUNT <= short_press_time)
      KEYM_KEY_READ = NO_KEY_PRES;
    if (KEYM_PRESS_COUNT >= short_press_time && KEYM_PRESS_COUNT <= long_press_time)
      KEYM_KEY_READ = M_KEY_PRES;
    if (KEYM_PRESS_COUNT >= long_press_time)
      KEYM_KEY_READ = M_KEY_LONG_PRES;
  }
  if (KEYM) {
    KEYM_PRESS_COUNT = 0;
    KEYM_UP = 0;//按键状态，0为弹起，1为按下
  }
  //DOWN_KEY
  if (KEYD == 0) {
    KEYD_PRESS_COUNT++;
    KEYD_UP = 1;
    if (KEYD_PRESS_COUNT <= short_press_time)
      KEYD_KEY_READ = NO_KEY_PRES;
    if (KEYD_PRESS_COUNT >= short_press_time && KEYD_PRESS_COUNT <= long_press_time)
      KEYD_KEY_READ = DOWN_KEY_PRES;
    if (KEYD_PRESS_COUNT >= long_press_time)
      KEYD_KEY_READ = DOWN_KEY_LONG_PRES;
  }
  if (KEYD) {
    KEYD_PRESS_COUNT = 0;
    KEYD_UP = 0;//按键状态，0为弹起，1为按下
  }



  if (KEYU_KEY_READ == UP_KEY_PRES && KEYU_UP == 0) {
      Key_KEYU_UP();//上翻
    KEYU_KEY_READ = NO_KEY_PRES;
  }


  if (KEYM_KEY_READ == M_KEY_PRES && KEYM_UP == 0) {
      Key_KEYM_UP();//确认
    KEYM_KEY_READ = NO_KEY_PRES;
  }


  if (KEYD_KEY_READ == DOWN_KEY_PRES && KEYD_UP == 0) {
   
    
      Key_KEYD_UP();//下翻
      
    KEYD_KEY_READ = NO_KEY_PRES;
  }

  if (KEYU_KEY_READ == UP_KEY_LONG_PRES && KEYU_UP == 0) {
      Key_KEYU_LP_UP();//长按上翻
    KEYU_KEY_READ = NO_KEY_PRES;
  }
  if (KEYM_KEY_READ == M_KEY_LONG_PRES && KEYM_UP == 0) {
     Key_KEYM_LP_UP();//长按确认
    KEYM_KEY_READ = NO_KEY_PRES;
  }
  if (KEYD_KEY_READ == DOWN_KEY_LONG_PRES && KEYD_UP == 0) {
     Key_KEYD_LP_UP();//长按下翻
    KEYD_KEY_READ = NO_KEY_PRES;
  }


  if(menu.Menu_page==2 & menu.Main_menu_inde1 ==1){
    String a1;
    String a2;
    String a3;
    String a4;
    String a5;
    String a6;
    String a7;
    String fileName;
    

    if(Switch_433.available()){
      a1 = "433_";
     // String stringOne = String(Switch_433.getReceivedValue(), HEX);
      a2 = String(Switch_433.getReceivedValue());
      a3 = dec2binWzerofill(Switch_433.getReceivedValue(),Switch_433.getReceivedBitlength());
      a4 = String(Switch_433.getReceivedDelay());//震荡
      a5 = String(Switch_433.getReceivedProtocol());//协议      
      a6 = String(Switch_433.getReceivedBitlength());
      a7 = String(RC_existence(a1 + a2));
      fileName = a1 + a2;

      if (Debug == false){Receiving_mode(fileName,a4);Switch_433.resetAvailable();RC_received(fileName,"433|" + a3 + "|" + a4 + "|" + a5);}
      if (Debug == true ){DebugPrintln("&1433|" + a2 + "|" + a6 + "|" + a3 + "|" + a4 + "|" + a5 + "|" + a7 +  "&2");}//调试模式

      }
      
    if(Switch_315.available()){
      
      a1 = "315_";
     // String stringOne = String(Switch_315.getReceivedValue(), HEX);
      a2 = String(Switch_315.getReceivedValue());
      a3 = dec2binWzerofill(Switch_315.getReceivedValue(),Switch_315.getReceivedBitlength());
      a4 = String(Switch_315.getReceivedDelay());//震荡
      a5 = String(Switch_315.getReceivedProtocol());//协议 
      a6 = String(Switch_315.getReceivedBitlength());
      a7 = String(RC_existence(a1 + a2));
      fileName = a1 + a2;
      if (Debug == false){Receiving_mode(fileName,a4);Switch_315.resetAvailable();RC_received(fileName,"315|" + a3 + "|" + a4 + "|" + a5);}
      if (Debug == true ){DebugPrintln("&1315|" + a2 + "|" + a6 + "|" + a3 + "|" + a4 + "|" + a5 + "|" + a7 +  "&2");}
      
      }
    
    }  

  if (menu.retrieval == false) {
    Menu_ion();
 //   memset(Arrayname, 0, sizeof Arrayname);
    Dir dir = LittleFS.openDir("/");

    List("[返回上级]");


    while (dir.next()) {
      List(dir.fileName());

      menu.FileRet = true;
      

    }
    
    
    
    for(int i = 0; i < myAnimalList.size(); i++){
       DebugPrint("文件：");
       DebugPrintln(retList(i));

      
      }
    DebugPrint(" 文件数：");
    DebugPrintln(myAnimalList.size());
    


    menu.retrieval = true;
  }


}
