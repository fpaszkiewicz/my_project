#include "item.h"

Item::Item(std::string name, float netto, char VAT, int amount){
    _name = name;
    _netPrice = netto;
    _vatType = VAT;
    _amount = amount;
    int tax;
    switch(VAT){
    case 'A':
        tax = 23;
        break;
    case 'B':
        tax = 8;
        break;
    case 'C':
        tax = 0;
        break;
    }
    _price = (netto + netto / 100 * tax) * amount;
};

std::string Item::name() const{
    return _name;
}

float Item::netPrice() const{
    return _netPrice;
}

char Item::VAT() const{
    return _vatType;
}

int Item::amount() const{
    return _amount;
}

float Item::price() const{
    return _price;
}
