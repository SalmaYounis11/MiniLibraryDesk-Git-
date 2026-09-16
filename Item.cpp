#include "Item.h"
#include <iostream>

Item::Item(int id, std::string title)
{
    this->id = id;
    this->title = title;
    this->borrowed = false;
}

int Item::getId() const
{
    return id;
}

std::string Item::getTitle() const
{
    return title;
}

bool Item::isBorrowed() const
{
    return borrowed;
}

void Item::borrow()
{
    borrowed = true;
}

void Item::giveBack()
{
    borrowed = false;
}

void Item::display() const
{
    std::cout << id << " | "
              << title << " | ";

    if (borrowed)
        std::cout << "borrowed";
    else
        std::cout << "available";

    std::cout << std::endl;
}

Item::~Item()
{
}