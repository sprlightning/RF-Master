#include <LittleFS.h>       //文件存储库
#include "Gr_LinkedList.h"  //链表 修改版
#include <ArduinoJson.h>
FSInfo fs_info;



class Animal {
public:
  char *name;
  char *Base10;
  bool isMammal;
};

Linked<Animal *> myAnimalList = Linked<Animal *>();
String Read(String filename);
bool Get_Exis(String filename);
void Set_System(bool oled, bool cartoon, bool Jump, String ssid, String password, String diyssid, String diypassword, String espdhcp, String ip, int wg0pin, int wg1pin, int wg2pin, int wg3pin, int Rolling);

//文本分割
String fenge(String str, String fen, int index) {
  int weizhi;
  String temps[str.length()];
  int i = 0;
  do {
    weizhi = str.indexOf(fen);
    if (weizhi != -1) {
      temps[i] = str.substring(0, weizhi);
      str = str.substring(weizhi + fen.length(), str.length());
      i++;
    } else {
      if (str.length() > 0)
        temps[i] = str;
    }
  } while (weizhi >= 0);

  if (index > i) return "-1";
  return temps[index];
}
//-------初始化存储---------
bool DateBegin() {
  bool a = LittleFS.begin();
  LittleFS.info(fs_info);
  if (!Get_Exis("System") && a) {
    Set_System(false, true, false, "", "", "", "", "esp-spgj", "192.168.4.1", 12 , 16 , 13 , 15,10);
  }
  return a;
}


int Get_wg0pin() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["wg0pin"];
}
int Get_wg1pin() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["wg1pin"];
}
int Get_wg2pin() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["wg2pin"];
}
int Get_wg3pin() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["wg3pin"];
}
int Get_Rolling() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["Rolling"];
}

//=====================================================================
void Set_wg0pin(int pin) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["wg0pin"] = pin;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
void Set_wg1pin(int pin) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["wg1pin"] = pin;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
void Set_wg2pin(int pin) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["wg2pin"] = pin;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
void Set_wg3pin(int pin) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["wg3pin"] = pin;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
void Set_Rolling(int pin) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["Rolling"] = pin;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}





//-------文件读取---------
String Read(String filename) {
  File file = LittleFS.open("/" + filename, "r");
  if (file) {
    String str;
    while (file.available()) {
      str += (char)file.read();
    }
    file.close();
    return str;
  } else {
    return "";
  }
}

//--------读取屏幕反转开关--------
bool Get_reverse() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["oled"];
}

//--------读取logo动画开关--------
bool Get_logo() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["logo"];
}
//--------读取页面跳转开关--------
bool Get_Jump() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["Jump"];
}

//--------读取espdhcp--------
String Get_espdhcp() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["espdhcp"];
}
//--------读取espdhcp--------
String Get_ip() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["ip"];
}
//--------文件是否存在--------
bool Get_Exis(String filename) {
  File f = LittleFS.open(filename, "r");
  return f;
}

//--------设置系统文件--------
void Set_System(bool oled, bool logo, bool Jump, String ssid, String password, String diyssid, String diypassword, String espdhcp, String ip,int wg0pin, int wg1pin, int wg2pin, int wg3pin, int Rolling) {
  LittleFS.remove("System");
  StaticJsonDocument<400> jsonBuffer;
  jsonBuffer["oled"] = oled;
  jsonBuffer["logo"] = logo;
  jsonBuffer["Jump"] = Jump;
  jsonBuffer["ssid"] = ssid;
  jsonBuffer["password"] = password;
  jsonBuffer["diyssid"] = diyssid;
  jsonBuffer["diypassword"] = diypassword;
  jsonBuffer["espdhcp"] = espdhcp;
  jsonBuffer["ip"] = ip;
  jsonBuffer["wg0pin"] = wg0pin;
  jsonBuffer["wg1pin"] = wg1pin;
  jsonBuffer["wg2pin"] = wg2pin;
  jsonBuffer["wg3pin"] = wg3pin;
  jsonBuffer["Rolling"] = Rolling;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}

//--------设置屏幕反转--------
void Set_reverse(bool reverse) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["oled"] = reverse;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}

//--------设置logo动画开启关闭--------
void Set_logo(bool logo) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["logo"] = logo;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
//--------设置espdhcp--------
void Set_espdhcp(String espdhcp) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["espdhcp"] = espdhcp;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
//--------设置ip--------
void Set_ip(String ip) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["ip"] = ip;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
//--------设置 wifi--------
void Set_wifi(String ssid, String password) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["ssid"] = ssid;
  obj["password"] = password;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}

//--------设置自定义 wifi--------
void Set_diywifi(String diyssid, String diypassword) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["diyssid"] = diyssid;
  obj["diypassword"] = diypassword;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
//--------获取自定义 wifi名--------
String Get_diyssid() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["diyssid"];
}

