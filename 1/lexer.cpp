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
            std::cin >> t;
            return t;
        }
    }
}