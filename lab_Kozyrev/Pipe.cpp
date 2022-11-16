#include "Pipe.h"
#include "utils.h"

using namespace std;

int Pipe::MaxID = 0;

ostream& operator << (ostream& out, const Pipe& p)
{
    if (p.length != 0) {
        out << "Информация о трубе\n"
            << "Длина трубы: "
            << p.length << "\n"
            << "Диаметр трубы: "
            << p.diameter << "\n"
            << "Состояние трубы: ";
        if (p.status) {
            out << "Труба в работе\n";
        }
        else {
            out << "Труба в ремонте\n";
        }
    }
    else {
        out << "Данные по трубе не введены\n";
    }
    return out;
}

istream& operator >> (istream& in, Pipe& p)
{
    cout << "Введите длину трубы: ";
    p.length= Check_Correct(0, INT_MAX);
    cout << "Введите диаметр трубы:";
    p.diameter = Check_Correct(0, INT_MAX);
    cout << "Состояние трубы:\n";
    cout << "Если труба в работе, то введите 1, иначе введите 0: ";
    p.status = Check_Correct(0, 1);

    return in;
}
