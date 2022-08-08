#include <U8g2lib.h>
#include "Gr_ascii.h"

int first =2;//程序版本号
int tail  =8;//程序版本号

//1.3OLED 屏幕
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//0.96OLED 屏幕
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/5, /* data=*/4, /* reset=*/U8X8_PIN_NONE);

void Boot_logo_animation(){
  for (int a = 0; a < 10; a++){int b=0;int c=0;int e=0;
    u8g2.firstPage();
      do {
          for(int i = 0; i < 4; i++){ b=b+16;u8g2.drawXBM(13+b,18,16,16,day[i]);}
          if (a > 3){for(int i = 0; i < 7; i++){ c=c+8;u8g2.drawXBM(13+8+c,34,8,16,letter[i]);}
          u8g2.drawXBM(112,0,6,12,number[first]);u8g2.drawXBM(118,0,6,12,number[10]);u8g2.drawXBM(122,0,6,12,number[tail]);} 
          if (a > 4 & a < 7){u8g2.drawBox(88,46, 3, 3);}
          if (a > 6 & a < 9){u8g2.drawBox(88,46, 3, 3);u8g2.drawBox(94,46, 3, 3);}
          if (a > 8){u8g2.drawBox(88,46, 3, 3);u8g2.drawBox(94,46, 3, 3);u8g2.drawBox(100,46, 3, 3);}
          }while (u8g2.nextPage()); //画面加载完毕；
   delay(300);}}

void Main_menu(int inde){
  int a=0;int b=0;int C=0;int e=0;int f=0;
  if(inde==1){a=10;}if(inde==2){a=26;}if(inde==3){a=42;}if(inde==4){a=59;} 
  u8g2.firstPage();
  do {
    for(int i = 0; i < 4; i++)  {u8g2.drawXBM(25,i*16,7,14,Main[i]);u8g2.drawXBM(34,i*16,7,14,Main[4]);}//1234
    for(int i = 7; i < 11; i++) {b=b+14;u8g2.drawXBM(29+b,0,14,14,Main[i]);}//信号接收
    for(int i = 11; i < 15; i++){C=C+14;u8g2.drawXBM(29+C,16,14,14,Main[i]);}//发送模式
    for(int i = 5; i < 7; i++)  {f=f+7; u8g2.drawXBM(40+f,32,7,14,Main[i]);}//ap
    for(int i = 13; i < 15; i++){f=f+14;u8g2.drawXBM(36+f,32,14,14,Main[i]);}//模式
    for(int i = 15; i < 19; i++){e=e+14;u8g2.drawXBM(29+e,48,14,14,Main[i]);}//记录删除
  u8g2.setFont(u8g2_font_open_iconic_all_1x_t);u8g2.drawGlyph(7, a, 111); }while (u8g2.nextPage());//画面加载完毕；
  
  }
void Tips(){
  int b=0;int C=0;
  u8g2.firstPage();
  do {
    u8g2.drawRFrame(2, 5, u8g2.getDisplayWidth() - 4 , u8g2.getDisplayHeight() - 10,  8);
    for(int i = 2; i < 7; i++){ b=b+16;u8g2.drawXBM(13+b,12,16,16,day[i]);}//管家提醒
    for(int i = 19; i < 27; i++) {C=C+14;u8g2.drawXBM(-5+C,35,14,14,Main[i]);}//当前没有射频数据
   }while (u8g2.nextPage());

  
  }
void Receiving_mode (String fun0_s1, String zd){
  int b=0;int c=0;int e=0;int f=0;int g=0;
  String a1;
  u8g2.firstPage();
   do {

     u8g2.drawBox(0, 0, u8g2.getDisplayWidth(), 15);
     for(int i = 0; i < 5; i++){ b=b+12;u8g2.drawXBM(-4+b,2,12,12,Receiv_ing[i]);}//【返回上级
     for(int i = 5; i < 9; i++){ b=b+12;u8g2.drawXBM(2+b,2,12,12,Receiv_ing[i]);}//确认键】
     u8g2.setFont(u8g2_font_6x13_tr);//u8g2_font_wqy12_t_gb2312a  u8g2_font_wqy12_t_chinese1
     u8g2.setCursor(-2, 21); u8g2.print("----------------------------");
     if(fun0_s1 != ""){
      for(int i = 18; i < 21; i++){ c=c+12;u8g2.drawXBM(-12+c,18,12,12,Receiv_ing[i]);}//新保存
      u8g2.drawXBM(2+c,19,12,12,Receiv_ing[31]);u8g2.setCursor(45 , 29);u8g2.print(fun0_s1);
      
      
      
      
//      for(int i = 23; i < 25; i++){ e=e+12;u8g2.drawXBM(-12+e,32,12,12,Receiv_ing[i]);}//震荡
//      u8g2.drawXBM(1+e,33,12,12,Receiv_ing[31]);u8g2.setCursor(34 , 43);u8g2.print(zd);
//      
//      for(int i = 27; i < 29; i++){ e=e+12;u8g2.drawXBM(22+e,32,12,12,Receiv_ing[i]);}//键值
//      u8g2.drawXBM(34+e,33,12,12,Receiv_ing[31]);
//      f=0;
//      a1=stringOne.substring(4,6);
//      sscanf(a1.c_str(), "%x", &f);
//      u8g2.setCursor(88 , 43);u8g2.print(f);
//      
//      for(int i = 25; i < 27; i++){ g=g+12;u8g2.drawXBM(-12+g,45,12,12,Receiv_ing[i]);}//地址1
//      u8g2.drawXBM(2+g,46,6,12,number[18]);u8g2.drawXBM(7+g,46,12,12,Receiv_ing[31]);
//      f=0;
//      a1=stringOne.substring(2,4);
//      sscanf(a1.c_str(), "%x", &f);
//      u8g2.setCursor(39 , 56);u8g2.print(f);
//
//      for(int i = 25; i < 27; i++){ g=g+12;u8g2.drawXBM(22+g,45,12,12,Receiv_ing[i]);}//地址2
//      u8g2.drawXBM(2+g,46,6,12,number[19]);u8g2.drawXBM(7+g,46,12,12,Receiv_ing[31]);
//      f=0;
//      a1=stringOne.substring(0,2);
//      sscanf(a1.c_str(), "%x", &f);
//      u8g2.setCursor(90 , 56);u8g2.print(f);      


      
      
      } else {for(int i = 36; i < 40; i++){ 
        c=c+14;
        u8g2.drawXBM(8+c,30,14,14,Main[i]);
        u8g2.drawBox(83,41, 3, 3);u8g2.drawBox(89,41, 3, 3);u8g2.drawBox(95,41, 3, 3);}}
     
     
    // u8g2.setCursor(5 , 30);u8g2.print("Aa： "); u8g2.print(fun0_s1);
     //u8g2.setCursor(5, 45); u8g2.print("频率： ");u8g2.print(Mhz);

  
   }while (u8g2.nextPage());
  } 

