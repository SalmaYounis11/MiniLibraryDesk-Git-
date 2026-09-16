#include "Device.h"
#include <iostream>

Device::Device(int id, std::string title, std::string location)
    : Item(id, title)
{
    this->location = location;
}

std::string Device::getLocation() const
{
    return location;
}

void Device::display() const
{
    std::cout << "[Device] " << getId() << " | "
              << getTitle() << " | "
              << getLocation() << " | ";

    if (isBorrowed())
        std::cout << "borrowed";
    else
        std::cout << "available";

    std::cout << std::endl;
}

std::string Device::toCsv() const
{
    return "D," + std::to_string(getId()) + "," +
           getTitle() + "," + getLocation() + "," +
           std::to_string(isBorrowed() ? 1 : 0);
}