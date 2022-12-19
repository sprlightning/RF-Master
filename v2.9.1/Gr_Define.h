//以下三个定义为调试定义
#define DebugBegin(baud_rate)    Serial.begin(baud_rate)
#define DebugPrintln(message)    Serial.println(message)
#define DebugPrint(message)      Serial.print(message)


struct Menu_structure {
  int Menu_page;//菜单页面判断 1,主菜单 2,接收菜单 3,发送菜单 4,AP模式 5,记录删除 6,删除页面菜单 7,系统设置页 8,初始化 9,内网调试
  int Main_menu_inde1;//主菜单索引 1,信号接收 2,发送模式 3,AP模式 4,记录删除 5,系统设置 6,内网调试
  int Main_menu_inde2;//发送菜单索引
  int Main_menu_inde3;//AP模式索引
  int Main_menu_inde4;//全部文件删除页
  int Main_menu_inde5;//系统设置
  int page;//记录总共页面数 与二维数组对应
  int subscript ;//记录菜单最后的下标
  int Page_turning ;//记录翻页页数
  int Count;
  bool Wifi ;
  bool Power;
  bool serial; 
  bool Switch;//射频控制
  bool RC;
  bool udp;
  bool a1;
  
  } menu = {1, 2, 0, 0, 1, 1, 0, 0, 0, 0 , false, false, false, false, false, false, false};

#include "Gr_List.h"
#include "Gr_RC.h"
RC rc;



#include <LittleFS.h>
#include "Gr_OLED.h"
#include "Gr_Switch.h" 
#include "Gr_WiFi.h"        //wifi  
#include "Gr_Key.h"  
 
