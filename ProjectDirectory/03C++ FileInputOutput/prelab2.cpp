// Jason McKinnerney jlm573
// September 15, 2020
// CS1428 Lab 17
// Pre-Lab Assignment 2
//
// Copy 3 variables from input file and send to output file


#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	string firstName;
	string lastName;
	int year;

	ifstream fin;
	fin.open("prelab_input.txt");

	if (!fin)
        {
		cout << "ERROR - File failed to open. make sure that "
		     << "the input file and this file are in the"
		     << "same directory" << endl;
                return -1;
         }

	ofstream fout;
	fout.open("flux_capacitor.txt");

    fin >> firstName >> lastName >> year;

    year += 30;

    fout << firstName << " " <<lastName << " " << year << endl;

	fin.close();
	fout.close();

	return 0;
}
