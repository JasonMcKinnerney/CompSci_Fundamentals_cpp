//Jason McKinnerney jlm573
//09/23/2020
//CS1428 Lab
//Lab 3
//Description: this program will allow the user to play a game of Slug,
//  Frog, Snake against a randomized computer opponent

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int user_num;
    int comp_num;

    // Generate the computer's choice randomly:
    srand(time(NULL));
    comp_num = rand() % 3 + 1;

    // Get the user's choice:
    cout << "Slug-Frog-Snake Game" << endl
         << " 1. Slug" << endl
         << " 2. Frog" << endl
         << " 3. Snake" << endl
         << "Enter a number : ";
    cin >> user_num;
    cout << endl;



    if ((user_num == 1) && (comp_num == 1))
        cout << "You both chose slug! It's a tie!" << endl;
    else if ((user_num == 1) && (comp_num == 2))
        cout << "Frog beats slug! You lose!" << endl;
    else if ((user_num == 1) && (comp_num == 3))
        cout << "Slug beats snake! You win!" << endl;
    else if ((user_num == 2) && (comp_num == 1))
        cout << "Frog beats slug! You win!" << endl;
    else if ((user_num == 2) && (comp_num == 2))
        cout << "You both chose frog! It's a tie!" << endl;
    else if ((user_num == 2) && (comp_num == 3))
        cout << "Snake beats frog! You lose!" << endl;
    else if ((user_num == 3) && (comp_num == 1))
        cout << "Slug beats snake! You lose!" << endl;
    else if ((user_num == 3) && (comp_num == 2))
        cout << "Snake beats frog! You win!" << endl;
    else if ((user_num == 3) && (comp_num == 3))
        cout << "You both chose snake! It's a tie!" << endl;
    else
        cout << "ERROR - Invalid Input. Terminating Program." << endl;

    return 0;
}
