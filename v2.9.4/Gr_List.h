#include <LinkedList.h>
class Animal {
  public:
    char *name;
    bool isMammal;
};
LinkedList<Animal*> myAnimalList = LinkedList<Animal*>();





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
  //链表根据名字删除数据
void DeleString(String Str){
  
  for(int i = 0; i < myAnimalList.size(); i++){
    if(retList(i) == Str){DeleList(i);}
    }

  
  }

//链表根据名字修改数据
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
