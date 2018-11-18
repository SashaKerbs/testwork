#include <iostream>
#include <fstream>

#include "argumentparser.h"
#include "fileparser.h"

using namespace std;

void printHelp();

int main(int argc, char* argv[])
{
    ArgumentParser arg(argc, argv);
    try {
        switch (arg.getFunction())
        {
        case ArgumentParser::FindWords:
        {
            FileParser parser(arg.getFileName());
            const string& word = arg.getSearchWord();
            int count = parser.findNumberOfWords(word);
            cout << "Number of words \"" << word << "\": " << count << endl;
            break;
        }
        case ArgumentParser::Checksum:
        {
            FileParser parser(arg.getFileName());
            auto checksum = parser.getChecksum();
            cout << "Checksum = 0x" << hex << checksum << endl;
            break;
        }
        case ArgumentParser::Help:
            printHelp();
            break;
        case ArgumentParser::NonFunction:
            cout << "Use help -h";
            break;
        }
    }
    catch (ifstream::failure& e) {
        cout << "Error: Failure to open " << arg.getFileName() << std::endl;
    }
    return 0;
}

void printHelp()
{
    cout << "Usage: FileparserTest.exe [OPTION]... " << endl;
    cout << " -f FILE  " << endl;
    cout << " -m words|checksum " << endl;
    cout << " -v WORD " << endl;
    cout << " -h " << endl;
    cout << "\nExamples:\n" << endl;
    cout << "FileparserTest.exe -f FILE -m words -v WORD" << endl;
    cout << "Search for number of WORD in FILE\n" << endl;
    cout << "FileparserTest.exe -f FILE -m checksum" << endl;;
    cout << "Calculate a 32-bit checksum for FILE\n" << endl;
    cout << "FileparserTest.exe -h" << endl;
    cout << "Show this help" << endl;
}
