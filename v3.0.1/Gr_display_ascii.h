//16x16
uint8_t day[] [32]= {
{0x10,0x10,0x08,0x10,0x7C,0x10,0x44,0x10,0x7C,0x7F,0x44,0x10,0x7C,0x10,0x44,0x10,0x44,0x12,0x7F,0x14,0x60,0x14,0x50,0x10,0x48,0x10,0x44,0x10,0x52,0x14,0x20,0x08},/*"射",0*/
{0x08,0x00,0x88,0x7F,0x0A,0x04,0x3A,0x02,0x8A,0x3F,0x8A,0x20,0xFF,0x24,0x80,0x24,0x88,0x24,0xAA,0x24,0xAA,0x24,0xAA,0x22,0x21,0x0A,0x10,0x11,0x8C,0x20,0x43,0x40},/*"频",1*/
{0x04,0x02,0xFC,0x7E,0x12,0x09,0xA1,0x10,0x80,0x00,0xFE,0x7F,0x02,0x40,0xF9,0x27,0x08,0x04,0xF8,0x07,0x08,0x00,0xF8,0x0F,0x08,0x08,0x08,0x08,0xF8,0x0F,0x08,0x08},/*"管",2*/
{0x40,0x00,0x80,0x00,0xFE,0x7F,0x02,0x40,0x01,0x20,0xFE,0x3F,0x40,0x00,0xB0,0x10,0x8E,0x09,0x40,0x05,0x30,0x03,0x8E,0x05,0x60,0x19,0x18,0x61,0x47,0x01,0x80,0x00},/*"家",3*/
{0x08,0x00,0x88,0x3F,0x88,0x20,0x88,0x20,0xBF,0x3F,0x88,0x20,0x88,0x20,0xA8,0x3F,0x18,0x00,0xCC,0x7F,0x0B,0x04,0x88,0x04,0x88,0x3C,0x88,0x04,0x4A,0x05,0x24,0x7E},/*"提",4*/
{0x00,0x00,0x7F,0x3E,0x14,0x22,0x14,0x3E,0x7F,0x22,0x55,0x3E,0x55,0x08,0x55,0x0A,0x75,0x3E,0x43,0x09,0x41,0x08,0x7F,0x3E,0x41,0x08,0x41,0x08,0x7F,0x7F,0x41,0x00},/*"醒",5*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00},/*"：",6*/
};

