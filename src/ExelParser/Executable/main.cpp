#include <iostream>
#include <../includes/Lib/Lib.hpp>

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");
  ProgrammStart:
  cout << "введите цифру для выбора функционала или напишите 0 для выхода из программы :\n";
  cout << "1)преобразовать CSV в Exel\n";
  cout << "2)Создать календарь\n";
  cout << "3)Создать Расписание\n";
  cout << "4)Создать таблицу QR кодов\n";
  int n;
  cin >> n;
  while (n != 0) {
    if (n == 1) {
      Workbook CSV;
      CSV.CreateConvertXlsxFile();
      CSV.Convert_CSV();
      goto ProgrammStart;
}
    if (n == 2) {
      Workbook Calendar;
      Calendar.CreateXlsxFile();
      Calendar.CreateCalendar();
      goto ProgrammStart;
      }
    if (n == 3) {
      Workbook syllabus;
      syllabus.CreateXlsxFile();
      syllabus.CreateSyllabusTable();
      goto ProgrammStart;
      }
    if (n == 4) {
    Workbook QRTable;
    QRTable.CreateXlsxFile();
    QRTable.CreateQRTable();
    goto ProgrammStart;
    }
    }
    cout << "End Programm, Bye!" << endl;
    return 0;
}