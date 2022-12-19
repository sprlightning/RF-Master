#include "RCSwitch.h"
#include "TCSwitch.h"
RCSwitch Switch_433  = RCSwitch();
TCSwitch Switch_315 = TCSwitch();



void Eft(String Str) {
  String datajson = rc.Read(Str);

//  DebugPrintln(datajson);
  if (datajson != "") {
    String agreement = rc.RetRF("agreement", datajson);
    String Base = rc.RetRF("Base2", datajson);
    String shock = rc.RetRF("shock", datajson);
    String Protocol = rc.RetRF("Protocol", datajson);
    int a2 = atoi(shock.c_str());//震荡值
    int a3 = atoi(Protocol.c_str());//协议
        if (agreement == "0") { Switch_433.setProtocol(a3); Switch_433.setPulseLength(a2); Switch_433.send(Base.c_str()); }
        if (agreement == "1") { Switch_315.setProtocol(a3); Switch_315.setPulseLength(a2); Switch_315.send(Base.c_str()); }
  }


}
