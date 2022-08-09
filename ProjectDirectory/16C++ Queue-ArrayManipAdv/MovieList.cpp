// File Name: MovieList.h
//
//Author: Jason McKinnerney
//Collaborators: None
//Date: 4/14/2021
//Assignment Number: PA5
//CS 2308 Spring 2021
//
//Description: Implement a part of functionality for the Netflix queue. 
// Your program will implement some of the desired functionality by storing
// the list of movie titles in a linked list.
//
#include <string>
#include <iostream>
#include "MovieList.h"

//Constructor
MovieList:: MovieList() {
    top = nullptr;
}

//Destructor
MovieList::~MovieList() {
    
    MovieNode *p;

    while (top != nullptr) {
        p = top;
        top = top -> next;
        delete p;
    }
}


//display: Print movie titles from top to bottom, with positions numbered 
//put a colon and space between the number and the movie title) one movie per line
//
//paramaters: out for test cases
//void

void MovieList::display(ostream& out){
    MovieNode *p = top;
    int i = 0;
    while (p != nullptr) {
        out << i << ": " << p -> title << endl; 
        p = p->next;
        i++;
    }
}

//addToTop: Add a movie to the top of the list
//
//paramaters: Movie Title to be added

void MovieList::addToTop(string movieName){
    MovieNode *newMovie = new MovieNode;
    newMovie -> title = movieName;
    newMovie -> next = nullptr;
    newMovie -> next = top;

    top = newMovie;

}

// addToBottom: Add a movie to the bottom of the list
//
//paramaters: Movie Title to be added

void MovieList::addToBottom(string movieName) {
    MovieNode *newMovie = new MovieNode;
    newMovie->title = movieName;
    newMovie->next = nullptr;

    if (top == nullptr) {
        top = newMovie;
    }
    else {
        MovieNode *p = top;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newMovie;
    }
}

//remove(): Remove a movie at the given position. 
//
//paramaters: position - position of movie to remove in list
//Return true if successful, false if there is no movie at position n.

bool MovieList::remove(int position){
    MovieNode *p = top;
    MovieNode *n = NULL;
    int i = 0;

    while (p !=NULL && i != position) {
        n = p;
        p = p -> next;
        i++;
    }

    if (p != nullptr) {
        if (n != nullptr) {
            n -> next = p-> next;
            delete p;
        }
        else {
            top = p -> next;
            delete p;
        }
        return true;
    }
    else {
        return false;
    }
}

//moveToPosition: Move movie with given title to position n (0 is top)
//
//Paramater 1: movieName - requested movie title to move
//Paramater 2: Position - Where to move in list
//
//returns true if found and moved;

bool MovieList::moveToPosition(string movieName, int position){
    MovieNode *p = top;
    MovieNode *n = NULL;
    
    int i = 0;

    while (p !=NULL && p -> title != movieName) {
        n = p;
        p = p -> next;
    }
    
    if (p != nullptr) {
        if (n != nullptr) {
            n -> next = p -> next;
            delete p;
        }
        else {
            top = p -> next;
            delete p;
        }
    }
    else {
        return false;
    }

    MovieNode *node = top;
    MovieNode *prev = NULL;

    MovieNode *newnode = new MovieNode;
    newnode->title = movieName;
    newnode->next = nullptr;
    

    while (node != NULL && i != position) {
        prev = node;
        node = node -> next;
        i++;
    }

    if (prev != nullptr) { 
        prev -> next = newnode;
        newnode -> next = node;
    }
    else {
        newnode -> next = top;
    }
    return true;
}

//moveToTop: Move a movie with given title to position 0 (top)
//
//Paramater 1: movieName - requested movie title to move
//returns true if found and moved;

bool MovieList::moveToTop(string movieName){
    MovieNode *p = top;
    MovieNode *n = NULL;

    
    while (p !=NULL && p -> title != movieName) {
        n = p;
        p = p -> next;
    }

    if (p != nullptr) {
        if (n != nullptr) {
            n -> next = p -> next;
            p -> next = top;
            top = p;
        }
        return true;
    }
    else {
        return false;
    }
}

// nextLarger: Returns the move title (string t) that would come next after the title t in alphabetical order. 
// Use the algorithm to find the minimum string in a list, but ignore any movie with title t,
// and any that come before it in alphabetical order.
//
//Parameter 1: movieName - string to compare size to.
//Returns next largest string

string MovieList::nextLarger(string movieName){
    string larger = "";
    MovieNode *p = top;
    MovieNode *n = top;

    while (p != nullptr && larger == "") {
        if (p -> title > movieName) {
            larger = p -> title;
        }
        p = p -> next;
    }

    while (n != nullptr) {
        if (n -> title > movieName) {
            if (n -> title < larger) {
                larger = n -> title;
            }
        }
        n = n -> next;
    }
    
    return larger;
}
 
//Use (i.e. call) nextLarger(string) to output the titles in sorted order with positions numbered. 
//The Linked list remains in the same order
//
// Paramater 1: test cases
// void

void MovieList::displaySorted(ostream& out){
    string start = "";
    int i = 1;
    MovieNode *p = top;
    start = nextLarger("");
    out << "0: " << start << endl; 
    
    while (p -> next != nullptr) {
        start = nextLarger(start);
        out << i << ": " << start << endl;
        p = p -> next;
        i++;
    }

}


