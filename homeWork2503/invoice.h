#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include "item.h"
#include <vector>

class Invoice
{
    std::string _nipBuyer;
    std::string _nipSeller;

public:
    Invoice(int seller, int buyer);
    Invoice(std::string seller, std::string buyer);

    void add_item(Item item);
    std::vector<Item> _listItem;

    std::string nipBuyer()const;
    std::string nipSeller()const;

    friend std::ostream& operator<<(std::ostream& out, const Invoice& t);
};

#endif // INVOICE_H
