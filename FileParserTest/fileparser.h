#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>

using namespace std;

class FileParser
{
public:
    FileParser(const string& file);
    int findNumberOfWords(const string& word);
    unsigned __int32 getChecksum();
private:
    string m_file;
};

#endif // FILEPARSER_H
