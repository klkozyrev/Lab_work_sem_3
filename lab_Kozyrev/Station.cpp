#include "Station.h"
#include "utils.h";

using namespace std;

int Station::MaxID = 0;

ostream& operator << (ostream& out, const Station& s)
{
    if (s.name != "") {
        out << "\n" << "Информация о комперсорной станции\n"
            << "Название станции: "
            << s.name << "\n"
            << "Всего цехов: "
            << s.total << "\n"
            << "Рабочих цехов "
            << s.work << "\n"
            << "Эффективность "
            << s.efficiency << "\n"
            << "Статус работы станции ";
        if (s.status) {
            out << "Станция запущена\n";
        }
        else {
            out << "Станция остановлена\n";
        };
    }
    else {
        out << "Данные по станции не введены\n";
    }

    return out;
}

istream& operator >> (istream& in, Station& s)
{
    s.id = Station::MaxID++;
    s.total = 0;
    cout << "Введите кодовое имя станции: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, s.name);
    cout << "Введите общее кол-во цехов: ";
    s.total = Check_Correct(0, INT_MAX);
    cout << "Введите кол-во рабочих цехов: ";
    s.work = Check_Correct(0, s.total);
    cout << "Введите эффективность: ";
    s.efficiency = Check_Correct(0, INT_MAX);
    cout << "Состояние компресорной станции:\n";
    cout << "Если вы хотите запустить станцию, то введите 1, если остановить введите 0: ";
    s.status = Check_Correct(0, 1);

    return in;

}