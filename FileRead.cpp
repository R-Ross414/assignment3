
#include "FileRead.h"
#include <iostream>
#include <fstream>
#include <string>

//////////////////////////////////////////////////////////////////////
FileRead::FileRead()
{
  FileName = "";
  lines = NULL;
}
//////////////////////////////////////////////////////////////////////
FileRead::FileRead(string fileName)
{
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
FileRead::~FileRead() {}
//////////////////////////////////////////////////////////////
void FileRead::printFile()
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
string FileRead::getLine(int linenum)
{
  return lines[linenum];
}
