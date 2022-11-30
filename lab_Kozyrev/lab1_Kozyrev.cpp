// lab1_Kozyrev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>;
#include "Pipe.h";
#include "Station.h";
#include "utils.h";
#include <unordered_map>;
#include <unordered_set>;

using namespace std;

unordered_map<int, Pipe> Pipemap;
unordered_map<int, Station> Stationmap;
unordered_set<int> PipeIDs;
unordered_set<int> StationIDs;

void point_menu() {
    system("cls");
    cout << "Главное меню" << endl;
    cout << "1. Добавить трубу\n"
        << "2. Добавить КС\n"
        << "3. Просмотр всех заданных объектов\n"
        << "4. Редактировать трубу\n"
        << "5. Редактировать КС\n"
        << "6. Сохранить изменения\n"
        << "7. Загрузить данные\n"
        << "8. Поиск трубы\n"
        << "9. Поиск КС\n"
        << "0. Выход\n"
        << "Выберите пункт меню: ";
        
}






void show_all(unordered_map<int, Pipe>& Pipemap, unordered_map<int, Station>& Stationmap) {
    for (auto& Pipe : Pipemap) {
        cout << Pipe.second << endl;
    }
    for (auto& Station : Stationmap) {
        cout << Station.second << endl;
    }
}


int main()
{   
    setlocale(LC_ALL, "Russian");

    while(1) {
        point_menu();
        switch (Check_Correct(0, 9)) {
        case 1: {
            Pipe p;
            cin >> p;
            Pipemap.insert({ p.GetPipeID(),p });
            break;
        }
        case 2: {
            Station s;
            cin >> s;
            Stationmap.insert({ s.GetStationID(), s });
            break;
        }
        case 3: 
            show_all(Pipemap, Stationmap);
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6: {
            string x;
            cout << "Введите имя файла: " << endl;
            cin >> x;
            ofstream file;
            file.open(x + ".txt");
            if (!file)
                cout << "Файл не найден!!!" << endl;
            else {
                file << Pipemap.size() << " " << Stationmap.size() << endl;
                for (auto Pipe : Pipemap) {
                    Pipe.second.SavePipe(file);
                }
                for (auto Station : Stationmap) {
                    Station.second.SaveStation(file);
                }
            }
            break;
        }
        case 7: {
            string x;
            int len_Pipe, len_Station;
            Pipe p1;
            Station s1;
            cout << "Введите название файла: " << endl;
            cin >> x;
            ifstream file;
            file.open(x + ".txt");
            if (!file) {
                cout << "Файл не найден!!!";
            }
            else {
                Pipe::MaxID = 0;
                Station::MaxID = 0;
                Pipemap.clear();
                Stationmap.clear();
                file >> len_Pipe >> len_Station;
                for (int i = 0; i < len_Pipe; i++) {
                    p1.LoadPipe(file);
                    Pipemap.insert({ p1.GetPipeID(), p1 });
                    if (Pipe::MaxID <= p1.GetPipeID()) {
                        Pipe::MaxID = p1.GetPipeID() + 1;
                    }
                }
                for (int i = 0; i < len_Station; i++) {
                    s1.LoadStation(file);
                    Stationmap.insert({ s1.GetStationID(), s1 });
                    if (Pipe::MaxID <= s1.GetStationID()) {
                        Pipe::MaxID = s1.GetStationID() + 1;
                    }
                }
            }
            break;
        }
        case 0:
            cout << "Ещё увидимся!!! \n";
            return 0;
            break;

        } system("pause");
    }
}
