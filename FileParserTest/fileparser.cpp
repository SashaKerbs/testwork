#include <fstream>
#include <iostream>

#include "fileparser.h"

FileParser::FileParser(const string& file) : m_file(file)
{

}

int FileParser::findNumberOfWords(const string& word)
{
    ifstream fin;
    int numberWords = 0;
    fin.open(m_file, std::ifstream::in);
    if (!fin.is_open())
        throw ifstream::failure("file error");

    while (fin.eof()==NULL) {
        string temp;
        fin >> temp;
        if(word.compare(temp) == 0)
            numberWords++;
    }
    fin.close();
    return numberWords;
}

unsigned __int32 FileParser::getChecksum()
{
    ifstream fin;
    unsigned __int32 checksum = 0;
    unsigned __int32 word32;
    fin.open(m_file, std::ifstream::in | ios::binary);
    if (!fin.is_open()) {
        throw ifstream::failure("file error");
    }

    while(!fin.eof()) {
        fin.read((char*)&word32, sizeof(unsigned __int32));
        checksum += word32;
    }
    fin.close();
    return checksum;
}
