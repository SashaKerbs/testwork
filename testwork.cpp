
 #include "testwork.h"
 #include <fstream>
 #include <iostream>

   testwork::testwork(int argc , char* argv[])
   {
      param = new getopt(argc,argv);
      if(this->isHelp())
      {
         help();
      }
      else if(this->isChecksum())
      {
         file =  param->getparam("-f");
         unsigned int result = checksum(file);
         cout << "checksum = " << result << endl;
      } else if(this->isLookForWords())
      {
         file = param->getparam("-f");
         word = param->getparam("-v");
         int result = this->lookForWords(file,word);
         cout << "number of words " << result << endl;
      }
      else
         throw invalid_argument("parameter incorrect");
   }
   testwork::testwork(void)
   {
      string file = "";
      string Word = "";
      param = NULL;
   }
   unsigned int testwork::checksum(string fileName)
   {
      ifstream fin;
      unsigned int sum = 0;
      unsigned int word32;

      fin.open(fileName.c_str(), std::ifstream::in | ios::binary);
      if( !fin.is_open() )
      {
         throw invalid_argument("file error");
      }
      while(!fin.eof())
      {
         fin.read((char*)&word32, sizeof(int));
         sum += word32;
      }
      fin.close();
      return sum;
   }

   int testwork::lookForWords(string fileName, string wordSearch)
   {
      ifstream fin;
      string word;
      int countword = 0;
      fin.open(fileName.c_str(),std::ifstream::in );
      if( !fin.is_open() )
         throw invalid_argument("file error");
      while(fin.eof()==NULL)   {
         fin >> word ;
         if(wordSearch.compare(word) == 0 )
            countword++;
      }
      fin.close();
      return countword;
   }

   void testwork::help()
   {
      cout << " help on test.exe\n" << endl;
      cout << " -f file" << endl;
      cout << " -m could take on two values \"words\" for searching words and \"checksum\" for calculation the sum of 32-bit words" << endl;
      cout << " -v sets the search term " << endl;
      cout << " -h help" << endl;
   }

   bool testwork::isHelp()
   {
      if(param->findkey("-h") && !param->findkey("-f") && !param->findkey("-m")
               && !param->findkey("-v"))
         return true;
      else
         return false;
   }
   bool testwork::isChecksum()
   {
      if(!param->findkey("-h") && param->findkey("-f") && param->findkey("-m")
               && !param->findkey("-v") && strcmp(param->getparam("-m"), "checksum")==0 )
         return true;
      else
         return false;
   }
   bool testwork::isLookForWords()
   {
      if(!param->findkey("-h") && param->findkey("-f") && param->findkey("-m")
               && param->findkey("-v") && strcmp(param->getparam("-m"), "words")==0 )
         return true;
      else
         return false;
   }

   testwork::~testwork(void)
   {
      if(param)
         delete param;
   }
