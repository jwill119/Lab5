// Lab7MyStack.h
// Jacob Williams
// COSC 2030 Lab 5
//
// Header file for stack-implementation.


#ifndef MY_STACK_H
#define MY_STACK_H

#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::stack;
using std::vector;
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;


class MyStack {
    public:
        MyStack();
        ~MyStack();
        bool isEmpty(void) const;
        void push(char& c);
        char pull(void);
    private:
    //  vector<char> stuff;
        list<char> stuff;
};



#endif
