#ifndef Gr_RC_H
#define Gr_RC_H
#include "Arduino.h"
//#include <LittleFS.h>
//#include <ArduinoJson.h>

class RC {
  
   public:
 
   bool Begin(); 
   //库初始化   返回1 启动成功  返回0启动失败
   
   int  Existence(String filename);
   //文件是否存在 返回0 表示无文件 返回1表示文件存在
   
   int  File_save( String filename, String agreement , String Base10 , String Base2 , String shock , String Protocol);
   /**文件保存  返回0 表示保存失败 返回1表示保存成功 返回2表示文件存在
    * 参数1: 欲保存文件名字
    * 参数2：发射协议 {1,433 2,315 3,多文件}
    * 参数3：10进制数据
    * 参数4：2进制数据
    * 参数5：震荡
    * 参数6：协议
    * 
    */
   int File_Json(String filename , String Json );
   void File_Json1(String filename , String Json );
   String Read(String filename);
   //文件读取 成功返回读取到的json数据， 失败返回空文本
   
   void Rename (String filename1, String filename2);
   // 文件改名  原名字 ， 需要改的名字
   
   void Remov (String filename);
   // 文件删除  文件名
   
   String RetRF(String type, String json);
   //读取数据 参数1 数据类型  参数2json数据

   void System(int oled , int ID , int cartoon ,int Jump , String ssid , String password , String diyssid , String diypassword , unsigned int Time);
   /**
    * 保存系统设置
    * 1.屏幕反转控制
    * 2.设备id
    * 3.开机动画控制
    * 4.web跳转设置
    * 5.WiFi ssid
    * 6.WiFi 密码
    * 7.diy WiFi ssid
    * 8.diy WiFi 密码
    * 9.授时器
    */
   int GetSys_oled();           //屏幕
   int GetSys_ID();             //设备id
   int GetSys_cartoon();        //开机动画
   int GetSys_Jump();           //Web跳转设置     
   String GetSys_ssid();        //WiFi ssid
   String GetSys_password();    //WiFi 密码
   String GetSys_diyssid();     //diy WiFi ssid
   String GetSys_diypassword(); //diy WiFi 密码
   unsigned int GetSys_Time();
   void Set_Time(unsigned int Time) ; 
   String DataJson(String agreement , String Base10 , String Base2 , String shock , String Protocol);
   String RfDate(String type, String json);
   String GetSystem();
   void Set_System(String json);
  
    };





















#endif
