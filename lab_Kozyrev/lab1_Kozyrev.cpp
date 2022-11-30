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
#include <vector>;
#include <float.h>;

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


bool CheckPipeName(Pipe& p, string name) {
    return (p.name.find(name) != string::npos);
}
bool CheckPipeStatus(Pipe& p, bool status) {
    return (p.status == status);
}
bool CheckSName(Station& s, string Name) {
    return (s.name.find(Name) != string::npos);
}
bool CheckSWork(Station& s, double p) {
    return (s.GetUsing() >= p);
}


vector<int> SearchPipe(unordered_map <int, Pipe>& Pipemap) {
    vector<int> ids;
    int x;
    cout << "Отфильтровать трубу по \n 1. Имени \n 2. Статусу" << endl;
    x = Check_Correct(1, 2);
    if (x == 1) {
        string name;
        cout << "Введите имя трубы: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        ids = SearchPipebyParameter(Pipemap, CheckPipeName, name);
    }
    else {
        bool k;
        cout << "Если труба в работе, то введите 1, иначе введите 0:  " << endl;
        k = Check_Correct(0, 1);
        ids = SearchPipebyParameter(Pipemap, CheckPipeStatus, k);
    }
    return ids;
}


vector<int> SearchS(unordered_map <int, Station>& Stationmap) {
    int x;
    vector <int> id;
    cout << "Найти КС по: \n1. Имени \n2. Проценту неработающих цехов" << endl;
    x = Check_Correct(1, 2);
    if (x == 1) {
        string name;
        cout << "Введите имя КС: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = SearchSbyParameter(Stationmap, CheckSName, name);

    }
    else {
        double k;
        cout << "Введите процент неработающих цехов: " << endl;
        k = Check_Correct(0, 100);
        id = SearchSbyParameter(Stationmap, CheckSWork, k);
    }
    return id;
}


void EditPipe(unordered_map<int, Pipe>& Pipemap) {
    if (Pipemap.size() != 0) {
        cout << "1. Выбрать 1 трубу \n2. Выбрать несколько \n3. Удалить трубу" << endl;;
        int choice = Check_Correct(1, 3);
        if (choice == 1) {
            cout << "1. Выберите трубу: " << endl;
            for (auto& Pipe : Pipemap) {
                cout << Pipe.second << endl;
            }
            int id = Check_Correct(0, (int)Pipemap.size());
            if (Pipemap.find(id) != Pipemap.end()) {
                Pipemap[id].Edit_Pipe();
            }
            else
                cout << "Труба не найдена!!!";
        }
        if (choice == 2) {
            cout << "Выбрать трубы по \n1. Фильтру \n2. ID" << endl;
            int x = Check_Correct(1, 2);
            if (x == 1) {
                auto idp = SearchPipe(Pipemap);
                if (idp.size() != 0) {
                    cout << "Если труба в работе, то введите 1, иначе введите 0: " << endl;
                    bool s;
                    s = Check_Correct(0, 1);
                    for (auto& i : idp)
                        Pipemap[i].status = s;
                }
                else {
                    cout << "Труба не найдена!!!";
                }
            }

            if (x == 2) {
                unordered_set <int> ids;
                for (auto& Pipe : Pipemap) {
                    cout << Pipe.second << endl;
                }
                cout << "Введите кол-во труб которые вы бы хотели изменить" << endl;
                int n;
                int id;
                n = Check_Correct(1, (int)Pipemap.size());
                cout << "Enter the IDs of pipes" << endl;
                for (int i = 0; ids.size() < n; i++) {
                    id = Check_Correct(0, Pipe::MaxID - 1);
                    if (Pipemap.find(id) != Pipemap.end()) {
                        if (Pipemap.find(id) != Pipemap.end())
                            ids.insert(id);
                    }
                    else
                    {
                        cout << "Нет такой трубы!!!" << endl;;
                    }
                }
                cout << "Введите новый статус 1 если в работе, 0 если инчае" << endl;
                bool s;
                s = Check_Correct(0, 1);
                for (auto& i : ids) {
                    for (auto& i : ids)
                        Pipemap[i].status = s;
                }
            }
        }
        if (choice == 3) {
            cout << "1. ID трубы которую вы хотите удалить \n2. Удалить несколько труб" << endl;
            int d;
            d = Check_Correct(1, 2);
            if (d == 1) {
                for (auto& Pipe : Pipemap) {
                    cout << Pipe.second << endl;
                }
                cout << "Введите ID трубы, которую хотите удалить" << endl;
                int n;
                n = Check_Correct(0, Pipe::MaxID - 1);
                while (Pipemap.find(n) == Pipemap.end()) {
                    cout << "Нет такой трубы" << endl;
                    n = Check_Correct(0, Pipe::MaxID - 1);
                }
                Pipemap.erase(Pipemap.find(n));
            }

            else {
                unordered_set <int> ids;
                cout << "1. Удалить по фильтру \n2. Удалить по  ID" << endl;
                int action = Check_Correct(1, 2);
                if (action == 2){ 
                    for (auto& Pipe : Pipemap) {
                        cout << Pipe.second << endl;
                    }
                    cout << "Введите кол-во труб, которые хотитие удалить" << endl;;
                    int n = Check_Correct(1, (int)Pipemap.size());
                    cout << "Введите ID труб" << endl;

                    while (ids.size() < n)
                    {
                        int x = Check_Correct(0, Pipe::MaxID - 1);
                        if (Pipemap.find(x) != Pipemap.end())
                            ids.insert(x);
                        else
                            cout << "Нет такой трубы" << endl;
                    }

                    for (auto& id : ids) {
                        Pipemap.erase(Pipemap.find(id));
                    }

                }
                else {
                    auto idp = SearchPipe(Pipemap);
                    if (idp.size() != 0) {
                        for (auto& i : idp) {
                            Pipemap.erase(Pipemap.find(i));
                        }
                    }
                    else {
                        cout << "Нет таких труб!!!";

                    }

                }
            }

        }
    }



    else
        cout << "Нет труб!!!" << endl;
}



