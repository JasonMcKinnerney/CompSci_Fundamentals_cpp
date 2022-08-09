//Jason McKinnerney JLM573
//10/14/2020
//CS1428 Lab
//Lab 6
//Description: this program will play a simple betting game with the user

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL)); // needed to generate a random number
    char repeat;
    int myMoney = 1000,
        bet,
        computer_roll,
        user_roll;

    cout << "Gambling is an addiction..." << endl << endl;

    do {
        cout << "You currently have $" << myMoney << endl; //Get bet
        cout << "How much would your like to bet?"<< endl;
        cin >> bet;
        if (bet > myMoney || bet < 0) {   //Check for valid input
            cout << "ERROR: Invalid bet amount" << endl << endl;
        }
        else {
            computer_roll = rand() % 6 + 1;   //Determine rolls
            user_roll = rand() % 6 + 1;
            cout << "You rolled " << user_roll << endl;
            cout << "Your opponent rolled " << computer_roll << endl;

            if (user_roll > computer_roll) {
                myMoney = myMoney + bet;
                cout << "You win $" << bet << endl;   //If win
            }
            else {
                myMoney = myMoney - bet;
                cout << "You lose $" << bet << endl;    //If lose
            }

            if (myMoney == 0) {                //Broke
            cout << "You are out of money. You can't play anymore." << endl;
            }
            else {
            cout << "Would you like to continue? (Y or N): "; //Continue?
            cin >> repeat;
            cout << endl;
            }
        }

    } while (repeat != 'n' && repeat != 'N' && myMoney > 0);


    // Output the result:
    cout << "You ended with $" << myMoney << endl;

    return 0;
}

