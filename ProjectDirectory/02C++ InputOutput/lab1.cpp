//Jason McKinnerney jlm573
//September 9th
//CS1428 Lab 17
//Lab 1
//Description: this program will calculate a users jedi level

#include <iostream>
using namespace std;

int main() {

    float midi_chlorians;
    float age;
    float iq;
    float jedi_level;

    cout << "What is your midi-chlorian count?" << endl;
    cin >> midi_chlorians;

    cout << "What is your age?" << endl;
    cin >> age;

    cout << "What is your IQ?" << endl;
    cin >> iq;

    jedi_level = (midi_chlorians * age) / (90000 - (iq * iq));

    cout << "Your Jedi Level is " << jedi_level << "." << endl;


    return 0;
}
