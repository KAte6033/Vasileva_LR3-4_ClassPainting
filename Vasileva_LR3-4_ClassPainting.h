#ifndef VASILEVA_LR3_4_CLASSPAINTING_H
#define VASILEVA_LR3_4_CLASSPAINTING_H


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
#include <ctime>

using namespace std;
// #include <C:\\Users\\User\\Desktop\\ALL_LABS\\Laba3_4\\Vasileva_LR3-4_ClassPainting\\Vasileva_LR3-4_Methods.h>

class Painting
{
private:
    string title;
    string author;
    int year;

    // unsigned raz = 0;
    vector <int> prices = {};

    // int* prices {nullptr};

    public:
        
        // конструктор по умолчанию
        Painting();

        // конструктор преобразования
        Painting (const string& name_of_painting);

        // ещё один констурктор преобразлвания, чтобы делегирующий ссылался на него
        Painting (int new_year);


        // параметизированный делигирующий конструктор
        
        // создание картины, с заданным названием, автором, годом и массивом цен
        // Painting (string name_painting, string name_author, int yea_r, vector <int> price)
        // {};


        // параметезированный конструктор
        Painting (string name_painting, string name_author, int year_of_painting, vector <int> price);

        // Конструктор делегирующий
        Painting (string name_painting, int year_r);

        // параметизированный делигирующий конструктор
        Painting (string name_painting, vector <int> price);

        // Painting (string name_painting, string name_author, int yea_r, vector <int> price) : Painting(name_painting)
        // {};


        // конструктор копирования
        Painting (const Painting& other);
        // Painting (const Painting& other);


        ~Painting() {}; // деструктор 


        void set_title(const string &TITLE){
            title = TITLE;
        }

        string get_title () const {
            return title;
        };

        void set_author_name (const string &NAME){
            author = NAME;
        }

        string get_author_name () const {
            return author;
        }

        void set_prices (const vector <int> &PRICES ){
            prices = PRICES;

        }


        vector <int> get_prices () const {
            return prices;
        }

        void display() const;

        // Painting Painting :: NewNameOfOperationg(const Painting& other) const;

        // это мне надо, чтобы потом использовать в операторах
        pair<string, string> CombineNameAndAuthor(const Painting& other) const;

        // это мне надо чтобы считать среднее арифмитическое 
        int AveragePrice() const;

        void generate_random_prices();

        // int generate_random_prices(const Painting& other) {};
        
        // продемонстрировано
        Painting operator + (const Painting& other) const; 

        // продемонстрировано
        Painting operator - (const Painting& other) const;

        // продемонстрировано
        Painting operator * (const int x) const;

        // продемонстрировано
        bool operator < (const Painting& other) const;

        // продемонстрировано
        bool operator > (const Painting& other) const;
        
        // продемонстрировано
        Painting operator++(int);  // постфиксный инкремент

        // продемонстрировано
        Painting& operator++();    // префисксный инкремент

        // продемонстрировано
        Painting& operator--();       // префиксный декремент


        // продемонстрировано
        int& operator [](size_t index);

        // продемонстрировано
        const int& operator [](size_t index) const;

        // продемонстрировано
        Painting& operator = (const Painting& other); 


        // продемонстрировано
        friend ostream& operator << (ostream& my_stream, const Painting& obj );
        friend istream& operator >> (istream& my_stream, Painting& obj);
        
};


#endif