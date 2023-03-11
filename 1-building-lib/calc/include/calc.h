#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <string>

namespace math
{
    class calc
    {
    private:
    public:
        calc(std::string val, int num_1, int num_2, std::string clr);
        calc(std::string val, float num_1, float num_2, std::string clr);
        calc(std::string val, int num_1, float num_2, std::string clr);
        calc(std::string val, float num_1, int num_2, std::string clr);
        calc(std::string val, std::string clr);
        ~calc();
    };

} // namespace name

#endif // CALC_H
