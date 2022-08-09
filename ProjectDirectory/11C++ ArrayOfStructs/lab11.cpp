//Jason McKinnerney JLM573
//11/18/2020
//CS1428 Lab
//Lab 11
//Description: this program will track an inventory of items.

#include <iostream>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    double cost;
    int quantity;

};

int main()
{
    const int SIZE = 3;
    Item inventory[SIZE];
    int totalItems = 0,
        cheapestIndex = 0;
    double totalValue = 0;

    for(int i = 0; i < SIZE; i++)
    {
        cout << "Product #" << i + 1 << endl;
        cout << "Enter name: ";
        cin >> inventory[i].name;
        cout << "Enter cost: ";         // Fill array of structures
        cin >> inventory[i].cost;
        cout << "Enter quantity: ";
        cin >> inventory[i].quantity;

        totalItems += inventory[i].quantity;

        totalValue = totalValue + (inventory[i].quantity * inventory[i].cost);

        if (inventory[i].cost <= inventory[cheapestIndex].cost){
            cheapestIndex = i;
        }



        cout <<  endl << endl;
    }
    cout << left << setw(6) << fixed;
    cout << "Total number of items" << ":" << totalItems << endl;
    cout << "Total value of inventory" << ":" <<  "$" << totalValue << endl;
    cout << "Cheapest Item" << ":" <<  inventory[cheapestIndex].name << endl;

    return 0;
}
