//Jason McKinnerney JLM573
//11/4/2020
// Lab 9 Pre-Lab Assignment

// Program takes 5 numbers from a user (from console), stores them into an
// array, and then prints them to the screen (on the same line).


#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 5;  // size of array
    int numbers[SIZE];



	cout << "please enter 5 integers : " << endl;

	for (int i = 0 ; i < SIZE ; i++)
	{
		cin >> numbers[i];

	}

    cout << "The numbers now in the array are: ";

	for (int j = 0; j < SIZE ; j++) {
        cout << numbers[j] << " ";
	}
    cout << endl;

	return 0;
}
