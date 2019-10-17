#include "global.hpp"

void emit(int t, int tval)
{
    switch (t)
    {
    case '+': case '-': case '*': case '/':
        std::cout << (char)t << std::endl;
        break;
    case DIV:
        std::cout << "DIV" << std::endl;
        break;
    case MOD:
        std::cout << "MOD" << std::endl;
        break;
    case NUM:
        std::cout << tval << std::endl;
        break;
    case ID:
        std::cout << symtable[tval].getLex() << std::endl;
        break;
    default:
        std::cout << "token " << t << "tokenval " << tval << std::endl;
        break;
    }
}