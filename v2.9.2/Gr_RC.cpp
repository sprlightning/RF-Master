#include "Gr_RC.h"
#include <LittleFS.h>
#include <ArduinoJson.h>


//info(fs_info);

/*------------------------------------------------------------------------------------------------------------------------*/  
bool RC::Begin(){
  bool a = LittleFS.begin();
  if(a == 1){
    if(Existence("System") == 0 ){System(0,ESP.getChipId(),0,0,"","","","",0);}
    }
  
  return a;
}
/*------------------------------------------------------------------------------------------------------------------------*/  
int  RC::Existence(String filename){
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
/*------------------------------------------------------------------------------------------------------------------------*/  
int RC::File_save( String filename, String agreement , String Base10 , String Base2 , String shock , String Protocol) {
  int Random;
  int a = 0;
  Random =  Existence(filename);
  if (Random == 1) {a = 2;}
  if (Random == 0) {    
    StaticJsonDocument<400> jsonBuffer;
    jsonBuffer["agreement"] = agreement;
  //  jsonBuffer["Name"] = filename;
    jsonBuffer["Base10"] = Base10;
    jsonBuffer["Base2"] = Base2;
    jsonBuffer["shock"] = shock;
    jsonBuffer["Protocol"] = Protocol;
  
    String output;
    serializeJson(jsonBuffer, output);
    File file = LittleFS.open("/" + filename, "w");
    if (file.print(output)) { a = 1;} else { a = 0; }
    file.close();
  }
  return a;
}
/*------------------------------------------------------------------------------------------------------------------------*/  
int RC::File_Json(String filename , String Json ){
  int Random;
  int a = 0;
  Random =  Existence(filename);
  if (Random == 1) {a = 2;}
  if (Random == 0) {    
    File file = LittleFS.open("/" + filename, "w");
    if (file.print(Json)) { a = 1;} else { a = 0; }
    file.close();
   }
  return a;
  
  }
/*------------------------------------------------------------------------------------------------------------------------*/  
void RC::File_Json1(String filename , String Json ){
    File file = LittleFS.open("/" + filename, "w");
    file.print(Json);
    file.close();
   
  
  }
/*------------------------------------------------------------------------------------------------------------------------*/ 
String RC::Read(String filename){
  File  file = LittleFS.open( "/" + filename, "r");
  if (file) {
    String str;
    while (file.available()) {
      str += (char)file.read();
    }
    file.close();
    return str;
  } else { return ""; }
  
}
/*------------------------------------------------------------------------------------------------------------------------*/  
void RC::Rename (String filename1, String filename2){ 
  String json = Read(filename1);
  
  String agreement =  RetRF("agreement",json);
  String Base10 = RetRF("Base10",json);
  String Base2 = RetRF("Base2",json);
  String shock = RetRF("shock",json);
  String Protocol = RetRF("Protocol",json);
  LittleFS.remove(filename1);
  LittleFS.remove(filename2);

  File_save(filename2 , agreement , Base10  , Base2 , shock , Protocol);
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
void RC::Remov (String filename){LittleFS.remove(filename);}
/*------------------------------------------------------------------------------------------------------------------------*/  
String RC::RetRF(String type, String json){
   DynamicJsonDocument jsonBuffer(400);
   deserializeJson(jsonBuffer, json);
   JsonObject obj = jsonBuffer.as<JsonObject>();
   if(type == "agreement"){return obj["agreement"];}
//   if(type == "Name"){return obj["Name"];}
   if(type == "Base2"){return obj["Base2"];}
   if(type == "Base10"){return obj["Base10"];}
   if(type == "shock"){return obj["shock"];}
   if(type == "Protocol"){return obj["Protocol"];}  
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
void RC::System(int oled , int ID , int cartoon ,int Jump , String ssid , String password , String diyssid , String diypassword , unsigned int Time){
  LittleFS.remove("System");//不管文件存在还是不存在，都删除一次，然后在保存
  StaticJsonDocument<400> jsonBuffer;
    jsonBuffer["oled"] = oled;
    jsonBuffer["ID"] = ID;
    jsonBuffer["cartoon"] = cartoon;
    jsonBuffer["Jump"] = Jump;
    jsonBuffer["ssid"] = ssid;
    jsonBuffer["password"] = password;
    jsonBuffer["diyssid"] = diyssid;
    jsonBuffer["diypassword"] = diypassword;
    jsonBuffer["Time"] = Time;
    String output;
    serializeJson(jsonBuffer, output);
    File file = LittleFS.open("/System" , "w");
    file.print(output);
    file.close();
  
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
int RC::GetSys_oled(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["oled"];
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
int RC::GetSys_ID(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["ID"];
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
int RC::GetSys_cartoon(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["cartoon"];
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
String RC::GetSys_ssid(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["ssid"];
  }  
/*------------------------------------------------------------------------------------------------------------------------*/    
String RC::GetSys_password(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["password"];
  }  
/*------------------------------------------------------------------------------------------------------------------------*/    
String RC::GetSys_diyssid(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["diyssid"];
  }  
/*------------------------------------------------------------------------------------------------------------------------*/    
String RC::GetSys_diypassword(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["diypassword"];
  }  
/*------------------------------------------------------------------------------------------------------------------------*/ 
int RC::GetSys_Jump(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["Jump"];
  }  
/*------------------------------------------------------------------------------------------------------------------------*/ 
unsigned int RC::GetSys_Time(){
  String Json =  Read("System");
  //DebugPrintln(Json);
  DynamicJsonDocument jsonBuffer(400);
  deserializeJson(jsonBuffer, Json);
  JsonObject obj = jsonBuffer.as<JsonObject>();
  return obj["Time"];
  }
/*------------------------------------------------------------------------------------------------------------------------*/ 
void RC::Set_Time(unsigned int Time){
     System(GetSys_oled(),ESP.getChipId(),GetSys_cartoon(),GetSys_Jump(),GetSys_ssid(),GetSys_password(),GetSys_diyssid(),GetSys_diypassword(),Time);
} 
/*------------------------------------------------------------------------------------------------------------------------*/ 
String RC::DataJson(String agreement ,String Base10 , String Base2 , String shock , String Protocol){
    StaticJsonDocument<300> jsonBuffer;
    jsonBuffer["agreement"] = agreement;
    jsonBuffer["Base10"] = Base10;
    jsonBuffer["Base2"] = Base2;
    jsonBuffer["shock"] = shock;
    jsonBuffer["Protocol"] = Protocol;
  
    String output;
    serializeJson(jsonBuffer, output);
    return output;
  
  }
/*------------------------------------------------------------------------------------------------------------------------*/ 
String RC::RfDate(String type, String json){
   DynamicJsonDocument jsonBuffer(300);
   deserializeJson(jsonBuffer, json);
   JsonObject obj = jsonBuffer.as<JsonObject>();
   if(type == "agreement"){return obj["agreement"];}
   if(type == "Base2"){return obj["Base2"];}
   if(type == "shock"){return obj["shock"];}
   if(type == "Protocol"){return obj["Protocol"];}  
  }
/*------------------------------------------------------------------------------------------------------------------------*/   
String RC::GetSystem(){
  String Json =  Read("System");
  return Json;
  }
/*------------------------------------------------------------------------------------------------------------------------*/    
void RC::Set_System(String json){
   DynamicJsonDocument jsonBuffer(400);
   deserializeJson(jsonBuffer, json);
   JsonObject obj = jsonBuffer.as<JsonObject>();
   String oled = obj["oled"];
   String cartoon = obj["cartoon"];
   String Jump = obj["Jump"];

   System( oled.toInt() , ESP.getChipId() , cartoon.toInt() , Jump.toInt() , GetSys_ssid() , GetSys_password() , obj["diyssid"] , obj["diypassword"] , GetSys_Time());


  
  }



  
