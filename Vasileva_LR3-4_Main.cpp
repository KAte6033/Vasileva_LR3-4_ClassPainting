// #include <C:\\Users\\User\\Desktop\\ALL_LABS\\Laba3_4\\Vasileva_LR3-4_ClassPainting\\Vasileva_LR3-4_Methods.h>
#include "Vasileva_LR3-4_ClassPainting.cpp"

struct MenuItem
{
    string title; // название пункта меню
    function <void()> action; // действие, выполняемое при выборе пункта
};



int main() {
    map<int, MenuItem> menu = {
        {1, {"Использовать конструктор по умолчанию", Default_constructor}},
        {2, {"Использовать конструктор преобразования", Conversion_constructor}},
        {3, {"Использовать конструктор копирования", Copy_constructor}},
        {4, {"Использовать параметезированный конструктор (все параметры)", Parameterized_constructor}},
        {5, {"Использовать параметезированный делегирующий конструктор (название, вектор цен)", Deleg_par_constructor}},
        {6, {"Использовать параметезированный делегирующий конструктор (год создания)", Deleg__constructor}},
        {7, {"Добавить новую картину с консоли", Vvesti}},
        {8, {"Вывести все картины", Display_all}},
        {9, {"Отсортировать картины по году создания", Sort_paintings_by_year}},
        {10, {"Сложить две картины", Sum_of_the_paintings}},
        {11, {"Вычесть две картины", Subtract_of_paintings}},
        {12, {"Умножить картину на число с консоли", multiplying_picture_by_number}},
        {13, {"Сравнение картин по году создания", Comparison_by_year}},
        {14, {"Сравнение картин по средней цене", Average_price_comparison}},
        {15, {"Добавить рандомную цену в конец вектора цен", add_auction_price_end}},
        {16, {"Добавить рандомную цену в начало вектора цен", add_auction_price_begin}},
        {17, {"Удалить рандомную цену из вектора цен", delete_random_price}},
        {18, {"Заменить цену", delete_index_price}},
        {19, {"Вывести цену", Display_price_index}},
        {20, {"Создать копию (=)", Equal_object}},
        {21, {"Создать копию (=)", Equal_object}},
        
        // {19, {"Вывести все объекты класса", Display_all}},
        // {1, {"Тест дисплэй",  createObjDefault}}, //+
        // {2, {"Test preobraz", createObjPre}}, //+
        // {3, {"Test of name and vector", createObjPreWithVector}}, //+
        // {4, {"Тест перегруженного оператора >> ", Vvesti}},
        // {5, {"Вывести объект класса << ", Vivisti}},
        // {6, {"Вывести копию", Vivesti_copy}},
        // {7, {"Вывести сумму двух картин", Sum_Paintings}},
        // {8, {"Вывести разность двух картин", Difference_Paintings}},
        // {9, {"Умножение картины на число", Unoz}},
        // {10, {"Инкремент", Increment}},
        // {11, {"Декремент", Decrement}},
        // {12, {"Декремент", Decrement}},
        // {13, {"Скобки", Skobki}},
        // {14, {"Скобки для чтения", ReadSkobki}},
        // {15, {"Присваивание", Prisvaivanie}},
        // {16, {"Префиксный инкремент", PreIncrement}},
        // {17, {"Сравнение по году создания", Sravnenie_year}},
        // {18, {"Сравнение по средней цене", Sravn_sr_price}},
        // {19, {"Вывести все объекты класса", Display_all}},
        

        
        
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