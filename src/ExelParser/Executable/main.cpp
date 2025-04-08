#include <clocale>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <xlsxwriter/workbook.h>
#include <xlsxwriter/worksheet.h>
#include <../includes/Lib/Lib.hpp>

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");
  ProgrammStart:
  cout << "введите цифру для выбора функционала или напишите 0 для выхода из программы :" << endl;
  cout << "1)преобразовать CSV в Exel" << endl;
  cout << "2)Создать календарь" << endl;
  int n;
  cin >> n;
  while (n != 0) {
    if (n == 1) {
  //обернуть в функцию, возможно создать класс
  string Path;
  string Line;
  string SavePath;
  fstream CSV_Read;
  CSV_Read.exceptions(ifstream::badbit|ifstream::failbit); 
  cout << "Введите путь до файла:" << endl;
  cin >> Path;
  cout << "введите путь сохранения файла:" << endl; //сделать отдельно как путь для сохранения таблиц.
  cin >> SavePath;
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
    worksheet_write_string(worksheet, row, collum, acc.c_str(), nullptr);
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
}
    if (n == 2) {
      TryAgain:
      cout << "вам нужен календарь на год (1) или на месяц (2) ? :  для выхода напишите 0" << endl;
      int P;
      cin >> P;
      if (P==1) 
      {
        cout << "на какой год нужен календарь? : ";
        int Year;
        cin >> Year;
        if (Year % 4 == 0)
        {
          cout << "введите путь сохранения файла(пока нет реализации) :" << endl;
          calendar Year;
          Year.MakeYearCalendar();
          cout << "Календарь создан! Приятного пользования" << endl;
          goto TryAgain;
        }
        else 
        {
          cout << "введите путь сохранения файла(пока нет реализации) :" << endl;
          calendar LeapYear;
          LeapYear.MakeLeapYearCalendar();
          cout << "Календарь создан! Приятного пользования" << endl;
          goto TryAgain;
        }
      }
      else if (P==2) 
      {
        
      }
      else if (P == 0) 
      {
        goto ProgrammStart;
      }
      else 
      {
        cout << "выберите 1 или 2" << endl;
        goto TryAgain;
      }
    }
}
cout << "End Programm, Bye!" << endl;
  return 0;
}