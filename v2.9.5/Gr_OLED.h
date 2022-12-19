#include <U8g2lib.h>
#include "Gr_ascii.h"


int first =2;//程序版本号
int tail  =9;//程序版本号

//1.3OLED 屏幕
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//0.96OLED 屏幕
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/5, /* data=*/4, /* reset=*/U8X8_PIN_NONE);








void Boot_logo_animation(){
    for (int a = 0; a < 8; a++){int b=0;int c=0;int e=0;
    u8g2.firstPage();
      do {
          for(int i = 0; i < 4; i++){ b=b+16;u8g2.drawXBM(13+b,18,16,16,day[i]);}
          if (a > 2){
          u8g2.drawXBM(112,0,6,12,number[first]);
          u8g2.drawXBM(118,0,6,12,number[10]);
          u8g2.drawXBM(122,0,6,12,number[tail]);} 
          }while (u8g2.nextPage()); //画面加载完毕；
   delay(180);}
  
  }
void Tips(){
  int b=0;int C=0;
  u8g2.firstPage();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
  do {
    for(int i = 2; i < 7; i++){ b=b+16;u8g2.drawXBM(13+b,12,16,16,day[i]);}//管家提醒
    u8g2.setCursor(26, 42); u8g2.print("存储未能启动");
   }while (u8g2.nextPage());
  }
void Main_menu(int inde){
  int a=0;int b=0;int C=0;int e=0;int f=0;
  
  u8g2.firstPage();
  do {
    if(inde < 5){
    for(int i = 0; i < 4; i++)  {u8g2.drawXBM(25,i*16,7,14,Mainx14[i]);u8g2.drawXBM(34,i*16,7,14,Mainx14[10]);}//1234
    for(int i = 0; i < 4; i++)  {b=b+14;u8g2.drawXBM(29+b,0,14,14,Mainx28[i]);}//信号接收
    for(int i = 4; i < 8; i++)  {C=C+14;u8g2.drawXBM(29+C,16,14,14,Mainx28[i]);}//发送模式
    for(int i = 11; i < 13; i++){f=f+7; u8g2.drawXBM(40+f,32,7,14,Mainx14[i]);}//ap
    for(int i = 6; i < 8; i++)  {f=f+14;u8g2.drawXBM(36+f,32,14,14,Mainx28[i]);}//模式
    for(int i = 8; i < 12; i++) {e=e+14;u8g2.drawXBM(29+e,48,14,14,Mainx28[i]);}//记录删除
    }
    if(inde > 4){
      for(int i = 4; i < 6; i++)  {u8g2.drawXBM(25,(i - 4)*16,7,14,Mainx14[i]); u8g2.drawXBM(34,(i - 4)*16,7,14,Mainx14[10]);}//1234
      for(int i = 29; i < 33; i++) {b=b+14;u8g2.drawXBM(29+b,0,14,14,Mainx28[i]);}//系统设置 
      for(int i = 33; i < 37; i++) {C=C+14;u8g2.drawXBM(29+C,16,14,14,Mainx28[i]);}//内网调试 
      inde = inde - 4;
      }
      
  if(inde==1){a=10;}if(inde==2){a=26;}if(inde==3){a=42;}if(inde==4){a=59;}    
  u8g2.setFont(u8g2_font_open_iconic_all_1x_t);u8g2.drawGlyph(7, a, 111); }while (u8g2.nextPage());//画面加载完毕；
  
}

