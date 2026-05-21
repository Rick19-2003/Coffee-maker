#ifndef KAPEPE_H
#define KAPEPE_H

#include <iostream>
#include <string>
using namespace std;

class FoodOrder
{
private:
    string customerName;
    int total;

public:
    FoodOrder();
    void showMenu();
    string getItem(int choice);
    int getPrice(int choice);
    int addOuncePrice(int ounceChoice);
    string getOunce(int ounceChoice);
    void processOrder();
    void setCustomerName();
};

#endif
