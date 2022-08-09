// Jason McKinnerney JLM573
// 11/10/2020
// Write a function that multiplies each element in the array "myArray"
// by the variable "multiplyMe".

#include <iostream>

using namespace std;

void array_multiply(int arrayName[], const int & arraySize, int multiple);


int main()
{
    const int SIZE = 10;
    int myArray [SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int multiplyMe = 5;

    array_multiply(myArray, SIZE, multiplyMe);

    for(int i=0; i < SIZE; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;

}

void array_multiply(int arrayName[], const int & arraySize, int multiple){
    for (int j = 0; j < arraySize; j++){
        arrayName[j] = arrayName[j] * multiple;
    }
}
