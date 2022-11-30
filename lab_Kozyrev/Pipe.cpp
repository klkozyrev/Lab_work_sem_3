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
    out << "���������� � �����\n"
        << "ID: "
        << p.id << "\n"
        << "�������� �����: "
        << p.name << "\n"
        << "����� �����: "
        << p.lenght << "\n"
        << "������� �����: "
        << p.diametr << "\n"
        << "��������� �����: ";
          if (p.status) {
                out << "����� � ������\n";
          }
          else {
              out << "����� � �������\n";
          }
    return out;
}

istream& operator >> (istream& in, Pipe& p)
{
    cout << "ID ����� : " << p.id << endl;
    cout << "������� ��� �����: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "������� ����� �����: ";
    p.lenght= Check_Correct(0.0, DBL_MAX);
    cout << "������� ������� �����:";
    p.diametr = Check_Correct(0.0, DBL_MAX);
    cout << "��������� �����:\n";
    cout << "���� ����� � ������, �� ������� 1, ����� ������� 0: ";
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
    cout << "��������� �����: ";
    if (status) {
        cout << "����� � ������\n";
    }
    else {
        cout << "����� � �������\n";
    }
    cout << "���� ����� � ������, �� ������� 1, ����� ������� 0: ";
    status = Check_Correct(0, 1);
}

