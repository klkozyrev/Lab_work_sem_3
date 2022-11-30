#include "Pipe.h"
#include "utils.h"

using namespace std;

int Pipe::MaxID = 0;

ostream& operator << (ostream& out, const Pipe& p)
{   
    for (int i = 0; i < Pipe::MaxID; i++) {
        if (p.lenght != 0) {
            out << "Информация о трубе\n"
                << "ID: "
                << p.id << "\n"
                << "Длина трубы: "
                << p.lenght << "\n"
                << "Диаметр трубы: "
                << p.diametr << "\n"
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
    }
    return out;
}

istream& operator >> (istream& in, Pipe& p)
{
    p.id = Pipe::MaxID++;
    cout << "Введите длину трубы: ";
    p.lenght= Check_Correct(0, INT_MAX);
    cout << "Введите диаметр трубы:";
    p.diametr = Check_Correct(0, INT_MAX);
    cout << "Состояние трубы:\n";
    cout << "Если труба в работе, то введите 1, иначе введите 0: ";
    p.status = Check_Correct(0, 1);

    return in;
}
