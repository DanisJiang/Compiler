#include "global.hpp"

void error(std::string m)
{
    std::cerr << "line " << lineno << ": " << m << std::endl;
    exit(1);
}