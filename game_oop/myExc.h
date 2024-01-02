#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class MyException : public std::exception {
public:
	virtual void printMessage() = 0;
};