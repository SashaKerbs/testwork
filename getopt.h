
#ifndef GETOPT
#define GETOPT

#include <string>
#include <stdexcept>
using namespace std;

//класс getopt выполняет задачу разбора параметров по ключам и выбор параметров
class getopt        
{
char **argument;
int size;
int currentposition;
public:
// передача кол-ва параметров и списка параметров классу
   getopt(int argc, char *argv[]);
// поиск ключа в списке параметров
   bool findkey(char* key);
//выбор параметров по ключу numparam определяет номер параметра привязанного к ключу
   char* getparam(char* key);

private:
//является ли текущая строка  ключом/параметром
   isParam(char* param);


};
#endif
