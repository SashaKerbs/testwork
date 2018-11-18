#include <fstream>
#include <iostream>

#include "fileparcer.h"

FileParcer::FileParcer(const string& file) : m_file(file)
{

}

int FileParcer::findNumberOfWords(const string& word)
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

unsigned __int32 FileParcer::getChecksum()
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
