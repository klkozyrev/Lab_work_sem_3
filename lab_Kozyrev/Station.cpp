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
    out << "\n" << "���������� � ������������ �������\n"
        << "ID: "
        << s.id << "\n"
        << "�������� �������: "
        << s.name << "\n"
        << "����� �����: "
        << s.total << "\n"
        << "������� ����� "
        << s.work << "\n"
        << "������������� "
        << s.efficiency << "\n";
    return out;
}

istream& operator >> (istream& in, Station& s)
{   
    cout << "ID: \n" << s.id << endl;
    cout << "������� ������� ��� �������: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, s.name);
    cout << "������� ����� ���-�� �����: ";
    s.total = Check_Correct(0, INT_MAX);
    cout << "������� ���-�� ������� �����: ";
    s.work = Check_Correct(0, s.total);
    cout << "������� �������������: ";
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
    cout << " ����� �����: " << total << endl;
    cout << "����� ������� ����� " << work << endl;
    cout << "������� ����� ����� ������� ����� " << endl;
    work = Check_Correct(0, total);
}
