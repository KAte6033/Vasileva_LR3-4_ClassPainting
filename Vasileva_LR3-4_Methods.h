#ifndef VASILEVA_LR3_4_METHODS_H
#define VASILEVA_LR3_4_METHODS_H


#include "Vasileva_LR3-4_ClassPainting.h"

using namespace std;

const int infinity = std::numeric_limits<int>::max();

// глобальный вектор всех объектов класса
// extern означает что переменная где-то реализована
extern vector <Painting> paintings;

// добавления объектов в глобальный вектор
void register_painting(const Painting& p) {
    paintings.push_back(p);
}
// нужно использовать после объектов конструктора копирования

void Display_all ()
{
    for (const Painting& p : paintings){
        cout << p << endl;
    }

};

// Функция для сортировки картин по году
void Sort_paintings_by_year() 
{
    sort(paintings.begin(), paintings.end());  
    // sort использует перегруженный оператор <
}

// ввод строк
bool User_Str (string input){
    // если строка пустая, то ввод некорректен
    if(input.empty()) return false;
    return true;

}

// ввод интовых
bool UserInput (string input){
    // если строка пустая, то ввод некорректен
    if(input.empty()) return false;

    // попытка
    try {
        // преобразование введённого значения  в тип int 
        int number  = stoi(input);
    }

    catch (...) // если возникла ошибка в блоке try
    {return false;}
    return true;

}

// ввод беззнаковых
bool UserUnsig (string input){
    // если строка пустая, то ввод некорректен
    if(input.empty()) return false;

    // попытка
    try {
        // преобразование введённого значения  в тип int 
        unsigned number  = stoul(input);
    }

    catch (...) // если возникла ошибка в блоке try
    {return false;}
    return true;
}

//ввод интовых чисел
function <void()> EnterNumber (int& varlink, string label){
    return [&varlink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserInput(raw_input)){
            cout << "Неккоректный ввод!" << endl;
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varlink = stoi(raw_input);
    };
}

//ввод интовых чисел больше 0
function <void()> EnterNumberBolsheZero (int& varlink, string label){
    return [&varlink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserInput(raw_input) || stoi(raw_input) < 1){
            cout << "Неккоректный ввод!" << endl;
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varlink = stoi(raw_input);
    };
}


// function <void()> EnterNumber (int& varlink, string label){
//     return [&varlink, label](){
//         string raw_input;
//         cout << label << " = ";
//         getline(cin, raw_input);

//         while (!UserInput(raw_input)){
//             cout << label << " = ";
//             getline(cin, raw_input);
//         }

//         while(stoi(raw_input) < 1){
//             cout << "Неккоректный ввод!" << endl;
//         }
//         varlink = stoi(raw_input);
//     };
// }

// ввод строк
function <void()> EnterStr (string& varlink, string label){
    return [&varlink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!User_Str(raw_input)){
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varlink = raw_input;
    };
}

// ввод беззнаковых
function <void()> EnterUnsign (unsigned& varlink, string label){
    return [&varlink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserUnsig(raw_input)){
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varlink = stoul(raw_input);
    };
}



void Default_constructor ()
{
    Painting p1;
    register_painting(p1);

    cout << "Объект класса, созданный по умолчанию: " << endl;
    cout << p1;
}


void Conversion_constructor ()
{
    Painting p2 ("Liza");
    register_painting(p2);

    cout << "Объект класса, созданный конструктором преобразования: " << endl;
    cout << p2;

}


void Copy_constructor ()
{
    int x;

    // здесь выбираем 1 или 2 объект, уже добавленный в вектор
    // на его основе с помощбю конструктора копирования создаём новый объект
    x = rand() % (2 - 1) + 1;

    if (paintings.empty() || paintings.size() < 2){
        cout << "Вектор пуст или в нём недостаточно элементов (<2), для создания объекта копированием,\n добавьте в вектор хотя бы 2 объекта!" << endl;
    }

    else{

        cout << "На основе этого объекта будет создан новый: " << endl;
        cout << paintings[x] << endl;

        Painting p3(paintings[x]);
        register_painting(p3);

        cout << "А это новый объект: " << endl;
        cout << p3 << endl;

    }

}


void Parameterized_constructor ()
{
    vector <int> price = {12000, 5400, 7800};

    cout << "При таких данных: " << endl;
    cout << "Title - \"Valenok\", Athor - Victor, Year - 543, Prices - 12000, 5400, 7800" << endl;
    cout << endl;
    cout << "создадим вектор с использованием параметезированного конструктора" << endl;

    Painting p4("Valenok", "Victor", 543, price);

    cout << p4;

}

void Deleg__constructor ()
{
    // // принимает название и вектор цен
    // vector <int> sold = {3450, 5600, 7800};

    // cout << "Есть такой вектор цен: " << endl;

    // for(int& p : sold){
    //     cout << p << " ";
    // }

    // cout << "И такое название: " << endl;

    // string name = "Piponika";

    // cout << name << endl;
    // cout << "Создадим объект класса с этими данными с помощью параметезированного делегирующего конструктора: " << endl;

    // Painting p5(name, sold);
    // paintings.push_back(p5);

    // cout << p5;

    Painting p5 =1815;
    cout << p5;


};

