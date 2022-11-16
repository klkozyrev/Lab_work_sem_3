#include "Station.h"
#include "utils.h";

using namespace std;

int Station::MaxID = 0;

ostream& operator << (ostream& out, const Station& s)
{
    if (s.name != "") {
        out << "\n" << "���������� � ������������ �������\n"
            << "�������� �������: "
            << s.name << "\n"
            << "����� �����: "
            << s.total << "\n"
            << "������� ����� "
            << s.work << "\n"
            << "������������� "
            << s.efficiency << "\n"
            << "������ ������ ������� ";
        if (s.status) {
            out << "������� ��������\n";
        }
        else {
            out << "������� �����������\n";
        };
    }
    else {
        out << "������ �� ������� �� �������\n";
    }

    return out;
}

istream& operator >> (istream& in, Station& s)
{
    s.id = Station::MaxID++;
    s.total = 0;
    cout << "������� ������� ��� �������: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, s.name);
    cout << "������� ����� ���-�� �����: ";
    s.total = Check_Correct(0, INT_MAX);
    cout << "������� ���-�� ������� �����: ";
    s.work = Check_Correct(0, s.total);
    cout << "������� �������������: ";
    s.efficiency = Check_Correct(0, INT_MAX);
    cout << "��������� ������������ �������:\n";
    cout << "���� �� ������ ��������� �������, �� ������� 1, ���� ���������� ������� 0: ";
    s.status = Check_Correct(0, 1);

    return in;

}