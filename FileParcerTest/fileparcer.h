#ifndef FILEPARCER_H
#define FILEPARCER_H

#include <string>

using namespace std;

class FileParcer
{
public:
    FileParcer(const string& file);
    int findNumberOfWords(const string& word);
    unsigned __int32 getChecksum();
private:
    string m_file;
};

#endif // FILEPARCER_H
