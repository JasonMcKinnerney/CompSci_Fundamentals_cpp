//Jason McKinnerney JLM573
//11/11/2020
//CS1428 Lab
//Lab 10
//Description: this program will drop the lowest from 5 grades

#include <iostream>
#include <iomanip>
using namespace std;

void getGrades(double g[], const int SIZE)
{
    cout << "Please enter " << SIZE << " grades:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cin >> g[i];
    }
}

double getAverage(double g[], const int SIZE)
{
    int total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        total += g[i];
    }
    return total/SIZE;
}

void findDropInfo(double g[], const int SIZE, double &lowest,
                  double &average) {
    lowest = g[0];
    for (int j = 1; j < SIZE; j++){
        if (g[j] < lowest) {    // Find Lowest Score
            lowest = g[j] ;
        }
    }

    int sum = 0;                 // Find Sum w/ lowest
    for (int i = 0; i < SIZE; i++) {
        sum = sum + g[i];
    }
    average = (sum - lowest)/(SIZE - 1);
}                               // Find average w/o lowest

void printData(double low, double av, double avg_before){
    cout << "Grade dropped: " << low << endl;
    cout << "Final Average: " << av << endl;
    cout << "Average Before Dropped Grade: " << avg_before << endl;
}

int main()
{
    const int SIZE = 5;
    double grades[SIZE];
    double lowest = 0;
    double avg = 0,
           avgBeforeDrop;

    getGrades(grades, SIZE);

    cout << "The 5 grades entered by the user are:" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << grades[i] << endl;     //Print grades back to console
    }

    avgBeforeDrop = getAverage(grades, SIZE);

    findDropInfo(grades, SIZE, lowest, avg);

    printData(lowest, avg, avgBeforeDrop);

    return 0;
}
