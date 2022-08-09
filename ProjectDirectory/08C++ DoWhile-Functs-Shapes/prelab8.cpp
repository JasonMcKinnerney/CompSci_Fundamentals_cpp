// Jason McKinnerney JLM573
// 10/26/2020
// Lab 8 Pre-Lab Assignment

// Add 3 functions to calculate the area of circle.

#include <iostream>
using namespace std;

double getRadius();

double calcArea(double);

void printResults(double);

int main()
{
    double radius,
           area;

    radius = getRadius();

    area = calcArea(radius);

    printResults(area);

}

double getRadius(){             // 'getRadius' asks the user to enter the radius of a circle
                                //  and returns the given value. (should return a double)
        double input_rad;

        cout << "Please enter the radius: ";
        cin >> input_rad;

        return input_rad;
}

double calcArea(double rad) {
    double PI = 3.14159;    //'calcArea' takes the radius and returns the area of a circle.
    double circleArea;

    circleArea = PI * (rad * rad);

    return circleArea;
}

void printResults(double result) {
                                // 'printResults' void type function that should print the results to console.
        cout << "The area of your circle is " << result << " units squared."
        << endl;

}
