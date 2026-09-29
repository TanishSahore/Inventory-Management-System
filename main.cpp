#include <iostream>
#include "Inventory.h"

using namespace std;

int main()
{
    Inventory inventory;
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "     INVENTORY MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "=========================================\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            inventory.addProduct();
            break;

        case 2:
            inventory.viewProducts();
            break;

        case 3:
            inventory.searchProduct();
            break;

        case 4:
            cout << "\nThank You for using Inventory Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 4);

    return 0;
}