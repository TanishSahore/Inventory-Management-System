#include "Inventory.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
Inventory::Inventory()
{
    loadProducts();
}

// Load products from file
void Inventory::loadProducts()
{
    products.clear();

    ifstream file("products.txt");

    if (!file)
        return;

    Product p;

    while (file >> p.id)
    {
        file.ignore();

        getline(file, p.name);
        getline(file, p.category);

        file >> p.price;
        file >> p.quantity;

        file.ignore();

        getline(file, p.supplier);

        products.push_back(p);
    }

    file.close();
}

// Save products to file
void Inventory::saveProducts()
{
    ofstream file("products.txt");

    for (Product p : products)
    {
        file << p.id << endl;
        file << p.name << endl;
        file << p.category << endl;
        file << p.price << endl;
        file << p.quantity << endl;
        file << p.supplier << endl;
    }

    file.close();
}

// Add Product
void Inventory::addProduct()
{
    Product p;

    cout << "\n===== Add New Product =====\n";

    p.input();

    products.push_back(p);

    saveProducts();

    cout << "\nProduct Added Successfully!\n";
}

// View Products
void Inventory::viewProducts()
{
    if (products.empty())
    {
        cout << "\nNo Products Available.\n";
        return;
    }

    cout << "\n========== Product List ==========\n";

    for (Product p : products)
    {
        p.display();
    }
}

// Search Product
void Inventory::searchProduct()
{
    int searchId;
    bool found = false;

    cout << "\nEnter Product ID to Search: ";
    cin >> searchId;

    for (Product p : products)
    {
        if (p.id == searchId)
        {
            cout << "\nProduct Found!\n";
            p.display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nProduct Not Found!\n";
    }
}