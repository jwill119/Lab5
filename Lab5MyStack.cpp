// Lab7MyStack.cpp
// Jacob Williams
// COSC 2030 Lab 5
//
// Function definitions for the stack-implementation.


#include "Lab5MyStack.h"

// Constructor constructs an empty stack
MyStack::MyStack() {
    stuff.resize(0);
}

// Empty destructor
MyStack::~MyStack() {
    stuff.resize(0);
}

// Check if stack is empty
bool MyStack::isEmpty(void) const {
    if (stuff.empty()) {
        return true;
    } else {
        return false;
    }
}

// Push a character to the stack
void MyStack::push(char& c) {
    stuff.push_back(c);
}

// Return the top character of the stack,
// also pop it off
char MyStack::pull(void) {
    char temp = stuff.back();
    stuff.pop_back();

    return temp;
}
