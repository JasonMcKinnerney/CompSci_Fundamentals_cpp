// Jason McKinnerney JLM573
// 10/7/2020
// No Collaborators
// Lab 5 Pre-Lab

// Finish the following program which adds up all integers from 0 to
// the user's given number inclusively using a FOR loop. The total should be
// assigned to the variable 'total'.

#include <iostream>
using namespace std;


int main()
{
    int number;
    int total;
    int i;

    cout << "Enter a positive integer to find the summation of"
         << " all numbers from 0 to the given number." << endl;
    cin >> number;

    for ( i = 0; i <= number; i = i + 1) {
            total = total + i;
    }






    cout << "Total : " << total << endl;

    return 0;
}
