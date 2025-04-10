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
      Workbook CSV;
      CSV.CreateConvertWorkbook();
      CSV.CSV_Convert();
      goto ProgrammStart;
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
