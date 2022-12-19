//上翻
void Key_KEYU_UP() {
//  DebugPrintln("上翻");
  if(menu.Power == false){
     if (menu.Menu_page == 1) {if (--menu.Main_menu_inde1 < 1) {menu.Main_menu_inde1  = 6;} Main_menu(menu.Main_menu_inde1);}
     if (menu.Menu_page == 4) {if (--menu.Main_menu_inde3 < 0) {menu.Main_menu_inde3  = 1;} html_Ol(menu.Main_menu_inde3);}
     if (menu.Menu_page == 6 or menu.Menu_page == 8) {if (--menu.Main_menu_inde4 < 0) {menu.Main_menu_inde4  = 1;} Delete_all(menu.Main_menu_inde4); }
     if (menu.Menu_page == 7) {if (--menu.Main_menu_inde5 < 1) {menu.Main_menu_inde5  = 5;} SysOled(menu.Main_menu_inde5); }
  
     if (menu.Menu_page == 3 or menu.Menu_page == 5) {
         --menu.Main_menu_inde2;
// DebugPrint("下翻索引：");
     
     //DebugPrintln(menu.Main_menu_inde2);
     if(menu.Main_menu_inde2 < 0){menu.Main_menu_inde2 = myAnimalList.size()-1;}
       page_2(menu.Main_menu_inde2);
      }
    }

   
  }
//下翻
void Key_KEYD_UP() {
  if(menu.Power == false){
  if (menu.Menu_page == 1) {if (++menu.Main_menu_inde1 > 6) {menu.Main_menu_inde1  = 1; } Main_menu(menu.Main_menu_inde1);}
  if (menu.Menu_page == 4) {if (++menu.Main_menu_inde3 > 1 ) {menu.Main_menu_inde3  = 0;} html_Ol(menu.Main_menu_inde3);}
  if (menu.Menu_page == 6 or menu.Menu_page == 8) {if (++menu.Main_menu_inde4 > 1) {menu.Main_menu_inde4  = 0;} Delete_all(menu.Main_menu_inde4); } 
  if (menu.Menu_page == 7) {if (++menu.Main_menu_inde5 > 5) {menu.Main_menu_inde5  = 1;} SysOled(menu.Main_menu_inde5); } 
  if (menu.Menu_page == 3 or menu.Menu_page == 5) {
     ++menu.Main_menu_inde2;
     //DebugPrint("下翻索引：");
     
    // DebugPrintln(menu.Main_menu_inde2);
     if(menu.Main_menu_inde2 == myAnimalList.size()){menu.Main_menu_inde2 = 0;}
     page_2(menu.Main_menu_inde2);
   }
  }
}
//确认
void Key_KEYM_UP() {
if(menu.Power == false){
/*------------------------------------------------------------------------------------------------------------------------*/   
 //如果页面=主菜单 并且 主菜单索引=1（接收菜单） 
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 1) {
    Switch_433.resetAvailable();  //进入接收菜单前清除串口数据
    Switch_315.resetAvailable();  //进入接收菜单前清除串口数据
    menu.Menu_page = 2;           //进入接收菜单
    Receiving_mode("","");        //菜单显示
    menu.Switch = true;
    return;} 
/*------------------------------------------------------------------------------------------------------------------------*/     
 //如果页面=主菜单 并且 主菜单索引=2（发射菜单）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 2) {
    menu.Menu_page = 3;  //进入发射菜单
         
    page_2(menu.Main_menu_inde2); //菜单显示
    return;}
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=主菜单 并且 主菜单索引=3（AP模式）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 3) {
    menu.Menu_page = 4;  //进入AP模式
    html_Ol(menu.Main_menu_inde3);
    return;}
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=主菜单 并且 主菜单索引=4（删除模式）    
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 4) {
    menu.Menu_page = 5;  //进入删除菜单
  
    page_2(menu.Main_menu_inde2);
    
    return;} 
