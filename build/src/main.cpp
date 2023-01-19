// src.cpp : Defines the entry point for the application.
//

#include "main.h"

#ifndef CMAKEMACRO1
#define CMAKEMACRO1 "NO SYSTEM NAME"
#endif

using namespace std;

int main()
{
	std::cout << "Hello CMake." << std::endl;
	std::cout << CMAKEMACRO1 << std::endl;

	#ifdef AWESOME
		std::cout << "YOU ARE AWESOME" << std::endl;
	#else
		std::cout << "Sorry, you are not awesome" << std::endl;
	#endif

	return 0;
}
