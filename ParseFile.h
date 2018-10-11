#include <iostream>
#include "GenStack.h"
#include <string>

using namespace std;

/*This helper function deals with the majority of the stack
operations. */
void ParseLineLogic(GenStack<char>* delim, char ch, int line_no)
{
  //push elem based on different cases of opening delimiters
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
  //cases specifically for ()
  else if (ch == ')') //if a ')' is found
  {
    if (delim->isEmpty()) //if there is no element in the stack already
    {
      cout << "Missing '(' at line " << line_no + 1 << endl;
      exit(0);
    }
    else if (delim->peek() == '(')
    {
      delim->pop();
    }
  }
  //////////////////////////////////////////////////////////////////////
  //cases specifically for []
  else if (ch == ']') //if a ']' is found
  {
    if (delim->isEmpty()) //if there is no element in the stack already
    {
      cout << "Missing '[' at line " << line_no + 1 << endl;
      exit(0);
    }
    else if (delim->peek() != '[')
    {
      cout << "Missing '[' at line " << line_no + 1 << endl;
      exit(0);
    }
    else if (delim->peek() == '[')
    {
      delim->pop();
    }
  }
  ////////////////////////////////////////////////////////////////////
  //case for }
  else if (ch == '}')
  {
    if (delim->isEmpty()) //if there is no element in the stack already
    {
      cout << "Reached end of file, missing '{'." << endl;
      exit(0);
    }
    else if (delim->peek() == '{')
    {
      delim->pop();
    }
  }
}

/*This helper function complements the other one and iterates
through the individual characters of the lines in the source code*/
void ParseLine(GenStack<char>* delim, string line, int line_no)
{
  int j = 0;

  while(j < line.length())
  {
    ParseLineLogic(delim, line[j], line_no);
    j++;
  }
}
