// File Name: DigitQueue.cpp
//
//Author: Jason McKinnerney
//Collaborators: None
//Date: 4/21/2021
//Assignment Number: PA6.2
//CS 2308 Spring 2021
//
// Implement a queue using a C++ integer variable to contain the entire contents 
// of the queue. In other words, instead of an array or linked list,
// one integer variable is used as a queue that can store several values.
// You should assume that the queue elements are integers in the range 1 to 9.

#include <iostream>
#include <cassert>
#include <cmath>
#include "DigitQueue.h"
using namespace std;

DigitQueue:: DigitQueue() { 
    queue = 0;      //the queue, container of the elements
    size = 0;       //the number of elements currently in the queue
}

void DigitQueue::enqueue(int num){       // Enqueue: Adds number to end of queue
    assert ((num < 10) && (num > 0));    // num is integer between 1 - 9
    queue = (pow(10,size)*num) + queue;  // adjust size by 1
    size = size + 1;
}
  


int DigitQueue::dequeue() {             // Dequeue: Removes number from front of queue
    int value = 0;                      // If Queue is not empty, dequeue first digit,
    if(!isEmpty()) {                    // change size by 1, and return value of digit
        value = queue % 10; 
        queue = queue / 10;
        size = size - 1;
    }
    else {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return value;
}    


bool DigitQueue::isEmpty(){         //Isempty: Boolean to see if size = 0
    return (size==0);
}


void DigitQueue::print(){           // Print digits from first to last in order
    if (!isEmpty()) {               // Printed in column form w/ one digit per line
        int count = size;           // If empty, no output needed.
        int value = queue;
        while (count > 0) {
            cout << value % 10 << endl;
            value = value / 10;
            count = count - 1;
        }
    }

}

