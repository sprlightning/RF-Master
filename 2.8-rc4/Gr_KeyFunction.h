//上翻
void Key_KEYU_UP() {
  //主菜单光标上翻
  if (menu.Menu_page == 1) {if (--menu.Main_menu_inde1 < 1) { menu.Main_menu_inde1  = 4;} Main_menu(menu.Main_menu_inde1);}
  if (menu.Menu_page == 4) {if (--menu.Main_menu_inde3 < 0) {menu.Main_menu_inde3  = 1;} html_Ol(menu.Main_menu_inde3);}

  if (menu.Menu_page == 3 or menu.Menu_page == 5) {
     --menu.Main_menu_inde2;
     DebugPrint("下翻索引：");
     
     DebugPrintln(menu.Main_menu_inde2);
     if(menu.Main_menu_inde2 < 0){menu.Main_menu_inde2 = myAnimalList.size()-1;}
     page_2(menu.Main_menu_inde2);
     
    
    

   }

    
    

  }



//确认
void Key_KEYM_UP() {
  DebugPrintln(menu.Main_menu_inde1);
 
  
//------------------------ 
//如果页面=主菜单 并且 主菜单索引=1（接收菜单） 
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 1) {
    Switch_433.resetAvailable();  //进入接收菜单前清除串口数据
    Switch_315.resetAvailable();  //进入接收菜单前清除串口数据
    menu.Menu_page = 2;           //进入接收菜单
    Receiving_mode("", "");       //菜单显示
    return;}
    
//------------------------
//如果页面=主菜单 并且 主菜单索引=2（发射菜单）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 2) {
    menu.Menu_page = 3;  //进入发射菜单
         
    page_2(menu.Main_menu_inde2); //菜单显示
    return;}
    
//------------------------
//如果页面=主菜单 并且 主菜单索引=3（AP模式）
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 3) {
    menu.Menu_page = 4;  //进入AP模式
    html_Ol(menu.Main_menu_inde3);
    return;}
    
//------------------------
//如果页面=主菜单 并且 主菜单索引=4（删除模式）    
  if (menu.Menu_page == 1 & menu.Main_menu_inde1 == 4) {
    menu.Menu_page = 5;  //进入删除菜单
  
    page_2(menu.Main_menu_inde2);
    return;}  
    
//------------------------
//如果页面=接收菜单 并且 主菜单索引=1（接收菜单） 
  if (menu.Menu_page == 2 & menu.Main_menu_inde1 == 1) {
 //   menu.retrieval = false;         //控制文件更新
   // delay(80);
    menu.Menu_page = 1;             //页面=主菜单
    Main_menu(menu.Main_menu_inde1);//返回主菜单
    return;}
    
//------------------------
//如果页面=AP模式 并且 主菜单索引=3（AP模式） 并且2级菜单=1（返回上级）
  if (menu.Menu_page == 4 & menu.Main_menu_inde1 == 3 & menu.Main_menu_inde3 == 1) {
    menu.Menu_page = 1;  //返回主菜单
    menu.Main_menu_inde3 = 0;
    Main_menu(menu.Main_menu_inde1);
    return;}
    
//------------------------
//如果页面=AP模式 并且 主菜单索引=3（AP模式） 并且2级菜单=0（开启WiFi）    
  if (menu.Menu_page == 4 & menu.Main_menu_inde1 == 3 & menu.Main_menu_inde3 == 0) {
    //开启 关闭WiFi
    if (menu.Wifi == false) {Open_Wifi(); } else {if (menu.Wifi == true) {Close_Wifi();}} html_Ol(menu.Main_menu_inde3);return;}  
    
//------------------------
//如果页面=发射模式 并且 主菜单索引=2（发送模式） 
  if (menu.Menu_page == 3 & menu.Main_menu_inde1 == 2) {
    DebugPrint("光标位索引：");
    DebugPrint(menu.Main_menu_inde2);
    DebugPrint(" 取文件名：");
    DebugPrintln(retList(menu.Main_menu_inde2));
    
    if(menu.Main_menu_inde2 == 0){menu.Menu_page = 1; Main_menu(menu.Main_menu_inde1);}
    if(menu.Main_menu_inde2 > 0){Eft(retList(menu.Main_menu_inde2));}
  
    return;} 
    
//------------------------    
//如果页面=删除模式 并且 主菜单索引=（删除模式）         
  if (menu.Menu_page == 5 & menu.Main_menu_inde1 == 4) {
   // String Read_RF = Arrayname[menu.Page_turning][menu.Main_menu_inde2 - 1];
  //  LittleFS.remove(Read_RF);
    if(menu.Main_menu_inde2 == 0){menu.Menu_page = 1; Main_menu(menu.Main_menu_inde1); return;}
    if(menu.Main_menu_inde2 > 0){
      String Read_RF = retList(menu.Main_menu_inde2);
      LittleFS.remove(Read_RF);
      DeleList(menu.Main_menu_inde2);
    }
   
    page_2(menu.Main_menu_inde2);
    return;} 
       

}



//下翻
void Key_KEYD_UP() {
    //主菜单光标下翻
  if (menu.Menu_page == 1) {if (++menu.Main_menu_inde1 > 4) {menu.Main_menu_inde1  = 1; } Main_menu(menu.Main_menu_inde1);}
  if (menu.Menu_page == 4) {if (++menu.Main_menu_inde3 > 1) {menu.Main_menu_inde3  = 0;} html_Ol(menu.Main_menu_inde3);}
  
  if (menu.Menu_page == 3 or menu.Menu_page == 5) {
     ++menu.Main_menu_inde2;
     DebugPrint("下翻索引：");
     
     DebugPrintln(menu.Main_menu_inde2);
     if(menu.Main_menu_inde2 == myAnimalList.size()){menu.Main_menu_inde2 = 0;}
     page_2(menu.Main_menu_inde2);
     
    
    

   }
  
  }




//长按上翻
void Key_KEYU_LP_UP() {
    if (menu.Menu_page == 3 or menu.Menu_page == 5 or menu.Menu_page == 4 or menu.Menu_page == 2) {
    menu.Menu_page = 1;
    u8g2.clear();
    delay(80);
    Main_menu(menu.Main_menu_inde1);
    menu.Main_menu_inde2 = 0;
  }
  }




//长按确认
void Key_KEYM_LP_UP() {}





//长按下翻
void Key_KEYD_LP_UP() {
    if (menu.Menu_page == 5) {
    menu.Menu_page = 1;
    LittleFS.format();
    u8g2.clear();
    myAnimalList.clear();
    List("[返回上级]");
    Main_menu(menu.Main_menu_inde1);
    menu.Main_menu_inde2 = 0;
  }
  }
