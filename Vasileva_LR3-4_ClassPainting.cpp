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

    generate_random_prices();
    // prices.resize(10, 0);

    // generate(prices.begin(), prices.end(), []() { return rand() % (100000 - 10000 + 1) + 10000; });

    // paintings.push_back(*this);

};




// конструктор преобразования реализация
Painting :: Painting (const string& name_of_painting) : title(name_of_painting), author("unknown") {
    year = rand() % (2001 - 1600 + 1) + 1600;

    // prices.resize(10, 0);

    // generate(prices.begin(), prices.end(), []() { return rand() % (1000000 - 10000 + 1) + 10000; });

    generate_random_prices();
    // paintings.push_back(*this);
};




// конструктор параметизированный

Painting :: Painting (string name_painting, string name_author, int year_of_painting, vector <int> price) 
: title(name_painting), author(name_author), year(year_of_painting), prices(price) 
{
    paintings.push_back(*this);
};


// Конструктор преобразования года делигирующийся
Painting :: Painting (int new_year) : title("unknown"), author("anonim"), year(new_year) 
{
    generate_random_prices();
    paintings.push_back(*this);
};

// Конструктор делегирующий
Painting :: Painting (string name_painting, int year_r) : Painting(year_r)
{
    set_title(name_painting);

};

// конструктор параметезированный  делегирующий
Painting :: Painting (string name_painting, const vector <int> price) : Painting(name_painting)
{
    set_prices(price);
    paintings.push_back(*this);

};






// старый конструктор копирования
// Painting :: Painting (const Painting& other) :  prices(other.prices)
// {
//     title = "unknown";
//     author = "anonim";

//     year = rand() % (2001 - 1600 + 1) + 1600;

// };

// конструктор копирования

Painting :: Painting (const Painting& other) :  title(other.title),
    author(other.author),
    year(other.year), // КОПИРУЕМ, а не создаём новый!
    prices(other.prices)

{};

// генерирует вектор рандомных цен 
void Painting :: generate_random_prices() 
{
    prices.resize(rand() % 10 + 1, 0);
    generate(prices.begin(), prices.end(), []() {
        return rand() % (100000 - 10000 + 1) + 10000;
    });
}

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


// функция, которая преобразует названия картин и имена авторов для вывода + и -
pair<string, string> Painting::CombineNameAndAuthor(const Painting& other) const {
    string name = "\"" + title + "\" and \"" + other.title + "\"";
    string authors = author + " and " + other.author;
    return {name, authors};
}


// int generate_random_prices(const Painting& other)
// {
//     other.prices.resize(10, 0);
//     generate(prices.begin(), prices.end(), []() {
//         return rand() % (100000 - 10000 + 1) + 10000;
//     });
// }


// считает среднее арифмитическое 

int Painting :: AveragePrice() const 
{
    if (prices.empty())
    {
        cout << "Vector is empty!";
        return 0;
    }
    else
    {
        int sum = 0;
        for (int p : prices) sum += p;
        return sum / prices.size();
    }
    
};



Painting Painting :: operator + (const Painting& other) const 
{   
    //
    vector<int> result_prices = prices;
    result_prices.insert(result_prices.end(), other.prices.begin(), other.prices.end());
    //


    // вернёт как переменные, т.е. распакует pair (auto [name, authors])
    auto [name, authors] = CombineNameAndAuthor(other);
    
    return Painting(name, authors, -1, result_prices);
    
};




Painting Painting ::  operator - (const Painting& other) const 
{
    // среднюю разницу стоимости по формуле
    // sr_zn (pfinting1.prices) - sr_zn (pfinting2.prices)
    // или создать новый вектор с этими двумя средними значениями картин, 
    // слева стоимость средняя 1 картины
    // справа средняя стоимость второй картины 
    //  вернуть новый объект через конструктор преобразования
    // год = -1, название А + Б, автор А + Б, цены - вернуть новый веткор
    // со средними значениями.

    int avg1 = AveragePrice();
    int avg2 = other.AveragePrice();

    vector<int> result_prices = {avg1, avg2};

    auto [name, authors] = CombineNameAndAuthor(other);

    return Painting(name, authors, -1, result_prices);

};


