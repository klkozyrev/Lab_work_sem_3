#pragma once
#include <string>;
class Station
{
    int id;

public:
    static int MaxID;
    std::string name;
    int total;
    int work;
    double efficiency;
    bool status;

    friend std::ostream& operator << (std::ostream& out, const Station& s);
    friend std::istream& operator >> (std::istream& in, Station& s);
};

