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
using namespace std;

class Painting
{
private:
    string title;
    string author;
    int year;
    vector <int> prices = {};

    public:
        
        Painting () : title(), author(), year(), prices() {};

        ~Painting() {};



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