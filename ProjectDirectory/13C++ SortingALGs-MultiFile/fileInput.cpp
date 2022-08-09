// This program reads data from a file.
// The file contains a series of pairs:  a number followed by a string on
//  the next line.  The string might contain spaces.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    int number;
    string x, y;
    int numbers[100];
    string strings[100];
    int count = 0;
    
    // Open the file.
    inputFile.open("dataset.txt");
    
    // Read the numbers and strings from the file and display them.
    while (inputFile >> number)  //attempts to read first number, if successful,
                                 //the condition is true, if it encounters the
                                 //end of the file, the condition is false
    {
        inputFile >>  ws;       // skips the newline after the number in the file
        getline(inputFile,y);   // reads until end of line including spaces
        cout << number << " " << y << endl;  // just to check the input process
                                             // remove above when successful
        numbers[count] = number;
        strings[count] = y;
        count++;
    }
    
    // Now the program can process the data in the arrays
    
    // Close the file.
    inputFile.close();
    return 0;
}
