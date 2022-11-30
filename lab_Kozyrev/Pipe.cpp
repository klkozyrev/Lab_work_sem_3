#include "Pipe.h"
#include "utils.h"

using namespace std;

int Pipe::MaxID = 0;

ostream& operator << (ostream& out, const Pipe& p)
{   
    for (int i = 0; i < Pipe::MaxID; i++) {
        if (p.lenght != 0) {
            out << "���������� � �����\n"
                << "ID: "
                << p.id << "\n"
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
        }
        else {
            out << "������ �� ����� �� �������\n";
        }
    }
    return out;
}

istream& operator >> (istream& in, Pipe& p)
{
    p.id = Pipe::MaxID++;
    cout << "������� ����� �����: ";
    p.lenght= Check_Correct(0, INT_MAX);
    cout << "������� ������� �����:";
    p.diametr = Check_Correct(0, INT_MAX);
    cout << "��������� �����:\n";
    cout << "���� ����� � ������, �� ������� 1, ����� ������� 0: ";
    p.status = Check_Correct(0, 1);

    return in;
}