Painting Painting ::  operator * (const int x) const
{
    // умножение картины на число

    vector<int> result_prices = prices;

    for (int& val : result_prices) {
        val *= x;
    }


    return Painting (title, author, year, result_prices);

};

bool Painting :: operator<(const Painting& other) const 
{
    return year < other.year;
};

bool Painting :: operator > (const Painting& other) const
{
    return AveragePrice() > other.AveragePrice();
};

// Painting Painting ::  operator < (const Painting& other) const 
// {
//     if (year < other.year) {
//         return *this;        // текущая картина старше
//     } else {
//         return other;        // другая картина старше или одинаково старая
//     }

// };

// Painting Painting::operator<(const Painting& other) const {
//     if (year < other.year) {
//         return *this;        // текущая картина старше
//     } else {
//         return other;        // другая картина старше или одинаково старая
//     }
// }

Painting Painting :: operator++(int)
{
    // добовляет рандомную цену в конец вектор с ценами
    prices.push_back(rand() % (50000 - 3000 + 1) + 3000);
    return Painting(title, author, year, prices);
    
};


Painting& Painting :: operator++() 
{
    // this-> prices.insert(prices.begin(), (rand() % (50000 - 3000 + 1) + 3000));
    // добавляем рандомную цену в начло вектора цен
    prices.insert(prices.begin(), (rand() % (50000 - 3000 + 1) + 3000));
    return *this;

}


Painting& Painting :: operator--()
{
    size_t a = prices.size();
    int index;

    index = rand() % a;

    if (index < a){
        prices.erase(prices.begin() + index);
        cout << "Удалён элемент номер: " << index + 1 << endl;
    }

    else
    {
        cout << "Индекс вне диапазона!" << endl;

    }

    return *this;
    
};

int& Painting :: operator[](size_t index) {

    return prices.at(index);
    // безопасный доступ с проверкой границ
};

// const только для чтения
const int& Painting :: operator[](size_t index) const 
{
    return prices.at(index);
};

Painting& Painting :: operator = (const Painting& other)
{
    if (this == &other){
        return *this;
    }

    else 
    {
        title = other.title;
        author = other.author;
        year = other.year;
        prices = other.prices;
        return *this;
    }
}; 



// Painting&  Painting :: operator--(int x)
// {

// }; 




ostream& operator << (ostream& my_stream, const Painting& obj ){

    my_stream << "Title: " << obj.title << ", Author's name: " << obj.author << ", Year: " << obj.year 
    << ", Prices: ";
    
    for (size_t i = 0; i < obj.prices.size(); ++i) {
        my_stream << obj.prices[i];
        if (i != obj.prices.size() - 1) {
            my_stream << ", ";
        }
    }

    my_stream << std::endl;
    return my_stream;
};


istream& operator >> (istream& my_stream, Painting& obj)
{
    string helper;
    int help_me;
    string vector_size;
    int vec_sz;
    vector <int> prices = {};


    // cout << "Enter title: ";
    EnterStr(helper, "Enter title: ")();
    // getline(my_stream, helper);
    obj.title = helper;
    cout << endl;

    // cout << "Enter author: ";
    EnterStr(helper, "Enter author: ")();
    // getline(my_stream, helper);
    obj.author = helper;
    cout << endl;

    // cout << "Enter year: ";
    EnterNumberBolsheZero(help_me, "Enter year: ")();
    // getline(my_stream, helper);
    // obj.year = stoi(helper);
    obj.year = help_me;
    cout << endl;

    // cout << "Enter size of vector: ";
    EnterNumberBolsheZero(help_me, "Enter size of vector: ")();
    // getline(my_stream, vector_size);
    // vec_sz = stoi(vector_size);
    vec_sz = help_me;

    obj.prices.clear();

    for (int i = vec_sz; i > 0; i-- ){
        EnterNumber(help_me,"Enter price: ")();
        // cout << "Enter " << i << " price: ";
        // getline(my_stream, helper);
        // obj.prices.push_back(stoi(helper));
        obj.prices.push_back(help_me);
    }
    return my_stream;
};


// вектор хранящий все объекты класса Painting
vector<Painting> paintings;







#endif