void page_2(int inde) {

  uint8_t h;int a1;
  u8g2_uint_t w;
  u8g2.firstPage();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
  w = u8g2.getDisplayWidth();
  
  
 
  do {
  
  u8g2.drawBox(0, 0, w, 15);
  u8g2.setDrawColor(0);
  if(menu.Menu_page == 3){u8g2.setCursor(6, 12); u8g2.print("【 发射菜单 】");u8g2.print(" " + String(myAnimalList.size()-1));}
  if(menu.Menu_page == 5){u8g2.setCursor(6, 12); u8g2.print("【 删除菜单 】");u8g2.print(" " + String(myAnimalList.size()-1));}
  
  u8g2.setDrawColor(1);
  
  

  for (int i = 0; i < 4; i++) {
   if(i+inde < myAnimalList.size()){
    u8g2.drawBox(0, 15+ ( 12 * i), 17, 15);
    u8g2.setDrawColor(0);
    u8g2.setCursor(2, 27 + ( 12 * i));u8g2.print(String(i+inde));
    u8g2.setDrawColor(1);
    
    u8g2.setCursor(29, 27 + ( 12 * i)); 
    u8g2.print( retList(i+inde));//String((menu.Count ) + i) + "." +
    
    }

    
    }
 

    
  u8g2.setFont(u8g2_font_open_iconic_all_1x_t);u8g2.drawGlyph(18, 26, 111);
   }while (u8g2.nextPage());

}
void html_Ol(int inde){
  int b=0;int c=0;int e=0;
  
  u8g2.firstPage();
   do {
    u8g2.drawBox(0, 0, u8g2.getDisplayWidth(), 16);
    if(menu.Wifi == false){
      for(int i = 27; i < 31; i++) {b=b+7;u8g2.drawXBM(10+b,1,7,14,Main[i]);}//wifi
      for(int i = 9; i < 11; i++) {c=c+12;u8g2.drawXBM(11+c,21,12,12,Receiv_ing[i]);}//开启
      for(int i = 12; i < 14; i++) {c=c+6;u8g2.drawXBM(26+c,22,6,12,number[i]);}//ap
      u8g2.drawXBM(34+c,23,6,12,number[11]);
      for(int i = 14; i < 18; i++) {c=c+6;u8g2.drawXBM(39+c,22,6,12,number[i]);}//wifi
      
      u8g2.drawXBM(16+b,1,14,14,Main[31]);u8g2.drawXBM(32+b,1,14,14,Main[32]);u8g2.drawXBM(46+b,1,14,14,Main[35]);u8g2.drawXBM(60+b,1,14,14,Main[34]);}
    if(menu.Wifi == true){
      for(int i = 27; i < 31; i++) {b=b+7;u8g2.drawXBM(10+b,1,7,14,Main[i]);}//wifi
      for(int i = 11; i < 13; i++) {c=c+12;u8g2.drawXBM(11+c,21,12,12,Receiv_ing[i]);}//关闭
      for(int i = 12; i < 14; i++) {c=c+6;u8g2.drawXBM(26+c,22,6,12,number[i]);}//ap
      u8g2.drawXBM(34+c,23,6,12,number[11]);
      for(int i = 14; i < 18; i++) {c=c+6;u8g2.drawXBM(39+c,22,6,12,number[i]);}//wifi
      u8g2.drawXBM(16+b,1,14,14,Main[31]);u8g2.drawXBM(32+b,1,14,14,Main[32]);u8g2.drawXBM(46+b,1,14,14,Main[35]);u8g2.drawXBM(60+b,1,14,14,Main[33]);} 
      
    for(int i = 13; i < 18; i++) {e=e+12;u8g2.drawXBM(11+e,35,12,12,Receiv_ing[i]);}//返回主菜单      
    u8g2.setFont(u8g2_font_6x12_tn); 
    u8g2.setCursor(-2, 21); u8g2.print("-----------------------------");

    u8g2.setFont(u8g2_font_open_iconic_all_1x_t);
    if (inde == 0){u8g2.drawGlyph(5, 31, 111);}
    if (inde == 1){u8g2.drawGlyph(5, 45, 111);}    
    
     }while (u8g2.nextPage());
   
  }

  
