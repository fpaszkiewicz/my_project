#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item
{

    std::string _name;
    float _netPrice;
    char _vatType;
    int _amount;
    float _price;

public:
    Item(std::string name, float netto, char VAT, int amount);
    std::string name() const;
    float netPrice() const;
    char VAT() const;
    int amount() const;
    float price() const;
};

#endif // ITEM_H
