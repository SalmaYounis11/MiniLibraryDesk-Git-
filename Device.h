#pragma once

#include "Item.h"

class Device : public Item
{
private:
    std::string location;

public:
    Device(int id, std::string title, std::string location);

    std::string getLocation() const;

    void display() const override;

    std::string toCsv() const override;
};