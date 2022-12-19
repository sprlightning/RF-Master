 /**
 * OLED SCL D1 io5
 * OLED SDA D2 io4
 * 433接收 D6 io12
 * 433发射 D0 io16
 * 315接收 D7 io13
 * 315发射 D8 io15
 * 上翻页  D3 io0
 * 确定键  D4 io2
 * 下翻页  D5 io14
 */

/*
 * 2.9
 * 1.修复后台网页数据数量超过30出现显示问题
 * 2.增加后台页面 上一页 下一页 跳转 网页数据数量显示等功能
 * 3.增加进入后台自动跳转控制（连接热点WiFi自动跳转后台 开启关闭控制）
 * 4.修复文件改备注名时，如果有重复名会直接覆盖的问题（当出现重复名字时会使用一个1至100的随机数加入到新的名字后面）
 * 5.增加设备初始化功能，与单独的删除所有文件不同，该初始化会删除所有文件，包括系统保存的配置文件
 * 6.改善屏幕息屏模式下误触的情况发生（只有在息屏的情况下才会触发防误触功能，当长按确认键息屏时防误触启动，当再次长按确认键息屏解除时防误触关闭）
 * 7.负优化，文件保存系统现在更加严谨，存储队列更加严格，但是存储速度相应降低
 * 8.增加自定义热点WiFi名称与开启热点WiFi密码功能（使用WiFi热点密码功能，密码位长度必须大于等于8位数 小于20位   当WiFi密码长度等于0时就不会开启WiFi密码功能，自定义WiFi热点名字不受影响）
 * 9.增加OTA固件更新功能（该功能目前测试中，稳定性未知）
 * 10.增加后台OTA升级页面（单独的请求页面，请求地址 http://192.168.4.1/update）
 * 11.增加后台设置页面（单独的请求页面，请求地址 http://192.168.4.1/set）
 * 12.优化发射菜单与删除菜单的显示bug（当数据超过100以后，3位数显示会与白边重合的问题，如果超过3位数了，我想就是要找某一个遥控信号也得半小时吧！！！）
 * 13.
 * 14.
 *  
2.9.3 更新发射模式为连续发射
操作方式：
按下确认发射键以后，进入连续发射，此时基本所有按键操作方式失效，板载led开始闪烁，一直闪烁为一直发射，解除发射需要按上键解除，如led还在闪烁需要大力按下上键解除，解除连续发射以后，所有按键恢复正常操作
 * 
 * 
 * .增加内网调试功能区（该功能需要上位机与内网WiFi支持）开发中~
 * .增加授时器
 * 
2.9.4 更新
 1.优化发射方法，重新定义按键检测方式抛弃 2.9.3的按键检测方式  其他操作与2.9.1一致 发射改为长按确认键1秒后连续发射 松开按键停止，在发射菜单页长按不会息屏，其他页面不影响
 2.修复发射的一个小bug （发射315信号有概率成为433信号的可能）
 */


//unsigned int TIME = 1440;
String ver = "v2.9.4";
#include "Gr_Define.h"

void setup() {
 DebugBegin(9600);
 u8g2.begin();   //初始化屏幕驱动
 u8g2.enableUTF8Print();
 ESP.wdtEnable(3000);

 if(rc.Begin() == 0){
  Tips();
  }else {
    //rc.Remov("System");
      
      pinMode(UP_KEY, INPUT_PULLUP);
      pinMode(M_KEY, INPUT_PULLUP);
      pinMode(DOWN_KEY, INPUT_PULLUP); 
         
      Switch_433.enableReceive(12);   // 接收器
      Switch_433.enableTransmit(16);  // 发送器
      Switch_315.enableReceive(13);   // 接收器
      Switch_315.enableTransmit(15);  // 发送器
      key_tick.attach_ms(1, flip);
      if(rc.GetSys_oled() == 1){u8g2.setDisplayRotation(U8G2_R2);}
      if(rc.GetSys_cartoon() == 1){Boot_logo_animation();}
      Main_menu(menu.Main_menu_inde1);
    
      RC_FS();
      //com_ota();
    
//    if(rc.GetSys_Time() < TIME){
//    
//    
//
//
//    }else {
//      //授时器超时7天失效
//      Tips2(); //函数提醒授权时间失效
//      com_ota();
//      RC_FS();
//      }
 
  }
 
 
}

