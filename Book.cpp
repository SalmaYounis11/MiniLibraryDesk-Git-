#include "Book.h"
#include <iostream>

Book::Book(int id, std::string title, std::string author)
    : Item(id, title)
{
    this->author = author;
}

std::string Book::getAuthor() const
{
    return author;
}

void Book::display() const
{
    std::cout << "[Book] " << getId() << " | "
              << getTitle() << " | "
              << getAuthor() << " | ";

    if (isBorrowed())
        std::cout << "borrowed";
    else
        std::cout << "available";

    std::cout << std::endl;
}

std::string Book::toCsv() const
{
    return "B," + std::to_string(getId()) + "," +
           getTitle() + "," + getAuthor() + "," +
           std::to_string(isBorrowed() ? 1 : 0);
}