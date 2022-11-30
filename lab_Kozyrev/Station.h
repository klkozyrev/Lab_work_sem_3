#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <float.h>

class Station
{
public:
    static int MaxID;
    std::string name = "";
    friend std::ostream& operator << (std::ostream& out, const Station& s);
    friend std::istream& operator >> (std::istream& in, Station& s);
    void SaveStation(std::ofstream& file);
    int GetStationID() { return id; };
    void LoadStation(std::ifstream& file);
    void EditStation();
    Station() {
        id = MaxID++;
    }
    double GetUsing() { return (((double)total - (double)work) / (double)work) * 100; }
private:
    int total, work, id;
    double efficiency;
};

