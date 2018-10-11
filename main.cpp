#include "ParseFile.h"
#include "FileRead.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  bool Yes;  //this bool determines if the main body of code runs
  Yes = true;
  string cmd = argv[1];
///////////////////////////////////////////////////////////////////
  while(Yes)
  {
    cout << "Analyzing " << cmd << "..." << endl;
    FileRead myfile(cmd);

    //object for the stack temp class
    GenStack<char>* delim = new GenStack<char>();
////////////////////////////////////////////////////////////////////
    int i = 0;
    while (i < myfile.line_no) //while loop for iterating line by line
    {
      string line = myfile.getLine(i);
      ParseLine(delim, line, i); //helper function for most stack operations
////////////////////////////////////////////////////////////////////
      if (!delim->isEmpty()) //check if the stack is empty (empty means all delims match)
      {
        if (delim->peek() != '{') //cases if delim is () or []
        {
          if (delim->peek() == '(')
          {
            cout << "Missing ) at line " << i + 1 << endl;
            break;
          }
          else if (delim->peek() == '[')
          {
            cout << "Missing ] at line " << i + 1 << endl;
            break;
          }
        }
        else //case if delim is {}
        {
          if (i = myfile.line_no - 1)
          {
            cout << "Reached end of file, missing } at line " << endl;
            break;
          }
        }
      }
      i++;
    }
////////////////////////////////////////////////////////////////////////////
//prompt the user to answer if they would like to enter another file or exit
    char response;
    cout << "Would you like to enter another file location?" << endl;
    cout << "Enter 'Y' for yes, and 'N' for no." << endl;
    cin >> response;

    if(response == 'Y' || response == 'y') //case does not matter
    {
      cout << "Enter new file to be analyzed" << endl;
      cin >> cmd; //new command line argument by user input
      Yes = true;
    }
    if(response == 'N' || response == 'n') //case does not matter
    {
      Yes = false; //restart while loop
      cout << "Exiting program..." << endl;
    }
    else //if response is none of the choices
    {
      cout << "Not a valid response. Exiting program..." << endl;
      Yes = false;
    }
  }
///////////////////////////////////////////////////////////////////////
exit(0);
return 0;
}
