#ifndef VASILEVA_LR3_4_METHODS_H
#define VASILEVA_LR3_4_METHODS_H

#include <algorithm>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <limits>
#include <cmath>
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

Painting p1;




#endif