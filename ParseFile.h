#include <iostream>
#include "GenStack.h"
#include <string>

using namespace std;

void ParseLineLogic(GenStack<char>* delim, char ch, int line_no)
{
  if (ch == '(')
  {
    delim->push(ch);
  }
  else if (ch == '[')
  {
    delim->push(ch);
  }
  else if (ch == '{')
  {
    delim->push(ch);
  }
  ////////////////////////////////////////////////////////////////////
  else if (ch == ')')
  {
    if (delim->isEmpty())
    {
      cout << "Missing '(' at line " << endl;
      //turn into system exit /////////////
      //break;
    }
    else if (delim->peek() == '(')
    {
      delim->pop();
    }
  }
  ////////////////////////////////////////////////////////////////////
  else if (ch == ']')
  {
    //cout << "hello world" << endl;
    if (delim->isEmpty())
    {
      cout << "Missing '[' at line " << endl;
      //system.exit needed////////
      //break;
    }
    else if (delim->peek() != '[')
    {
      cout << "Missing '[' at line " << endl;
      //system exit//////
        //break;
    }
    else if (delim->peek() == '[')
    {
      delim->pop();
    }
  }
  ////////////////////////////////////////////////////////////////////
  else if (ch == '}')
  {
    if (delim->isEmpty())
    {
      cout << "Missing '{'. See line " << line_no + 1 << endl;
    }
    else if (delim->peek() == '{')
    {
      //cout << "Popping '{'" << endl;
      delim->pop();
    }
  }
}

void ParseLine(GenStack<char>* delim, string line, int line_no)
{
  int j = 0;

  while(j < line.length())
  {
    ParseLineLogic(delim, line[j], line_no);
    j++;
  }
}
