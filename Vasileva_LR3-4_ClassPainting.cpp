#ifndef VASILEVA_LR3_4_CLASSPAINTING_CPP
#define VASILEVA_LR3_4_CLASSPAINTING_CPP

#include "Vasileva_LR3-4_Methods.h"
// #include "Vasileva_LR3-4_ClassPainting.h"


Painting :: Painting () 
{
    title = "unknown";
    author = "anonim";

    year = rand() % (2001 - 1600 + 1) + 1600;

    prices.resize(10, 0);

    generate(prices.begin(), prices.end(), []() { return rand() % (1000000 - 10000 + 1) + 10000; });

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


// ostream& operator + (, const Painting& obj ){};




#endif