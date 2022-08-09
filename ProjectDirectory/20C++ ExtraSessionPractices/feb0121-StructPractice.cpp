#include <iostream>
#include <iomanip>


using namespace std;

// SI Session 02/01/2021


const int SIZE = 3;

//1. define a struct with variables for the first name, graduation year, and GPA of a Student.
struct Structure{
    string name;
    int gradyear;
    double GPA;

};

//3. write a function called 'calcTotal' that calculates the total GPA of all the students.
double calcTotal (Structure sample[]) {

    double total = 0.0;

    for (int i = 0; i < SIZE; i++)
        total = total + sample[i].GPA;


    return total;
}


int main(){

//2. in main, declare an instance of the structure as an array with a size of 3, and hard code some sample data in
    Structure sample[SIZE];


    sample[0].name = "Tony";
    sample[0].gradyear = 1998;
    sample[0].GPA = 3.8;

    sample[1].name = "Jason";
    sample[1].gradyear = 2004;
    sample[1].GPA = 3.5;

    sample[2].name = "Michele";
    sample[2].gradyear = 2006;
    sample[2].GPA = 4.0;


//4. Print the information about the three students to the screen.
    for (int i = 0; i < SIZE; i++) {
        cout << "Student #" << i + 1 << " " << endl;
        cout << "Name: " << sample[i].name << endl;
        cout << "Graduation Year: " << sample[i].gradyear << endl;
        cout << "GPA: " << sample[i].GPA << endl << endl;
    }

//5. Print the average GPA for the students to the screen.


    cout << "Average: " << (calcTotal(sample)) / 3;

}
