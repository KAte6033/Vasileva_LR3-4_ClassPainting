// #include <C:\\Users\\User\\Desktop\\ALL_LABS\\Laba3_4\\Vasileva_LR3-4_ClassPainting\\Vasileva_LR3-4_Methods.h>
#include "Vasileva_LR3-4_ClassPainting.cpp"

struct MenuItem
{
    string title; // название пункта меню
    function <void()> action; // действие, выполняемое при выборе пункта
};



int main() {
    map<int, MenuItem> menu = {
        {1, {"Тест дисплэй",  createObjDefault}}, //+
        {2, {"Test preobraz", createObjPre}}, //+
        {3, {"Test of name and vector", createObjPreWithVector}}, //+
        {4, {"Тест перегруженного оператора >> ", Vvesti}},
        {5, {"Вывести объект класса << ", Vivisti}},
        {6, {"Вывести копию", Vivesti_copy}},
        {7, {"Вывести сумму двух картин", Sum_Paintings}},
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