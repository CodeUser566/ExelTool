#include <fstream>
#include <map>
#include <png.h>
#include <pngconf.h>
#include <string>
#include <xlsxwriter.h>
#include <qrencode.h>

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
    bool CreateQR(std::string Text,std::string Filename);

    public:
    Workbook();
    ~Workbook();

    void CreateConvertXlsxFile();
    void CreateXlsxFile();
    void CreateSyllabusTable();
    void Convert_CSV();
    void CreateCalendar();
    void CreateQRTable();
};
#endif