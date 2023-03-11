#include <calc.h>
#include <print.h>

math::calc::calc(std::string val, int num_1, int num_2, std::string clr)
{
    if (val.compare("plus") == 0)
        print::msg("Total:", num_1 + num_2, clr);
    if (val.compare("minus") == 0)
        print::msg("Total:", num_1 - num_2, clr);
}
math::calc::calc(std::string val, float num_1, float num_2, std::string clr)
{
    if (val.compare("plus") == 0)
        print::msg("Total:", num_1 + num_2, clr);
    if (val.compare("minus") == 0)
        print::msg("Total:", num_1 - num_2, clr);
};
math::calc::calc(std::string val, int num_1, float num_2, std::string clr)
{
    if (val.compare("plus") == 0)
        print::msg("Total:", num_1 + num_2, clr);
    if (val.compare("minus") == 0)
        print::msg("Total:", num_1 - num_2, clr);
};
math::calc::calc(std::string val, float num_1, int num_2, std::string clr)
{
    if (val.compare("plus") == 0)
        print::msg("Total:", num_1 + num_2, clr);
    if (val.compare("minus") == 0)
        print::msg("Total:", num_1 - num_2, clr);
};
math::calc::calc(std::string val, std::string clr)
{
    print::msg(val, clr);
};

math::calc::~calc()
{
}
