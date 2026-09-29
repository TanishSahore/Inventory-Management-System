#include "Product.h"

Product::Product()
{
    id = 0;
    price = 0;
    quantity = 0;
}

void Product::input()
{
    cout << "\nEnter Product ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, name);

    cout << "Enter Category: ";
    getline(cin, category);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;

    cin.ignore();

    cout << "Enter Supplier: ";
    getline(cin, supplier);
}

void Product::display()
{
    cout << "\n----------------------------------------\n";
    cout << "Product ID : " << id << endl;
    cout << "Name       : " << name << endl;
    cout << "Category   : " << category << endl;
    cout << "Price      : " << price << endl;
    cout << "Quantity   : " << quantity << endl;
    cout << "Supplier   : " << supplier << endl;
    cout << "----------------------------------------\n";
}