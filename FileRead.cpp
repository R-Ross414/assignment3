
#include "FileRead.h"
#include <iostream>
#include <fstream>
#include <string>

//////////////////////////////////////////////////////////////////////
FileRead::FileRead() //default constructor
{
  FileName = "";
  lines = NULL;
}
//////////////////////////////////////////////////////////////////////
FileRead::FileRead(string fileName) //overloaded constructor
{
  //this constructor handles most of the initial processing of the source code
  FileName = fileName;
  Stream.open(fileName);
  string line = "";
  int i = 0;

  while(getline(Stream, line))
  {
    i++;
  }

  line_no = i;
  lines = new string[line_no];

  Stream.close();
  Stream.open(fileName);

  i = 0;

  while(getline(Stream, line))
  {
    lines[i] = line;
    i++;
  }
}
//////////////////////////////////////////////////////////////
FileRead::~FileRead() {} //destructor

//////////////////////////////////////////////////////////////
void FileRead::printFile() //void method for printing the file lines
{
  string line = "";

  for (int i = 0; i < line_no; i++)
  {
    cout << lines[i] << endl;
  }

  Stream.close();
  Stream.open(FileName);
}
//////////////////////////////////////////////////////////////
string FileRead::getLine(int linenum) //solely returns source code lines as strings 
{
  return lines[linenum];
}
