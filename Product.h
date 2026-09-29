#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
    int id;
    string name;
    string category;
    float price;
    int quantity;
    string supplier;

    Product();

    void input();
    void display();
};

#endif