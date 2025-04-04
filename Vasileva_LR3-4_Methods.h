#ifndef VASILEVA_LR3_4_METHODS_H
#define VASILEVA_LR3_4_METHODS_H


#include "Vasileva_LR3-4_ClassPainting.h"

using namespace std;

const int infinity = std::numeric_limits<int>::max();


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

// ввод интовых чисел
function <void()> EnterNumber (int& varlink, string label){
    return [&varlink, label](){
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserInput(raw_input)){
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varlink = stoi(raw_input);
    };
}

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

// Painting p1;


// заполняем вектор с клавиатуры
// vector<Bus> DB_Bus;
// void printDatabase();

// заполняем вектор с клавиатуры


void createObjDefault (){
    Painting p1;
    p1.display();
    // p1.display();
}

void createObjPre (){
    Painting p1 ("Cat");
    p1.display();
}

void createObjPreWithVector(){
    vector <int> base = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Painting p2("Dog", base);
    p2.display();
}

Painting p4;
void Vvesti(){
    cout << "Введите объект класса: " << endl;
    cin >> p4;

}

void Vivisti (){
    cout << p4; 
}



void Vivesti_copy (){
    Painting p5{p4};
    cout << p5;
}

void Sum_Paintings () {

    Painting p00{p4};
    Painting pp = p00 + p4;
    cout << pp << endl;

}

void Difference_Paintings () {
    vector <int> e = {14, 67, 42}; // 41
    Painting ret ("Liza", e);
    Painting p00{p4};
    Painting pp = p00 - ret;
    cout << pp << endl;

}

void Unoz () {
    vector <int> e = {14, 67, 42}; // 41
    Painting ret ("Liza", e);
    int x = 3;
    ret = ret * x;
    cout << "Картина выросла в цене в " << x << " раза!";
    cout << ret;
}

void Increment ()
{
    p4++;
    cout << p4;
}


void Decrement ()
{
    vector <int> e = {14, 3, 9};
    Painting ret ("Liza", e);
    --ret;
    cout << ret;
    --ret;
    cout << ret;
    --ret;
    cout << ret;
}

void Skobki () 
{
    vector <int> ass = {1, 2, 3};

    Painting p99 ("Salo", ass);

    p99[2] = 11;
    cout << p99;
}

void ReadSkobki ()
{
    vector <int> ass = {1, 2, 3};

    Painting p99 ("Salo", ass);

    p99[2] = 11;
    cout << p99;
    cout << p99[1];

}

void Prisvaivanie ()
{
    vector <int> ass = {1, 2, 3};
    vector <int> bass = {4, 5, 6};

    Painting p99 ("Salo", ass);
    Painting p88 ("Tomato", bass);

    p99 = p88;
    cout << p99;
}
// void Disp1 () {
//     p1.display();
// }

void PreIncrement ()
{
    vector <int> vec = {1, 2, 3};
    Painting pre_inc ("Dom", vec);

    cout << pre_inc;

    ++pre_inc;

    cout << pre_inc;
}

// void Sravnenie ()
// {
//     vector <int> price1 = {4,5,6};
//     Painting year_menishe ("Loki", "Igor", 560, price1);

//     vector <int> price2 = {7, 8, 9};
//     Painting year_bolishe ("Tor", "Lana", 1560, price2);

//     cout << year_menishe < year_bolishe;
//     Painting new_paint =  year_menishe < year_bolishe;

//     cout << new_paint;

// }


void Sravnenie_year ()
{
    vector <int> price1 = {4,5,6}; // 5
    Painting year_menishe ("Loki", "Igor", 560, price1);

    vector <int> price2 = {7, 8, 9}; // 8
    Painting year_bolishe ("Tor", "Lana", 1560, price2);

    if (year_menishe < year_bolishe) {
        cout << "Картина Loki старше" << endl;
    } else {
        cout << "Картина Tor старше или того же года" << endl;
    };

}

void Sravn_sr_price ()
{
    vector <int> price1 = {4,5,6}; // 5
    Painting year_menishe ("Loki", "Igor", 560, price1);

    vector <int> price2 = {7, 8, 9}; // 8
    Painting year_bolishe ("Tor", "Lana", 1560, price2);

    if (year_bolishe > year_menishe)
    {
        cout << "Tor стоит больше!";
    }

    else {
        cout << "Loki стоит больше!";

    };

};








#endif