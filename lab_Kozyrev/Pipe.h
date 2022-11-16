#pragma once
#include <string>

class Pipe
{  
    int id;

public:
    static int MaxID;
    std::string name;
    double length;
    double diameter;
    bool status;

    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
    friend std::istream& operator >> (std::istream& in, Pipe& p);
};

