//---------------------------------------------------------------------------


#pragma hdrstop
#include <string>
#include <conio.h>
#include <fstream>
#include <iostream>

//---------------------------------------------------------------------------

#pragma argsused

 using namespace std;

#include "testwork.h"

 /*
 Класс testwork описан в testwork.h и testwork.cpp
 класс getopt отвечает за разбор параметров
 */

int main(int argc, char* argv[])
{
try
{
   testwork test(argc, argv);
}
catch(invalid_argument& e)
{
   cerr << e.what() << endl;
   return -1;
}
getch();
return 0;
}
//---------------------------------------------------------------------------

