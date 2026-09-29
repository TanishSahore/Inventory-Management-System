#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <fstream>
#include "Product.h"

using namespace std;

class Inventory
{
private:
    vector<Product> products;

public:
    Inventory();

    void loadProducts();
    void saveProducts();

    void addProduct();
    void viewProducts();
    void searchProduct();      // NEW
};

#endif