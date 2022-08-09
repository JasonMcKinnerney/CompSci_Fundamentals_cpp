//Jason McKinnerney JLM573
//10/7/2020
//CS1428 Lab
//Lab 5
//Description: this program will print a pattern of user-input length

#include <iostream>
using namespace std;

int main() {

    int rows, multiple;

    // Prompt the user for the number of rows and the multiple:
    cout << "Enter the number of rows you would like to print (1-25): ";
    cin >> rows;
    cout << "Enter the multiple: ";
    cin >> multiple;

    if ((rows >= 1 && rows <= 25) && (multiple >= 1 && multiple <= 25)) {

        for (int i = 1; i <= (rows + 1); i++) {
            if ( i % multiple == 0) {
                cout << '*' * 10 << endl;
            }
            else {
                cout << "##########" << endl;
            }
        }
    }

    else {
        cout << "Invalid Input." << endl;
    }


    return 0;
}
