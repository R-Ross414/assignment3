#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileRead
{
  public:
    /*The 2 constrcutors will initialize variables and pointers and
    gather information needed about the file */
    FileRead();
    FileRead(string FileName);
    ~FileRead();

    /*Method #1 is a print method. Method #2 will be used to keep
    track of line number */
    void printFile(); //Method #1
    string getLine(int linenum); //Method #2

    /*Most of these class variables are self explanatory. FileName
    takes in the file name as a string input. Stream is the input
    stream object that needs to be processed. Lines is a pointer used
    index through the file line by line. Line_no is line number, or
    the specific index location */
    string FileName;
    ifstream Stream;
    string* lines;
    int line_no;

};
