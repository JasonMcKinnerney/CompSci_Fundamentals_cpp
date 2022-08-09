//File Name: main.cpp
//
//Author: Jason McKinnerney
//Collaborators: None
//Date: 2/14/2021
//Assignment Number: PA2
//CS 2308 Spring 2021
//
//
//Description of Program: Will read in file and fill a movie structure
//Using this structure we will allow a user to access different parts
//of details on the movie. Then search and sort by different means.

//Principles: Linear & Binary Search ++ Bubble & Selection Sort
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Movie {
    int id;
    string name;
    string releaseDate;
    double rating;
};

//readMovies: Reads the movie database from a txt file into Movie structure
//
//ifstream in is the txt file that is declared in main containing the movies
//movies[] struct is filled from text file
//size constant is adjusted here to match count of movies from txt file
void readMovies(ifstream& in, Movie movies[], int& size) {

    int num = 0;
    while (in >> movies[num].id) {
        in >> ws;
        getline(in , movies[num].name);
        getline(in , movies[num].releaseDate);
        in >> movies[num].rating;
        in >> ws;
        num++;
    }
    size = num;
}
//displayMovies: Function prints out table of movies to console
//
//movies[] struct contains the movie information
//SIZE allows iteration over correct amount of movies
void displayMovies(Movie movies[], int SIZE) {
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;
    for (int i=0; i < SIZE; i++) {
        cout << setprecision(1) << fixed << left
         << setw(3) << movies[i].id
         << setw(26) << movies[i].name
         << setw(12) << movies[i].releaseDate
         << movies[i].rating
         << endl;
    }
}

//sortByDateRating: Sorts the movie array into release date, and
//                  if the date's match, then sort by rating.Bubble.
//
//movies[] struct contains the movie information
//SIZE allows iteration over correct amount of movies
//returns void, but changes structure array
void sortByDateRating(Movie movies[], int SIZE) {
    Movie temp;
    bool swapped;
    do {
        swapped = false;

        for (int i = 0; i < SIZE - 1; i++) {
            if (movies[i].releaseDate > movies[i+1].releaseDate) {
                temp = movies[i];
                movies[i] = movies[i + 1];
                movies[i + 1] = temp;
                swapped = true;
            }
            else if ((movies[i].releaseDate == movies[i+1].releaseDate)
                && (movies[i].rating < movies[i+1].rating)) {
                temp = movies[i];
                movies[i] = movies[i + 1];
                movies[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped == true);
}

//sortById: Sorts the movie array by id, using selection sort
//
//movies[] struct contains the movie information
//SIZE allows iteration over correct amount of movies
//returns void, but changes structure array
void sortById(Movie movies[], const int SIZE){
    int indexSmallest;
    for (int i = 0; i < SIZE - 1; i++) {
        indexSmallest = i;
        for (int j = i; j < SIZE; j++) {
            if (movies[j].id < movies[indexSmallest].id) {
                indexSmallest = j;
            }
        }
        Movie temp = movies[i];
        movies[i] = movies[indexSmallest];
        movies[indexSmallest] = temp;
    }

}
//linearSearchByName: Finds movie information using name of movie
//
//movies[] struct contains the movie information
//SIZE allows iteration over correct amount of movies
//targetName is the requested name
//returns position of movie in array
int linearSearchByName(Movie movies[], int SIZE, string targetName){
    for (int i = 0; i < SIZE; i++) {
        if (targetName == movies[i].name)
            return i;
    }
    return -1;
}
//linearSearchByName: Finds movie information using ID number, Binary
//
//movies[] struct contains the movie information
//SIZE allows iteration over correct amount of movies
//targetId is the requested Id number
//returns position of movie in array
int binarySearchById(Movie movies[], int SIZE, int targetId) {
   int first = 0;
   int last = SIZE - 1;
   int position = -1;
   int middle;
   bool found = false;
   sortById(movies, SIZE);
   while (!found && first <= last)
    {
    middle = (first + last) / 2;
    if (movies[middle].id == targetId) {
        found = true;
        position = middle;
    }
    else if (targetId < movies[middle].id) {
        last = middle - 1;
    }
    else {
        first = middle + 1;
    }
    }
    return position;
}

int main() {
    int request;
    int idRequest;
    string target;
    int choice;
    int SIZE = 100;
    ifstream fin;
    Movie movies[SIZE];

    // Read in the file
    fin.open("movies.txt");
    readMovies(fin, movies, SIZE);
    fin.close();

    do {
      // Display the menu.
      cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
      cin >> choice;

      // Validate the menu selection.
      while (choice < 1 || choice > 5) {
         cout << "Please enter 1, 2, 3, 4, or 5:" << endl;;
         cin >> choice;
      }

      // Validate and process the user's choice.
      if (choice != 5) {

         // Respond to the user's menu selection.
         switch (choice)
         {
            case 1:
                sortById(movies, SIZE);
                displayMovies(movies, SIZE);
                break;
            case 2:
                sortByDateRating(movies, SIZE);
                displayMovies(movies, SIZE);
                break;
            case 3:
                cout << "Please enter a movie name:" << endl;
                cin >> ws;
                getline(cin, target);
                request = linearSearchByName(movies, SIZE, target);

                if (request != -1) {
                    cout << "Release date of '" << movies[request].name <<
                    "' is " << movies[request].releaseDate << endl;
                }
                else {
                    cout << "No movie found with name: " << target << endl;
                }

                break;
            case 4:
                cout << "Please enter a movie id:" << endl;
                cin >> idRequest;
                request = binarySearchById (movies, SIZE, idRequest);
                if (request != -1) {
                    cout << left
                         << setw(3) << "ID"
                         << setw(26) << "Name"
                         << setw(12) << "Date"
                         << "Rating" << endl;
                    cout << left
                         << fixed << setprecision(1)
                         << setw(3) << movies[request].id
                         << setw(26) << movies[request].name
                         << setw(12) << movies[request].releaseDate
                         << movies[request].rating << endl;
                }
                else {
                    cout << "No movie found with id: " << idRequest << endl;
                }
            }
        }
     }
     while (choice != 5);
        cout << "Exiting the program...\n";




// Exit the program:
return 0;
}

