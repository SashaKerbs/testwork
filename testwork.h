

#ifndef TESTWORK
#define TESTWORK


#include "getopt.h"
#include <stdexcept>
#include <string>
using namespace std;
//класс testwork выполняет задачи поставленные в тестовом задании,
//так же был разработан класс getopt для разбора параметров командной строки
//класс testwork может выполнять поставленную задачу от начало до конца
//вызовом функции testwork(int argc , char* argv[]);
//
class testwork
{

string file;
string word;
getopt* param;
public:
   testwork(int argc , char* argv[]);
   testwork(void);
   unsigned int checksum(string fileName); //расчет Checksum файла
   int lookForWords(string fileName, string wordSearch);// поиск вхождения слов в файл
   void help();//вывод Help
   ~testwork() ;
private:
   bool isHelp();//проверка параметров на help
   bool isChecksum(); //проверка параметров на Checksum
   bool isLookForWords();  //проверка параметров на поиск вхождения слова
//

};
#endif
