#include <iostream>
#include <fstream>

#include "argumentparcer.h"
#include "fileparcer.h"

using namespace std;

void printHelp();

int main(int argc, char* argv[])
{
    ArgumentParcer arg(argc, argv);
    try {
        switch (arg.getFunction())
        {
        case ArgumentParcer::FindWords:
        {
            FileParcer parcer(arg.getFileName());
            const string& word = arg.getSearchWord();
            int count = parcer.findNumberOfWords(word);
            cout << "Number of words \"" << word << "\": " << count << endl;
            break;
        }
        case ArgumentParcer::Checksum:
        {
            FileParcer parcer(arg.getFileName());
            auto checksum = parcer.getChecksum();
            cout << "Checksum = 0x" << hex << checksum << endl;
            break;
        }
        case ArgumentParcer::Help:
            printHelp();
            break;
        case ArgumentParcer::NonFunction:
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
    cout << "Usage: FileParcerTest.exe [OPTION]... " << endl;
    cout << " -f FILE  " << endl;
    cout << " -m words|checksum " << endl;
    cout << " -v WORD " << endl;
    cout << " -h " << endl;
    cout << "\nExamples:\n" << endl;
    cout << "FileParcerTest.exe -f FILE -m words -v WORD" << endl;
    cout << "Search for number of WORD in FILE\n" << endl;
    cout << "FileParcerTest.exe -f FILE -m checksum" << endl;;
    cout << "Calculate a 32-bit checksum for FILE\n" << endl;
    cout << "FileParcerTest.exe -h" << endl;
    cout << "Show this help" << endl;
}
