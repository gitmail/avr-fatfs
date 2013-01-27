#ifndef _MAIN_H_
#define _MAIN_H_
#define SINGLE_ITEM_SIZE 64 
char ReadSDFile(char *fnamep,int index, char *data, char mode);//读取一条数据
void ftochr(float a,char * dest);                  //浮点型转换成字符型
void itochr(int a,char * dest);                    //整型数据转换成字符型
void StructToChar(void);                           //将结构体中的数据转成字符型
void check(void );
float SquareRootFloat(float number);
char *get_name( char fnamep[] );
unsigned int findIndex(char *filename,char *buf);
void WriteFileHead(void) ;
void selfTest(void);
void WriteSDFile(void);
void CharToStruct(char *buf);
void timer1_init(void);
char scan_files (char* path); //文件查找函数 查找指定目录下的所有文件
#endif


