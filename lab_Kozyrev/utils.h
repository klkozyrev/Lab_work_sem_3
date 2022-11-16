#pragma once

#include <iostream>;


template <typename T>
T Check_Correct(T min, T max)
{
    T x;
    while ((std::cin >> x).fail() || x < min || x>max)
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "������ �� ������, ���������� ��� ���:";
    }
    return x;
}


//int check_correct_status() {
//    double x;
//    while ((cin >> x).fail() || x > 1 || x < 0 || trunc(x) != x) {
//        cin.clear();
//        cin.ignore(INT_MAX, '\n');
//        cout << "������ ��������, ���������� ��� ���: ";
//    }
//    if (x == 1) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//
//int check_correct_int(Station& s, bool indicator) {
//    double x;
//    if (indicator) {
//        while ((cin >> x).fail() || trunc(x) != x || x <= 0) {
//            cin.clear();
//            cin.ignore(INT_MAX, '\n');
//            cout << "������ ��������, ���������� ��� ���: ";
//        }
//    }
//    else
//        while ((cin >> x).fail() || trunc(x) != x || x > s.total || x < 0) {
//            cin.clear();
//            cin.ignore(INT_MAX, '\n');
//            cout << "������ ��������, ���������� ��� ���: ";
//        }
//    return x;
//}
//
//int check_correct_menu() {
//    double variant;
//    cout << "�������� ����� ����: ";
//    while ((cin >> variant).fail() || variant < 0 || variant > 7 || trunc(variant) != variant) {
//        cin.clear();
//        cin.ignore(INT_MAX, '\n');
//        cout << "������ ��������, ���������� ��� ���: ";
//    }
//    return variant;
//}