/* (6 X 12 , 微软雅黑 )*/
uint8_t number[][12]={
{0x00,0x00,0x00,0x0E,0x11,0x11,0x11,0x11,0x0E,0x00,0x00,0x00},/*"0",0*/
{0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x00,0x00,0x00},/*"1",1*/
{0x00,0x00,0x00,0x1E,0x10,0x10,0x0C,0x02,0x1E,0x00,0x00,0x00},/*"2",2*/
{0x00,0x00,0x00,0x1E,0x10,0x0C,0x10,0x10,0x0E,0x00,0x00,0x00},/*"3",3*/
{0x00,0x00,0x00,0x10,0x18,0x14,0x12,0x3F,0x10,0x00,0x00,0x00},/*"4",4*/
{0x00,0x00,0x00,0x1E,0x02,0x0E,0x10,0x10,0x0E,0x00,0x00,0x00},/*"5",5*/
{0x00,0x00,0x00,0x1C,0x06,0x1E,0x22,0x22,0x1C,0x00,0x00,0x00},/*"6",6*/
{0x00,0x00,0x00,0x1E,0x10,0x08,0x08,0x04,0x04,0x00,0x00,0x00},/*"7",7*/
{0x00,0x00,0x00,0x1C,0x22,0x1C,0x22,0x22,0x1C,0x00,0x00,0x00},/*"8",8*/
{0x00,0x00,0x00,0x1C,0x22,0x22,0x3C,0x30,0x1E,0x00,0x00,0x00},/*"9",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00},/*".",10*/
{0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",11*/

{0x00,0x00,0x04,0x04,0x0C,0x0A,0x0A,0x1E,0x12,0x33,0x00,0x00},/*"A",12*/
{0x00,0x00,0x0F,0x12,0x12,0x0E,0x02,0x02,0x02,0x07,0x00,0x00},/*"P",13*/
{0x00,0x00,0x15,0x15,0x15,0x15,0x0E,0x0A,0x0A,0x0A,0x00,0x00},/*"W",14*/
{0x00,0x04,0x04,0x00,0x00,0x06,0x04,0x04,0x04,0x0E,0x00,0x00},/*"i",15*/
{0x00,0x00,0x1F,0x12,0x0A,0x0E,0x0A,0x02,0x02,0x07,0x00,0x00},/*"F",16*/
{0x00,0x04,0x04,0x00,0x00,0x06,0x04,0x04,0x04,0x0E,0x00,0x00},/*"i",17*/
{0x00,0x00,0x04,0x06,0x04,0x04,0x04,0x04,0x04,0x0E,0x00,0x00},/*"1",18*/
{0x00,0x00,0x0E,0x11,0x11,0x08,0x04,0x02,0x01,0x1F,0x00,0x00},/*"2",19*/



  };
/* (7 X 14 , 新宋体 )*/
uint8_t Mainx14[][14]={
{0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"1",0*/
{0x00,0x00,0x1C,0x22,0x22,0x20,0x10,0x10,0x08,0x04,0x22,0x3E,0x00,0x00},/*"2",1*/
{0x00,0x00,0x1C,0x22,0x22,0x20,0x18,0x20,0x20,0x22,0x22,0x1C,0x00,0x00},/*"3",2*/
{0x00,0x00,0x10,0x10,0x18,0x14,0x14,0x12,0x3E,0x10,0x10,0x38,0x00,0x00},/*"4",3*/

{0x00,0x00,0x3E,0x02,0x02,0x1E,0x22,0x20,0x20,0x22,0x22,0x1C,0x00,0x00},/*"5",4*/
{0x00,0x00,0x0C,0x12,0x01,0x1D,0x23,0x21,0x21,0x21,0x22,0x1C,0x00,0x00},/*"6",5*/
{0x00,0x00,0x3E,0x22,0x10,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x00,0x00},/*"7",6*/
{0x00,0x00,0x1E,0x21,0x21,0x21,0x1E,0x12,0x21,0x21,0x21,0x1E,0x00,0x00},/*"8",7*/
{0x00,0x00,0x0E,0x11,0x21,0x21,0x31,0x2E,0x20,0x20,0x12,0x0C,0x00,0x00},/*"9",8*/

{0x00,0x00,0x0C,0x12,0x21,0x21,0x21,0x21,0x21,0x21,0x12,0x0C,0x00,0x00},/*"0",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00},/*".",10*/
{0x00,0x00,0x00,0x08,0x08,0x14,0x14,0x14,0x1C,0x22,0x22,0x77,0x00,0x00},/*"A",11*/
{0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x02,0x02,0x02,0x07,0x00,0x00},/*"P",12*/

/* (7 X 14 , 宋体 ) 阳极*/ 
{0xFF,0xFF,0xFF,0x94,0xD5,0xD5,0xD5,0xD5,0xC9,0xEB,0xEB,0xEB,0xFF,0xFF},/*"W",13*/
{0xFF,0xFF,0xFF,0xC1,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xC1,0xFF,0xFF},/*"I",14*/
{0xFF,0xFF,0xFF,0xC0,0xBD,0xFD,0xED,0xE1,0xED,0xFD,0xFD,0xF8,0xFF,0xFF},/*"F",15*/
{0xFF,0xFF,0xFF,0xC1,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xC1,0xFF,0xFF},/*"I",16*/
};
/* (14 X 14 , 新宋体 )*/
uint8_t Mainx28[][28]={
{0x88,0x00,0x08,0x01,0xF4,0x1F,0x04,0x00,0xE6,0x0F,0x05,0x00,0xE4,0x0F,0x04,0x00,0xE4,0x0F,0x24,0x08,0x24,0x08,0x24,0x08,0xE4,0x0F,0x24,0x08},/*"信",0*/
{0xFC,0x07,0x04,0x04,0x04,0x04,0xFC,0x07,0x00,0x00,0x00,0x00,0xFF,0x1F,0x10,0x00,0x08,0x00,0xFC,0x07,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x03},/*"号",1*/
{0x84,0x00,0x04,0x01,0xE4,0x0F,0x5F,0x04,0x84,0x02,0xF4,0x1F,0x84,0x00,0x8C,0x00,0xF7,0x1F,0x44,0x04,0x64,0x02,0x84,0x01,0x44,0x06,0x37,0x08},/*"接",2*/
{0x10,0x01,0x10,0x01,0x12,0x01,0x12,0x1F,0x92,0x08,0x52,0x09,0x12,0x09,0x1A,0x09,0x16,0x05,0x12,0x05,0x10,0x02,0x10,0x05,0x90,0x08,0x50,0x10},/*"收",3*/
{0x40,0x00,0x44,0x04,0x44,0x08,0x22,0x00,0xFE,0x1F,0x20,0x00,0x10,0x00,0xF0,0x07,0x28,0x04,0x24,0x02,0x42,0x01,0x81,0x00,0x60,0x03,0x1C,0x1C},/*"发",4*/
{0x20,0x08,0x42,0x04,0x04,0x00,0xE4,0x0F,0x00,0x01,0x00,0x01,0xF7,0x1F,0x04,0x01,0x84,0x02,0x84,0x04,0x44,0x08,0x24,0x08,0x0A,0x00,0xF1,0x1F},/*"送",5*/
{0x44,0x04,0x44,0x04,0xE4,0x1F,0x4F,0x04,0xE4,0x0F,0x24,0x08,0xEE,0x0F,0x36,0x08,0xE5,0x0F,0x04,0x01,0xF4,0x1F,0x84,0x02,0x44,0x04,0x34,0x18},/*"模",6*/
{0x00,0x05,0x00,0x09,0x00,0x01,0xFF,0x1F,0x00,0x01,0x00,0x01,0x3E,0x01,0x08,0x01,0x08,0x01,0x08,0x02,0x08,0x12,0x78,0x14,0x0F,0x18,0x00,0x10},/*"式",7*/
{0x02,0x00,0xE4,0x0F,0x04,0x08,0x00,0x08,0x00,0x08,0x07,0x08,0xE4,0x0F,0x24,0x00,0x24,0x00,0x24,0x00,0x34,0x00,0x2C,0x10,0x24,0x10,0xC0,0x1F},/*"记",8*/
{0x00,0x00,0xFE,0x07,0x00,0x04,0xFC,0x07,0x00,0x04,0xFF,0x1F,0x40,0x00,0x44,0x04,0xC8,0x02,0x50,0x01,0x48,0x02,0x44,0x04,0x43,0x18,0x70,0x00},/*"录",9*/
{0x00,0x10,0xDC,0x11,0x54,0x11,0x54,0x15,0x54,0x15,0x54,0x15,0xFE,0x17,0x54,0x15,0x54,0x15,0x54,0x15,0x54,0x11,0x54,0x11,0x5A,0x11,0xA1,0x1D},/*"删",10*/
{0x00,0x01,0x0F,0x01,0x89,0x02,0x49,0x04,0x25,0x08,0xD5,0x17,0x09,0x01,0x09,0x01,0xE9,0x0F,0x09,0x01,0x27,0x09,0x21,0x11,0x11,0x11,0xC1,0x01},/*"除",11*/
{0x40,0x00,0x42,0x08,0x44,0x04,0x48,0x02,0xFF,0x0F,0x00,0x08,0x00,0x08,0x00,0x08,0xFE,0x0F,0x00,0x08,0x00,0x08,0x00,0x08,0xFF,0x0F,0x00,0x08},/*"当",12*/
{0x04,0x04,0x08,0x02,0xFF,0x1F,0x00,0x00,0x7E,0x08,0x42,0x09,0x42,0x09,0x7E,0x09,0x42,0x09,0x42,0x09,0x7E,0x09,0x42,0x08,0x42,0x08,0x72,0x0E},/*"前",13*/
{0x00,0x00,0xC2,0x07,0x44,0x04,0x48,0x04,0x40,0x04,0x21,0x18,0x12,0x00,0xE8,0x0F,0x48,0x08,0x44,0x04,0x84,0x02,0x02,0x01,0xC2,0x06,0x30,0x18},/*"没",14*/
{0x20,0x00,0x20,0x00,0xFF,0x1F,0x10,0x00,0xF8,0x07,0x0C,0x04,0x0A,0x04,0xF9,0x07,0x08,0x04,0x08,0x04,0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x07},/*"有",15*/
{0x08,0x04,0x04,0x04,0x3E,0x04,0xA2,0x1F,0x3E,0x04,0x22,0x04,0xBE,0x04,0x22,0x05,0x3F,0x05,0x28,0x04,0x24,0x04,0x22,0x04,0x21,0x04,0x38,0x07},/*"射",16*/
{0x08,0x00,0xC8,0x1F,0x3A,0x02,0x0A,0x01,0x8A,0x0F,0xBF,0x08,0x80,0x0A,0x88,0x0A,0xAA,0x0A,0xA9,0x0A,0x90,0x0A,0x08,0x05,0x84,0x08,0x43,0x08},/*"频",17*/
{0x08,0x02,0x49,0x02,0x2A,0x02,0x7F,0x1E,0x1C,0x09,0x2A,0x09,0xC9,0x0A,0x04,0x0A,0x3F,0x0A,0x24,0x0A,0x26,0x04,0x18,0x04,0x2C,0x0A,0x43,0x11},/*"数",18*/
{0x04,0x00,0xE4,0x0F,0x24,0x08,0x2F,0x08,0xE4,0x0F,0x24,0x02,0x24,0x02,0xEC,0x1F,0x27,0x02,0x24,0x02,0xA4,0x0F,0x94,0x08,0x94,0x08,0x8F,0x0F},/*"据",19*/
{0xF7,0xFE,0xF7,0xFA,0xF6,0xF6,0xF5,0xFE,0x15,0xE0,0xF7,0xFE,0xF7,0xFE,0x73,0xFD,0x75,0xFD,0x76,0xFD,0xB7,0xFB,0xB7,0xFB,0xD7,0xF7,0xE7,0xEF},/*"状",20*/
{0xBF,0xFF,0xBF,0xFF,0x00,0xE0,0xBF,0xFF,0x5F,0xFF,0xEF,0xFE,0xD3,0xF9,0xBC,0xE7,0xFF,0xFF,0xBF,0xFF,0x77,0xF7,0x75,0xEF,0xF5,0xED,0x0E,0xFC},/*"态",21*/
{0x01,0xF0,0xF7,0xFD,0xF7,0xFD,0xF7,0xFD,0xF7,0xFD,0xF7,0xFD,0x00,0xE0,0xF7,0xFD,0xF7,0xFD,0xF7,0xFD,0xFB,0xFD,0xFB,0xFD,0xFD,0xFD,0xFE,0xFD},/*"开",22*/
{0xF7,0xFD,0xEF,0xFD,0xEF,0xFE,0x01,0xF0,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0x00,0xE0,0x5F,0xFF,0x5F,0xFF,0xEF,0xFE,0xF7,0xFD,0xFB,0xFB,0xFC,0xE7},/*"关",23*/
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0xFF,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0xFF,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF},/*"：",24*/
{0x04,0x01,0x3C,0x1F,0x8A,0x04,0x51,0x08,0x40,0x00,0xFC,0x07,0x40,0x00,0xFF,0x1F,0x00,0x01,0xFE,0x0F,0x00,0x01,0x08,0x01,0x10,0x01,0xC0,0x01},/*"等",25*/
{0x08,0x01,0x04,0x01,0xE2,0x0F,0x09,0x01,0x08,0x01,0xF4,0x1F,0x06,0x04,0x05,0x04,0xF4,0x1F,0x04,0x04,0x24,0x04,0x44,0x04,0x04,0x04,0x04,0x07},/*"待",26*/
{0x84,0x00,0x04,0x01,0xE4,0x0F,0x5F,0x04,0x84,0x02,0xF4,0x1F,0x84,0x00,0x8C,0x00,0xF7,0x1F,0x44,0x04,0x64,0x02,0x84,0x01,0x44,0x06,0x37,0x08},/*"接",27*/
{0x10,0x01,0x10,0x01,0x12,0x01,0x12,0x1F,0x92,0x08,0x52,0x09,0x12,0x09,0x1A,0x09,0x16,0x05,0x12,0x05,0x10,0x02,0x10,0x05,0x90,0x08,0x50,0x10},/*"收",28*/
{0x80,0x07,0x7E,0x00,0x20,0x00,0x10,0x02,0x08,0x01,0xFC,0x00,0x20,0x02,0x18,0x04,0xFE,0x0F,0x40,0x08,0x48,0x02,0x44,0x04,0x42,0x08,0x70,0x00},/*"系",29*/
{0x84,0x00,0x04,0x01,0x02,0x00,0xE9,0x1F,0x8F,0x00,0x84,0x04,0x42,0x08,0xE1,0x0F,0x8F,0x0A,0x80,0x02,0x40,0x02,0x4C,0x12,0x23,0x12,0x10,0x1C},/*"统",30*/
{0x02,0x00,0xC4,0x07,0x44,0x04,0x40,0x04,0x40,0x04,0x27,0x18,0x14,0x00,0xE4,0x0F,0x44,0x08,0x44,0x04,0x94,0x02,0x0C,0x01,0xC4,0x06,0x30,0x18},/*"设",31*/
{0xFE,0x0F,0x12,0x09,0x12,0x09,0xFE,0x0F,0x40,0x00,0xFE,0x0F,0x40,0x00,0xFC,0x07,0x04,0x04,0x04,0x04,0x44,0x04,0x44,0x04,0x44,0x04,0xFF,0x1F},/*"置",32*/
{0x40,0x00,0x40,0x00,0x40,0x00,0xFE,0x1F,0x42,0x10,0x42,0x10,0xA2,0x10,0x12,0x11,0x0A,0x12,0x06,0x14,0x02,0x10,0x02,0x10,0x02,0x10,0x02,0x1C},/*"内",33*/
{0x00,0x00,0xFE,0x1F,0x02,0x10,0x42,0x14,0xCA,0x14,0x52,0x15,0x22,0x12,0x22,0x12,0x52,0x15,0x52,0x15,0x8A,0x10,0x46,0x10,0x02,0x10,0x02,0x1C},/*"网",34*/
{0x02,0x00,0xE4,0x1F,0x24,0x11,0x20,0x11,0xA7,0x17,0x24,0x11,0xE4,0x1F,0x24,0x10,0xA4,0x17,0xB4,0x14,0xAC,0x14,0xA4,0x17,0x20,0x10,0x10,0x1C},/*"调",35*/
{0x02,0x0A,0x04,0x12,0x04,0x02,0xF0,0x1F,0x00,0x02,0x07,0x02,0xE4,0x02,0x44,0x02,0x44,0x02,0x44,0x04,0x54,0x14,0xCC,0x15,0x74,0x18,0x00,0x10},/*"试",36*/
{0x02,0x00,0xC4,0x07,0x44,0x04,0x40,0x04,0x40,0x04,0x27,0x18,0x14,0x00,0xE4,0x0F,0x44,0x08,0x44,0x04,0x94,0x02,0x0C,0x01,0xC4,0x06,0x30,0x18},/*"设",37*/
{0x10,0x00,0xF8,0x07,0x0C,0x02,0x12,0x01,0xE0,0x00,0x18,0x03,0x07,0x1C,0xFC,0x07,0x44,0x04,0x44,0x04,0xFC,0x07,0x44,0x04,0x44,0x04,0xFC,0x07},/*"备",38*/
{0x00,0x00,0x7F,0x0F,0x14,0x08,0x14,0x08,0x7F,0x08,0x55,0x08,0x55,0x0F,0x63,0x01,0x41,0x01,0x7F,0x01,0x41,0x01,0x41,0x11,0x7F,0x11,0x41,0x1E},/*"配",39*/
{0x00,0x00,0xFE,0x1F,0x02,0x10,0x42,0x14,0xCA,0x14,0x52,0x15,0x22,0x12,0x22,0x12,0x52,0x15,0x52,0x15,0x8A,0x10,0x46,0x10,0x02,0x10,0x02,0x1C},/*"网",40*/





  
 }; 
/* (12 X 12 , 宋体 ) */  
uint8_t Receiv_ing[][24]{
{0x00,0x00,0xFE,0x03,0x88,0x00,0x88,0x00,0x88,0x00,0x88,0x00,0xFF,0x07,0x88,0x00,0x88,0x00,0x84,0x00,0x84,0x00,0x82,0x00},/*"开",0*/
{0x20,0x00,0x40,0x00,0xFC,0x07,0x04,0x04,0x04,0x04,0xFC,0x07,0x04,0x00,0xFC,0x07,0x0C,0x04,0x0A,0x04,0xFA,0x07,0x09,0x04},/*"启",1*/
{0x04,0x01,0x88,0x00,0x00,0x00,0xFE,0x03,0x20,0x00,0x20,0x00,0xFF,0x07,0x20,0x00,0x50,0x00,0x88,0x00,0x04,0x01,0x03,0x06},/*"关",2*/
{0x02,0x00,0xE4,0x07,0x00,0x04,0x42,0x04,0x42,0x04,0xFA,0x05,0x42,0x04,0x62,0x04,0x52,0x04,0x4A,0x04,0x62,0x04,0x02,0x07},/*"闭",3*/ 
{0x02,0x07,0xF4,0x00,0x10,0x00,0xF0,0x07,0x17,0x04,0x54,0x04,0x94,0x02,0x14,0x01,0x94,0x02,0x4C,0x04,0x0A,0x00,0xF1,0x07},/*"返",4*/
{0x00,0x00,0xFE,0x07,0x02,0x04,0x02,0x04,0xF2,0x04,0x92,0x04,0x92,0x04,0xF2,0x04,0x02,0x04,0x02,0x04,0xFE,0x07,0x02,0x04},/*"回",5*/
{0x10,0x00,0x20,0x00,0x00,0x00,0xFE,0x03,0x20,0x00,0x20,0x00,0x20,0x00,0xFE,0x03,0x20,0x00,0x20,0x00,0x20,0x00,0xFF,0x07},/*"主",6*/
{0x88,0x00,0xFF,0x07,0x88,0x00,0x80,0x03,0x7F,0x00,0x12,0x01,0xA4,0x00,0x20,0x00,0xFF,0x07,0xA8,0x00,0x24,0x01,0x23,0x06},/*"菜",7*/
{0x04,0x01,0x88,0x00,0xFE,0x03,0x22,0x02,0xFE,0x03,0x22,0x02,0xFE,0x03,0x20,0x00,0xFF,0x07,0x20,0x00,0x20,0x00,0x20,0x00},/*"单",8*/  
{0xFC,0x01,0x04,0x01,0xFC,0x01,0x04,0x01,0xFC,0x01,0x00,0x00,0xFF,0x07,0x20,0x00,0xE4,0x03,0x24,0x00,0x2A,0x00,0xF1,0x07},/*"是",9*/
{0xFF,0x07,0x20,0x00,0xB0,0x01,0x2C,0x02,0x23,0x04,0x20,0x00,0x00,0x00,0xFE,0x03,0x02,0x02,0x02,0x02,0xFE,0x03,0x02,0x02},/*"否",10*/
{0x00,0x04,0x77,0x04,0x55,0x05,0x55,0x05,0x55,0x05,0xFF,0x05,0x55,0x05,0x55,0x05,0x55,0x05,0x55,0x04,0x55,0x04,0x66,0x06},/*"删",11*/
{0x80,0x00,0x47,0x01,0x25,0x02,0x15,0x04,0xE3,0x03,0x83,0x00,0xF5,0x07,0x85,0x00,0xA5,0x02,0x93,0x04,0x89,0x04,0xC1,0x00},/*"除",12*/
{0x20,0x00,0x50,0x00,0x88,0x00,0x04,0x01,0x03,0x06,0xFC,0x01,0x20,0x00,0x20,0x00,0xFE,0x03,0x20,0x00,0x20,0x00,0xFF,0x07},/*"全",13*/
{0x08,0x00,0xBE,0x07,0x80,0x04,0xA2,0x04,0x94,0x02,0xFF,0x02,0x80,0x04,0xBE,0x04,0xA2,0x04,0xA2,0x03,0xBE,0x00,0xA2,0x00},/*"部",14*/
{0x88,0x00,0xAA,0x00,0x88,0x00,0xBF,0x07,0x4C,0x02,0x9A,0x02,0xA9,0x02,0x84,0x02,0x9F,0x02,0x12,0x01,0x8C,0x02,0x53,0x04},/*"数",15*/
{0x04,0x00,0xE4,0x07,0x24,0x04,0xEF,0x07,0x24,0x01,0xE4,0x07,0x2C,0x01,0xE7,0x07,0x64,0x04,0x54,0x04,0xD4,0x07,0x4E,0x04},/*"据",16*/
{0x40,0x00,0xCF,0x03,0x24,0x02,0x04,0x01,0xE2,0x07,0xAE,0x04,0xEB,0x07,0xAA,0x04,0xEA,0x07,0xAE,0x04,0xAA,0x04,0x10,0x06},/*"确",17*/
{0x82,0x00,0x84,0x00,0x80,0x00,0x80,0x00,0x87,0x00,0x84,0x00,0x44,0x01,0x44,0x01,0x54,0x01,0x2C,0x02,0x24,0x02,0x10,0x04},/*"认",18*/
{0x02,0x07,0xF4,0x00,0x10,0x00,0xF0,0x07,0x17,0x04,0x54,0x04,0x94,0x02,0x14,0x01,0x94,0x02,0x4C,0x04,0x0A,0x00,0xF1,0x07},/*"返",19*/
{0x00,0x00,0xFE,0x07,0x02,0x04,0x02,0x04,0xF2,0x04,0x92,0x04,0x92,0x04,0xF2,0x04,0x02,0x04,0x02,0x04,0xFE,0x07,0x02,0x04},/*"回",20*/
  
  }; 

 