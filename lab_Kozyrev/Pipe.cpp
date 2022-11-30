#include "Pipe.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int Pipe::MaxID = 0;

ostream& operator << (ostream& out, const Pipe& p)
{ 
    out << "Информация о трубе\n"
        << "ID: "
        << p.id << "\n"
        << "Название трубы: "
        << p.name << "\n"
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
    return out;
}

istream& operator >> (istream& in, Pipe& p)
{
    cout << "ID Трубы : " << p.id << endl;
    cout << "Введите имя трубы: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "Введите длину трубы: ";
    p.lenght= Check_Correct(0.0, DBL_MAX);
    cout << "Введите диаметр трубы:";
    p.diametr = Check_Correct(0.0, DBL_MAX);
    cout << "Состояние трубы:\n";
    cout << "Если труба в работе, то введите 1, иначе введите 0: ";
    p.status = Check_Correct(0, 1);

    return in;
}

void Pipe::SavePipe(std::ofstream& file)
{
    file << id << endl
        << name << endl
        << lenght << endl
        << diametr << endl
        << status << endl;
}

void Pipe::LoadPipe(std::ifstream& file)
{
    file >> id;
    file >> name;
    file >> lenght;
    file >> diametr;
    file >> status;
}

void Pipe::Edit_Pipe()
{
    cout << "Состояние трубы: ";
    if (status) {
        cout << "Труба в работе\n";
    }
    else {
        cout << "Труба в ремонте\n";
    }
    cout << "Если труба в работе, то введите 1, иначе введите 0: ";
    status = Check_Correct(0, 1);
}

