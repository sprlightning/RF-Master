#include <LittleFS.h>

//当前库初始化 instantiate
void instantiate() {
  if (!LittleFS.begin()) {
    DebugPrintln("LittleFS未能启动");
  } else {
    DebugPrintln("LittleFS启动成功");
  }
}
//返回0 表示无文件 返回1表示文件存在
int RC_existence(String filename) {
  File  f = LittleFS.open(filename, "r");
  int a;
  if ( !f ) {
    a = 0;
  } else {
    a = 1;
  }
  f.close();
  return a;
}
//文件保存 received 参数1:欲保存文件名字 参数2：欲保存文件数据
void RC_received( String filename, String filename1) {
  int Random;
  Random =  RC_existence(filename);
  if (Random == 1) {
    //DebugPrintln("文件存在");
  } else if (Random == 0) {
    List(filename);//添加到链表
    File file = LittleFS.open("/" + filename, "w");
    
    
    if (file.print(filename1)) {
      
      //DebugPrintln("写入成功");
    } else {
      //DebugPrintln("写入失败");
    }
    delay(20);
    file.close();
  }
}

//文件读取 reading 参数1:文件名字
String RC_reading(String filename) {
  File  file = LittleFS.open( "/" + filename, "r");
  if (file) {
    String str;
    while (file.available()) {
      str += (char)file.read();
    }
    file.close();
    return str;
  }
}
// 文件改名  原名字 ， 需要改的名字
void RC_rename (String filename, String filename2) {
  LittleFS.rename(filename, filename2);
}
