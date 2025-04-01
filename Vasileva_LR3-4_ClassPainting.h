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
        Painting (string name_of_painting);


        // параметизированный делигирующий конструктор
        
        // создание картины, с заданным названием, автором, годом и массивом цен
        // Painting (string name_painting, string name_author, int yea_r, vector <int> price)
        // {};

        // параметезированный конструктор

        Painting (string name_painting, string name_author, int year_of_painting, vector <int> price);

        // параметизированный делигирующий конструктор
        Painting (string name_painting, vector <int> price);

        // Painting (string name_painting, string name_author, int yea_r, vector <int> price) : Painting(name_painting)
        // {};


        // конструктор копирования
        Painting (const Painting& other);
        // Painting (const Painting& other);

        ~Painting() {}; // деструктор 

        // prices.clear




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

        // void set_prices ( unsigned razmer, vector <int>& PRICES ){
        //     if (razmer < PRICES.size()){
        //         prices.resize(razmer);
        //         prices.assign(PRICES.begin(), PRICES.begin() + razmer);
        //     }
        //     {
        //         cerr << "Error" << endl;
        //     }

        // }

        vector <int> get_prices () const {
            return prices;
        }

        void display() const;

        // Painting Painting :: NewNameOfOperationg(const Painting& other) const;

        // это мне надо, чтобы потом использовать в операторах
        pair<string, string> CombineNameAndAuthor(const Painting& other) const;

        // это мне надо чтобы считать среднее арифмитическое 
        int AveragePrice() const;

        Painting operator + (const Painting& other) const;

        Painting operator - (const Painting& other) const;

        Painting operator * (const int x) const;

        // friend ostream& operator + (ostream& my_stream, const Painting& obj ){};
        friend ostream& operator << (ostream& my_stream, const Painting& obj );
        friend istream& operator >> (istream& my_stream, Painting& obj);
        
};







// Painting Painting :: operator + (const Painting& other) const 
// {
//     vector<int> result_prices = prices;
//     result_prices.insert(result_prices.end(), other.prices.begin(), other.prices.end());

//     string name = "\"" + title + "\" and \"" + other.title + "\"";
//     string authors = author + " and " + other.author;
    


//     return Painting(name, authors, -1, result_prices);
    
// };

// Painting Painting ::  operator - (const Painting& other) const 
// {
//     // среднюю разницу стоимости по формуле
//     // sr_zn (pfinting1.prices) - sr_zn (pfinting2.prices)
//     // или создать новый вектор с этими двумя средними значениями картин, 
//     // слева стоимость средняя 1 картины
//     // справа средняя стоимость второй картины 
//     //  вернуть новый объект через конструктор преобразования
//     // год = -1, название А + Б, автор А + Б, цены - вернуть новый веткор
//     // со средними значениями.

//     vector<int> result_prices;
    
//     int sum1 = 0;
    
//     if (prices.empty() ) {
//         cout << "Vector is empty!" << endl;
//     }

//     else
//     {
        
//         for (int price : prices) {
//             sum1 += price;
//         }

//     }

    
//     int average1 = sum1 / prices.size();
//     result_prices.push_back(average1);

//     int sum2 = 0;

//     if (other.prices.empty() ) {
//         cout << "Vector is empty!" << endl;
//     }

//     else
//     {
//         for (int price : other.prices) {
//             sum2 += price;
//         }

//     }

//     int average2 = sum2 / other.prices.size();

//     result_prices.push_back(average2);

//     // vector<int> result_prices = prices;
//     // result_prices.insert(result_prices.end(), other.prices.begin(), other.prices.end());

//     string name = "\"" + title + "\" and \"" + other.title + "\"";
//     string authors = author + " and " + other.author;
    


//     return Painting(name, authors, -1, result_prices);



// };




// Vasileva_LR3-4_ClassPainting::Vasileva_LR3-4_ClassPainting(/* args */)
// {
// }

// Vasileva_LR3-4_ClassPainting::~Vasileva_LR3-4_ClassPainting()
// {
// }


#endif