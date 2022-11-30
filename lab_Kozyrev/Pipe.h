#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Pipe
{  
public:
    static int MaxID;
    string name = "";
    bool status = 0;
    

    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
    friend std::istream& operator >> (std::istream& in, Pipe& p);   
    
    void SavePipe(std::ofstream& file);
    int GetPipeID() { return id; };
    void LoadPipe(std::ifstream& file);
    void Edit_Pipe();
    Pipe() {
        id = MaxID++;

    }

private:
    int id;
    double lenght=0, diametr=0;
};

