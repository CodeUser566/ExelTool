#include <../includes/Lib/Lib.hpp>
#include <csetjmp>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <png.h>
#include <pngconf.h>
#include <qrencode.h>
#include <string>
#include <vector>
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

bool::Workbook::CreateQR(std::string Text,std::string Filename,const int ImgScale){
QRcode *QRcode = QRcode_encodeString(Text.c_str(),10,QR_ECLEVEL_M,QR_MODE_8,1);
if (!QRcode) {
std::cerr << "ошибка генерации кода!\n";
return false;
}
//масштабирование пикселей QR кода к изображению

//размеры изображения
const int imgWidth = QRcode->width * ImgScale;

//буфер изображения (RGBA)
std::vector<unsigned char> imgDataBuffer(imgWidth * imgWidth * 4);
for (int y = 0;y < QRcode->width;y++) {
  for (int x = 0;x < QRcode->width;x++) {
  //булевая операция по распознаванию цвета
  const bool isBlack = QRcode->data[y * QRcode->width + x] & 1;
  //заполнение области масштабирования
  for (int iy= 0; iy < ImgScale; iy++) {
    for (int ix = 0; ix < ImgScale; ix++) {
      int Pixelindex = ((y*ImgScale+iy)*imgWidth + (x*ImgScale+ix)) * 4;

      if (isBlack) {
        imgDataBuffer[Pixelindex + 0] = 0;   //R
        imgDataBuffer[Pixelindex + 1] = 0;   //G
        imgDataBuffer[Pixelindex + 2] = 0;   //B
        imgDataBuffer[Pixelindex + 3] = 255; //A
      }else {
        imgDataBuffer[Pixelindex + 0] = 255; //R
        imgDataBuffer[Pixelindex + 1] = 255; //G
        imgDataBuffer[Pixelindex + 2] = 255; //B
        imgDataBuffer[Pixelindex + 3] = 255; //A
      }
    }
  }
}
}
    // Сохранение в PNG
    FILE* FilePointer = fopen(Filename.c_str(), "wb");
    if (!FilePointer) {
      std::cerr << "ошибка открытия файла!\n";
      QRcode_free(QRcode);
      return false;
    }
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
      std::cerr << "Ошибка генерации PNG структуры!";
      fclose(FilePointer);
      QRcode_free(QRcode);
      return false;
    }
    png_infop info = png_create_info_struct(png);
    if (!info) {
      std::cerr << "Ошибка генерации PNG info структуры!";
      png_destroy_write_struct(&png, NULL);
      fclose(FilePointer);
      QRcode_free(QRcode);
      return false;
    }
    if (setjmp(png_jmpbuf(png))) {
      png_destroy_write_struct(&png, &info);
      fclose(FilePointer);
      QRcode_free(QRcode);
      return false;
    }
    png_init_io(png,FilePointer);
    png_set_IHDR(
      png, info,
      imgWidth, imgWidth,
      8, PNG_COLOR_TYPE_RGBA,
      PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_DEFAULT,
      PNG_FILTER_TYPE_DEFAULT
    );

    std::vector<png_bytep> RowPointers(imgWidth);
    for (int y = 0;y < imgWidth; y++) {
      RowPointers[y] = &imgDataBuffer[y* imgWidth * 4];
    }

    // Запись данных 
    png_write_info(png, info); //Заголовок
    png_write_image(png, RowPointers.data()); //Запись пикселей 
    png_write_end(png, NULL); //Завершение записи

    // Очистка
    png_destroy_write_struct(&png, &info);
    fclose(FilePointer);
    QRcode_free(QRcode);

    return true;
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

void Workbook::CreateQRTable(){
  std::string Name;
  std::string Email;
  std::string Phone;
  std::cout << "Введите ФИО, для Выхода введите 0:\n";
  std::cin >> Name;
  if (Name != "0") {
    std::cout << "Введите Email:\n";
    std::cin >> Email;
    if (CreateQR(Email,"/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/QRcodes/QR.png",4)) {
      std::cout << "Qr Успешно создан!\n";
    }
    else {std::cerr << "Ошибка создания QR!\n";}
    std::cout << "Введите телефон:\n";
    std::cin >> Phone;
    if (CreateQR(Phone,"/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/QRcodes/QR.png",4)) {
      std::cout << "Qr Успешно создан!\n";
    }
    else {std::cerr << "Ошибка создания QR!\n";}
  }




if (CreateQR("This a Test QR code!","/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/QRcodes/QR.png",4)) {
  std::cout << "Qr успешно создан!\n";
}else {
std::cerr << "ошибка создания QR!\n";
}
}