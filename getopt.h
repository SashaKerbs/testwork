#ifndef GETOPT
#define GETOPT

#define FIRST_PARAM 1

#include <string>
#include <stdexcept>
using namespace std;

//класс getopt выполн€ет задачу разбора параметров по ключам и выбор параметров
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
//выбор параметров по ключу numparam определ€ет номер параметра прив€занного к ключу
   char* getparam(char* key,unsigned int numparam = FIRST_PARAM);

private:
//€вл€етс€ ли текуща€ строка  ключом/параметром
   isParam(char* param);


};
#endif