void html_Ol(int inde){
  int b=0;int c=0;int e=0;
  
  u8g2.firstPage();
   do {
    u8g2.drawBox(0, 0, u8g2.getDisplayWidth(), 16);
    if(menu.Wifi == false){
      for(int i = 13; i < 17; i++) {b=b+7;u8g2.drawXBM(10+b,1,7,14,Mainx14[i]);}//wifi
      for(int i = 0; i < 2; i++)   {c=c+12;u8g2.drawXBM(11+c,21,12,12,Receiv_ing[i]);}//开启
      for(int i = 12; i < 14; i++) {c=c+6;u8g2.drawXBM(26+c,22,6,12,number[i]);}//ap
      u8g2.drawXBM(34+c,23,6,12,number[11]);
      for(int i = 14; i < 18; i++) {c=c+6;u8g2.drawXBM(39+c,22,6,12,number[i]);}//wifi
      
      u8g2.drawXBM(16+b,1,14,14,Mainx28[20]);u8g2.drawXBM(32+b,1,14,14,Mainx28[21]);u8g2.drawXBM(46+b,1,14,14,Mainx28[24]);u8g2.drawXBM(60+b,1,14,14,Mainx28[23]);}
    if(menu.Wifi == true){
      for(int i = 13; i < 17; i++) {b=b+7;u8g2.drawXBM(10+b,1,7,14,Mainx14[i]);}//wifi
      for(int i = 2; i < 4; i++)   {c=c+12;u8g2.drawXBM(11+c,21,12,12,Receiv_ing[i]);}//关闭
      for(int i = 12; i < 14; i++) {c=c+6;u8g2.drawXBM(26+c,22,6,12,number[i]);}//ap
      u8g2.drawXBM(34+c,23,6,12,number[11]);
      for(int i = 14; i < 18; i++) {c=c+6;u8g2.drawXBM(39+c,22,6,12,number[i]);}//wifi
      u8g2.drawXBM(16+b,1,14,14,Mainx28[20]);u8g2.drawXBM(32+b,1,14,14,Mainx28[21]);u8g2.drawXBM(46+b,1,14,14,Mainx28[24]);u8g2.drawXBM(60+b,1,14,14,Mainx28[22]);}
      
    for(int i = 4; i < 9; i++) {e=e+12;u8g2.drawXBM(11+e,35,12,12,Receiv_ing[i]);}//返回主菜单      
    u8g2.setFont(u8g2_font_6x12_tn); 
    u8g2.setCursor(-2, 21); u8g2.print("-----------------------------");
   // u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    
   // u8g2.setCursor(23, 59);u8g2.print("192.168.4.1");
    
    u8g2.setFont(u8g2_font_open_iconic_all_1x_t);
    if (inde == 0){u8g2.drawGlyph(5, 31, 111);}
    if (inde == 1){u8g2.drawGlyph(5, 45, 111);}    
    
     }while (u8g2.nextPage());
   
}
void Delete_all(int inde){
  int b=0;int C=0;int e=0;
  u8g2.firstPage();
  do {
    u8g2.drawRFrame(2, 5, u8g2.getDisplayWidth() - 4 , u8g2.getDisplayHeight() - 10,  4);
    for(int i = 2; i < 7; i++){ b=b+16;u8g2.drawXBM(13+b,8,16,16,day[i]);}//管家提醒
    for(int i = 9; i < 17; i++) {C=C+12;u8g2.drawXBM(3+C,27,12,12,Receiv_ing[i]);}//是否删除全部数据
    for(int i = 17; i < 19; i++) {e=e+14;u8g2.drawXBM(12+e,43,12,12,Receiv_ing[i]);}//是否删除全部数据
    for(int i = 19; i < 21; i++) {e=e+14;u8g2.drawXBM(32+e,43,12,12,Receiv_ing[i]);}//是否删除全部数据
    u8g2.setFont(u8g2_font_open_iconic_all_1x_t);
    if (inde == 0){u8g2.drawGlyph(14, 53, 111);}
    if (inde == 1){u8g2.drawGlyph(64, 53, 111);}  

   }while (u8g2.nextPage());

  
}

