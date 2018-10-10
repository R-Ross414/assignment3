#include "GenStack.h"
#include "FileRead.h"
#include <iostream>
#include <fstream> //(?)

using namespace std;

int main(int argc, char **argv)
{
  bool Yes;
  Yes = true;

////////////////////////////////////////////////////////////////////
while(Yes)
{
  string cmd = argv[1];
  cout << "Enter a source code file to analyze" << endl;
  cout << "Analyzing " << cmd << "..." << endl;
  FileRead myfile(cmd);

  //objects for the stack temp class
  GenStack<char> delim;

////////////////////////////////////////////////////////////////////
  int i = 0;
  while (i < myfile.line_no)
  {
    int j = 0;
    string line = myfile.getLine(i);

    while(j < line.length())
    {
////////////////////////////////////////////////////////////////////
      if (line[j] == '(')
      {
        delim.push(line[j]);
      }
      else if (line[j] == '[')
      {
        delim.push(line[j]);
      }
      else if (line[j] == '{')
      {
        delim.push(line[j]);
      }
////////////////////////////////////////////////////////////////////
      else if (line[j] == ')')
      {
        if (delim.isEmpty())
        {
          cout << "Missing '(' at line " << endl;
          //turn into system exit /////////////
          break;
        }
        else if (delim.peek() == '(')
        {
          delim.pop();
        }
      }
////////////////////////////////////////////////////////////////////
      else if (line[j] == ']')
      {
        //cout << "hello world" << endl;
        if (delim.isEmpty())
        {
          cout << "Missing '[' at line " << endl;
          //system.exit needed////////
          break;
        }
        else if (delim.peek() != '[')
        {
          cout << "Missing '[' at line " << endl;
          //system exit//////
            break;
        }
        else if (delim.peek() == '[')
        {
          delim.pop();
        }
      }
////////////////////////////////////////////////////////////////////
  else if (line[j] == '}')
  {
    if (delim.isEmpty())
    {
      cout << "Missing '{' at line " << i << endl;
    }

    else if (delim.peek() == '{')
    {
      cout << "Popping '{'" << endl;
      delim.pop();
    }
  }

////////////////////////////////////////////////////////////////////
      j++;
    }

////////////////////////////////////////////////////////////////////
    if (!delim.isEmpty())
    {
      if (delim.peek() == '(')
      {
        cout << "Missing ) at line " << i << endl;
      }
      else if (delim.peek() == '[')
      {
        cout << "Missing ] at line " << i << endl;
      }
      if (delim.peek() == '{')
      {
        cout << "Missing } at line " << i << endl;
      }
      break;
    }

      //make file line an object
      //iterate through each char
      //if it is a [{( add to stack
      //if it is )}] then pop (if a match)
      //store the index of the stack
    i++;
  }

////////////////////////////////////////////////////////////////////
char response;
cout << "Would you like to enter another file location?" << endl;
cout << "Enter 'Y' for yes, and 'N' for no." << endl;
cin >> response;

if(response == 'Y' || response == 'y')
{
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
