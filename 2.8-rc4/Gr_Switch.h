#include <RCSwitch.h>
#include <TCSwitch.h>
RCSwitch Switch_433  = RCSwitch();
TCSwitch Switch_315 = TCSwitch();

void Eft(String Str){
      /* 0.433/315判断
     * 1.2进制
     * 2.震荡值
     * 3.协议
     * 
    */
  String RF_data = RC_reading(Str);
  String a0 = fenge(RF_data,"|",0);//433/315判断
  String a1 = fenge(RF_data,"|",1);//2进制
  String a5 = fenge(RF_data,"|",2);//震荡值
  String a6 = fenge(RF_data,"|",3);//协议
  int a2 = atoi(a5.c_str());//震荡值
  int a3 = atoi(a6.c_str());//协议

  if(a0 == "433"){
    Switch_433.setProtocol(a3);
    Switch_433.setPulseLength(a2);
    Switch_433.send(a1.c_str());}
  
  if(a0 == "315"){
    Switch_315.setProtocol(a3);
    Switch_315.setPulseLength(a2);
    Switch_315.send(a1.c_str());}

  }
