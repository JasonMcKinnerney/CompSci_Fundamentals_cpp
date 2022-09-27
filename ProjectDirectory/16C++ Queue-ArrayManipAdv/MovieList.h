// File Name: MovieList.h


#include <string>
#include <iostream>
using namespace std;

struct MovieNode {
    string title;
    MovieNode *next;
};

class MovieList {
public:
    MovieList();
    ~MovieList();
    void display(ostream& out);
    void addToTop(string title);
    void addToBottom(string title);
    bool remove(int position);
    bool moveToPosition(string title, int position);
    bool moveToTop(string title);
    string nextLarger(string title);
    void displaySorted(ostream& out);
private:
    MovieNode* top;
};

