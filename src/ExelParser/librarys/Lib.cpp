#include <../includes/Lib/Lib.hpp>

calendar::calendar()
{
    months[1] = workbook_add_worksheet(YearCalendar,"январь");
    months[2] = workbook_add_worksheet(YearCalendar,"февраль");
    months[3] = workbook_add_worksheet(YearCalendar,"март");
    months[4] = workbook_add_worksheet(YearCalendar,"апрель");
    months[5] = workbook_add_worksheet(YearCalendar,"май");
    months[6] = workbook_add_worksheet(YearCalendar,"июнь");
    months[7] = workbook_add_worksheet(YearCalendar,"июль");
    months[8] = workbook_add_worksheet(YearCalendar,"август");
    months[9] = workbook_add_worksheet(YearCalendar,"сентябрь");
    months[10] = workbook_add_worksheet(YearCalendar,"октябрь");
    months[11] = workbook_add_worksheet(YearCalendar,"ноябрь");
    months[12] = workbook_add_worksheet(YearCalendar,"декабрь");
};
calendar::~calendar()
{
    workbook_close(YearCalendar);
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