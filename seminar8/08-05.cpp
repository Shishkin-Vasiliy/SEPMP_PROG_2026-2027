#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book)
{
    return book.price > 1000;
}

int main()
{
    Book book1 = {"C++", 500, 1200.0f};
    Book book2 = {"C", 300, 800.0f};

    std::cout << isExpensive(book1) << std::endl;
    std::cout << isExpensive(book2) << std::endl;

    return 0;
}