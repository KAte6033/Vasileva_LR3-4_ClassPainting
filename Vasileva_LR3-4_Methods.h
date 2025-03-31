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

// void Disp1 () {
//     p1.display();
// }






#endif