void EditStation(unordered_map<int, Station>& Stationmap) {
    vector <int> idcs;
    if (Stationmap.size() != 0) {
        cout << "1. Изменить 1 КС \n2. Изменить несколько \n3. Удалить КС" << endl;
        int edit;
        int x;
        edit = Check_Correct(1, 3);
        if (edit == 1) {
            int id;
            for (auto& Station : Stationmap) {
                cout << Station.second << endl;
            }
            cout << "" << endl;
            cout << "Выберите станцию для редактирования " << endl;
            id = Check_Correct(0, (int)Stationmap.size());
            if (Stationmap.find(id) != Stationmap.end()) {
                Stationmap[id].EditStation();
            }
        }
        if (edit == 2) {
            unordered_set <int> idw;
            cout << "Выбрать по  \n1. Фильтру 2. ID" << endl;
            int n;
            n = Check_Correct(1, 2);
            if (n == 2) {
                for (auto& Station : Stationmap) {
                    cout << Station.second << endl;
                }
                cout << "Введите кол-во КС, которой хотите изменить" << endl;
                int y;
                y = Check_Correct(1, (int)Stationmap.size());
                cout << "Введите ID" << endl;
                for (int i = 0; idw.size() < y; i++) {
                    cin >> x;
                    if (Stationmap.find(x) != Stationmap.end())
                        idw.insert(x);
                    else {

                        cout << "Нет такой станции" << endl;
                    }
                }
                for (auto& id : idw)

                    Stationmap[id].EditStation();
            }

            else {
                auto idp = SearchS(Stationmap);
                if (idp.size() != 0) {
                    for (auto& i : idp)
                        Stationmap[i].EditStation();
                }

                else {
                    cout << "Нет такой станции";

                }

            }
        }
        if (edit == 3) {
            cout << "1. ID одной КС которой хотитие удолить \n2. Удолить несколько КС" << endl;
            int d;
            d = Check_Correct(1, 2);
            if (d == 1) {
                for (auto& Station : Stationmap) {
                    cout << Station.second << endl;
                }
                cout << "Введите ID станции, которую хотит удалить" << endl;
                int n;
                n = Check_Correct(0, Station::MaxID - 1);
                while (Stationmap.find(n) == Stationmap.end()) {
                    cout << "Нет такой станции" << endl;
                    n = Check_Correct(0, Station::MaxID - 1);
                }
                Stationmap.erase(Stationmap.find(n));

            }
            else {
                unordered_set <int> idd;
                cout << "1. Удалить по фильтру 2. Удалить по ID" << endl;
                int n;
                n = Check_Correct(1, 2);
                if (n == 2) {
                    for (auto& Station : Stationmap) {
                        cout << Station.second << endl;
                    }
                    cout << "Введите кол-во КС которые хотитие удалить " << endl;
                    int y;
                    int x;
                    y = Check_Correct(1, (int)Stationmap.size());
                    cout << "Введите ID КС" << endl;
                    for (int i = 0; i < y; i++) {
                        x = Check_Correct(0, Station::MaxID);
                        if (Stationmap.find(x) != Stationmap.end())
                            idd.insert(x);
                        else
                        {
                            i = i - 1;
                            cout << "Нет такой станции" << endl;
                        }
                    }
                    for (auto& i : idd) {
                        Stationmap.erase(Stationmap.find(i));
                    }
                }
                else {
                    auto idp = SearchS(Stationmap);
                    if (idp.size() != 0) {
                        for (auto& i : idp) {
                            Stationmap.erase(Stationmap.find(i));
                        }
                    }
                    else {
                        cout << "Нет такой станции" << endl;


                    }
                }

            }
        }
    }
    else
        cout << "Нет станций для измения" << endl;
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
        case 3: {
            show_all(Pipemap, Stationmap);
            break;
        }
        case 4: {
            EditPipe(Pipemap);
            break;
        }
        case 5: {
            EditStation(Stationmap);
            break;
        }
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
        case 8: {
            if ( Pipemap.size() != 0 ) {
                auto x = SearchPipe(Pipemap);
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << Pipemap[i] << endl;
                }
                else {
                    cout << "Нет такой трубы" << endl;
                }
            }
            else {
                cout << "Нет труб для поиска" << endl;
            }
            break;
        }
        case 9: {
            if (Stationmap.size() != 0) {
                auto x = SearchS(Stationmap);
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << Stationmap[i] << endl;
                }
                else {
                    cout << "Нет такой станции" << endl;
                }
            }
            else {
                cout << "Нет станций для поиска" << endl;
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
