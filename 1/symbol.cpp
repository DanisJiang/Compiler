#include "global.hpp"

// std::vector<entry> symtable;

int lookup(const std::string &s)
{
    int p;
    for (p = 0; p < symtable.size(); p++) {
        if (s.compare(symtable[p].getLex())) {
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