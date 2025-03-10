#include <clocale>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");


  //обернуть в функцию, возможно создать класс
  string Path;
  string Line;
  string acc;
  ifstream CSV_Read;
  list<string> Headers;

  CSV_Read.exceptions(ifstream::badbit|ifstream::failbit); 
  cout << "Введите путь до файла:";
  cin >> Path;
  try
  {
    CSV_Read.open(Path);
  } 
  catch (const ifstream::failure & ex) 
  {
    cout << "Ошибка открытия файла, Проверьте правильность написания файла.Также убедитесь что формат файла .CSV" << endl;
    cout << ex.what() << endl;
    cout << ex.code() << endl;
  }

 getline(CSV_Read,Line);


for (int i = 0; i <= Line.length(); i++) 
{
  char CurrentSymbol = Line[i];

  if (CurrentSymbol == ',')
  {
    Headers.push_front(acc);
    acc.clear();
    continue;
  }
  acc += CurrentSymbol;
}
if (!acc.empty()) 
{
  Headers.push_front(acc);
}
  

CSV_Read.close();
  return 0;
}