#include <../includes/Lib/Lib.hpp>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <xlsxwriter/workbook.h>
#include <xlsxwriter/worksheet.h>



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


void Workbook::Insert29Days(int month){
  int row = 0;
  int col = 0;
  for (int i = 1;i < 30;i++) 
    {
      worksheet_write_number(WorksheetPointer[month], row, col, i, nullptr);
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
      worksheet_write_number(WorksheetPointer[month], row, col, i, nullptr);
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
      worksheet_write_number(WorksheetPointer[month], row, col, i, nullptr);
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
      worksheet_write_number(WorksheetPointer[month], row, col, i, nullptr);
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
  WorksheetPointer[1] = workbook_add_worksheet(workbook,"январь");
  Insert31Days(1);
  WorksheetPointer[2] = workbook_add_worksheet(workbook,"февраль");
  Insert29Days(2);
  WorksheetPointer[3] = workbook_add_worksheet(workbook,"март");
  Insert31Days(3);
  WorksheetPointer[4] = workbook_add_worksheet(workbook,"апрель");
  Insert30Days(4);
  WorksheetPointer[5] = workbook_add_worksheet(workbook,"май");
  Insert31Days(5);
  WorksheetPointer[6] = workbook_add_worksheet(workbook,"июнь");
  Insert30Days(6);
  WorksheetPointer[7] = workbook_add_worksheet(workbook,"июль");
  Insert31Days(7);
  WorksheetPointer[8] = workbook_add_worksheet(workbook,"август");
  Insert31Days(8);
  WorksheetPointer[9] = workbook_add_worksheet(workbook,"сентябрь");
  Insert30Days(9);
  WorksheetPointer[10] = workbook_add_worksheet(workbook,"октябрь");
  Insert31Days(10);
  WorksheetPointer[11] = workbook_add_worksheet(workbook,"ноябрь");
  Insert30Days(11);
  WorksheetPointer[12] = workbook_add_worksheet(workbook,"декабрь");
  Insert31Days(12);
}

void::Workbook::MakeMonthCalendar(int Year,int month){
  if (Year % 4 == 0) {
  switch (month) {
    case 1:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "январь");
    Insert31Days(1);
    break;
    case 2:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "февраль");
    Insert29Days(1);
    break;
    case 3:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "март");
    Insert31Days(1);
    break;
    case 4:
    workbook_add_worksheet(workbook, "апрель");
    Insert30Days(1);
    break;
    case 5:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "май");
    Insert31Days(1);
    break;
    case 6:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "июнь");
    Insert30Days(1);
    break;
    case 7:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "июль");
    Insert31Days(1);
    break;
    case 8:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "август");
    Insert31Days(1);
    break;
    case 9:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "сентябрь");
    Insert30Days(1);
    break;
    case 10:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "октябрь");
    Insert31Days(1);
    break;
    case 11:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "ноябрь");
    Insert30Days(1);
    break;
    case 12:
    WorksheetPointer[1] = workbook_add_worksheet(workbook, "декабрь");
    Insert31Days(1);
    break;
  }
  }
  else {
    switch (month) {
      case 1:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "январь");
      Insert31Days(1);
      break;
      case 2:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "февраль");
      Insert28Days(1);
      break;
      case 3:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "март");
      Insert31Days(1);
      break;
      case 4:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "апрель");
      Insert30Days(1);
      break;
      case 5:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "май");
      Insert31Days(1);
      break;
      case 6:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "июнь");
      Insert30Days(1);
      break;
      case 7:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "июль");
      Insert31Days(1);
      break;
      case 8:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "август");
      Insert31Days(1);
      break;
      case 9:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "сентябрь");
      Insert30Days(1);
      break;
      case 10:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "октябрь");
      Insert31Days(1);
      break;
      case 11:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "ноябрь");
      Insert30Days(1);
      break;
      case 12:
      WorksheetPointer[1] = workbook_add_worksheet(workbook, "декабрь");
      Insert31Days(1);
      break;
  }
}
}

