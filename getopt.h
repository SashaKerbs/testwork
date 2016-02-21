#ifndef GETOPT
#define GETOPT

#define FIRST_PARAM 1

#include <string>
#include <stdexcept>
using namespace std;

//����� getopt ��������� ������ ������� ���������� �� ������ � ����� ����������
class getopt        
{
char **argument;
int size;
int currentposition;
public:
// �������� ���-�� ���������� � ������ ���������� ������
   getopt(int argc, char *argv[]);
// ����� ����� � ������ ����������
   bool findkey(char* key);
//����� ���������� �� ����� numparam ���������� ����� ��������� ������������ � �����
   char* getparam(char* key,unsigned int numparam = FIRST_PARAM);

private:
//�������� �� ������� ������  ������/����������
   isParam(char* param);


};
#endif
