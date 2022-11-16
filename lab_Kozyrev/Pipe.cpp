#include "Pipe.h"
#include "utils.h"

using namespace std;

int Pipe::MaxID = 0;

ostream& operator << (ostream& out, const Pipe& p)
{
    if (p.length != 0) {
        out << "���������� � �����\n"
            << "����� �����: "
            << p.length << "\n"
            << "������� �����: "
            << p.diameter << "\n"
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
    return out;
}

istream& operator >> (istream& in, Pipe& p)
{
    cout << "������� ����� �����: ";
    p.length= Check_Correct(0, INT_MAX);
    cout << "������� ������� �����:";
    p.diameter = Check_Correct(0, INT_MAX);
    cout << "��������� �����:\n";
    cout << "���� ����� � ������, �� ������� 1, ����� ������� 0: ";
    p.status = Check_Correct(0, 1);

    return in;
}
