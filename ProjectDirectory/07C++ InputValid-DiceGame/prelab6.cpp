// Jason McKinnerney JLM573
// 10/13/2020
#include <iostream>

using namespace std;

int main()
{

    int number;
    int total = 0;
    int counter = 0; //initialize the variable

    // user enters a number
    cout << "Enter a positive integer to find the summation of ";
    cout << "all numbers from 0 to the given number up to 100." << endl;
    cin >> number;

    // check for invalid user input
    if (number < 1  || number > 100)
    {
        cout << "Invalid Input" << endl;
        return -1; // terminate program
    }

    while (counter <= number) {
        total = total + counter;
        counter = counter + 1;
    }

    cout << "Your total is :" << total;

    return 0;
}
