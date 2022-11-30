#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Station
{
public:
    static int MaxID;
    std::string name;
    friend std::ostream& operator << (std::ostream& out, const Station& s);
    friend std::istream& operator >> (std::istream& in, Station& s);
    void SaveStation(std::ofstream& file);
    int GetStationID() { return id; };
    void LoadStation(std::ifstream& file);
     
    Station() {
        id = MaxID++;
    }

private:
    int total, work, id;
    double efficiency;
};

