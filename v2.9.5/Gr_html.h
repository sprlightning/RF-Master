String HTML(){
             String html;
             html = "";
             html += "<!DOCTYPE html>\n <html>\n";
             html += "<meta charset=\"UTF-8\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
             html += "<title>315/433射频管家</title>\n";
             html += "</head>\n";
             html += "<body style='margin:0;padding:0'>\n";
             html += "<p style='color: green; text-align:center; font-size:28px' > ";
             html += "控制中心";
             html += "</p>\n";
             
            // html += "<p style='color: #130c0e; text-align:center; font-size:24px' > ";
             
            // html += "</br> 尊敬的QQ: 1778747708 用户";
             //html += "</br> ";
            // html += "<p style='color: #130c0e; text-align:center; font-size:22px' > ";
            // html += "</br> 欢迎使用";
            // html += "</br> ";
             html += "<p style='color: blue; text-align:center; font-size:24px' > ";
             html += "<a href=\"/\">点击 进入射频管家控制中心</a> ";
             
            // html += "<p style='color: blue; text-align:left; font-size:16px' > ";
            // html += "</br> 总存储空间： " + String(fs_info.totalBytes) + " Bytes";
            // html += "</br> 已用空间： " + String(fs_info.usedBytes) + " Bytes";

             html += "</p></body></html>";
             return html;}
String responseHTML()
{
  String html;
  html = "";
  html += "<!DOCTYPE html>\n <html>\n";
  html += "<meta charset=\"UTF-8\">" ;
  html += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> ";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<title>315/433射频管家</title>\n";
  html += "<head>\n";
  html += "<style>\n";
  
  html += ".button1 {";
  html += "width: 48px;";
  html += "height: 24px;";
  html += "text-align: center;";
  html += "background-color: #1d953f;";
 // html += "background: url("+modify+") no-repeat;";
  html += "color: white;";
  html += "border: 1px solid #1d953f;";
  html += "border-radius:10px;";
  html += "}";
  html += ".button2 {";
  html += "width: 48px;";
  html += "height: 24px;";
  html += "text-align: center;";
  html += "background-color: #017AFF;";
  html += "color: white;";
  html += "border: 1px solid #017AFF;";
  html += "border-radius:10px;";
  html += "}";
  html += ".button3 {";
  html += "width: 48px;";
  html += "height: 24px;";
  html += "text-align: center;";
  html += "background-color: #d93a49;";
  html += "color: white;";
  html += "border: 1px solid #d93a49;";
  html += "border-radius:10px;";
  html += "}";  
  
  html += ".button4 {";
  html += "width: 63px;";
  html += "height: 24px;";
  html += "text-align: center;";
  html += "background-color: #FFFFFF;";
  html += "color: #130c0e;";
  html += "border: 1px solid #f58220;";
  html += "border-radius:10px;";
  html += "}";  

  
  html += ".span-3 {";
  html += "        padding: 4px 4px;";
  html += "        text-align: right;";
  html += "        background-color: #FFFFFF;";
  html += "        margin: 0.5rem 0.2rem 1rem 0.2rem;";
  html += "        border-radius:6px;";
  html += "}";
  html += "p{";
  html += "        margin:0px 0";
  html += "} ";
  html += ".span-3 td {";
  html += "        top: 1rem;";
  html += "text-align: left;";
  html += "border-bottom:2px solid rgb(239,239,239);";
  html += "}";  

  html += ".span-4 {";
  html += "        padding: 4px 4px;";
  html += "        text-align: right;";
  html += "        background-color: #FFFFFF;";
  html += "        margin: 0.5rem 0.2rem 1rem 0.2rem;";
  html += "        border-radius:6px;";
  html += "}";

  html += ".span-4 td {";
  html += "        top: 0rem;";
  html += "text-align: left;";
 // html += "border-bottom:2px solid rgb(239,239,239);";
  html += "}"; 

   
  html += "</style>\n";
  html += "</head>\n";
  
  html +="<body style='margin:0;padding:0' bgcolor=\"#E6E7E9\">\n";
  html +="<h1 style=\"display:inline;\">&nbsp;射频管家 </h1>";
  html +="<h5 style=\"display:inline; color: #464547;\">" + ver + "</h5>";
  
  html +="<div class=\"span-3\">"; 
  html +="<table style=\"border-collapse: collapse; width: 100%;\">";
  html +="       <thead>";
  html +="         <tr>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         </tr>";
  html +="       </thead>";
  
  html +="       <tbody>";
  String FileName;
  
  for(int i = Max; i < myAnimalList.size(); i++){
    
    
    if(i > Max + 15){break;}
        FileName = retList(i);
        html += "<form mothod=\"get\" >";
        html += "<tr>"; 
      //  html += "<td>&nbsp;</td>";        
        html += "<td><p style=\"font-size:18px\">" + String(i) + "</p></td>";
        html += "<td>";
        html += "<input style=\"background:transparent;border:1px solid #ffffff;font-size:18px;top: 4px;width: 140px; padding:0px 2px;\" name=\"newname\" value="+ FileName + ">";
        html += "<p style=\"font-size:12px\">&nbsp;" + rc.RetRF("Base10",rc.Read(FileName))+ "/" + rc.RetRF("shock",rc.Read(FileName))+ "</p>";
        html += "</td>";

        html += "<td><button name=\"Rename\" value=" + FileName + " type=\"submit\" class=\"button1\">修改</button></td>";        
        html += "<td><button name=\"Launch\" value=" + FileName + " type=\"submit\" class=\"button2\">发射</button></td>";
        html += "<td><button name=\"Delete\" value=" + FileName + " type=\"submit\" class=\"button3\">删除</button></td>";
        html += "</tr></form>"; 

      }  

                   
  html += "       </tbody>";
  html += "</table>";
  html += "</div>";


if(myAnimalList.size() > 16){
  
  html +="<div class=\"span-4\">"; 
  html +="<table style=\"border-collapse: collapse; width: 100%;\">";
  html +="       <thead>";
  html +="         <tr>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         <th></th>";
  html +="         </tr>";
  html +="       </thead>";
  
  html +="       <tbody>";

  html += "<form mothod=\"get\" >";
  html += "<tr>"; 
      //  html += "<td>&nbsp;</td>";        
  html += "<td><button name=\"reduce\" value=上一页 type=\"submit\" class=\"button4\">上一页</button></td>";       

  html += "<td> &nbsp;&nbsp;"+String(int(ceil(Max / 15)) + 1)+"/" + String(int(ceil(myAnimalList.size() / 15)) + 1) + "&nbsp;&nbsp;</td>";
  
  html += "<td>";   
  html += "<input style=\"background:transparent;border:1px solid #ffffff;font-size:16px;top: 4px;width: 85px; padding:0px 2px;text-align: center; \" name=\"Jumpname\" pattern=[0-9]* value="+String(int(ceil(Max / 15)) + 1)+">";
  html += "</td>";
 
       
  html += "<td><button name=\"Jump\" value=跳转 type=\"submit\" class=\"button4\">跳转</button></td>";
  html += "<td><button name=\"plus\" value=下一页 type=\"submit\" class=\"button4\">下一页</button></td>";
  html += "</tr></form>"; 
                
  html += "       </tbody>";
  html += "</table>";
  html += "</div>"; 

}

     
  html += "作者<果仁>创作作品";

  
  html += "</body>";
  html += "</html>\n";


  return html;

}

