#include <map>
#include <xlsxwriter.h>
#include <xlsxwriter/workbook.h>


class calendar
{
    private:
    lxw_workbook *YearCalendar;
    std::map<int, lxw_worksheet*> months;
    public:
    calendar(const char* Path)
    {
        lxw_workbook *YearCalendar = workbook_new(Path);
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
    }
    ~calendar()
    {
        workbook_close(YearCalendar);
    };
     void Insert29Days(int moth,int row, int col)
      {
        for (int i = 0;i < 30;i++) 
          {
            worksheet_write_number(months[moth], row, col, row, nullptr);
          }
      }
};
