
#include "getopt.h"

   getopt::getopt(int argc, char *argv[])
   {
      argument = argv;
      size = argc;
   }                
   bool getopt::findkey(char* key)
   {
      for(int i=1; i<size ;i++)
      {
         if(strcmp(argument[i], key)==0)
            return true;
      }
      return false;
   }
   char* getopt::getparam(char* key,unsigned int numparam )
   {
      for(int i=1; i < (size-numparam) ;i++)
      {
         if(strcmp(argument[i], key)==0 && isParam(argument[i+numparam]) )
            return argument[i+numparam];
      }
      string error = "error parameters with key = " + string(key);
      throw invalid_argument(error);
   }

   getopt::isParam(char* param)
   {
      if(param != NULL)
         if(param[0] != '-')
            return true;
      return false;
   }
