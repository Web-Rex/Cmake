#include "main.h"

int main()
{
    std::cout << "Main: " << "Working" << "\n";

    #if MY_DEBUG
            std::cout << "Mode: " << "Debug" << "\n";
    #else
            std::cout << "Mode: " << "Release" << "\n";
    #endif
    return 0;
}