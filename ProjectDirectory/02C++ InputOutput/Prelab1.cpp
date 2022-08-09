//Jason McKinnerney jlm573
//09/08/2020
//CS1428 Lab
//Prelab 1
//Description:      There are a several errors with the below code
//                  Fix the syntax and logical errors.

#include <iostream>

using namespace std;

int main()
{
    // Problems Fixed: cin arrows flipped, squaring x operation reversed, x and y operations moved to past user input

    int x;
	int y;


	cout << "Enter the value for X" << endl;
	cin >> x;

	cout << "Enter the value for Y" << endl;
	cin >> y;

	x = x * x;

	y += 10;

	cout << "X squared = " << x << endl
	     << "Y + 10  = " << y << endl;



    // 2.

    double weightPounds;
    double weightKilo;
    const double CONVERSION = 2.20462 ;

	cout << "Many pounds can you lift?" << endl;
    cin >> weightPounds;

    weightKilo = weightPounds / CONVERSION;

    cout << weightPounds << " pounds is equal to " << weightKilo << " kilograms." << endl;





	return 0;
}
