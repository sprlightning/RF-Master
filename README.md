
人生规划千万条，遵纪守法头一条。

射频管家不在维护，感谢大家的支持！

——————更新于2023年8月27日——————

因原作者（bug508）不再维护射频管家RF，所以我在此更新，并命名为RF-Master来加以区分；

一些问题：原作者的程序使用的是ESPAsyncWebServer.h，但是Arduino中能下载的是ESPAsyncWebSrv.h，另外原作者的程序存在string返回不完整的问题；

以上问题都会导致编译失败；解决方法就是新增一个库[ESPAsyncWebServer](https://github.com/sprlightning/ESPAsyncWebServer)，该库指向Arduino上的ESPAsyncWebSrv库；另外为缺失string返回值的函数增加返回值，用“return "";”即可；

这体现在3.0.1版本中，bug已修复，其中lib文件夹中的就是[ESPAsyncWebServer](https://github.com/sprlightning/ESPAsyncWebServer)库，需要用Arduino手动安装ZIP库的方式加载进去；
