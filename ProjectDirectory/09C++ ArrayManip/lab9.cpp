//Jason McKinnerney JLM573
//11/4/2020
//CS1428 Lab
//Lab 9
//Description: this program will track run distances for the user
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int SIZE = 7; //number of days
    const string WEEK[] = {"Sunday",
                           "Monday",
                           "Tuesday",
                           "Wednesday",
                           "Thursday",
                           "Friday",
                           "Saturday"};

    double distances[SIZE];
    double total = 0,
           average;
    int longest_index = 0;

    cout << "Please enter the distance run." << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << WEEK[i] << "  : ";      // Input distances
        cin >> distances[i];
    }

    for (int j = 0; j < SIZE; j++) {    //Finding Total
        total = total + distances[j];
    }

    average = total / SIZE;         // Finding Average

    int maximum = 0;
    for (int z = 0; z < SIZE; z++) {       // Finding Max distance
        if (distances[z] > maximum) {
            maximum = distances[z];
            longest_index = z;
        }
    }



    cout << fixed << setprecision(2)
         << "Total distance  : " << total << endl
         << "Average distance : " << average << endl
         << "Longest distance : " << distances[longest_index] << " miles on " << WEEK[longest_index] << endl;


    return 0;
}

