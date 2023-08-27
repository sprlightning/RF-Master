struct Menu_structure {
  int Menu_page;//菜单页面判断 1,主菜单 2,接收菜单 3,发送菜单 4,AP模式 5,记录删除 6,删除页面菜单 7,系统设置页 8,初始化 9,内网调试
  int Main_menu_inde1;//主菜单索引 1,信号接收 2,发送模式 3,AP模式 4,记录删除 5,系统设置 6,内网调试，
  int Main_menu_inde2;//发送菜单索引
  int Main_menu_inde3;//AP模式索引
  int Main_menu_inde4;//全部文件删除页
  int Main_menu_inde5;//系统设置
  int page;//记录总共页面数 与二维数组对应
  int subscript ;//记录菜单最后的下标
  int Page_turning ;//记录翻页页数
  int Count;
  bool Wifi ;
  bool autoWifi;
  bool Power;
  bool serial; 
  bool Switch;//射频控制
  bool RC;
  bool udp;
  bool DebugBeginWifi;
  bool JsRf;
  int a3;
  int a4;  
  int Rolling;
} menu = {1, 2, 0, 0, 1, 1, 0, 0, 0, 0 , false, false, false, false, false, false, false, false, false, 0, 0, 0};




String ver = "v3.0";    //固件版本号

#include "Gr_DataSave.h"//文件存储调用  第1调用优先级
#include "Gr_display.h" //屏幕显示调用
#include "Gr_wifi.h"
#include "Gr_Switch.h"  //Switch
#include "Gr_Key.h"


