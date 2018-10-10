#include "GenStack.h"
#include "FileRead.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  //trying to make cmd line arg work
  string FileName;
  cout << "Enter a source code file to analyze" << endl;
  cout << "Analyzing 'Input.cpp'..." << endl;
  //cin >> FileName;
  //FileRead* file = new FileRead(argc);
  FileRead* file = new FileRead("Input.cpp");
  //file->printFile();

  /*for (int i = 0; i < file->line_no; i++)
  {
    cout << "Line number: " << i + 1 << endl;
    cout << file->getLine(i) << endl;
  }; */

  GenStack<string> codeLines();
  GenStack<char> errorLine();

  int i = 0;
  while(i < file->line_no)
  {
    int j = file->getLine(i).length();
    int k;
    cout << "number of chars in  " << i + 1 << " : " << j << endl;
    while(k < j)
    {
      
    }
    i++;
  }

  /*int i = 0;

  while(i < file->line_no)
  {
    int j = 0;

    while(j < file->getLine(i).length())
    {

    }

    i++;
  } */
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