void Deleg_par_constructor ()
{
    // принимает название и вектор цен
    vector <int> sold = {3450, 5600, 7800};

    cout << "Есть такой вектор цен: " << endl;

    for(int& p : sold){
        cout << p << " ";
    }

    cout << "И такое название: " << endl;

    string name = "Piponika";

    cout << name << endl;
    cout << "Создадим объект класса с этими данными с помощью параметрезированного делегирующего конструктора: " << endl;

    // Painting p5(name, sold);
    // paintings.push_back(p5);

    // cout << p5;

    Painting p6(name, sold);
    cout << p6;




};
// Painting p1;

void Sum_of_the_paintings ()
{
    Painting p7;
    register_painting(p7);
    Painting p8(1917);

    Painting p9 = p7 + p8;

    cout << "1 картина: " << endl;
    cout << p7;

    cout << "2 картина: " << endl;
    cout << p8;

    cout << endl;
    cout << "Объект, который получился: " << endl;
    cout << endl;
    cout << p9 << endl;
    // register_painting(p9);

}

void Subtract_of_paintings ()
{
    Painting p10(2025);
    Painting p11(2024);

    cout << "1 картина: " << endl;
    cout << p10;

    cout << "2 картина: " << endl;
    cout << p11;

    cout << "Новая картина: " << endl;

    Painting p12 = p11 - p10;

    cout << p12 << endl;


}

void multiplying_picture_by_number ()
{
    Painting p13(1999);
    int chislo;

    cout << "Картина: " << endl;
    cout << p13;

    // cout << "Умножим эту картину на число: " << endl;


    // контроль ввода число >= 1
    EnterNumberBolsheZero(chislo,"Умножим эту картину на число: ")();

    // cin >> chislo;

    Painting p14 = p13 * chislo;
    cout << "Результат: " << endl;
    cout << p14;
    
}

void Comparison_by_year ()
{
    Painting p15(2000);
    Painting p16(200);

    cout << "1 картина: " << endl;
    cout << p15;

    cout << "2 картина: " << endl;
    cout << p16;

    bool a = p15 < p16;

    cout << endl;
    cout << "Результат сравнения 1 картина < 2 картина:" << endl;

    if ( a != 0){
        cout << "Картина 1 старше чем картина 2" << endl;
    }
    else{
        cout << "Картина 2 старше чем картина 1 или того же года" << endl;
    }

}

void Average_price_comparison ()
{
    vector <int> vec1 = {1, 2, 3};
    vector <int> vec2 = {4, 5, 6};

    string name1 = "Painitng_1";
    string name2 = "Painting_2";

    Painting p17(name1, vec1);
    Painting p18(name2, vec2);

    cout << "1 картина: " << endl;
    cout << p17;

    cout << "2 картина: " << endl;
    cout << p18;


    bool a = p17 > p18;

    cout << endl;
    cout << "Результат сравнения 1 картина > 2 картина:" << endl;

    if (a != 0){
        cout << "Картина 1 дороже чем картина 2" << endl;
    }
    else
    {
        cout << "Картина 2 дороже или стоит также как картина 1";
    }

}

void add_auction_price_end()
{
    Painting p19;
    cout << "Картина 1: " << endl;
    cout << p19 << endl;
    cout << endl;;

    cout << "Добавим рандомную цену с аукциона в конец вектора цен:" << endl;
    p19++;
    // register_painting(p19);
    cout << p19 << endl;
}

void add_auction_price_begin()
{
    Painting p20;
    cout << "Картина: " << endl;
    cout << p20 << endl;
    cout << endl;

    cout << "Добавим рандомную цену с аукциона в начало вектора цен:" << endl;
    ++p20;
    register_painting(p20);
    cout << p20 << endl;

}

void delete_random_price ()
{
    Painting p21;
    cout << "Картина: " << endl;
    cout << p21 << endl;
    cout << endl;

    cout << "Удалим рандомную цену картины" << endl;
    --p21;
    register_painting(p21);
    cout << p21 << endl;

}

void delete_index_price ()
{
    Painting p22;

    cout << "Картина: " << endl;
    cout << p22 << endl;

    int x, y;

    EnterNumber(x, "Введите порядковый номер цены, которую вы бы хотели заменить: ")();
    x-=1;

    EnterNumber(y, "Введите новую цену: ")();
    cout << endl;

    p22[x] = y;

    cout << "Результат замены: " << endl;

    cout << p22 << endl;

    register_painting(p22);
}

void Display_price_index()
{
    Painting p23;
    int x;

    register_painting(p23);

    cout << "Картина: " << endl;
    cout << p23 << endl;
    cout << endl;

    EnterNumber(x, "Введите порядковый номер цены которую вы бы хотели увидеть: ")();
    x-=1;

    cout << x + 1 << " цена: "  << p23[x] << endl;
}

