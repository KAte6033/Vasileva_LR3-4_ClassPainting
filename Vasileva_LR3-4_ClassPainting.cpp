#ifndef VASILEVA_LR3_4_CLASSPAINTING_CPP
#define VASILEVA_LR3_4_CLASSPAINTING_CPP

#include "Vasileva_LR3-4_Methods.h"
// #include "Vasileva_LR3-4_ClassPainting.h"


// конструктор по умолчанию
Painting :: Painting () 
{
    title = "unknown";
    author = "anonim";

    year = rand() % (2001 - 1600 + 1) + 1600;

    prices.resize(10, 0);

    generate(prices.begin(), prices.end(), []() { return rand() % (100000 - 10000 + 1) + 10000; });

    // for (int i = 0 ; i < 10; i++){
    //     prices[i] = rand() % (1000000 - 10000 + 1) + 10000;
    // }



    // generate ()[];

};

// конструктор преобразования реализация
Painting :: Painting (string name_of_painting) : title(name_of_painting), author("unknown") {
    year = rand() % (2001 - 1600 + 1) + 1600;

    prices.resize(10, 0);

    generate(prices.begin(), prices.end(), []() { return rand() % (1000000 - 10000 + 1) + 10000; });
};


// конструктор параметезированный  делегирующий

Painting :: Painting (string name_painting, const vector <int> price) : Painting(name_painting)
{
    set_prices(price);

};

// конструктор копирования

Painting :: Painting (const Painting& other) :  prices(other.prices)
{
    title = "unknown";
    author = "anonim";

    year = rand() % (2001 - 1600 + 1) + 1600;

};

// Painting :: Painting (const Painting& other) :  prices(other.prices) 
// {};


// Painting :: Painting (const Painting& other) :  title(other.title), author(other.author), year(other.year), prices(other.prices) 
// {};

// Painting :: Painting (string name_painting, string name_author, int yea_r, const vector <int> price) : Painting(name_painting)
// {
//     set_prices(price);

// };

// Painting :: Painting (const Painting& other) : ;

// string title;
// string author;
// int year;
// vector <int> prices = {};

void Painting :: display() const {
    cout << "Title: " << title << ", Author's name: " << author << ", Year: " << year 
    << ", Prices: ";
    
    for (int i = 0; i < prices.size(); i ++){
        cout << prices[i];

        if ( i != prices.size() - 1){
            cout << ", ";
        }
    }

    cout << endl;
    
};

ostream& operator << (ostream& my_stream, const Painting& obj ){

    // string st;
    // string title;
    // string author;
    // string year;
    // string vector_size;
    // int vec_sz;
    // vector <int> prices = {};

    my_stream << "Title: " << obj.title << ", Author's name: " << obj.author << ", Year: " << obj.year 
    << ", Prices: ";
    
    for (int i = 0; i < obj.prices.size(); i ++){
        cout << obj.prices[i];

        if ( i != obj.prices.size() - 1){
            cout << ", ";
        }
    }

    cout << endl;

    return my_stream;
};


istream& operator >> (istream& my_stream, Painting& obj)
{
    string st;
    string title;
    string author;
    string year;
    string vector_size;
    int vec_sz;
    vector <int> prices = {};


    cout << "Enter title: ";
    getline(my_stream, st);
    obj.title = st;
    cout << endl;

    cout << "Enter author: ";
    getline(my_stream, st);
    obj.author = st;
    cout << endl;

    cout << "Enter year: ";
    getline(my_stream, st);
    obj.year = stoi(st);
    cout << endl;

    cout << "Enter size of vector: ";
    getline(my_stream, vector_size);
    vec_sz = stoi(vector_size);

    obj.prices.clear();

    for (int i = vec_sz; i > 0; i-- ){
        cout << "Enter " << i << " price: ";
        getline(my_stream, st);
        obj.prices.push_back(stoi(st));
    }
    return my_stream;
};




// ostream& operator + (, const Painting& obj ){};




#endif