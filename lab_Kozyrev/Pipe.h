#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Pipe
{  
public:
    static int MaxID;
    string name = "";
    bool status = 0;
    Pipe() {
        id = MaxID++;

    }

    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
    friend std::istream& operator >> (std::istream& in, Pipe& p);   
    
    void SavePipe(std::ofstream& file);
    int GetPipeID() { return id; };
    void LoadPipe(std::ifstream& file);
private:
    int id;
    double lenght=0, diametr=0;
};

