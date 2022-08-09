//File Name: PasswordManager.cpp
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

#include "PasswordManager.h"
#include<string>

//encrypt: this takes a password (a string) and returns the encrypted form of the password. 
//
//param1: pass - unencrypted password
//returns: encrypted password
string PasswordManager::encrypt(string pass) {
   string ret = "";
   for(int i = 0; i < pass.length(); ++i){
       ret += ((pass[i] - 33) + 45) % 94 + 33;
   }
   return ret;
}

//meetsCriteria: this takes (a password) and returns true if it meets the criteria:
//
//param1: pass - password
//returns: boolean if password meets requirements

bool PasswordManager::meetsCriteria(string pass) {
    bool valid = true;
    bool digit = false;
    bool lower = false;
    char ch;


    if (pass.length() < 9) {
        valid = false;
        return valid;
    }
    if (pass[0] == '_') {
        valid = false;
        return valid;
    } 
    
    
    for (int i = 0; i < pass.length(); ++i){
        ch = pass[i];
        if (islower(ch)){
            lower = true;
        }
        if (isdigit(ch)) {
            digit = true;
        }    
    }

    if (digit != true || lower != true) {
        valid = false;
    }
    return valid;
}    

//setUsername: takes a string and stores it in the proper member variable.
//
//param1: user - username read in
//returns: void

void PasswordManager::setUsername(string user) {
    username = user;

}


//setEncryptedPassword: takes a string (an already encrypted password) 
//and stores it in the proper member variable.
//
//param1: pass - encrypted password
//returns: void
void PasswordManager::setEncryptedPassword(string pass){
    encrypted = pass;

}

//setNewPassword: takes a string (a proposed, unencrypted, password). 
//If it meets the criteria in meetsCriteria, it encrypts the password and stores it in the member variable
//
//param1: reset - encrypted password
//returns: boolean if it changed

bool PasswordManager::setNewPassword(string reset){
    bool flag = false;
    if (meetsCriteria(reset)) {
        encrypted = encrypt(reset);
        flag = true;    
    }
    return flag;
}

//getUsername: Gets username from class
//
//
//param1: none
//returns: Username

string PasswordManager::getUsername() const{
    return username;
}

//getEncryptedPassword: Gets EncryptedPassword from class
//
//
//param1: none
//returns: Password

string PasswordManager::getEncryptedPassword() const{
    return encrypted;
}

//authenticate: takes a string (a password) and returns true if, once encrypted, it 
//matches the encrypted string stored in the the member variable. Else returns false. 
//
//param1: password
//returns: boolean if it matches

bool PasswordManager::authenticate(string pass){
    bool flag;
    string tempEncrypt;
    tempEncrypt = encrypt(pass);
    if (tempEncrypt == encrypted) {
        flag = true;
    }
    else {
        flag = false;
    }
    return flag;
}