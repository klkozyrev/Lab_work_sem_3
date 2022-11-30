#pragma once
#include <string>;
class Station
{
    
    
public:
    static int MaxID;
    std::string name;
    bool status;

    friend std::ostream& operator << (std::ostream& out, const Station& s);
    friend std::istream& operator >> (std::istream& in, Station& s);

    int GetStationID() { return id; };

private:
    int total, work, id;
    double efficiency;
};

