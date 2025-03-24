#include "invoice.h"
#include "item.h"
#include <iostream>

using namespace std;
Invoice::Invoice(int seller, int buyer){
    Invoice(std::to_string(seller), std::to_string(buyer));
};
Invoice::Invoice(std::string seller, std::string buyer){
    _nipSeller = seller;
    _nipBuyer = buyer;
};

void Invoice::add_item(Item item){
    _listItem.emplace_back(item);
}

std::string Invoice::nipSeller() const{
    return _nipSeller;
}

std::string Invoice::nipBuyer() const{
    return _nipBuyer;
}

std::ostream& operator<<(std::ostream& out, const Invoice& t) {
    out << "------------------VAT invoice------------------\n";
    out << "===============================================\n";
    out << "Seller: " + t.nipSeller() + "\tBuyer: " + t.nipBuyer() + "\n\n";

    float sumPrice = 0;
    for (size_t i = 0; i < t._listItem.size(); i++) {
        out << std::to_string(i + 1) + ". " + t._listItem[i].name() + " | "
                   + std::to_string(t._listItem[i].netPrice()) + " | "
                   + std::to_string(t._listItem[i].VAT()) + " | "
                   + std::to_string(t._listItem[i].amount()) + " | "
                   + std::to_string(t._listItem[i].price()) + "\n";
        sumPrice += t._listItem[i].price();
    }
    out << "Total : " + std::to_string(sumPrice) + "\n";

    return out;
}
