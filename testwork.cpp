 #include "testwork.h"
 #include <fstream>
 #include <iostream>

 void  testwork::parse_cl(int argc , char* argv[])
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
      cout << " Usage: test [OPTION]... " << endl;
      cout << " -f FILE  " << endl;
      cout << " -m words|checksum " << endl;
      cout << " -v TERM " << endl;
      cout << " -h " << endl;

      cout << "\nExamples:\n" << endl;
      cout << "test -f FILE -m words -v TERM" << endl;
      cout << "Search for TERM in FILE\n" << endl;
      cout << "test -f FILE -m checksum" << endl;;
      cout << "Compute a 32-bit checksum for FILE\n" << endl;
      cout << "test -h" << endl;
      cout << "Show this help" << endl;
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
