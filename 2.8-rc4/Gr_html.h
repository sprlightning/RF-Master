String HTML = ""
              "<!DOCTYPE html>\n <html>\n"
              "<meta charset=\"UTF-8\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
              "<title>315/433射频管家</title>\n"
              "</head>\n"
              "<body style='margin:0;padding:0'>\n"
              "<p style='color: green; text-align:center; font-size:20px' > "
              "控制中心"
              "</p>\n"
              "<a href=\"/\">点击 进入射频管家控制中心</a> "
              "<p style='color: blue; text-align:center; font-size:20px' > "
              "</p></body></html>";
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
  html += "padding: 1px 4px;";
  html += "text-align: center;";
  html += "background-color: #4CAF50;";
  html += "color: white;";
  html += "border: 1px solid #4CAF50;";
  html += "border-radius:10px;";
  html += "}";
  html += ".button2 {";
  html += "padding: 1px 4px;";
  html += "text-align: center;";
  html += "background-color: #017AFF;";
  html += "color: white;";
  html += "border: 1px solid #017AFF;";
  html += "border-radius:10px;";
  html += "}";
  html += "</style>\n";
  html += "</head>\n";
  html += "<body style='margin:0;padding:0'>\n";
  html += "<p style='color: green; text-align:center; font-size:20px' > ";
  html += "射频管家控制中心";
  html += "</p>\n";
  html += "<table border= \"1\" celllspacing=\"0\"  width=\"100%\">";
  html += "<tr> <td>名称</td> <td>改快捷名称及指令操作</td> </tr>";
  Dir dir = LittleFS.openDir("/");
  String FileName;
  while (dir.next()) {
    FileName = dir.fileName();
    html += "<tr ></tr>";
    html += "<form mothod=\"post\" >";
    html += "<td>" + FileName + " </td>";
    html += "<td><input placeholder=\"请输入\"  name=\"newname\"/>";
    html += "<button name=\"Rename\" value=" + FileName + " type=\"submit\" class=\"button1\">改名</button>";
    html += "<button name=\"Launch\" value=" + FileName + " type=\"submit\" class=\"button1\">发射</button>";
    html += "<button name=\"Delete\" value=" + FileName + " type=\"submit\" class=\"button1\">删除</button>";
    html += "</td></form>";
  }

  html += "</table>";
  html += "<p>\n";
  html += "<form mothod=\"post\" target=\"framename\">";
  html += "<button name=\"Refresh\" value=刷新 type=\"submit\" class=\"button2\">▶网页手动刷新◀</button></br> </form>\n";
  html += "<form mothod=\"post\" target=\"framename\">";
  html += "<button name=\"Reboot\" value=重启 type=\"submit\" class=\"button2\">▶设备硬件重启◀</button>";
  html += "</br> 将对设备进行重启操作</form>";
  html += "<form mothod=\"post\" target=\"framename\">";
  html += "<button name=\"Format\" value=格式化 type=\"submit\" class=\"button2\">▶设备初始化◀</button>";
  html += "</br> 将对设备内部已保存射频数据进行格式化操作</form>";

  html += "</body>";
  html += "</html>\n";


  return html;

}

void homepage() {
  String newname = webServer.arg("newname");      //修改的文件名字
  String Reboot = webServer.arg("Reboot");        //重启
  String Format = webServer.arg("Format");        //格式化
  String Rename = webServer.arg("Rename");        //改名指令
  String Launch = webServer.arg("Launch");        //发射指令
  String Delete = webServer.arg("Delete");        //删除指令
  String Refresh = webServer.arg("Refresh");      //网页手动刷新


  if (Rename.length() > 0) {
    if (newname.length() > 0) {
      RenameList(Rename, newname);
      RC_rename(Rename, newname);
      


    }

  }
  if (Launch.length() > 0) {
     Eft(Launch);
    }
  if (Delete.length() > 0) {
    DeleString(Delete);
    LittleFS.remove(Delete);
    


  }
  if (Reboot.length() > 0) {

    ESP.restart();


  }
  if (Format.length() > 0) {
    myAnimalList.clear();
    List("[返回上级]");
    LittleFS.format();
    
  }
  
  if (Refresh.length() > 0) {
    webServer.send(200, "text/html", responseHTML());
  }

  webServer.send(200, "text/html", responseHTML());
}
