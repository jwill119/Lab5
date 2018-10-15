// Lab7Driver.cpp
// Jacob Williams
// COSC 2030 Lab 5
//
// The testing file for the lab.

#include "Lab5MyStack.h"

/*                                    *
 * The functions we have to deal with *
 *                                    */

// The first function: Reverses via a stack of characters
string stringReversal1(string input);

// The second function: Reverses via a vector of characters
string stringReversal2(string input);

// The third function: Reverses via a list of characters
string stringReversal3(string input);

// The fourth function: Reverses via MyStack
string stringReversal4(string input);


int main() {
    cout << endl << "Test a string via first method." << endl;
    string firstInp;
    cin >> firstInp;
    string firstOut = stringReversal1(firstInp);

    cout << endl << firstOut << endl << endl;


    cout << endl << "Test a string via second method." << endl;
    string secondInp;
    cin >> secondInp;
    string secondOut = stringReversal2(secondInp);

    cout << endl << secondOut << endl << endl;


    cout << endl << "Test a string via third method." << endl;
    string thirdInp;
    cin >> thirdInp;
    string thirdOut = stringReversal3(thirdInp);

    cout << endl << thirdOut << endl << endl;

    cout << endl << "Test a string via MyStack method!" << endl;
    string fourthInp;
    cin >> fourthInp;
    string fourthOut = stringReversal4(fourthInp);

    cout << endl << fourthOut << endl << endl;



    return 0;
}

// Reverses a string via a stack of characters.
string stringReversal1(string input) {
    string reversedString;
    stack<char> temp;

    // Build the stack
    for (int i = 0; i < input.size(); i++) {
        temp.push(input.at(i));
    }

    // Put back onto reversed string
    while (!temp.empty()) {
        reversedString.push_back(temp.top());
        temp.pop();
    }



    return reversedString;
}

// Reverse a string via a vector of characters.
string stringReversal2(string input) {
    string reversedString;
    vector<char> temp;

    // Build the vector
    for (int i = 0; i < input.size(); i++) {
        temp.push_back(input.at(i));
    }

    // Put the reversed string together
    while (!temp.empty()) {
        reversedString.push_back(temp.back());
        temp.pop_back();
    }

    return reversedString;
}


// Reverse a string via a list of characters.
string stringReversal3(string input) {
    string reversedString;
    list<char> temp;

    // Build the list
    for (int i = 0; i < input.size(); i++) {
        temp.push_back(input.at(i));
    }

    // Put the reversed string together
    for (int i = 0; i < input.size(); i++) {
        reversedString.push_back(temp.back());
        temp.pop_back();
    }

    return reversedString;
}

// Reverse a string via the MyStack class.
string stringReversal4(string input) {
    string reversedString;
    MyStack temp;

    // Build the MyStack
    for (int i = 0; i < input.size(); i++) {
        temp.push(input.at(i));
    }

    // Construct the reversed string.
    while (!temp.isEmpty()) {
        reversedString.push_back(temp.pull());
    }

    return reversedString;
}
