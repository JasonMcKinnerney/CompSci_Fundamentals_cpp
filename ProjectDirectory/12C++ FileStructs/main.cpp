//File Name: main.cpp
//
//Author: Jason McKinnerney JLM573
//No Collaborators
//Date: 1/29/2021
//PA #: 1 File Folders
//CS 2308 Spring 2021
//
//This Program will create an array of file structures and
//allow the user to append the file number and size


#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;    //Constant for different amount of folders


struct Database{        // Database structure created
    string name;        // Will take folders name, num of files
    int numfiles;       // and folders total size
    double size;

};





//displayFolder: Will display the database in a readable table
//
//files[] - passes the array structure as reference
//SIZE - Used for iterating over array
//Returns Void
void displayFolder(Database files[], const int SIZE) {
        cout << left
        << setw(3) << "N"
        << setw(15) << "Name"
        << setw(10) << "Num files"
        << setw(10) << "Size(Mb)"
        << endl;

    for(int i = 0; i < SIZE; i++)
        cout << left
        << setw(3) << (i+1)
        << setw(15) << files[i].name
        << setw(10) << files[i].numfiles
        << setw(10) << setprecision(2) << fixed
        << files[i].size
        << endl;
}

//addFile: Gives choice to add files to array
//
//files[] array param that access structure
//returns choice, this int will check in main if we need to add any more

int addFile(Database files[]) {
    int choice = 0;
    double fileSize = 0;
    cout << "Enter the folder number (0 to quit):" << endl;
    cin >> choice;
    if (choice > 0 && choice <= 10) {
        cout << "Enter the file size:" << endl;
        cin >> fileSize;
        files[choice - 1].numfiles = files[choice - 1].numfiles + 1;
        files[choice - 1].size = files[choice - 1].size + fileSize;
        return choice;
        }
    if (choice > 10 || choice < 0) {
        cout << "Invalid folder number" << endl;
        return choice;
    }
    else
        return 0;
}

// totalSize: Adds sizes of all folders together
// files[]: Same array used to manip contents in structure
// SIZE to loop over entire array
// returns void
void totalSize(Database files[], const int SIZE) {
    double totSize = 0.0;
    for(int i = 0; i < SIZE; i++)
        totSize = totSize + files[i].size;
    cout << "Total size of all folders: " << totSize << endl;
}

// largAVsize - Finds Max Size/File size category in array
// files[]: Same array used to manip contents in structure
// SIZE to loop over entire array
// returns void

void largAVsize(Database files[], const int SIZE) {
    double highAV = files[0].size / files[0].numfiles;
    string highIndex = files[0].name;
    for(int i = 1; i < SIZE; i++) {
        if ((files[i].size / files[i].numfiles) > highAV) {
            highAV = (files[i].size / files[i].numfiles);
            highIndex = files[i].name;
        }
    }
    cout << "Folder with the largest average file size: "
    << highIndex << endl;
}

int main() {

// Initialize entire structure with correct info
    Database folder[SIZE];
    folder[0].name = "Documents";
    folder[0].numfiles = 5;
    folder[0].size = 12.38;

    folder[1].name = "Downloads";
    folder[1].numfiles = 11;
    folder[1].size = 17.22;

    folder[2].name = "Pictures";
    folder[2].numfiles = 27;
    folder[2].size = 30.26;

    folder[3].name = "Videos";
    folder[3].numfiles = 6;
    folder[3].size = 22.75;

    folder[4].name = "Projects";
    folder[4].numfiles = 3;
    folder[4].size = 7.94;

    folder[5].name = "Labs";
    folder[5].numfiles = 6;
    folder[5].size = 1.44;

    folder[6].name = "Music";
    folder[6].numfiles = 45;
    folder[6].size = 102.73;

    folder[7].name = "Favorites";
    folder[7].numfiles = 4;
    folder[7].size = 2.10;

    folder[8].name = "Contacts";
    folder[8].numfiles = 35;
    folder[8].size = 3.51;

    folder[9].name = "Miscellaneous";
    folder[9].numfiles = 1;
    folder[9].size = 2.23;

    //Initialized choice that will be returned from addFile
    int choice = 0;

    // Calls two functions below,
    //Prints information to console and asks for any changes
    // Repeats until 0 is chosen by user and is returned
    do {displayFolder(folder, SIZE);
        choice = addFile(folder);
    }
    while (choice != 0);


    totalSize(folder, SIZE);    //Call Function

    largAVsize(folder,SIZE);    //Call Function

    return 0;
}
