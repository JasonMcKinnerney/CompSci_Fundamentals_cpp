// File Name: bracketMatcher.cpp
//
//Author: Jason McKinnerney
//Collaborators: None
//Date: 4/21/2021
//Assignment Number: PA6.1
//CS 2308 Spring 2021
//
//Description:Given a text file, your program will determine if all the parentheses, 
//curly braces, and square brackets match, and are nested appropriately. 
//Your program should work for mathematical formulas and most computer programs.
//Your program should read in the characters from the file, one at a time, 
//but ignore all characters except for the following: { } ( ) [ ]
// 
// 

#include <iostream>
#include <fstream>
#include <string>
#include "IntStack.h"


using namespace std;

int main () {
    string fileRequest; //file name requested by user
    char ch;            // character to read from file
    char stackChar;     // character to pop from stack
    ifstream fin;       

    //Open file and check file open
    cout << "Enter the name of a file to check:" << endl;
    cin >> fileRequest;
    fin.open(fileRequest);

    if (fin.is_open()) {

    IntStack bracketChecker;  //stack to store char


    while (!fin.eof()) {       //Loop through char until end of file
        fin.get(ch);

        switch(ch) {
            case '(':                        //If char is open bracket, push
                bracketChecker.push(')');    //corresponding closing bracket
                break;

            case '[': 
                bracketChecker.push(']');
                break;

            case '{': 
                bracketChecker.push('}');
                break;


            case '}': 
                if (bracketChecker.isEmpty()) {          //if char is closing bracket
                    cout << "Unmatched }" << endl;       //Check stack to see if empty
                    fin.close();
                    return 0;
                }
                
                else {
                    stackChar = bracketChecker.pop();       //pop char and compare
                    if (stackChar != ch) { 
                        cout << "Expected a " << stackChar << " but found a "  << ch << endl;
                        fin.close();
                        return 0;
                    }
                }
                break;
            
            case ']':                                      //Same as above
                if (bracketChecker.isEmpty()) {
                    cout << "Unmatched ]" << endl;
                    fin.close();
                    return 0;
                }
                
                else {
                    stackChar = bracketChecker.pop();
                    if (stackChar != ch) { 
                        cout << "Expected a " << stackChar << " but found a "  << ch << endl;
                        fin.close();
                        return 0;
                    }
                }
                break;

            case ')': 
                if (bracketChecker.isEmpty()) {
                    cout << "Unmatched )" << endl;          //Same as above
                    fin.close();
                    return 0;
                }
                
                else {
                    stackChar = bracketChecker.pop();
                    if (stackChar != ch) { 
                        cout << "Expected a " << stackChar << " but found a "  << ch << endl;
                        fin.close();
                        return 0;
                    }  
                }
                break;

            default: //Do Nothing
                break;
            }
        }

        if (bracketChecker.isEmpty()) {              //Check for empty stack
            cout << "All brackets match" << endl;
        }

        else {
            stackChar = bracketChecker.pop();           //Find leftover char if any
            cout << "Missing " << stackChar << endl;
        }
    } 


    else {
        cout << "Error opening file." << endl;
    }

    fin.close();
    return 0;
}