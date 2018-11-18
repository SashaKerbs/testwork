#include "argumentparser.h"

ArgumentParser::ArgumentParser(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') {
            string key = argv[i];
            if ((key.compare("-f") == 0 ||
                 key.compare("-m") == 0 ||
                 key.compare("-v") == 0) &&
                    (i + 1) < argc) {
                m_options[key] = argv[i+1];
                i++;
            } else {
                m_options[key] = "";
            }
        } else {
            m_options["unkey arg"] += argv[i];
        }
    }
}

ArgumentParser::Function ArgumentParser::getFunction()
{
    if (m_options.count("-m")) {
        if (m_options["-m"].compare("words") == 0)
            return FindWords;
        if (m_options["-m"].compare("checksum") == 0)
            return Checksum;
    } else if (m_options.count("-h"))
        return Help;
    else
        return NonFunction;
}

const string ArgumentParser::getFileName()
{
    if(m_options.count("-f"))
        return m_options["-f"];
    else
        return "";
}

const string ArgumentParser::getSearchWord()
{
    if(m_options.count("-v"))
        return m_options["-v"];
    else
        return "";
}
