// src.cpp : Defines the entry point for the application.
//

#include "main.h"


int main()
{
	std::cout << "Hello CMake." << std::endl;

#if USE_OUT_LIB == 1

	print::print_msg log;
	log.log("i am working");

#elif USE_OUT_LIB == 2

	math::operations op;
	int sum = op.sum(3, 4);
	std::cout << "Sum of 3 + 4 :" << sum << std::endl;

#elif USE_OUT_LIB == 3

	Convert val(5);

#endif // DEBUG


	// std::cout << OUT_LIB << std::endl;

	return 0;
}