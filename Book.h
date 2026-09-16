#pragma once

#include "Item.h"

class Book : public Item
{
private:
    std::string author;

public:
    Book(int id, std::string title, std::string author);

    std::string getAuthor() const;

    void display() const override;

    std::string toCsv() const override;
};