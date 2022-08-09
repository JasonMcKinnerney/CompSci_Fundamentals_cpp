//Jason McKinnerney JLM573
//9/30/2020
//CS1428 Lab 17
//Lab 4 - No Collaborators
//Description: this program will caculate the number of calories
//    in a meal based on user input

#include <iostream>
using namespace std;

int main()
{
    char meal_choice;  //user's choice
    int servings,
        total_calories;

    cout << "Welcome to the Calorie Count-ulator!\n";

    cout << "Enter your meal choice ([P]izza, [S]alad, [H]amburger)\n";
    cin >> meal_choice;

    cout << "Enter the amount of servings (1-9):\n";
    cin >> servings;

    if ((servings >= 1) && (servings <= 9))
    {   switch (meal_choice)
        {
            case 'p':
            case 'P':
                cout << "Total calories consumed: " << 500 * servings << endl;
            break;
            case 's':
            case 'S':
                cout << "Total calories consumed: " << 150 * servings << endl;
            break;
            case 'h':
            case 'H':
                cout << "Total calories consumed: " << 450 * servings << endl;
            default:
                cout << "ERROR: Invalid meal choice. Terminating the program." << endl;
        }
    }
    else
    {
        cout << "ERROR: Invalid serving amount. Terminating the program." << endl;
    }

    return 0;
}
