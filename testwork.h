

#ifndef TESTWORK
#define TESTWORK


#include "getopt.h"
#include <stdexcept>
#include <string>
using namespace std;
//����� testwork ��������� ������ ������������ � �������� �������,
//��� �� ��� ���������� ����� getopt ��� ������� ���������� ��������� ������
//����� testwork ����� ��������� ������������ ������ �� ������ �� �����
//������� ������� testwork(int argc , char* argv[]);
//
class testwork
{

string file;
string word;
getopt* param;
public:
   testwork(int argc , char* argv[]);
   testwork(void);
   unsigned int checksum(string fileName); //������ Checksum �����
   int lookForWords(string fileName, string wordSearch);// ����� ��������� ���� � ����
   void help();//����� Help
   ~testwork() ;
private:
   bool isHelp();//�������� ���������� �� help
   bool isChecksum(); //�������� ���������� �� Checksum
   bool isLookForWords();  //�������� ���������� �� ����� ��������� �����
//

};
#endif
