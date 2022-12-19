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
unsigned int timecnt;
unsigned int timecnt1; 
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
     if(menu.a2 == false){

       Key_KEYU_UP();

     }else {
      menu.a2 = false;
      pinMode(M_KEY, INPUT_PULLUP);

      }
      //上翻
    KEYU_KEY_READ = NO_KEY_PRES;
  }


  if (KEYM_KEY_READ == M_KEY_PRES && KEYM_UP == 0) {
      Key_KEYM_UP();//确认
    KEYM_KEY_READ = NO_KEY_PRES;
  }


  if (KEYD_KEY_READ == DOWN_KEY_PRES && KEYD_UP == 0) {
    if(menu.a2 == false){
      Key_KEYD_UP();
    }

      Key_KEYD_UP();//下翻
      
    KEYD_KEY_READ = NO_KEY_PRES;
  }

  if (KEYU_KEY_READ == UP_KEY_LONG_PRES && KEYU_UP == 0) {
     if(menu.a2 == false){
      Key_KEYU_LP_UP();//长按上翻
     }
    KEYU_KEY_READ = NO_KEY_PRES;
  }
  if (KEYM_KEY_READ == M_KEY_LONG_PRES && KEYM_UP == 0) {
     if(menu.a2 == false){
     Key_KEYM_LP_UP();//长按确认
     }
    KEYM_KEY_READ = NO_KEY_PRES;
  }
  if (KEYD_KEY_READ == DOWN_KEY_LONG_PRES && KEYD_UP == 0) {
     if(menu.a2 == false){
     Key_KEYD_LP_UP();//长按下翻
     }
    KEYD_KEY_READ = NO_KEY_PRES;
  } 
  

/*------------------------------------------------------------------------------------------------------------------------*/  
if(menu.Switch == true){
  
  String Value;String Base2;String Delay;String Protocol;String fileName;String promote;
  if(Switch_433.available()){
    
    Value = String(Switch_433.getReceivedValue());
    Base2 = dec2binWzerofill(Switch_433.getReceivedValue(),Switch_433.getReceivedBitlength());
    Delay = String(Switch_433.getReceivedDelay());//震荡
    Protocol = String(Switch_433.getReceivedProtocol());//协议        
    fileName = "433_" + Value;
    if(menu.RC == false){
        int Save = rc.File_save( fileName , "0" , Value , Base2 , Delay , Protocol );//返回0 表示保存失败 返回1表示保存成功 返回2表示文件存在
        if (Save == 0){promote = "文件保存失败";}
        if (Save == 1){promote = "文件保存成功"; List(fileName);}
        if (Save == 2){promote = "文件已存在";}
        Receiving_mode(fileName,promote);
     }
    if(menu.RC == true){
      String FileName = "RF13" + rc.DataJson( "0" ,Value , Base2 , Delay , Protocol);
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(FileName.c_str());
      Udp.endPacket();
      }
    
    Switch_433.resetAvailable();
    }
    
  if(Switch_315.available()){ 
    Value = String(Switch_315.getReceivedValue());
    Base2 = dec2binWzerofill(Switch_315.getReceivedValue(),Switch_315.getReceivedBitlength());
    Delay = String(Switch_315.getReceivedDelay());//震荡
    Protocol = String(Switch_315.getReceivedProtocol());//协议        
    fileName = "315_" + Value;
    if(menu.RC == false){
       int Save = rc.File_save( fileName , "1" , Value , Base2 , Delay , Protocol );
       if (Save == 0){promote = "文件保存失败";}
       if (Save == 1){promote = "文件保存成功"; List(fileName);}
       if (Save == 2){promote = "文件已存在";}
       Receiving_mode(fileName,promote);
     }
    if(menu.RC == true){
      String FileName = "RF13" + rc.DataJson( "1" , Value , Base2 , Delay , Protocol);
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(FileName.c_str());
      Udp.endPacket();
      }
         
    Switch_315.resetAvailable();    
    }

  

  }
  
//timecnt = millis() / 1000 / 60;
//    if(timecnt > timecnt1){
//        timecnt1 = timecnt;
//        rc.Set_Time(rc.GetSys_Time() + 1);
//        DebugPrint("设备在线时长累计 = ");
//        DebugPrint(rc.GetSys_Time()); 
//        DebugPrintln(" 分钟");
//        if(rc.GetSys_Time() > TIME){ESP.restart();}
//     
//      }

/*------------------------------------------------------------------------------------------------------------------------*/  

 
}
