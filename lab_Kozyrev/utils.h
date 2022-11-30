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
