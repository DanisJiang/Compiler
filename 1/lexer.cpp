#include "global.hpp"

// int lineno = 1;

// get the number from cin
int lexan()
{
    int t;
    while (1) {
        t = getchar();
        if (t == ' ' || t == '\t')
            ;
        else if (t == '\n') {
            lineno++;
        }
        else if (isdigit(t)) {
            ungetc(t, stdin);
            std::cin >> tokenval;
            return NUM;
        }
        else if (isalpha(t)) {
            std::string tmp;
            std::cin >> tmp;
            int p = lookup(tmp);
            if (p == -1) {
                p = insert(tmp, ID);
            }
            tokenval = p;
            return symtable[p].getToken();
        }
        else if (t == EOF)
            return DONE;
        else {
            tokenval = 0;
            return t;
        }
    }
}