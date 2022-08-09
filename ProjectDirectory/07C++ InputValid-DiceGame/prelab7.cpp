// Jason McKinnerney JLM573
// 10/20/2020
// Lab 7 Prelab Assignment

#include <iostream>
using namespace std;


void outputMessage(){
    cout << "Welcome to my fabulous Jedi power level calculator!" << endl
         << "This program will take your age, weight, and" << endl
         << "midichlorean count and return your Jedi power level!"
         << endl << endl;

}

double jediCalculator (){

    double level;

    int age;
    int weight;
    int mcc;

    cout << "please enter your age : ";
    cin >> age;
    cout << "please enter your weight : ";
    cin >> weight;
    cout << "please enter your midicholrean count : ";
    cin >> mcc;
    level = static_cast <double>(mcc * age) / (weight * weight);

    return level;
}

int main(){

    outputMessage();

    double jedi_level = jediCalculator();
    cout << "Your Jedi Level is : " << jedi_level;

    return 0;

}