/*------------------------------------------------------------------------------------------------------------------------*/ 
 //如果页面=主菜单 并且 主菜单索引=5（系统设置）      
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 5) {
    menu.Menu_page = 7;  //进入系统设置
    menu.Main_menu_inde5 = 1;
    SysOled (menu.Main_menu_inde5);
    //page_2(menu.Main_menu_inde2);
    
    return;} 
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=接收菜单 并且 主菜单索引=1（接收菜单） 
  if (menu.Menu_page == 2 & menu.Main_menu_inde1 == 1) {
    menu.Switch = false;
    menu.Menu_page = 1;             //页面=主菜单
    Main_menu(menu.Main_menu_inde1);//返回主菜单
    return;}
    
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=AP模式 并且 主菜单索引=3（AP模式） 并且2级菜单=1（返回上级）
  if (menu.Menu_page == 4 & menu.Main_menu_inde1 == 3 & menu.Main_menu_inde3 == 1) {
    menu.Menu_page = 1;  //返回主菜单
    menu.Main_menu_inde3 = 0;
    Main_menu(menu.Main_menu_inde1);
    return;}
    
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=AP模式 并且 主菜单索引=3（AP模式） 并且2级菜单=0（开启WiFi）    
  if (menu.Menu_page == 4 & menu.Main_menu_inde1 == 3 & menu.Main_menu_inde3 == 0) {
    //开启 关闭WiFi
    if (menu.Wifi == false) {
      if(rc.GetSys_Jump() == 1){
        
        Open_Wifi_Jump();
        }else {
          Open_Wifi_NoJump(); 
          }
      
      
      } else {
        if (menu.Wifi == true) {Close_Wifi();}
        }
         
        html_Ol(menu.Main_menu_inde3);
        return;
        }  
 
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=发射模式 并且 主菜单索引=2（发送模式） 
  if (menu.Menu_page == 3 & menu.Main_menu_inde1 == 2) {
    DebugPrint("光标位索引：");
    DebugPrint(menu.Main_menu_inde2);
    DebugPrint(" 取文件名：");
    DebugPrintln(retList(menu.Main_menu_inde2));
    
    if(menu.Main_menu_inde2 == 0){menu.Menu_page = 1; Main_menu(menu.Main_menu_inde1);}
    if(menu.Main_menu_inde2 > 0){
      //menu.a2 = true;
        String datajson = rc.Read(retList(menu.Main_menu_inde2));
        agreement = rc.RetRF("agreement", datajson);
        Base = rc.RetRF("Base2", datajson);
        shock = rc.RetRF("shock", datajson);
        Protocol = rc.RetRF("Protocol", datajson);
        menu.a3 = atoi(shock.c_str());
        menu.a4 = atoi(Protocol.c_str());
      //Eft(retList(menu.Main_menu_inde2));
      }
  
    return;} 
/*------------------------------------------------------------------------------------------------------------------------*/ 
//如果页面=删除模式 并且 主菜单索引=（删除模式）         
  if (menu.Menu_page == 5 & menu.Main_menu_inde1 == 4) {

    if(menu.Main_menu_inde2 == 0){menu.Menu_page = 1; Main_menu(menu.Main_menu_inde1); return;}
    if(menu.Main_menu_inde2 > 0){
      String Read_RF = retList(menu.Main_menu_inde2);
      rc.Remov(Read_RF);
      DeleList(menu.Main_menu_inde2);
      if(menu.Main_menu_inde2 == myAnimalList.size()){--menu.Main_menu_inde2;}
      
    }
   
    page_2(menu.Main_menu_inde2);
    return;} 
/*------------------------------------------------------------------------------------------------------------------------*/ 
 //如果页面=删除页面菜单 
  if(menu.Menu_page == 6){
    if(menu.Main_menu_inde4 == 0){
     int GetSys_oled = rc.GetSys_oled();
     int GetSys_cartoon = rc.GetSys_cartoon();
     int GetSys_Jump = rc.GetSys_Jump();
     String GetSys_ssid = rc.GetSys_ssid();
     String GetSys_password = rc.GetSys_password();
     String GetSys_diyssid = rc.GetSys_diyssid();
     String GetSys_diypassword = rc.GetSys_diypassword();
     unsigned int GetSys_Time = rc.GetSys_Time();
     LittleFS.format();
     u8g2.clear();
     myAnimalList.clear();
     List("[返回上级]");
     
     rc.System(GetSys_oled,ESP.getChipId(),GetSys_cartoon,GetSys_Jump,GetSys_ssid,GetSys_password,GetSys_diyssid,GetSys_diypassword,GetSys_Time);
     
     menu.Menu_page = 1;
     Main_menu(menu.Main_menu_inde1);
     menu.Main_menu_inde2 = 0;
     menu.Main_menu_inde4 = 1;
     return;
      }
      
     if(menu.Main_menu_inde4 == 1){    
     menu.Menu_page = 1;  //返回主菜单
     menu.Main_menu_inde4 = 1;
     menu.Main_menu_inde2 = 0;
     Main_menu(menu.Main_menu_inde1);
     return;}
    }       
/*------------------------------------------------------------------------------------------------------------------------*/
 //如果页面=系统设置菜单 
 if(menu.Menu_page == 7 & menu.Main_menu_inde5 == 1){
    menu.Menu_page = 1;  //返回主菜单
    menu.Main_menu_inde5 = 1;
    Main_menu(menu.Main_menu_inde1);
    return;} 
