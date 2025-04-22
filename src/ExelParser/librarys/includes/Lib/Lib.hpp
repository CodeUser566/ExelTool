#include <fstream>
#include <map>
#include <xlsxwriter.h>
#include <xlsxwriter/workbook.h>

#ifndef WORKBOOK
#define WORKBOOK
class Workbook
{
    private:
    lxw_workbook *workbook;
    std::fstream ConvertFile;
    std::map<int, lxw_worksheet*> WorksheetPointer;

    void Insert28Days(int month);
    void Insert29Days(int month);
    void Insert30Days(int month);
    void Insert31Days(int month);
    void MakeYearCalendar();
    void MakeLeapYearCalendar();
    void MakeMonthCalendar(int Year,int month);
    void SyllabusDay(int &row,int &col,std::string Day);

    public:
    Workbook();
    ~Workbook();

    void CreateConvertXlsxFile();
    void CreateXlsxFile();
    void CreateSyllabusTable();
    void Convert_CSV();
    void CreateCalendar();
};
#endif