void::Workbook::MakeLeapYearCalendar(){
  WorksheetPointer[1] = workbook_add_worksheet(workbook,"январь");
  Insert31Days(1);
  WorksheetPointer[2] = workbook_add_worksheet(workbook,"февраль");
  Insert28Days(2);
  WorksheetPointer[3] = workbook_add_worksheet(workbook,"март");
  Insert31Days(3);
  WorksheetPointer[4] = workbook_add_worksheet(workbook,"апрель");
  Insert30Days(4);
  WorksheetPointer[5] = workbook_add_worksheet(workbook,"май");
  Insert31Days(5);
  WorksheetPointer[6] = workbook_add_worksheet(workbook,"июнь");
  Insert30Days(6);
  WorksheetPointer[7] = workbook_add_worksheet(workbook,"июль");
  Insert31Days(7);
  WorksheetPointer[8] = workbook_add_worksheet(workbook,"август");
  Insert31Days(8);
  WorksheetPointer[9] = workbook_add_worksheet(workbook,"сентябрь");
  Insert30Days(9);
  WorksheetPointer[10] = workbook_add_worksheet(workbook,"октябрь");
  Insert31Days(10);
  WorksheetPointer[11] = workbook_add_worksheet(workbook,"ноябрь");
  Insert30Days(11);
  WorksheetPointer[12] = workbook_add_worksheet(workbook,"декабрь");
  Insert31Days(12);
}

//Public функции

void Workbook::SyllabusDay(int &row,int &col,std::string Day){
  std::string LessonName;
  std::string LessonTime;
  std::string LessonRoom;
  Start:
  std::cout << "Введите название предмета, для выхода напишите 0:\n";
  std::cin >> LessonName;
  if (LessonName != "0") 
  {
    worksheet_write_string(WorksheetPointer[1], row,col, Day.c_str(),nullptr);
    col++;
    worksheet_write_string(WorksheetPointer[1],row,col,LessonName.c_str(),nullptr); 
    col++;
    std::cout << "Введите время:\n";
    std::cin  >> LessonTime;
    worksheet_write_string(WorksheetPointer[1],row,col,LessonTime.c_str(),nullptr);
    col++;
    std::cout << "Введите аудиторию\n";
    std::cin >> LessonRoom;
    worksheet_write_string(WorksheetPointer[1],row,col,LessonRoom.c_str(),nullptr);
    col = 0;
    row++;
    goto Start;
  }
  else 
  {
    std::cout << "Ввод окончен!\n";
  }
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

void Workbook::CreateSyllabusTable(){
  int D;
  int row = 0;
  int col = 0;
  WorksheetPointer[1] = workbook_add_worksheet(workbook, NULL);
  worksheet_write_string(WorksheetPointer[1], row, col, "День", nullptr);
  col = col++;
  worksheet_write_string(WorksheetPointer[1], row, col, "Предмет", nullptr);
  col = col++;
  worksheet_write_string(WorksheetPointer[1], row, col, "Время", nullptr);
  col = col++;
  worksheet_write_string(WorksheetPointer[1], row, col, "Аудитория", nullptr);
  row = row++;
  Start:
  std::cout << "Выберите день недели, для выхода выберите 0 :\n";
  std::cout 
  << "1)понедельник\n" 
  << "2)вторник\n" 
  << "3)среда\n" 
  << "4)Четверг\n" 
  << "5)Пятница\n" 
  << "6)Суббота\n" 
  << "7)Воскресенье\n";
  std::cin >> D;
  if (D >= 0 and D <=7) {
    while (D != 0) {
      switch (D) 
      {
        case 1:
        SyllabusDay(row,col,"Понедельник");
        goto Start;
        case 2:
        SyllabusDay(row,col,"Вторник");
        goto Start;
        case 3:
        SyllabusDay(row,col,"Среда");
        goto Start;
        case 4:
        SyllabusDay(row,col,"Четверг");
        goto Start;
        case 5:
        SyllabusDay(row,col,"Пятница");
        goto Start;
        case 6:
        SyllabusDay(row,col,"Суббота");
        goto Start;
        case 7:
        SyllabusDay(row,col,"Воскресенье");
        goto Start;
      }
    }
  }
  else {
    std::cout << "Введённое значение находится вне диапазона или не соответствует формату числа. Введите значение заного\n";
    goto Start;
  }
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
      MakeYearCalendar();
      std::cout << "Календарь создан! Приятного использования!\n";
    }
    else 
    {
      MakeLeapYearCalendar();
      std::cout << "Календарь создан! Приятного использования!\n";
    }
  }
  else if (P==2) {
    int Y;
    int M;
    std::cout << "Какой год? Укажите цифрой:\n";
    //Добавить проверку на ввод года
    std::cin >> Y;
    std::cout << "на какой месяц нужен календарь? Укажите цифрой от 1 до 12:\n";
    //Добавить проверку на ввод месяца
    std::cin >> M;
    MakeMonthCalendar(Y,M);
    std::cout << "Календарь на месяц создан! Приятного использования!\n";
  }
  else if (P == 0) {
    return;
  }
  else {
    std::cout << "выберите 1 или 2\n";
    goto TryAgain;
}
}

void Workbook::CreateChessTable(){
  
}
