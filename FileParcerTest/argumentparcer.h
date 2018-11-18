#ifndef ARGUMENTPARCER_H
#define ARGUMENTPARCER_H

#include <map>
#include <string>

using namespace std;

class ArgumentParcer
{
public:
    enum Function {
        FindWords,
        Checksum,
        Help,
        NonFunction
    };

public:
    ArgumentParcer(int argc, char* argv[]);
    Function getFunction();
    const string getFileName();
    const string getSearchWord();

private:
    // key, value
    map <string, string> m_options;
};

#endif // ARGUMENTPARCER_H