const String SetForm =   "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\
  <html xmlns=\"http://www.w3.org/1999/xhtml\">\
  <head>\
  <style type=\"text/css\">\
  INPUT {font-size:20px};\
  TEXTAREA{font-size:20px};\
  Button {font-size :20px};\
  </style>\
  <meta name=\"viewport\" content=\"width=320px, user-scalable=no, initial-scale=1, maximum-scale=1\">\
  <title>8266 Set</title>\
  </head>\
  <body>\
  <form action=\"weatherset\" method=\"post\" enctype=\"application/x-www-form-urlencoded\">\
    <table width=\"0\" border=\"0\">\
    <tr>\
      <td> AP SSID:</td>\
      <td><input name=\"SSID\" type=\"text\" /></td>\
    </tr>\
    <tr>\
      <td>AP Password:</td>\
      <td><input name=\"password\" type=\"password\" /></td>\
    </tr>\
    <tr>\
      <td> </td>\
    </tr>\
    <tr>\
      <td>Key:</td>\
      <td><input name=\"Key\" type=\"text\" /></td>\
    </tr>\
    <tr>\
      <td>City:</td>\
      <td><input name=\"City\" type=\"text\" /></td>\
    </tr>\
  </table>\
  <input name=\"submitOK\" type=\"submit\" value=\"Set\" />\
  </form>\
  </body>\
  </html>";
  
void homepage() {
  String newname = webServer.arg("newname");      //修改的文件名字
  String Rename = webServer.arg("Rename");        //改名指令
  String Launch = webServer.arg("Launch");        //发射指令
  String Delete = webServer.arg("Delete");        //删除指令
  String reduce = webServer.arg("reduce");        //上一页
  String plus = webServer.arg("plus");        //下一页
  String Jump = webServer.arg("Jump");        //下一页
  if (Jump.length() > 0){
    String Jumpname = webServer.arg("Jumpname");
    if (Jumpname.length() > 0){
    int a = atoi(Jumpname.c_str());
    int b = int(ceil(myAnimalList.size() / 15)) + 1;
    if(a > b){a = b;}
    
    Max = a * 15 - 14;
     }
    }
  
  if (reduce.length() > 0){
    Max = Max - 15;
    if(Max < 1){Max = 1;}
    
    }
  if (plus.length() > 0){
    Max = Max + 15;
    if(Max > myAnimalList.size()){Max = Max - 15;}
    
    }

  
  if (Rename.length() > 0) {
    
    String newname = webServer.arg("newname");
    DebugPrint("被改名字 ");
    DebugPrintln(newname);

    if (newname.length() > 0) {
     if(Rename != newname){
      //该方式防止网页重复提交刷新命令导致一直改名
      
        while (rc.Existence(newname) == 1){ 
          newname = newname + String(random(1,100));
         }
      DebugPrintln(rc.Existence(newname));
      DebugPrintln( newname );
        /**
       * newname = 新文件名字
       * Rename  = 被修改文件名字
       * 1.先读出被修改文件数据 json数据
       * 2.删除被修改文件的文件
       * 3.把读出的数据保存成新的数据文件
       */
      
      String Json = rc.Read(Rename);
      rc.Remov(Rename);
      DeleString(Rename);
      RenameList(Rename, newname); 
      rc.File_Json1( newname ,  Json );
      List(newname);
         
     }
    }
   }
  
  if (Launch.length() > 0) {
     Eft(Launch);
    }
  if (Delete.length() > 0) {
    DeleString(Delete);
    rc.Remov(Delete);
   // LittleFS.remove(Delete);
    
  }
  
  webServer.send(200, "text/html", responseHTML());
}
void handleSet()                            //打开网页设置页面
{
  webServer.send(200, "text/html", SetForm);

  
}

void Restart() {ESP.restart();}
