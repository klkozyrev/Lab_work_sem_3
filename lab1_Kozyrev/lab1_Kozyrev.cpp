// lab1_Kozyrev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe {
    double length;
    double diameter;
    bool status;
};

struct Station {
    string name;
    int total;
    int work;
    double efficiency;
    bool status;
};


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
        << "0. Выход" << endl;
}

int check_correct_menu() {
    double variant;
    cout << "Выбирите пункт меню: ";
    while ((cin >> variant).fail() || variant < 0 || variant > 7 || trunc(variant) != variant) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Данные неверные, попробуйте ещё раз: ";
    }
    return variant;
}
    int check_correct_int(Station &s, bool indicator){
    double x;
    if (indicator) {
        while ((cin >> x).fail() || trunc(x) != x || x <= 0) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Данные неверные, попробуйте ещё раз: ";
        }
    }else
        while ((cin >> x).fail() || trunc(x) != x || x > s.total ) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Данные неверные, попробуйте ещё раз: ";
        }
    return x;
}

int check_correct_double() {
    double x;
    while ((cin >> x).fail() || x <= 0) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Данные неверные, попробуйте ещё раз: ";
    }
    return x;
}

int check_correct_status() {
    double x;
    while ((cin >> x).fail() || x>1 || x<0 || trunc(x)!=x) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Данные неверные, попробуйте ещё раз: ";
    }
    if (x == 1) {
        return true;
    }
    else {
        return false;
    }
}

void add_pipe(Pipe &p) {
    if (p.length == 0) {
        cout << "Введите длину трубы: ";
        p.length = check_correct_double();
        cout << "Введите диаметр трубы:";
        p.diameter = check_correct_double();
        cout << "Состояние трубы:\n";
        cout << "Если труба в работе, то введите 1, иначе введите 0: ";
        p.status = check_correct_status();
    }
    else {
        cout << "Труба уже создана\n";
    }
}

void add_station(Station &s) {
    if (s.name == "") {
        s.total = 0;
        cout << "Введите кодовое имя станции: ";
        cin >> s.name;
        cout << "Введите общее кол-во цехов: ";
        s.total = check_correct_int(s, true);
        cout << "Введите кол-во рабочих цехов: ";
        s.work = check_correct_int(s, false);
        cout << "Введите эффективность: ";
        s.efficiency = check_correct_double();
        cout << "Состояние компресорной станции:\n";
        cout << "Если вы хотите запустить станцию, то введите 1, если остановить введите 0: ";
        s.status = check_correct_status();
    }
    else {
        cout << "Станция уже создана\n";
    }

}

void show_all(Pipe &p, Station &s) {
    if (p.length != 0) {
        cout << "Информация о трубе\n"
            << "Длина трубы: "
            << p.length << "\n"
            << "Диаметр трубы: "
            << p.diameter << "\n"
            << "Состояние трубы: ";
        if (p.status) {
            cout << "Труба в работе\n";
        }
        else {
            cout << "Труба в ремонте\n";
        }
    }
    else {
        cout << "Данные по трубе не введены\n";
    }

    if (s.name != "") {
        cout << "\n" << "Информация о комперсорной станции\n"
            << "Название станции: "
            << s.name << "\n"
            << "Всего цехов: "
            << s.total << "\n"
            << "Рабочих цехов "
            << s.work << "\n"
            << "Эффективность "
            << s.efficiency << "\n"
            << "Статус работы станции ";
        if (s.status) {
            cout << "Станция запущена\n";
        }
        else {
            cout << "Станция остановлена\n";
        };
    }
    else {
            cout << "Данные по станции не введены\n";
    }
}

void edit_pipe(Pipe &p) {
    if (p.length != 0) {
        cout << "Измените длину трубы:\n";
        cout << "Предыдущие значение: " << p.length << "\n";
        cout << "Новое значение\n";
        p.length = check_correct_double();
        cout << "Измените диаметр трубы:\n";
        cout << "Предыдущие значение: " << p.length << "\n";
        cout << "Новое значение\n";
        p.diameter = check_correct_double();
        cout << "Измените состояние трубы:\n";
        cout << "Если труба в работе, то введите 1, иначе введите 0: \n";
        p.status = check_correct_status();
    }
    else {
        cout << "Данные не введены, либо введены не окончательно\n";
    }
}

void edit_station(Station &s) {
    if (s.name != "") {
        cout << "Измените название станции:\n";
        cout << "Предыдущие название: " << s.name << "\n";
        cout << "Новое название\n";
        cin >> s.name;
        cout << "Измените кол-во цехов:\n";
        cout << "Предыдущие значение: " << s.total << "\n";
        cout << "Новое значение\n";
        s.total = check_correct_int(s, true);
        cout << "Измените кол-во рабочих цехов:\n";
        cout << "Предыдущие значение: " << s.work << "\n";
        cout << "Новое значение\n";
        s.work = check_correct_int(s, false);
        cout << "Если компресорная станция в работе, то введите 1, иначе введите 0: \n";
        s.status = check_correct_status();
    }
    else {
        cout << "Данные не введены, либо введены не окончательно\n";
    }
}

void save(Pipe &p, Station &s) {
    ofstream output("output.txt");
    if (p.length != 0) {
        output << "Информация о трубе \n"
            << "Длина трубы: "
            << p.length << "\n"
            << "Диаметр трубы: "
            << p.diameter << "\n"
            << "Состояние трубы: ";
        if (p.status) {
            output << "Труба в работе\n";
        }
        else {
            output << "Труба в ремонте\n";
        }
    }
    else {
        output << "Данные по трубе не введены\n";
    }

    if (s.name != "") {
        output << "\n" << "Информация о комперсорной станции\n"
            << "Название станции :"
            << s.name << "\n"
            << "Всего цехов: "
            << s.total << "\n"
            << "Рабочих цехов "
            << s.work << "\n"
            << "Эффективность "
            << s.efficiency << "\n"
            << "Статус работы станции ";
        if (s.status) {
            output << "Станция запущена\n";
        }
        else {
            output << "Станция остановлена\n";
        };
    }
    else {
        output << "Данные по станции не введены\n";
    }
    output.close();
}

void download(Pipe& p, Station& s) {
    
}



int main()
{   Station s;
    Pipe p;
    p.length = 0;
    s.name = "";
    
    setlocale(LC_ALL, "Russian");

    while (1) {
        point_menu();
        switch (check_correct_menu()) {
        case 1:
            add_pipe(p);
            break;
        case 2:
            add_station(s);
            break;
        case 3:
            show_all(p, s);
            break;
        case 4:
            edit_pipe(p);
            break;
        case 5:
            edit_station(s);
            break;
        case 6:
            save(p, s);
            break;
        case 7:
            download(p, s);

            break;
        case 0:
            if (p.status && s.status) {
                return 0;
            }
            else {
                cout << "Проверьте включили ли вы станцию и вывели ли вы трубу из ремонта!\n";
            }
            break;

        }
        system("pause");
    }
}
