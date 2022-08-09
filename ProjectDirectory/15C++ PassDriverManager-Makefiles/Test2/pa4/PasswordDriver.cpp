//File Name: PasswordDriver.cpp
//
//Author: Jason McKinnerney
//Collaborators: None
//Date: 3/30/2021
//Assignment Number: PA4
//CS 2308 Spring 2021
//
//
//Description of Program: Write a C++ program that will simulate a Change Password Utility.
//One class, PasswordManager, that will manage a single password for a given username.
//A driver containing a main function that will allow the user to change their password.


#include<iostream>
using namespace std;
#include "PasswordManager.h"
#include <fstream>

        

int main() {    
    const int SIZE = 3;         //array size
    string tempuser, temppass;  //strings to read in initial data
    int index = -1;             //index for matching username
    string userrequest, oldpass, newpass;   //user input change requests

    PasswordManager users[SIZE];            

    ifstream fin;                   //Readin the text file and applying it
    fin.open("passwords.txt");      // to the users array
    if(!fin) {
        cout << "File does not exist" << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        fin >> tempuser >> temppass;
        users[i].setUsername(tempuser);
        users[i].setEncryptedPassword(temppass);
    }
    
    fin.close();

    cout << "Please enter your netID:" << endl;     //Gather User Input
    cin >> userrequest;
    cout << "Please enter your old password:" << endl;
    cin >> oldpass;
    cout << "Please enter your new password:" << endl << endl;
    cin >> newpass;


    for (int i = 0; i < SIZE; i++) {
        if (users[i].getUsername() == userrequest) {        //Find username match
            index = i;
        }
    }

    if (index != -1) {
        if (users[index].authenticate(oldpass) == true) {       //Verify requests are valid
            if (users[index].setNewPassword(newpass) == true){
                cout << "Password has been changed for netID: " 
                     << userrequest << endl << endl;
            }
            else {
                cout << "New Password does not meet criteria." << endl << endl; //User error messages
            }   
        }
        else {
            cout << "Old password is incorrect." << endl << endl;
        }
    }        
    else {  
        cout << "NetID is invalid, password not changed." << endl << endl;
    }
    
    

    for (int i = 0; i < SIZE; i++) {    //output class information
        cout << users[i].getUsername() << "  " << users[i].getEncryptedPassword() << endl; 
    }

    return 0;
}
