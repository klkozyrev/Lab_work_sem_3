#pragma once
#include <string>
#include <iostream>
#include <vector>

class Pipe
{  
public:
    static int MaxID;
    std::string name;
    bool status;


    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
    friend std::istream& operator >> (std::istream& in, Pipe& p);   

    int GetPipeID() { return id; };

private:
    int id;
    double lenght=0, diametr=0;
};

