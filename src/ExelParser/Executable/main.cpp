#include <OpenXLSX/headers/XLCell.hpp>
#include <OpenXLSX/headers/XLCellReference.hpp>
#include <OpenXLSX/headers/XLDocument.hpp>
#include <OpenXLSX/headers/XLWorkbook.hpp>
#include <clocale>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <ostream>
#include <string>
#include "OpenXLSX/OpenXLSX.hpp"

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");

  //обернуть в функцию, возможно создать класс
  string Path;
  string Line;
  string acc;
  fstream CSV_Read;
  list<string> Headers;
  int lastsym;
  CSV_Read.exceptions(ifstream::badbit|ifstream::failbit); 


  cout << "Введите путь до файла:";
  getline(cin,Path);

  try
  {
    CSV_Read.open(Path,fstream::in | fstream::out);
  } 
  catch (const ifstream::failure & ex) 
  {
    cout << "Ошибка открытия файла, Проверьте правильность написания файла.Также убедитесь что формат файла .CSV" << endl;
    cout << ex.what() << endl;
    cout << ex.code() << endl;
  }

//имя файла 
  lastsym = Path.rfind('/');
  string Filename = Path.substr(lastsym + 1);
  Filename.erase(lastsym = Filename.rfind('.'));


  while (!CSV_Read.eof()) 
  {
    getline(CSV_Read,Line);
    for (int i = 0; i <= Line.length(); i++) 
  {
  char CurrentSymbol = Line[i];
  if (CurrentSymbol == ',')
  {
    Headers.push_front(acc);
    acc.clear();
    continue;
  }
  acc += CurrentSymbol;
  }
  if (!acc.empty()) 
  {
  acc.erase('\0');
  Headers.push_front(acc);
  acc.clear();
  }
  }

  
  OpenXLSX::XLDocument doc;
  doc.create("/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/Exel/" + Filename + ".xlsx");
  auto wks = doc.workbook().worksheet("Sheet1");
  doc.save();
  CSV_Read.close();

  cout << "Bye!" << endl;
  return 0;
}