void Delete_all2(int inde){
  int b=0;int C=0;int e=0;
  u8g2.firstPage();
  do {
    u8g2.drawRFrame(2, 5, u8g2.getDisplayWidth() - 4 , u8g2.getDisplayHeight() - 10,  4);
    for(int i = 2; i < 7; i++){ b=b+16;u8g2.drawXBM(13+b,8,16,16,day[i]);}//管家提醒
    for(int i = 9; i < 17; i++) {C=C+12;u8g2.drawXBM(3+C,27,12,12,Receiv_ing[i]);}//是否删除全部数据
    for(int i = 17; i < 19; i++) {e=e+14;u8g2.drawXBM(12+e,43,12,12,Receiv_ing[i]);}//是否删除全部数据
    for(int i = 19; i < 21; i++) {e=e+14;u8g2.drawXBM(32+e,43,12,12,Receiv_ing[i]);}//是否删除全部数据
    u8g2.setFont(u8g2_font_open_iconic_all_1x_t);
    if (inde == 0){u8g2.drawGlyph(14, 53, 111);}
    if (inde == 1){u8g2.drawGlyph(64, 53, 111);}  

   }while (u8g2.nextPage());

  
}  
void SysOled(int inde){
  int a=0;
  u8g2.firstPage();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
  String GetSys_oled;String GetSys_cartoon;String GetSys_Jump;
  
  if(rc.GetSys_oled() == 1){GetSys_oled = "屏幕反转  [已开启]";}else {GetSys_oled = "屏幕反转  [已关闭]";}
  if(rc.GetSys_cartoon() == 1){GetSys_cartoon = "开机动画  [已开启]";}else {GetSys_cartoon = "开机动画  [已关闭]";}
  if(rc.GetSys_Jump() == 1){GetSys_Jump = "页面跳转  [已开启]";}else {GetSys_Jump = "页面跳转  [已关闭]";}
    
  if(inde==1){a=10;}if(inde==2){a=22;}if(inde==3){a=36;}if(inde==4){a=48;}if(inde==5){a=60;}
  do { 
    
    u8g2.setCursor(22, 13 * 1 - 2); u8g2.print("[ >返回主页< ]");
    u8g2.setCursor(22, 13 * 2 - 2); u8g2.print(GetSys_oled);
    u8g2.setCursor(22, 13 * 3 - 2); u8g2.print(GetSys_cartoon);
    u8g2.setCursor(22, 13 * 4 - 2); u8g2.print(GetSys_Jump);
    u8g2.setCursor(22, 13 * 5 - 2); u8g2.print("设备初始化");
    u8g2.setFont(u8g2_font_open_iconic_all_1x_t);u8g2.drawGlyph(8, a, 111);
    
    }while (u8g2.nextPage());
}
void Receiving_mode (String fun0_s1,String fun0_s2){
  int b=0;int c=0;int e=0;int f=0;int g=0;
  String a1;
  u8g2_uint_t w;
  u8g2.firstPage();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
   do {
    
     w = u8g2.getDisplayWidth();
     u8g2.drawBox(0, 0, w, 15);
     u8g2.setDrawColor(0);
     u8g2.setCursor(10, 12); u8g2.print("【返回上级 确认键】");

     u8g2.setDrawColor(1);
     u8g2.setCursor(0, 21); u8g2.print("------------------------");

     if(fun0_s1 != ""){
            u8g2.setCursor(3 , 30);u8g2.print("文件: "); u8g2.print(fun0_s1);
            u8g2.setCursor(3 , 43);u8g2.print(fun0_s2); 
            u8g2.setCursor(3 , 56);u8g2.print("已保存数: "); u8g2.print(myAnimalList.size()-1);

      
      } else {for(int i = 25; i < 29; i++){ 
        c=c+14;
        u8g2.drawXBM(8+c,30,14,14,Mainx28[i]);
        u8g2.drawBox(83,41, 3, 3);u8g2.drawBox(89,41, 3, 3);u8g2.drawBox(95,41, 3, 3);}}
     


  
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
    u8g2.drawBox(0, 15 + ( 12 * i), 22, 15);
    u8g2.setDrawColor(0);
    u8g2.setCursor(2, 27 + ( 12 * i));u8g2.print(String(i+inde));
    u8g2.setDrawColor(1);
    
    u8g2.setCursor(36, 27 + ( 12 * i)); 
    u8g2.print( retList(i+inde));//String((menu.Count ) + i) + "." +
    
    }

    
  }
 

    
  u8g2.setFont(u8g2_font_open_iconic_all_1x_t);u8g2.drawGlyph(24, 26, 111);
   }while (u8g2.nextPage());

} 




void Tips2(){
  int b=0;int C=0;
  u8g2.firstPage();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
  do {
    for(int i = 2; i < 7; i++){ b=b+16;u8g2.drawXBM(13+b,12,16,16,day[i]);}//管家提醒
    u8g2.setCursor(26, 42); u8g2.print("授权时间到期");
   }while (u8g2.nextPage());
  }

void Debugging( String fun0_s1, String fun0_s2 , String fun0_s3 , String fun0_s4 ){
  int a=0;
  u8g2.firstPage();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
  do { 
    
    u8g2.setCursor(5, 13 * 1 - 2); u8g2.print("[ 网络调试 ]");
    u8g2.setCursor(5, 13 * 2 - 2); u8g2.print(fun0_s1);
    u8g2.setCursor(5, 13 * 3 - 2); u8g2.print(fun0_s2);
    u8g2.setCursor(5, 13 * 4 - 2); u8g2.print(fun0_s3);
    u8g2.setCursor(5, 13 * 5 - 2); u8g2.print(fun0_s4);


 //   u8g2.setFont(u8g2_font_open_iconic_all_1x_t);u8g2.drawGlyph(8, a, 111);
    
    }while (u8g2.nextPage());
}



  
