#include "global.hpp"
// std::vector<entry> symtable;

int lookup(const std::string &s)
{
    int p;
    // std::cout << "look up " << s << std::endl;
    for (p = 0; p < symtable.size(); p++) {
        // std::cout << symtable[p].getLex() << std::endl;
        if (!s.compare(symtable[p].getLex())) {
            // std::cout << p << std::endl;
            return p;
        }
    }
    return -1;
}

int insert(std::string s, int tok)
{
    entry p(s, tok);
    symtable.push_back(p);
    return symtable.size()-1;
}