#include <print.h>
#include <color.h>

void print::msg(std::string val_1, int val_2, std::string clr)
{
    check(clr);
    std::cout << val_1 << val_2 << std::endl;
    check("dflt");
}
void print::msg(std::string val_1, float val_2, std::string clr)
{
    check(clr);
    std::cout << val_1 << val_2 << std::endl;
    check("dflt");
}
void print::msg(std::string val_1, std::string val_2, std::string clr)
{
    check(clr);
    std::cout << val_1 << val_2 << std::endl;
    check("dflt");
}
void print::msg(std::string val_1, std::string clr)
{
    check(clr);
    std::cout << val_1 << std::endl;
    check("dflt");
}

// [ n-clr ]

void print::msg(std::string val_1, int val_2)
{
    std::cout << val_1 << val_2 << std::endl;
}
void print::msg(std::string val_1, float val_2)
{
    std::cout << val_1 << val_2 << std::endl;
}
void print::msg(std::string val_1)
{
    std::cout << val_1 << std::endl;
}

// [ chexk ]

void print::check(std::string val)
{
    if (val == "blu") 
        color::setColor(1);
    else if (val == "grn")  
        color::setColor(2);
    else if (val == "red")  
        color::setColor(4);
    else if (val == "prpl") 
        color::setColor(5);
    else if (val == "yll")  
        color::setColor(6);
    else if (val == "dflt") 
        color::setColor(7);
    else {
        std::cout << "This color does not exist" << std::endl;
        std::cout << "Val: " << val << std::endl;
    };
    // 15 > is background color

}