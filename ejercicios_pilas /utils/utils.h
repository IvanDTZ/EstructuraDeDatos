#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using namespace std;

class ScreenStack {
private:
    string* screens;
    int top;
    int maxSize;

public:
    ScreenStack(int size);
    ~ScreenStack();

    bool isFull();
    bool isEmpty();
    void push(string screen);
    string pop();
    string peek();
    void display();
    bool isValidModel(string model);
};

#endif