//--------获取自定义 wifi密码--------
String Get_diypassword() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["diypassword"];
}
//--------获取 wifi--------
String Get_ssid() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["ssid"];
}
//--------获取 wifi密码--------
String Get_password() {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["password"];
}
//--------设置自动跳转--------
void Set_Jump(bool Jump) {
  String Json = Read("System");
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  obj["Jump"] = Jump;
  String output;
  serializeJson(jsonBuffer, output);
  File file = LittleFS.open("/System", "w");
  file.print(output);
  file.close();
}
//添加名字到链表
void List(String Str) {
  char *str;
  const int len = Str.length();
  str = new char[len + 1];

  strcpy(str, Str.c_str());
  Animal *cat = new Animal();

  cat->name = str;
  cat->isMammal = true;
  myAnimalList.add(cat);
}
//添加名字到链表
void List1(String Str, String Str1) {
  char *str;
  char *str1;
  const int len = Str.length();
  const int len1 = Str1.length();
  str = new char[len + 1];
  str1 = new char[len1 + 1];

  strcpy(str, Str.c_str());
  strcpy(str1, Str1.c_str());
  Animal *cat = new Animal();

  cat->name = str;
  cat->Base10 = str1;
  cat->isMammal = true;
  myAnimalList.add(cat);
}
//删除链表数据
void DeleList(int i) {

  myAnimalList.remove(i);
}
//根据索引取文件名字
String retList(int i) {
  char *str;
  Animal *animal;
  animal = myAnimalList.get(i);
  if (animal->isMammal) {
    str = animal->name;
    return str;
  }
  return "";//返回空字符，不然会编译失败
}
//根据索引取10进制数据
String Get_ListBase10(int i) {
  char *str;
  Animal *animal;
  animal = myAnimalList.get(i);
  if (animal->isMammal) {
    str = animal->Base10;
    return str;
  }
  return "";//返回空字符，不然会编译失败
}
//链表根据名字删除数据
void DeleString(String Str) {

  for (int i = 0; i < myAnimalList.size(); i++) {
    if (retList(i) == Str) { DeleList(i); }
  }
}
//链表根据名字修改数据 文件名 10进制数据
void RenameList(String Str, String Str1) {

  for (int i = 0; i < myAnimalList.size(); i++) {
    if (retList(i) == Str) {
      char *str;
      const int len = Str1.length();
      str = new char[len + 1];

      strcpy(str, Str1.c_str());
      Animal *cat = new Animal();

      cat->name = str;
      cat->isMammal = true;
      myAnimalList.set(i, cat);
    }
  }
}
//删除文件
void Deledata(String filename) {
  LittleFS.remove(filename);
}

//10转2进制
static char *dec2binWzerofill(unsigned long Dec, unsigned int bitLength) {
  static char bin[64];
  unsigned int i = 0;

  while (Dec > 0) {
    bin[32 + i++] = ((Dec & 1) > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }

  for (unsigned int j = 0; j < bitLength; j++) {
    if (j >= bitLength - i) {
      bin[j] = bin[31 + i - (j - (bitLength - i))];
    } else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';

  return bin;
}
//自动补齐
String Complement(String data , int frequency) {
  String text;
  for (int i = 0; i < frequency - data.length(); i++) {
    text = text + "0";
  }
  return text + data;
}
//文件保存
bool File_save(String filename, String pattern , String Base10 , int Position , int Pulse , int Protocol) {
  String output;
  output = pattern + Complement(String(Base10.length()) , 2) + Base10 +  Complement(String(Position) , 3)  + Complement(String(Pulse) , 5) + Complement(String(Protocol) , 2);
  DebugPrintln(output);

  File file = LittleFS.open("/" + filename, "w");
  bool state = file.print(output);
  if (state) {
    file.close();
    return true;
  } else {
    Deledata(filename);  //保存失败以后删除已经创建的文件夹
    file.close();
    return false;
  }
  return true;
}

//获取链表文件是否存在
bool Get_ListExis(String filename) {
  for (int i = 0; i < myAnimalList.size(); i++) {
    if (retList(i) == filename) {
      return true;
    }
  }
  return false;
}

//获取链表10进制是否存在
bool Get_ListExisBase10(String filename) {
  for (int i = 0; i < myAnimalList.size(); i++) {
    if (Get_ListBase10(i) == filename) {
      return true;
    }
  }
  return false;
}

//获取链表10进制=》文件名
String Get_ListBase10_Name(String filename) {
  for (int i = 0; i < myAnimalList.size(); i++) {
    if (Get_ListBase10(i) == filename) {
      return retList(i);
    }
  }
  return "";
}
//读取链表10进制数据
String Base10_1(String filename){
  String data = Read(filename); 
  String Base10_length = data.substring(2,4);
  String Base10 = data.substring(4 , Base10_length.toInt() + 4);
  return Base10;
}
