// Jason McKinnerney jlm573
// 9/23/2020
// No Collaborators
// Pre-lab 3

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

        int random_number;


        srand(time(NULL));


        random_number = rand() % 20 + 1;

        cout << "You roll a " << random_number << ": ";


        if (random_number == 20)
            cout << "CRITICAL HIT!!" << endl;

        else if (random_number > 11)
            cout << "Attack Strikes" << endl;

        else
            cout << "Attack Misses" << endl;



    return 0;
}
