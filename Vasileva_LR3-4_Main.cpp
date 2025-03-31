#include <C:\\Users\\User\\Desktop\\ALL_LABS\\Laba3_4\\Vasileva_LR3-4_ClassPainting\\Vasileva_LR3-4_Methods.h>


struct MenuItem
{
    string title; // название пункта меню
    function <void()> action; // действие, выполняемое при выборе пункта
};



int main() {
    map<int, MenuItem> menu = {
        // {1, {"Тест дисплэй",  } }, //+
        // {2, {"Вывести базу данных", printDatabase}}, //+
        // {3, {"Добавить автобус", addBusToDB}}, //+
        // {4, {"Найти все автобусы по маршруту", findBusesByRoute}},
        // {5, {"Вывести автобусы, у которох срок эксплуатации более 10 лет", Skoka_Let}},
        // {6, {"Вывести все автобусы, у которых пробег более 10000 км", MnogaKm}}
    };

    int choice = 0;

    while (true)
    {
        cout << "Меню:" << endl;

        for (const auto& item : menu){
            cout << "Task " << item.first << ". " << item.second.title << endl;

        }

        cout << "0. Выход" << endl; 

        EnterNumber (choice, "Введите номер пункта: ")();

        if (choice == 0){
            cout << "@ 2025 Ekaterina Vasileva" << endl;
            break;
        }

        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        }
        else{
            cout << "Некорректный ввод. ";
        }

        cout << endl << endl;

    }

    return 0; 

}