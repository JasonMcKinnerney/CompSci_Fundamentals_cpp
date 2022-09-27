// File Name: TestDriver.cpp
//
// Author: Jason McKinnerney
// A new test driver for a MovieList.
//

#include <iostream>
#include "MovieList.h"

using namespace std;

MovieList* movieQueueFromArray(const string titles[], const int SIZE){
    MovieList* movieQueue = new MovieList();
    for (int i = SIZE - 1; i >= 0; --i){
        movieQueue->addToTop(titles[i]);
    }
    return movieQueue;
}

// Random movies I remember with short titles
const int N_TITLES = 8;
string titles[N_TITLES] = {
    "Star Wars",
    "Mary Poppins",
    "Grease",
    "Titanic",
    "Apocalypse Now",
    "Forrest Gump",
    "Slumdog Millionaire",
    "A League of Their Own"
};
MovieList movieQueue;

int main() {
    
    // ---------------------------------------------------------------
    
    cout << "Add to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Add to the bottom and to the top" << endl;
    movieQueue = MovieList();
    movieQueue.addToBottom("Forrest Gump");
    movieQueue.addToTop("Titanic");
    movieQueue.addToBottom("Grease");
    movieQueue.addToTop("Star Wars");
    movieQueue.addToTop("Disaster Movie");
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Remove a movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool removed = movieQueue.remove(3);
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Remove the first movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    removed = movieQueue.remove(0);
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Try to remove a non-existing movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    removed = movieQueue.remove(10);
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Delete all movies (should be empty)" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    for (int i = 0; i < N_TITLES; ++i){
        movieQueue.remove(0);
    }
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Move a movie to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToTop("Titanic");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Try to move a non-existing movie to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToTop("Not even a movie");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Move a movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToPosition("Mary Poppins", 4);
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Try to move a non-existing movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToTop("NONAME");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Test next larger: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    string nextLarger = movieQueue.nextLarger("Mary Poppins");
    cout << "Next larger to " << "'Mary Poppins' " << "'" << nextLarger << "'" << endl << endl;
    
    cout << "Test next larger again: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Forrest Gump");
    cout << "Next larger to " << "'Forrest Gump' " << "'" << nextLarger << "'" << endl << endl;
 
    cout << "Test next larger again: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Canada");
    cout << "Next larger to " << "'Canada' " << "'" << nextLarger << "'" << endl << endl;

    // ---------------------------------------------------------------
    
    cout << "Test next larger without next larger: ";
    
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Z");
    cout << "Next larger to " << "'Z' is " << "'" << nextLarger << "'" << endl << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Display sorted movies" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    movieQueue.displaySorted(cout);
    cout << endl;
    
    return 0;
}
