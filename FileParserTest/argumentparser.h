#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <map>
#include <string>

using namespace std;

class ArgumentParser
{
public:
    enum Function {
        FindWords,
        Checksum,
        Help,
        NonFunction
    };

public:
    ArgumentParser(int argc, char* argv[]);
    Function getFunction();
    const string getFileName();
    const string getSearchWord();

private:
    // key, value
    map <string, string> m_options;
};

#endif // ARGUMENTPARSER_H
