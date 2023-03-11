#include <color.h>

color::setColor::setColor(int val)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, val);
}
color::setColor::~setColor()
{
}