void loop() {  
if (menu.a1 == true){
  menu.a1 = false;
  com_ota();
  } 
if(menu.a2 == true){
    if (agreement == "0") { Switch_433.setProtocol(menu.a4); Switch_433.setPulseLength(menu.a3);Switch_433.setRepeatTransmit(1); Switch_433.send(Base.c_str()); }
    if (agreement == "1") { Switch_315.setProtocol(menu.a4); Switch_315.setPulseLength(menu.a3);Switch_315.setRepeatTransmit(1); Switch_315.send(Base.c_str()); } 
}
                        
if (menu.Wifi == true) {
      if(rc.GetSys_Jump() == 1){
         dnsServer.processNextRequest();//dns跳转处理
        }
       webServer.handleClient(); //WEB处理函数
       MDNS.update();  
  }
/*------------------------------------------------------------------------------------------------------------------------*/   
if (menu.udp == true) {
  webServer.handleClient(); //WEB处理函数
  MDNS.update();   //MNDS服务
  int packetSize = Udp.parsePacket();
  if (packetSize){
    // 收到Udp数据包
    //Serial.printf("收到Udp数据包 %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0){incomingPacket[len] = 0;}
    String data = incomingPacket;
    String Issue = data.substring(0,2);//获取下发指令
    
    if(Issue == "10"){
       String ID = "ID" + String(ESP.getChipId())+ ver;
       Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
       Udp.write(ID.c_str());
       Udp.endPacket();
       //上位机连接扫描应答
      }

     if(Issue == "11"){
         String FileName = "RF11" + String(myAnimalList.size()-1);
         Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
         Udp.write(FileName.c_str());
         Udp.endPacket();
          }
      if(Issue == "12"){
         String quantity = data.substring(2,7);//分离下发指令 获取文件编号指令
         if(myAnimalList.size() > 0){
         String FileName = retList(quantity.toInt());
         String DataPacket = "RF12" + data.substring(0,7) + "$|" + FileName + "|$" + rc.Read(FileName) ;//使用特定包头 将下发文件指令上传到上位机
         Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
         Udp.write(DataPacket.c_str());
         Udp.endPacket();
         }
          
        }
       if(Issue == "13"){ menu.Switch = true;  menu.RC = true; }
       if(Issue == "14"){ menu.Switch = false; menu.RC = false;} 
       if(Issue == "15"){ ESP.restart(); }
       if(Issue == "16"){ 
           DebugPrint("在线发射测试：");
           DebugPrintln(data.substring(2));
           String agreement =  rc.RfDate("agreement",data.substring(2));
           String Base = rc.RfDate("Base2",data.substring(2));
           String shock = rc.RfDate("shock",data.substring(2));
           String Protocol = rc.RfDate("Protocol",data.substring(2));
           int a2 = atoi(shock.c_str());//震荡值
           int a3 = atoi(Protocol.c_str());//协议
           if (agreement == "0") { Switch_433.setProtocol(a3); Switch_433.setPulseLength(a2); Switch_433.send(Base.c_str()); }
           if (agreement == "1") { Switch_315.setProtocol(a3); Switch_315.setPulseLength(a2); Switch_315.send(Base.c_str()); }
         }
       if(Issue == "17"){ 
        for (int i = 0; i < data.length(); i++){
          if(data.substring(i,i+1) == "{"){
            String promote;
            String FileName = data.substring(2 , i );//取名字
            String DataJson = data.substring(i);
            int Save = rc.File_Json( FileName , DataJson );
            if (Save == 0){promote = "RF17设备文件保存失败";}
            if (Save == 1){promote = "RF17设备文件保存成功";List(FileName);}
            if (Save == 2){promote = "RF17设备文件已存在";}
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write(promote.c_str());
            Udp.endPacket();            
            break;
            }
          }
        }
       if(Issue == "18"){ 
            String DataJson = rc.GetSystem();
            String DataSys = "Sy" + DataJson;
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write(DataSys.c_str());
            Udp.endPacket();          
        }
       if(Issue == "19"){ rc.Set_System(data.substring(2));
            String DataSys = "RF19系统设置成功！";
            Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
            Udp.write(DataSys.c_str());
            Udp.endPacket(); 
        } 
       if(Issue == "20"){
        String FileName;String DataJson;
        for (int i = 0; i < data.length(); i++){
          if(data.substring(i,i+1) == "{"){
            FileName = data.substring(7 , i );//取名字
            DataJson = data.substring(i);
            break;
            }
          }
          DebugPrint(FileName);
          DebugPrintln(DataJson);

         rc.File_Json1( FileName , DataJson );
         String quantity = data.substring(2,7);//分离下发指令 获取文件编号指令
     //    String FileName = retList(quantity.toInt());
         String DataPacket = "RF20" + data.substring(0,7) + "$|" + FileName + "|$设备回应---->接收成功！";//使用特定包头 将下发文件指令上传到上位机
         List(FileName);
         Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
         Udp.write(DataPacket.c_str());
         Udp.endPacket();
        
        
        }

  } //packetSize Udp数据包
 }  //menu.udp == true
}   //loop
void RC_FS(){
  //文件枚举
   // Menu_ion();
 //   memset(Arrayname, 0, sizeof Arrayname);
    Dir dir = LittleFS.openDir("/");

    List("[返回上级]");


    String filename;
    while (dir.next()) {
      filename = dir.fileName();
      //DebugPrintln(filename);
      if(filename != "System"){List(filename);}
//      menu.FileRet = true;
      
    }
}
