#include <map>
#include <xlsxwriter.h>
#include <xlsxwriter/workbook.h>
#ifndef CALENDAR
#define CALENDAR

class calendar
{
    private:
    std::map<int, lxw_worksheet*> months;
    lxw_workbook *YearCalendar = workbook_new("/media/gorillabacteria/SSD_2/VScode_Projects/ExelParser/Exel/YearCalendar.xlsx");
    
    public:
    calendar();
    ~calendar();
    void Insert29Days(int month);
    void Insert28Days(int month);
    void Insert30Days(int month);
    void Insert31Days(int month);
    void MakeCalendar();
};
#endif