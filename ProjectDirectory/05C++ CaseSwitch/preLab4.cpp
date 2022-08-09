// Jason McKinnerney JLM573
// 09/30/2020
// The following is an extremely scientific personality test that can predict
// how well you will do in this course.


#include <iostream>

using namespace std;

int main()
{
     char answer;
     string message;

     cout << "Is Star Trek better than Star Wars? ('Y' or 'N')" << endl;
     cin >> answer;

     // TODO - Change the following IF-ELSE statement to an
     // equivalent switch statement.

     switch (answer) {
        case 'y':
        case 'Y':
            cout << "You think Star Trek is better than Star Wars..." << endl;
            message = "Wrong! You are likely to fail this class...";
            break;
        case 'n':
        case 'N':
            cout << "You do not think think Star Trek is better than Star Wars..." << endl;
            message = "Correct! You will undoubtedly ace this class!!!!" ;
            break;
        default:
            message = "Invalid Input. This does not bode well for you.";
            break;
     }
     cout << message << endl;

     return 0;
}
