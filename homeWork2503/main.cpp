#include <iostream>
#include "Time.h"
#include "invoice.h"
#include "item.h"
using namespace std;

int main()
{
    // Time t1(200);
    // cout << t1 << endl; // displays 03m:20s
    // Time t2;
    // cin >> t2; // user enters 10h12m01s

    // Time t3 = t2 - t1; // 10h:8m:41s
    // cout << t2 << endl;
    // int t3s = t3; // 36521
    // cout << t3s << endl;


    Invoice inv("7770003699", "0123456789");
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
    return 0;
}