void Equal_object ()
{
    Painting p24;
    register_painting(p24);
    
    cout << "Картина 1: " << endl;
    cout << p24 << endl;

    Painting p25 = p24;
    register_painting(p25);

    cout << "Копия картины 1: " << endl;
    cout << p25 << endl;
}







// void createObjDefault (){
//     Painting p1;
//     paintings.push_back(p1);
//     p1.display();
//     // p1.display();
// }

// void createObjPre (){
//     Painting p1 ("Cat");
//     paintings.push_back(p1);
//     p1.display();
// }

// void createObjPreWithVector(){
//     vector <int> base = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     Painting p2("Dog", base);
//     paintings.push_back(p2);
//     p2.display();
// }



void Vvesti(){
    Painting p4;
    cout << "Введите объект класса: " << endl;
    cin >> p4;
    register_painting(p4);

}

// void Vivisti (){
//     cout << p4; 
// }



// void Vivesti_copy (){
//     Painting p5{p4};
//     paintings.push_back(p5);
//     cout << p5;
// }

// void Sum_Paintings () {

//     Painting p00{p4};
//     paintings.push_back(p00);

//     Painting pp = p00 + p4;
//     paintings.push_back(pp);

//     cout << pp << endl;

// }

// void Difference_Paintings () {
//     vector <int> e = {14, 67, 42}; // 41
//     Painting ret ("Liza", e);
//     paintings.push_back(ret);


//     Painting p00{p4};
//     paintings.push_back(p00);

//     Painting pp = p00 - ret;
//     paintings.push_back(pp);

//     cout << pp << endl;

// }

// void Unoz () {
//     vector <int> e = {14, 67, 42}; // 41

//     Painting ret ("Liza", e);
//     paintings.push_back(ret);

//     int x = 3;
//     ret = ret * x;
//     cout << "Картина выросла в цене в " << x << " раза!";
//     cout << ret;
// }

// void Increment ()
// {
//     p4++;
//     cout << p4;
// }


// void Decrement ()
// {
//     vector <int> e = {14, 3, 9};

//     Painting ret ("Liza", e);
//     paintings.push_back(ret);

//     --ret;
//     cout << ret;
//     --ret;
//     cout << ret;
//     --ret;
//     cout << ret;
// }

// void Skobki () 
// {
//     vector <int> ass = {1, 2, 3};

//     Painting p99 ("Salo", ass);
//     paintings.push_back(p99);

//     p99[2] = 11;
//     cout << p99;
// }

// void ReadSkobki ()
// {
//     vector <int> ass = {1, 2, 3};

//     Painting p99 ("Salo", ass);
//     paintings.push_back(p99);

//     p99[2] = 11;
//     cout << p99;
//     cout << p99[1];

// }

// void Prisvaivanie ()
// {
//     vector <int> ass = {1, 2, 3};
//     vector <int> bass = {4, 5, 6};

//     Painting p99 ("Salo", ass);
//     paintings.push_back(p99);

//     Painting p88 ("Tomato", bass);
//     paintings.push_back(p88);

//     p99 = p88;
//     cout << p99;
// }
// // void Disp1 () {
// //     p1.display();
// // }

// void PreIncrement ()
// {
//     vector <int> vec = {1, 2, 3};
//     Painting pre_inc ("Dom", vec);

//     cout << pre_inc;

//     ++pre_inc;

//     cout << pre_inc;
// }

// // void Sravnenie ()
// // {
// //     vector <int> price1 = {4,5,6};
// //     Painting year_menishe ("Loki", "Igor", 560, price1);

// //     vector <int> price2 = {7, 8, 9};
// //     Painting year_bolishe ("Tor", "Lana", 1560, price2);

// //     cout << year_menishe < year_bolishe;
// //     Painting new_paint =  year_menishe < year_bolishe;

// //     cout << new_paint;

// // }


// void Sravnenie_year ()
// {
//     vector <int> price1 = {4,5,6}; // 5
//     Painting year_menishe ("Loki", "Igor", 560, price1);

//     vector <int> price2 = {7, 8, 9}; // 8
//     Painting year_bolishe ("Tor", "Lana", 1560, price2);

//     if (year_menishe < year_bolishe) {
//         cout << "Картина Loki старше" << endl;
//     } else {
//         cout << "Картина Tor старше или того же года" << endl;
//     };

// }

// void Sravn_sr_price ()
// {
//     vector <int> price1 = {4,5,6}; // 5
//     Painting year_menishe ("Loki", "Igor", 560, price1);

//     vector <int> price2 = {7, 8, 9}; // 8
//     Painting year_bolishe ("Tor", "Lana", 1560, price2);

//     if (year_bolishe > year_menishe)
//     {
//         cout << "Tor стоит больше!";
//     }

//     else {
//         cout << "Loki стоит больше!";

//     };

// };








#endif