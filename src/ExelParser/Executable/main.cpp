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
  ProgrammStart:
  cout << "введите цифру для выбора функционала или 0 для выхода из программы :" << endl;
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
  getline(cin,Path);
  cout << "введите путь сохранения файла:" << endl; //сделать отдельно как путь для сохранения таблиц.
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
      cout << "вам нужен календарь на год (1) или на месяц (2) ? :  для выхода выберите 0" << endl;
      int P;
      cin >> P;
      if (P==1) 
      {
        cout << "на какой год нужен календарь? : ";
        int Year;
        cin >> Year;
        if (Year % 4 == 0)
        {
          cout << "введите путь сохранения файла(пока нет реализации) :";
          lxw_workbook *YearCalendar = workbook_new("/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/Exel/YearCalendar.xlsx");
          //господи иисусе. Это надо спрятать
          lxw_worksheet *WorksheetJanuary = workbook_add_worksheet(YearCalendar,"Январь");
          int row = 0;
          int col = 0;
          for (int row;row < 31;row++) 
          {
            worksheet_write_number(WorksheetJanuary, row, col, row + 1, nullptr);
            if (row % 4)
            {
              col++;
            }
          }
          lxw_worksheet *WorksheetFebruary = workbook_add_worksheet(YearCalendar,"Февраль");

          lxw_worksheet *WorksheetMarch = workbook_add_worksheet(YearCalendar,"март");

          lxw_worksheet *WorksheetApril = workbook_add_worksheet(YearCalendar,"апрель");

          lxw_worksheet *WorksheetMay = workbook_add_worksheet(YearCalendar,"май");

          lxw_worksheet *WorksheetJune = workbook_add_worksheet(YearCalendar,"июнь");

          lxw_worksheet *WorksheetJuly = workbook_add_worksheet(YearCalendar,"июль");

          lxw_worksheet *WorksheetAugust  = workbook_add_worksheet(YearCalendar,"август");

          lxw_worksheet *WorksheetSeptember = workbook_add_worksheet(YearCalendar,"сентябрь");

          lxw_worksheet *WorksheetOctober = workbook_add_worksheet(YearCalendar,"октябрь");

          lxw_worksheet *WorksheetNovember = workbook_add_worksheet(YearCalendar,"ноябрь");

          lxw_worksheet *WorksheetDecember  = workbook_add_worksheet(YearCalendar,"декабрь");

          workbook_close(YearCalendar);
          cout << "Календарь создан! Приятного пользования" << endl;
          goto TryAgain;
        }
      }
      else if (P==2) 
      {
        //тут стоит использовать словарь ключ-значение
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