/*------------------------------------------------------------------------------------------------------------------------*/ 
 if(menu.Menu_page == 7 & menu.Main_menu_inde5 == 2){
   int GetSys_oled = rc.GetSys_oled();
   if(GetSys_oled == 1){GetSys_oled = 0;}else {GetSys_oled = 1;}
  
   rc.System(GetSys_oled,ESP.getChipId(),rc.GetSys_cartoon(),rc.GetSys_Jump(),rc.GetSys_ssid(),rc.GetSys_password(),rc.GetSys_diyssid(),rc.GetSys_diypassword(),rc.GetSys_Time());
   SysOled(menu.Main_menu_inde5);
   return;}
/*------------------------------------------------------------------------------------------------------------------------*/ 
 if(menu.Menu_page == 7 & menu.Main_menu_inde5 == 3){
   int GetSys_cartoon = rc.GetSys_cartoon(); 
   if(GetSys_cartoon == 1){GetSys_cartoon = 0;}else {GetSys_cartoon = 1;}
   rc.System(rc.GetSys_oled(),ESP.getChipId(),GetSys_cartoon,rc.GetSys_Jump(),rc.GetSys_ssid(),rc.GetSys_password(),rc.GetSys_diyssid(),rc.GetSys_diypassword(),rc.GetSys_Time());
   SysOled(menu.Main_menu_inde5);
   return;}
/*------------------------------------------------------------------------------------------------------------------------*/ 
 if(menu.Menu_page == 7 & menu.Main_menu_inde5 == 4){
   int GetSys_Jump = rc.GetSys_Jump(); 
   if(GetSys_Jump == 1){GetSys_Jump = 0;}else {GetSys_Jump = 1;}
   rc.System(rc.GetSys_oled(),ESP.getChipId(),rc.GetSys_cartoon(),GetSys_Jump,rc.GetSys_ssid(),rc.GetSys_password(),rc.GetSys_diyssid(),rc.GetSys_diypassword(),rc.GetSys_Time());
   SysOled(menu.Main_menu_inde5);
   return;}
/*------------------------------------------------------------------------------------------------------------------------*/ 
 if(menu.Menu_page == 7 & menu.Main_menu_inde5 == 5){
  menu.Menu_page = 8;
  Delete_all2(menu.Main_menu_inde4);
  
  return;}
/*------------------------------------------------------------------------------------------------------------------------*/ 
  if(menu.Menu_page == 8){
    if(menu.Main_menu_inde4 == 0){
     unsigned int GetSys_Time = rc.GetSys_Time();
     LittleFS.format();
     u8g2.clear();
     myAnimalList.clear();
     List("[返回上级]");
     
     rc.System(0,ESP.getChipId(),1,0,"","","","",GetSys_Time);
     
     menu.Menu_page = 1;
     Main_menu(menu.Main_menu_inde1);
     menu.Main_menu_inde2 = 0;
     menu.Main_menu_inde4 = 1;
     return;
      }
      
     if(menu.Main_menu_inde4 == 1){    
     menu.Menu_page = 1;  //返回主菜单
     menu.Main_menu_inde4 = 1;
     menu.Main_menu_inde2 = 0;
     Main_menu(menu.Main_menu_inde1);
     return;}    
    
    
    
    
    }
  
/*------------------------------------------------------------------------------------------------------------------------*/ 
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 6){
    menu.a1 = true;
    return;
    
    }
/*------------------------------------------------------------------------------------------------------------------------*/ 

/*------------------------------------------------------------------------------------------------------------------------*/ 

/*------------------------------------------------------------------------------------------------------------------------*/ 

/*------------------------------------------------------------------------------------------------------------------------*/
 
/*------------------------------------------------------------------------------------------------------------------------*/ 






      
  }
}
//长按上翻
void Key_KEYU_LP_UP() {
if(menu.Power == false){  
    if(menu.Menu_page != 1){
    menu.Menu_page = 1;             //页面=主菜单
    Main_menu(menu.Main_menu_inde1);//返回主菜单
    menu.Main_menu_inde2 = 0;
    }
  
  
  
  }
}  
//长按确认
void Key_KEYM_LP_UP() {
  if(menu.Power == false & menu.a2 == false){menu.Power = true;} else {menu.Power = false;} 
 // if(menu.Power == true){menu.Power = false;} 
  u8g2.setPowerSave(menu.Power);
  
    
  
  }
//长按下翻
void Key_KEYD_LP_UP() {
if(menu.Power == false){   
    if (menu.Menu_page == 5) {
      DebugPrint(myAnimalList.size());
     if(myAnimalList.size() > 1){
      menu.Menu_page = 6;
      Delete_all(menu.Main_menu_inde4);
      }
      
      
      
     }  
  
  
    }  
  }
