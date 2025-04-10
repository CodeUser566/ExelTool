#include <../includes/Lib/Lib.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <xlsxwriter/workbook.h>





void calendar::MakeMonthCalendar(){
  
}
Workbook::Workbook(){
  workbook = workbook_new("/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/Exel/Table.xlsx");
}
Workbook::~Workbook(){
  workbook_close(workbook);
}

void Workbook::CreateXlsxFile(){
  std::string FileSavePath;
  std::string FileName;
  std::cout << "Введите путь сохранения файла\n";
  std::cin >> FileSavePath;
  std::cout << "Введите имя файла\n";
  std::cin >> FileName;

  FileSavePath = FileSavePath + FileName + ".xlsx";
  const char * Workbookname = FileSavePath.c_str();
  workbook = workbook_new(Workbookname);
}

void Workbook::CreateCalendar(){
  TryAgain:
  std::cout << "вам нужен календарь на год (1) или на месяц (2) ? :  для выхода напишите 0\n";
  int P;
  std::cin >> P;
  if (P==1) {
    std::cout << "на какой год нужен календарь? : ";
    int Year;
    std::cin >> Year;
    if (Year % 4 == 0)
    {
      Workbook Calendar;
      Calendar.MakeYearCalendar();
      std::cout << "Календарь создан! Приятного использования!\n";
    }
    else 
    {
      Workbook Calendar;
      Calendar.MakeLeapYearCalendar();
      std::cout << "Календарь создан! Приятного использования!\n";
    }
  }
  else if (P==2) {
    
    goto TryAgain;
  }
  else if (P == 0) {
    return;
  }
  else {
    std::cout << "выберите 1 или 2\n";
    goto TryAgain;
}
}

void Workbook::Insert29Days(int month){
  int row = 0;
  int col = 0;
  for (int i = 1;i < 30;i++) 
    {
      worksheet_write_number(months[month], row, col, i, nullptr);
      if (i %4 == 0)
      {
        row++;
        col = 0;
        continue;
      }
      col++;
    }
}
void Workbook::Insert28Days(int month){
  int row = 0;
  int col = 0;
  for (int i = 1;i < 29;i++) 
    {
      worksheet_write_number(months[month], row, col, i, nullptr);
      if (i %4 == 0)
      {
        row++;
        col = 0;
        continue;
      }
      col++;
    }
}
void Workbook::Insert30Days(int month){
  int row = 0;
  int col = 0;
  for (int i = 1;i < 31;i++) 
    {
      worksheet_write_number(months[month], row, col, i, nullptr);
      if (i %4 == 0)
      {
        row++;
        col = 0;
        continue;
      }
      col++;
    }
}
void Workbook::Insert31Days(int month){
  int row = 0;
  int col = 0;
  for (int i = 1;i < 32;i++) 
    {
      worksheet_write_number(months[month], row, col, i, nullptr);
      if (i %4 == 0)
      {
        row++;
        col = 0;
        continue;
      }
      col++;
    }
}
void::Workbook::MakeYearCalendar(){
  months[1] = workbook_add_worksheet(workbook,"январь");
  Insert31Days(1);
  months[2] = workbook_add_worksheet(workbook,"февраль");
  Insert29Days(2);
  months[3] = workbook_add_worksheet(workbook,"март");
  Insert31Days(3);
  months[4] = workbook_add_worksheet(workbook,"апрель");
  Insert30Days(4);
  months[5] = workbook_add_worksheet(workbook,"май");
  Insert31Days(5);
  months[6] = workbook_add_worksheet(workbook,"июнь");
  Insert30Days(6);
  months[7] = workbook_add_worksheet(workbook,"июль");
  Insert31Days(7);
  months[8] = workbook_add_worksheet(workbook,"август");
  Insert31Days(8);
  months[9] = workbook_add_worksheet(workbook,"сентябрь");
  Insert30Days(9);
  months[10] = workbook_add_worksheet(workbook,"октябрь");
  Insert31Days(10);
  months[11] = workbook_add_worksheet(workbook,"ноябрь");
  Insert30Days(11);
  months[12] = workbook_add_worksheet(workbook,"декабрь");
  Insert31Days(12);
}
void::Workbook::MakeLeapYearCalendar(){
  months[1] = workbook_add_worksheet(workbook,"январь");
  Insert31Days(1);
  months[2] = workbook_add_worksheet(workbook,"февраль");
  Insert28Days(2);
  months[3] = workbook_add_worksheet(workbook,"март");
  Insert31Days(3);
  months[4] = workbook_add_worksheet(workbook,"апрель");
  Insert30Days(4);
  months[5] = workbook_add_worksheet(workbook,"май");
  Insert31Days(5);
  months[6] = workbook_add_worksheet(workbook,"июнь");
  Insert30Days(6);
  months[7] = workbook_add_worksheet(workbook,"июль");
  Insert31Days(7);
  months[8] = workbook_add_worksheet(workbook,"август");
  Insert31Days(8);
  months[9] = workbook_add_worksheet(workbook,"сентябрь");
  Insert30Days(9);
  months[10] = workbook_add_worksheet(workbook,"октябрь");
  Insert31Days(10);
  months[11] = workbook_add_worksheet(workbook,"ноябрь");
  Insert30Days(11);
  months[12] = workbook_add_worksheet(workbook,"декабрь");
  Insert31Days(12);
}


void Workbook::CreateConvertXlsxFile(){
  ConvertFile.exceptions(std::ifstream::badbit|std::ifstream::failbit);
  int lastsym;
  std::string FilePath;
  std::string FileSavePath;
  const char* Workbookname;
  
  std::cout << "Введите путь до файла :\n";
  std::cin >> FilePath;
  try
  {
    ConvertFile.open(FilePath,std::fstream::in | std::fstream::out);
  } 
  catch (const std::ifstream::failure & ex) 
  {
    std::cout << "Ошибка открытия файла, Проверьте правильность написания файла.Также убедитесь что формат файла .CSV\n";
    std::cout << ex.what() << std::endl;
    std::cout << ex.code() << std::endl;
  }
  lastsym = FilePath.rfind('/');
  FilePath = FilePath.substr(lastsym + 1);
  FilePath.erase(lastsym = FilePath.rfind('.'));
  std::cout << "Введите путь сохранения файла : \n";
  std::cin >> FileSavePath;
  FileSavePath = FileSavePath + FilePath + ".xlsx";
  Workbookname = FileSavePath.c_str();
  workbook = workbook_new(Workbookname);
  std::cout << "Файл Exel создан\n";
}
 //создание Листа и переменных для цикла
 void Workbook::Convert_CSV(){
 int row = 0;
 int collum = 0;
 std::string acc;
 std::string Line;
 lxw_worksheet *worksheet = workbook_add_worksheet(workbook,nullptr);
//считывание файла
 while (!ConvertFile.eof()) 
 {
   getline(ConvertFile,Line);
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
 ConvertFile.close();
 std::cout << "Файл конвертирован!\n";
}