//File Name: main.cpp
//
//Author: Jason McKinnerney
//Collaborators: None
//Date: 3/8/2021
//Assignment Number: PA3
//CS 2308 Spring 2021
//
//
//Description of Program: Use pointers to manipulate arrays and learn to
//dereference. 4 functions created.
//Principles: Pointers and arrays

#include <iostream>
using namespace std;

//Given
void showArray(int* array, int size);
int *duplicateArray (int *arr, int size);

//isSorted: return true if the elements of the array are already in ascending order,
//and false if they are not.
//
//*arr - Array of integers passed by pointer notation
//size - Size of array being passed in
//returns: Bool flag. True if array is sorted in order, false if not

bool isSorted (int *arr, int size) {
    bool flag;
    showArray (arr, size);
    for (int i=0; i < size - 1; i++) {
        if (*(arr + i) < *(arr + (i + 1))) {
            flag = true;
        }
        else {
            flag = false;
            return flag;
        }
    }
    return flag;
}
//sort2withSum: Takes two integers, sorts them, then returns the sum
//
//param 1 - *x pointer looking at location of variable x
//param 2 - *y pointer looking at location of variable y
//returns: Sum of x and y variables

int sort2withSum (int *x, int *y) {
    if (*x > *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    return *x + *y;
}

//grow: Takes an array, and creates a new array with double the original
//array values
//
//param 1 - *arr - array that is to be copied
//param 2 - size - of original array
//returns: pointer to new array that is double the size

int *grow (int *arr, int size) {

   int *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address

   newArray = new int [size * 2];  //allocate new array

   for (int index = 0; index < size; index++) {
      newArray[(2 * index)] = arr[index];
      newArray[((2 * index) + 1)] = arr[index];
   }
        //copy to new array

   return newArray;
}
//subArray: Creates a copy of a portion of another array
//
//param 1 - *arr - array that is to be copied
//param 2 - start - starting index to start the copy
//param 3 - length - length of new array
//returns: pointer to new array that is the portion of array

int *subArray (int *array, int start, int length) {
     int *result = duplicateArray( (array + start) , length);
     return result;
}

int main() {
    int testArr1[8] = {1,2,3,4,5,6,7,8};
    int testArr2[8] = {8,7,6,5,4,3,2,1};
    int testArr3[8] = {1,2,3,5,4,6,7,8};


    int testArrayGrow[9] = {1,2,3,4,5,6,7,8,9};
    int expectedArrayGrow[2 * 9] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};

    int testArraySub[8] = {18, 19, 15, 16, 12, 11, 13, 14};
    const int arrayStartIdx = 3, arrayLength = 4;
    int expectedArraySub[4] = {16, 12, 11, 13};

    cout << "Testing isSorted:" << endl;
    cout << "test data array 1: ";
    bool flag = isSorted(testArr1, 8);
    cout << "Expected result: true" << endl;
    cout << "Actual result:   " << boolalpha << flag << endl;

    cout << "test data array 2: ";
    flag = isSorted(testArr2, 8);
    cout << "Expected result: false" << endl;
    cout << "Actual result:   " << boolalpha << flag << endl;

    cout << "test data array 3: ";
    flag = isSorted(testArr3, 8);
    cout << "Expected result: false" << endl;
    cout << "Actual result:   " << boolalpha << flag << endl << endl;

     //use with sort2withSum
    int a = 8;
    int b = 5;

    cout << "Testing sort2withSum" << endl;
    cout << "test data: " << "a:"<< a << " b:" << b << endl;
    int answer = sort2withSum (&a, &b);
    cout << "Expected result: 13  a: 5  b: 8" << endl;
    cout << "Actual results : " << answer << "  a: "
         << a << "  b: " << b << endl;

    a = 2;
    b = 5;
    cout << "test data: " << "a:"<< a << " b:" << b << endl;
    answer = sort2withSum (&a, &b);
    cout << "Expected result: 7  a: 2  b: 5" << endl;
    cout << "Actual results : " << answer << "  a: "
         << a << "  b: " << b << endl << endl;



    cout << "Testing grow:" << endl;
    cout << "test data: ";
    showArray(testArrayGrow, 9);
    int *growth = grow(testArrayGrow, 9);
    cout << "Expected result:";
    showArray(expectedArrayGrow, 18);
    cout << "Actual result:  ";
    showArray (growth, 18);
    cout << endl;

    cout << "Testing subArray:" << endl;
    cout << "test data: 18 19 15 16 12 11 13 14 " << endl;
    cout << "start and length: " << arrayStartIdx << " "
         << arrayLength << endl;
    int *subTest = subArray(testArraySub, arrayStartIdx, arrayLength);

    cout << "result:   " ;
    showArray(subTest, arrayLength);
    cout << "expected: ";
    showArray(expectedArraySub, arrayLength);


return 0;
}

//***********************************************************
// showArray: displays the elements of an integer array in one line
//       separated by a space.
// array: an array of ints
// size: the number of ints in the array
//***********************************************************
void showArray (int *array, int size) {
    for (int i=0; i<size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//***********************************************************
// duplicateArray: creates a new array that contains the elements of the
//      array argument in the same order
// array: an array of ints
// size: the number of ints in the array
// returns a pointer to the new array.
//      If an invalid size is passed the function returns null.
// NOTE: it is the caller's responsibility to delete the returned array
//      when finished with it.
//***********************************************************
int *duplicateArray (int *arr, int size) {

   int *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address

   newArray = new int [size];  //allocate new array

   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];  //copy to new array

   return newArray;
}
