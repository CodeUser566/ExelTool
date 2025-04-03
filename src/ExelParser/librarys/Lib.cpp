#include <../includes/Lib/Lib.hpp>

calendar::calendar()
{}

calendar::~calendar()
{
    workbook_close(Calendar);
}
void calendar::Insert29Days(int month)
{
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
void calendar::Insert28Days(int month)
{
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
void calendar::Insert30Days(int month)
{
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
void calendar::Insert31Days(int month)
{
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
void calendar::MakeYearCalendar()
{
  months[1] = workbook_add_worksheet(Calendar,"январь");
  Insert31Days(1);
  months[2] = workbook_add_worksheet(Calendar,"февраль");
  Insert29Days(2);
  months[3] = workbook_add_worksheet(Calendar,"март");
  Insert31Days(3);
  months[4] = workbook_add_worksheet(Calendar,"апрель");
  Insert30Days(4);
  months[5] = workbook_add_worksheet(Calendar,"май");
  Insert31Days(5);
  months[6] = workbook_add_worksheet(Calendar,"июнь");
  Insert30Days(6);
  months[7] = workbook_add_worksheet(Calendar,"июль");
  Insert31Days(7);
  months[8] = workbook_add_worksheet(Calendar,"август");
  Insert31Days(8);
  months[9] = workbook_add_worksheet(Calendar,"сентябрь");
  Insert30Days(9);
  months[10] = workbook_add_worksheet(Calendar,"октябрь");
  Insert31Days(10);
  months[11] = workbook_add_worksheet(Calendar,"ноябрь");
  Insert30Days(11);
  months[12] = workbook_add_worksheet(Calendar,"декабрь");
  Insert31Days(12);
}
void calendar::MakeMonthCalendar(int month)
{
  
}