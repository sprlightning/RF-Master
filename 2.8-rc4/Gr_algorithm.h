struct Menu_structure {
  int Menu_page;//菜单页面判断 1,主菜单 2,接收菜单 3,发送菜单 4,AP模式 5,记录删除
  int Main_menu_inde1;//主菜单索引 1,信号接收 2,发送模式 3,AP模式 4,记录删除
  int Main_menu_inde2;//发送菜单索引
  int Main_menu_inde3;//AP模式索引
  int page;//记录总共页面数 与二维数组对应
  int subscript ;//记录菜单最后的下标
  int Page_turning ;//记录翻页页数
 // int Min;
 // int Max;
  int Count;
  
  bool FileRet;
  bool retrieval ;
  bool Wifi ;
  bool T1 ;//特殊菜单 返回判断  比如无文件的提示界面

} menu = {1, 2, 0, 0, 0, 0, 0, 0,  false, false, false, false};
  
  
void Menu_ion(){
  //该函数 初始化各个记录参的数值使其恢复到开机前状态
 // menu.Main_menu_inde1 = 2;
  menu.Main_menu_inde2 = 0;
  menu.Main_menu_inde3 = 0;
  menu.page = 0;
  menu.Count = 0;
  menu.subscript = 0;
  menu.Page_turning = 0;menu.Page_turning = 0;

  menu.FileRet = false;
  menu.retrieval = false;
  
  }

//添加名字到链表 
void List (String Str){
    char *str; 
    const int len = Str.length();
    str =new char[len+1];
    
    strcpy(str,Str.c_str());    
    Animal *cat = new Animal();
      
    cat->name = str;
    cat->isMammal = true;
    myAnimalList.add(cat);

  
  }
void DeleList(int i){

   myAnimalList.remove(i);
  }




//根据索引取文件名字
String retList (int i){
  char *str;
  Animal *animal;
  animal = myAnimalList.get(i);
  if(animal->isMammal){
    str = animal->name;
    return str;
    }
  
  }
void DeleString(String Str){
  
  for(int i = 0; i < myAnimalList.size(); i++){
    if(retList(i) == Str){DeleList(i);}
    }

  
  }

void RenameList(String Str,String Str1){

  for(int i = 0; i < myAnimalList.size(); i++){
     if(retList(i) == Str){
      char *str; 
      const int len = Str1.length();
      str =new char[len+1];
    
      strcpy(str,Str1.c_str());    
      Animal *cat = new Animal();
      
      cat->name = str;
      cat->isMammal = true;
      myAnimalList.set(i,cat);

      
      }
    }
  
  }


  
  //10转2进制 
static char * dec2binWzerofill(unsigned long Dec, unsigned int bitLength) {
  static char bin[64]; 
  unsigned int i=0;

  while (Dec > 0) {
    bin[32+i++] = ((Dec & 1) > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }

  for (unsigned int j = 0; j< bitLength; j++) {
    if (j >= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    } else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';
  
  return bin;
}




//文本分割 
String fenge(String str, String fen, int index)
{
  int weizhi;
  String temps[str.length()];
  int i = 0;
  do
  {
    weizhi = str.indexOf(fen);
    if (weizhi != -1)
    {
      temps[i] =  str.substring(0, weizhi);
      str = str.substring(weizhi + fen.length(), str.length());
      i++;
    }
    else {
      if (str.length() > 0)
        temps[i] = str;
    }
  }
  while (weizhi >= 0);

  if (index > i)return "-1";
  return temps[index];
}


//String Arrayname[99][5];
