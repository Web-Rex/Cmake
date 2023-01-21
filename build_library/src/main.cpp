// src.cpp : Defines the entry point for the application.
//

#include "main.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	math::operations op;
	int sum = op.sum(3, 4);
	std::cout << "Sum of 3 + 4 :" << sum << std::endl;

	return 0;
}