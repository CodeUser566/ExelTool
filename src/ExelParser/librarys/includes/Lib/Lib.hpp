#include <fstream>
#include <map>
#include <xlsxwriter.h>
#include <xlsxwriter/workbook.h>
#ifndef CALENDAR
#define CALENDAR

class calendar
{
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
    std::map<int, lxw_worksheet*> months;

    public:
    Workbook();
    ~Workbook();

    void CreateConvertXlsxFile();
    void CreateXlsxFile();


    void Convert_CSV();
    void CreateCalendar();
    void MakeYearCalendar();
    void MakeLeapYearCalendar();
    void Insert28Days(int month);
    void Insert29Days(int month);
    void Insert30Days(int month);
    void Insert31Days(int month);
};
#endif