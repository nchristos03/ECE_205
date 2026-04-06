#include <iostream>
using namespace std;

class Book
{
    public:
        Book(string cat1, int year1, int isbn1);
        bool isAvailable();
    private:
        string cat;
        int year;
        int isbn;
};

Book::Book(string cat1, int year1, int isbn1)
{
    cat = cat1;
    year = year1;
    isbn = isbn1;
}

bool Book::isAvailable()
{
    if(cat == "history")
    {
        if(year > 1950)
            return true;
    }
    return false;
}

void display(bool available)
{
    if (available)
        cout << "The book is available!";
    else
        cout << "The book is not available.";
}

Book getBook()
{
    string cat1;
    int year1, isbn1;

    cout << "Enter the category of the book: ";
    cin >> cat1;

    cout << "Enter the year the book was published: ";
    cin >> year1;

    cout << "Enter the ISBN of the book: ";
    cin >> isbn1;

    Book book1(cat1, year1, isbn1);
    return book1;
}

int main()
{
    Book book1 = getBook();
    bool available = book1.isAvailable();
    display(available);

    return 0;
}