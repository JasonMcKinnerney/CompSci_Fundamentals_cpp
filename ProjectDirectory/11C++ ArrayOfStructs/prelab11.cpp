//Jason McKinnerney JLM573
// 11/18/2020
// Prelab 11 Lab 17


#include <iostream>
#include <fstream>


using namespace std;

struct Dog
{
    string name;
    string breed;
    char gender;
    int age;
};

int main()
{
	Dog dog1;

	dog1.name = "Sparky";
	dog1.gender = 'M';          //Fill Structure for dog1
	dog1.age = 5;
	dog1.breed = "Collie";

    Dog dog2;

    cout << "Please enter enter information for dog2: " << endl;

    cout << "Name: ";
    cin >> dog2.name;       //Receive dog2 details from console

    cout << "Age: ";
    cin >> dog2.age;

    cout << "Gender (M or F): ";
    cin >> dog2.gender;

    cout << "Breed: ";
    cin >> dog2.breed;

    cout << "Name: " << dog1.name << ", Gender: " << dog1.gender;
    cout << ", Age: " << dog1.age << ", Breed: " << dog1.breed << endl;

    cout << "Name: " << dog2.name << ", Gender: " << dog2.gender;
    cout << ", Age: " << dog2.age << ", Breed: " << dog2.breed << endl;




    return 0;
}
