#ifndef VASILEVA_LR3_4_CLASSPAINTING_H
#define VASILEVA_LR3_4_CLASSPAINTING_H


#include <C:\\Users\\User\\Desktop\\ALL_LABS\\Laba3_4\\Vasileva_LR3-4_ClassPainting\\Vasileva_LR3-4_Methods.h>

class Painting
{
private:
    string title;
    string author;
    int year;
    vector <int> prices = {};

    public:
        
        // конструктор по умолчанию
        Painting () : title(), author(), year(), prices() {};

        // конструкто преобразования

        Painting (string name_of_painting);

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
        
};

// Vasileva_LR3-4_ClassPainting::Vasileva_LR3-4_ClassPainting(/* args */)
// {
// }

// Vasileva_LR3-4_ClassPainting::~Vasileva_LR3-4_ClassPainting()
// {
// }


#endif