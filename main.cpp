#include "ParseFile.h"
#include "FileRead.h"
#include <iostream>
#include <fstream> //(?)

using namespace std;

int main(int argc, char **argv)
{
  bool Yes;
  Yes = true;
  string cmd = argv[1];

////////////////////////////////////////////////////////////////////
  while(Yes)
  {
    //cout << "Enter a source code file to analyze" << endl;
    cout << "Analyzing " << cmd << "..." << endl;
    FileRead myfile(cmd);

    //object for the stack temp class
    GenStack<char>* delim = new GenStack<char>();

  ////////////////////////////////////////////////////////////////////
    int i = 0;
    while (i < myfile.line_no)
    {
      string line = myfile.getLine(i);
      ParseLine(delim, line, i);

  ////////////////////////////////////////////////////////////////////
      if (!delim->isEmpty())
      {
        if (delim->peek() != '{')
        {
          if (delim->peek() == '(')
          {
            cout << "Missing ) at line " << i + 1 << endl;
          }
          else if (delim->peek() == '[')
          {
            cout << "Missing ] at line " << i + 1 << endl;
          }
        }
        else
        {
          if (i = myfile.line_no - 1)
          {
            cout << "Missing } at line " << i << endl;
          }
        }
      }
  /*algorithm
        //make file line an object
        //iterate through each char
        //if it is a [{( add to stack
        //if it is )}] then pop (if a match)
        //store the index of the stack */
      i++;
    }

  ////////////////////////////////////////////////////////////////////
    char response;
    cout << "Would you like to enter another file location?" << endl;
    cout << "Enter 'Y' for yes, and 'N' for no." << endl;
    cin >> response;

    if(response == 'Y' || response == 'y')
    {
      cout << "Enter new file location" << endl;
      cin >> cmd;
      Yes = true;
    }
    if(response == 'N' || response == 'n')
    {
      Yes = false;
    }
  }

cout << "program done" << endl;

  /*GenStack<char> myStack(10);

  myStack.push('R');
  myStack.push('O');
  myStack.push('S');
  myStack.push('S');

  myStack.print();
  cout << "peek-a-boo :" << myStack.peek() << endl;
  cout << "popping :" << myStack.pop() << endl;

  myStack.push('R');
  cout << "peek-a-boo :" << myStack.peek() << endl;
  cout << "popping :" << myStack.pop() << endl;

  myStack.print();
  while(!myStack.isEmpty())
  {
    cout << "popping :" << myStack.pop() << endl;
  };
*/
  return 0;
}
