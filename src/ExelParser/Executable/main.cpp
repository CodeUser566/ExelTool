#include <clocale>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <xlsxwriter/workbook.h>
#include <xlsxwriter/worksheet.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");

  //обернуть в функцию, возможно создать класс
  string Path;
  string Line;
  string SavePath;
  fstream CSV_Read;
  CSV_Read.exceptions(ifstream::badbit|ifstream::failbit); 


  cout << "Введите путь до файла:";
  getline(cin,Path);

  cout << "введите путь сохранения файла:";
  getline(cin,SavePath);

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

//имя файла и путь к файлу
  int lastsym;
  lastsym = Path.rfind('/');
  string Filename = Path.substr(lastsym + 1);
  Filename.erase(lastsym = Filename.rfind('.'));
  SavePath = SavePath + Filename + ".xlsx";
  const char* workbookName = SavePath.c_str();

  //создание таблицы и переменных для цикла
  lxw_workbook *workbook = workbook_new(workbookName);
  lxw_worksheet *worksheet = workbook_add_worksheet(workbook,nullptr);
  int row = 0;
  int collum = 0;
  string acc;

//считывание файла
  while (!CSV_Read.eof()) 
  {
    getline(CSV_Read,Line);
    for (int i = 0; i < Line.size(); i++) 
  {
  char CurrentSymbol = Line[i];
  if (CurrentSymbol == ';')
  {
    worksheet_write_string(worksheet, row, collum, acc.c_str(), NULL);
    acc.clear();
    collum++;
    continue;
  }
  acc += CurrentSymbol;
  }
  if (!acc.empty()) 
  {
   worksheet_write_string(worksheet, row, collum, acc.c_str(), NULL);
   collum = 0;
   acc.clear();
   row++;
  }
  }
  return workbook_close(workbook);
 
  

  CSV_Read.close();

  cout << "Bye!" << endl;
  return 0;
}