#include "Station.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int Station::MaxID = 0;

ostream& operator << (ostream& out, const Station& s)
{
    out << "\n" << "Информация о комперсорной станции\n"
        << "ID: "
        << s.id << "\n"
        << "Название станции: "
        << s.name << "\n"
        << "Всего цехов: "
        << s.total << "\n"
        << "Рабочих цехов "
        << s.work << "\n"
        << "Эффективность "
        << s.efficiency << "\n";
    return out;
}

istream& operator >> (istream& in, Station& s)
{   
    cout << "ID: \n" << s.id << endl;
    cout << "Введите кодовое имя станции: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, s.name);
    cout << "Введите общее кол-во цехов: ";
    s.total = Check_Correct(0, INT_MAX);
    cout << "Введите кол-во рабочих цехов: ";
    s.work = Check_Correct(0, s.total);
    cout << "Введите эффективность: ";
    s.efficiency = Check_Correct(0, 100);
    
    return in;
}

void Station::SaveStation(ofstream& file)
{
    file << id << endl
        << name << endl
        << total << endl
        << work << endl
        << efficiency << endl;
}

void Station::LoadStation(std::ifstream& file)
{
    file >> id;
    file >> name;
    file >> total;
    file >> work;
    file >> efficiency;
}

void Station::EditStation()
{
    cout << " Число цехов: " << total << endl;
    cout << "Число рабочих цехов " << work << endl;
    cout << "Введите новое число рабочих цехов " << endl;
    work = Check_Correct(0, total);
}
