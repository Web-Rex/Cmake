#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>

namespace print
{
    void msg(std::string val_1, int val_2, std::string clr);
    void msg(std::string val_1, float val_2, std::string clr);
    void msg(std::string val_1, std::string val_2, std::string clr);
    void msg(std::string val_1, std::string clr);
    void msg(std::string val_1, int val_2);
    void msg(std::string val_1, float val_2);
    void msg(std::string val_1, std::string val_2);
    void msg(std::string val_1);
    void check(std::string val);
} // namespace name

#endif // PRINT_H
