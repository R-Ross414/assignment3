#include "GenStack.h"
#include "FileRead.h"
#include <iostream>
#include <fstream> //(?)

using namespace std;

int main(int argc, char **argv)
{
  //trying to make cmd line arg work
  //string FileName;
  cout << "Enter a source code file to analyze" << endl;
  cout << "Analyzing 'Input.cpp'..." << endl;
  //cin >> FileName;
  //FileRead* file = new FileRead(argc);
  FileRead* file = new FileRead("Input.cpp");
  //file->printFile();

  GenStack<string> codeLines();
  GenStack<char> delim;

  int i = 0;
  while(i < file->line_no)
  {
    int j = 0;
    string line = file->getLine(i);
    while(j < line.length())
    {
      if (line[j] == '(')
      {
        delim.push(line[j]);
      }

      else if (line[j] == '[')
      {
        delim.push(line[j]);
      }

      else if (line[j] == ')')
      {
        if (delim.isEmpty())
        {
          cout << "Missing '(' at line " << i << endl;
          //turn into system exit /////////////
          break;
        }

        else if (delim.peek() == '(')
        {
          delim.pop();
        }
      }

      else if (line[j] == ']')
      {
        if (delim.isEmpty())
        {
          cout << "Missing '[' at line " << i << endl;
          //system.exit needed////////
          break;
        }

        else if (delim.peek() == '[')
        {
          delim.pop();
        }
      }
      j++;
    }

    if (!delim.isEmpty())
    {
      cout << "Missing ')' at line " << i << endl;
      break;
    }

      //make file line an object
      //iterate through each char
      //if it is a [{( add to stack
      //if it is )}] then pop (if a match)
      //store the index of the stack
    i++;
  }

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
