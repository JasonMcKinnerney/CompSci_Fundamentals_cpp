//File Name: PasswordManager.h
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

#include <string>
using namespace std;

//PasswordManager
//Stores usernames and encrypted passwords in class

class PasswordManager        
{
private:
    string username;
    string encrypted;
    string encrypt(string);
    bool meetsCriteria(string);
    
public:
    void setUsername(string);
    void setEncryptedPassword(string);
    bool setNewPassword(string);

    string getUsername() const;
    string getEncryptedPassword() const;
    
    bool authenticate(string);

};
