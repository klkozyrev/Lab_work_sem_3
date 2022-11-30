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

void edit_pipe(unordered_map <int, Pipe>& Pipemap) {
    if (Pipemap.size() != 0) {
        cout << "Выберите 1 трубу - 1 \n Выберите "
    }
}

void edit_station(Station &s) {
    if (s.name != "") {
        cout << "Измените кол-во рабочих цехов:\n";
        cout << "Всего цехов: " << s.total << "\n";
        cout << "Новое значение\n";
        s.work = Check_Correct(0, s.total);
        cout << "Если компресорная станция в работе, то введите 1, иначе введите 0: \n";
        s.status = Check_Correct(0, 1);
    }
    else {
        cout << "Данные не введены, либо введены не окончательно\n";
    }
}

//void save(Pipe &p, Station &s) {
//    ofstream output("intelligence.txt");
//    if (p.length != 0) {
//        output << "Pipe \n"
//            << p.length << "\n"
//            << p.diameter << "\n";
//        if (p.status) {
//            output << "1\n";
//        }
//        else {
//            output << "0";
//        }
//    }
//
//    if (s.name != "") {
//        output << "\n" << "Station\n"
//            << s.name << "\n"
//            << s.total << "\n"
//            << s.work << "\n"
//            << s.efficiency << "\n";
//        if (s.status) {
//            output << "1\n";
//        }
//        else {
//            output << "0\n";
//        };
//    }
//    output.close();
//}

//void download(Pipe& p, Station& s) {
//    char buff[50];
//
//    ifstream input("intelligence.txt"); 
//    if (!input.is_open()) // если файл не открыт
//        cout << "Файл не может быть открыт!\n"; // сообщить об этом
//    else {
//
//        input >> buff;
//        if (buff[0] == 'P') {
//            input >> p.length;
//            input >> p.diameter;
//            input >> p.status;
//            input >> buff;
//            if (buff[0] == 'S') {
//                input >> s.name;
//                input >> s.total;
//                input >> s.work;
//                input >> s.efficiency;
//                input >> s.status;
//            }
//        }
//        else if ( buff[0] == 'S') {
//            input >> s.name;
//            input >> s.total;
//            input >> s.work;
//            input >> s.efficiency;
//            input >> s.status;
//        }
//        else {
//            cout << "Данные не введены в файл\n";
//        }
//    }
//}

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
    Station s;
    Pipe p;
    
    setlocale(LC_ALL, "Russian");

    while (1) {
        point_menu();
        switch (Check_Correct(0, 9)) {
        case 1: 
              cin >> p;
              Pipemap.insert({ p.GetPipeID(),p });
              break;
        case 2: 
            cin >> s;
            Stationmap.insert({ s.GetStationID(), s });
            break;
        case 3: 
            show_all(Pipemap, Stationmap);
            break;
        case 4:
            edit_pipe(Pipemap);
            break;
        case 5:
            //edit_station(s);
            break;
        case 6:
            //save(p, s);
            break;
        case 7:
            //download(p, s);

            break;
        case 0:
            int k;
            cout << "Хотите ли сохранить изменения? Если хотитие введите 1 иначе 0 \n";
            cin >> k;
            if (k == 1) {
                //save(p, s);
            }
            return 0;
            break;

        }
        system("pause");
    }
}
