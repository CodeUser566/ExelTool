#include <fstream>
#include <map>
#include <xlsxwriter.h>
#include <xlsxwriter/workbook.h>
#ifndef CALENDAR
#define CALENDAR

class calendar
{
    private:
    lxw_workbook *Calendar = workbook_new("/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/Exel/YearCalendar.xlsx");
    std::map<int, lxw_worksheet*> months;

    void Insert29Days(int month);
    void Insert28Days(int month);
    void Insert30Days(int month);
    void Insert31Days(int month);
    
    public:
    calendar();
    ~calendar();

    void MakeMonthCalendar();
    void MakeYearCalendar();
    void MakeLeapYearCalendar();
};
#endif

#ifndef WORKBOOK
#define WORKBOOK
class Workbook
{
    private:
    lxw_workbook *workbook;
    std::fstream ConvertFile;

    
    public:

    void CreateCalendarWorkbook();
    void CreateConvertWorkbook();
    void CSV_Convert();

    Workbook();
    ~Workbook();
};
#endif