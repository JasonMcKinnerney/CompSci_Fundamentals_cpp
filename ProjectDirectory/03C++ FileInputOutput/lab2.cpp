//Jason McKinnerney jlm573
//9/16/2020
//CS1428 Lab 17
//No Collaborators
//Lab 2
//Description: this program will calculate the average scores
// of several Hogwarts houses and save the results to a file

#include <iostream>
#include <iomanip> // library for setw() and other i/o manipulators
#include <fstream> // library for file input and output
using namespace std;

int main() {

    string name, house;
    int grade1, grade2, grade3;
    double average;

    // Declare input file stream variable and open the input file:
    ifstream fin;
    fin.open("student_data.txt");

    ofstream fout;
    fout.open("averages.txt");

    // Error check to ensure the input file opened:
    if (!fin) {
        cout << "Could not open file. Terminating program." << endl;
        return -1;
    }

    // Write the column headers to the output file:
    fout << left;
    fout << setw(10) << "Name" << setw(13) << "House" << "Average" << endl;

    fin >> name >> house >> grade1 >> grade2 >> grade3;
    average = (grade1 + grade2 + grade3) / 3.0;
    fout << setw(10) << name << setw(13) << house
    << setprecision(1) << fixed << average << endl;

    fin >> name >> house >> grade1 >> grade2 >> grade3;
    average = (grade1 + grade2 + grade3) / 3.0;
    fout << setw(10) << name << setw(13) << house
    << setprecision(1) << fixed << average << endl;

    fin >> name >> house >> grade1 >> grade2 >> grade3;
    average = (grade1 + grade2 + grade3) / 3.0;
    fout << setw(10) << name << setw(13) << house
    << setprecision(1) << fixed << average << endl;


    cout << "Data written to averages.txt" << endl;

    // Close the input and output files:
    fout.close();
    fin.close();

    // Exit the program:
    return 0;
}
