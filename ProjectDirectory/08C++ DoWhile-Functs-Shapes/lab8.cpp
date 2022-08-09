//Jason McKinnerney JLM 573
//TO-DO: 10/28/2020
//CS1428 Lab
//Lab 8
//Description: this program will draw user defined shapes

#include <iostream>

using namespace std;

// Function Prototypes:
int getArea(int, int);
int getPerimeter(int, int);
void printPicture(int, int, char);
bool isValidSideLength(int);

int main()
{
    int width,
        height,
        perim,
        area;
    char symbol,
         cont;

    do{
        cout << "Please enter the following" << endl;
        cout << "Width: ";
        cin >> width;

        while(!isValidSideLength(width)) // Function Call
        {
            cout << "ERROR: Sides must be between 1 and 10." << endl
                 << "Enter the width: ";
            cin >> width;
        }

        cout << "Height: ";
        cin >> height;

        while(!isValidSideLength(height)) // Function Call
        {
            cout << "ERROR: Sides must be between 1 and 10." << endl
                 << "Enter the height: ";
            cin >> height;
        }

        cout << "Desired symbol for picture: ";
        cin >> symbol;

        perim = getPerimeter(width, height); // Function Call
        area = getArea(width, height); // Function Call
        cout << "\nPerimeter: " << perim << endl
             << "Area: " << area << endl
             << "Picture of your rectangle: " << endl;
        printPicture(width, height, symbol); // Function Call

        cout << "\nWould you like to print another picture? (Y or N): ";
        cin >> cont;

    }while(cont == 'Y' || cont == 'y');

    return 0;
}

int getArea(int wid, int len) { // Compute Area
    int area1 = 0;
    area1 = wid * len;

    return area1;
}

int getPerimeter(int width, int height){ // Compute Perimeter

    int perimeter = (2 * width) * (2 * height);

    return perimeter;
}

void printPicture(int column, int row, char ch) { // Print the picture
    for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= column; j++) {
                cout << ch;
            }
            cout << endl;
    }
}

bool isValidSideLength(int number){     // Check parameters
    if (number >= 1 & number <= 10) {
        return true;
    }
    else {
        return false;
    }
}




